# 2022_08_C_Class_Advanced
---
* 第1节	数据的存储
* 第2节	指针的进阶
* 第3节	字符串 内存函数
* 第4节	自定义类型（结构体 枚举 联合）
* 第5节	动态内存管理
* 第6节	文件操作
* 第7节	程序的编译（预处理） 链接

---
## 第1节 数据在内存中的存储
* 1.数据类型
* 2.整型在内存中的存储：原反补码
* 3.大小端字节序
* 4.浮点型在内存中的存储
* 注：limits.h,float.h
---
### 整型存储
* **Q1：char范围导致的死循环**
```c
unsigned char i = 0;
int main()
{
	for (i = 0; i <= 255; i++)
	{
		printf("hello world\n");
	}
	return 0;
}
```
注：
* char范围,0-255
* char圈，循环往复

* **Q2：字符串长度**
```c
int main()
{
	char a[1000];
	int i;
	for (i = 0; i < 1000; i++)
	{
		a[i] = -1 - i;
	}
	printf("%d", strlen(a));
	return 0;
}
```
注：
* -1 -2 -128 127 126 ... 0,255
* char圈,有符号char:0～127,-128,-127...-1
* ASCII码表![ASCII码表](http://cuihuan.net/wp_content/new/finance/ASCII.png)

* **Q3:无符号int导致的死循环**
```c
main()
{
	unsigned int i;
	for (i = 9; i >= 0; i--)
	{
		printf("%u\n", i);
	}
	return 0;
}
```
注：死循环，-1若u则超大数字

* **Q4.char范围（-128与128关系、char圆圈）**
```c
int main()
{
	char a = -128;
	char b = 128;
	if (a == b)
		printf("hello!");
	return 0;
}
```
注：相等，打印hello

* **Q5.负数的原反补（整型提升）**
```c
int main()
{
	char a = -128;
	printf("%u\n", a);
	printf("%d\n", a);

	return 0;
}
```
注：
* u为无符号型，超大数字ffffff80
* -128

* **Q6.系统字节序（大端/小端）**
```c
int check_sys()
{
	int a = 1;
	//返回1，小端
	//返回0，大端
	return *(char*)&a;;
}
int main()
{
	int ret = check_sys();
	if (ret == 1)
		printf("小端\n");
	else
		printf("大端\n");
	return 0;
}
```
注：
* 返回系统字节序大端、小端；
* 数字高位对应内存地址高位则小端机器，平时使用的基本是小端机器

* **Q7.负数的原反补（整型提升、截断）**
```c
int main()
{
	char a = -1;
	signed char b = -1;
	unsigned char c = -1;
	printf("a=%d b=%d c=%u\n", a, b, c);
	return 0;
}
```
注：
* -1 -1 255，涉及到整型提升、原反补
* 和Q5有点区别，该例c直接定为unsigned，数据截断

---
### 浮点型存储

* **Q1.计算-2.5浮点型存储序列**
  * //整型、浮点型内存存储形式不一样
  * //参考IEEE 754规定
```c
int main()
{
	//整型存入
	int n = 9;
	float* p = (float*)&n;
	//00000000 00000000 00000000 00001001	补码
	//0 00000000 000 0000000000 0000001001	按浮点数解读
	//(-1)^0 * 2^(1-127)*0.00000000000000000001001	
	printf("n的值 ：%d\n", n);	//9
	printf("*p的值：%f\n", *p);	//0.000000

	//浮点型存入
	*p = 9.0;
	//9.0
	//1001.0	二进制
	//1.001*2^3	指数变为3+127
	//0 10000010 001 0000000000 0000000000 内存存储值，电脑计算器可算为1091567616

	printf("n的值 ：%d\n", n);//1091567616
	printf("*p的值：%f\n", *p);//9.000000

	//举例1
	float f = -2.5;
	//-2.5
	//-10.1 二进制
	//-1.01 * 2^1	指数+127,变为128
	//1 10000000 010 0000000000 0000000000，内存存储值C0200000，可查内存也为000020c0小端，和计算的一致
	//
	return 0;
}
```
* **注**
  * ***IEEE 754***<img src="test_07_29\test_07_29\图片\浮点型数据-ieee754_1.jpg"/>
  * ***IEEE 754***<img src="test_07_29\test_07_29\图片\浮点型数据-ieee754_2.jpg"/>
  * 运行结果<img src="test_07_29\test_07_29\图片\浮点型数据-例子.jpg"/>

---
## 第2节 指针的进阶
* 1.字符指针
* 2.数组指针
* 3.指针数组
* 4.数组传参和指针传参
* 5.函数指针
* 6.函数指针数组
* 7.指向函数指针数组的指针
* 8.回调函数
* 9.指针和数组题解析
---
### 字符指针
* **Q1.常量字符串1**
```c
//segmentfault	内存访问
int main()
{
	const char* p = "abcdef";	//"abcdef"是个常量字符串
	//*p='W';
	printf("%s\n", p);
	return 0;
}
```
注：常量字符串不可改

* **Q2.常量字符串2**
```c
int main()
{
	char arr1[] = "haomo";
	char arr2[] = "haomo";
	char* p1 = "haomo";
	char* p2 = "haomo";
	if (arr1 == arr2)
		printf("arr1与arr2相等\n");
	if (p1 == p2)
		printf("p1与p2一样\n");

	return 0;
}
```
* p1与p2一样

### 指针数组
```c
int main()
{
	int arr1[] = { 1,2,3 };
	int arr2[] = { 2,3,4 };
	int arr3[] = { 4,5,6 };
	int* p[] = { arr1,arr2,arr3 };
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		int j = 0;
		for (j = 0; j < 3; j++)
		{
			printf("%d ", *(p[i]+j));
		}
		printf("\n");
	}
	return 0;
}
```
注：类似遍历二维数组，矩阵

### 数组指针、传参（数组、指针）
* 二维数组传参，形参只能省略第1个[],即行数，如void test(int *arr[][5])

```c
//数组 指针传参、数组指针
//数组传参
void print1(int arr[3][5], int x, int y)
{
	int i = 0;
	for (i = 0; i < x; i++)				//范围
	{
		int j = 0;
		for (j = 0; j < y; j++)			//范围
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
//指针传参
void print2(int(*p)[5],int x,int y)
{
	int i = 0;
	for (i = 0; i < x; i++)
	{
		int j = 0;
		for (j = 0; j < y; j++)
		{
			printf("%d ", p[i][j]);//最终
			//printf("%d ", *(p[i]+j));//简化
			//printf("%d ", (*(p + i))[j]);//简化
			//printf("%d ", *(*(p + i) + j));//原始版
		}
		printf("\n");
	}
}
int main()
{
	int arr[3][5] = { {1,2,3,4,5},{2,4,6,8,10},{3,5,7,9,11} };
	print1(arr, 3, 5);//    数组传参
	print2(arr, 3, 5);//数组指针传参
	return 0;
}
```
注：
* int(*p)[5]，数组指针
* p[i][j]等效于\*(\*(p+i)+j)或(\*(p+i))[j]或*(p[i]+j)),[]起到了<font color='red'>**加解**</font>

### 函数指针、函数指针数组、回调函数等
* 典型语句理解
```c
(* (void(*)()0)();
//把0强制转为void(*)()函数指针类型，调用0地址处的该函数
void(*signal(int, void(*)(int)))(int)////void(*)(int)//signal(int, void(*)(int))
//signal是1个函数声明，有2个参数，第1个是int，第2个是函数指针，该函数指针指向函数参数int，返回类型void
//signal函数的返回类型也是1个函数指针，该函数指针指向的函数的参数是int,返回类型是void
```
* 计算器-函数指针版
```c
int	Add(int x, int y)
{
	return x + y;
}
int	Sub(int x, int y)
{
	return x - y;
}
int	Mul(int x, int y)
{
	return x * y;
}
int	Div(int x, int y)
{
	return x / y;
}
void menu()
{
	printf("*****************************\n");
	printf("******  1.Add    2.Sub  *****\n");
	printf("********3.Mul    4.Div  *****\n");
	printf("********0.Exit***************\n");
}
Calc(int(*p)(int, int))
{
	int x = 0;
	int y = 0;
	printf("请输入两个操作数:>");
	scanf("%d%d", &x, &y);
	printf("%d\n", p(x, y));
}
int main()
{
	int input = 0;
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			Calc(Add);
			break;
		case 2:
			Calc(Sub);
			break;
		case 3:
			Calc(Mul);
			break;
		case 4:
			Calc(Div);
			break;
		default:
			break;
		}
	} while (input);

	return 0;
}
```
* 计算器-函数指针数组版
```c
int	Add(int x, int y)
{
	return x + y;
}
int	Sub(int x, int y)
{
	return x - y;
}
int	Mul(int x, int y)
{
	return x * y;
}
int	Div(int x, int y)
{
	return x / y;
}
void menu()
{
	printf("*****************************\n");
	printf("******  1.Add    2.Sub  *****\n");
	printf("********3.Mul    4.Div  *****\n");
	printf("********0.Exit***************\n");
	printf("*****************************\n");

}

int main()
{
	int input = 0;
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		int x = 0;
		int y = 0;
		int(*pfarr[5])(int, int) = { 0,Add,Sub,Mul,Div };
		if (input >= 1 && input <= 4)
		{
			printf("请输入两个操作数:>");
			scanf("%d%d", &x, &y);
			printf("%d\n", pfarr[input](x, y));
		}
		else
			printf("选择错误！\n");
	} while (input);

	return 0;
}
```
* 库函数qsort
```c
//库函数qsort
//整型、浮点型、结构体排序.
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
struct co_workers
{
	char name[20];//
	int height;	  //cm
};
//整型比较
int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}
//浮点型数组比较函数
int cmp_float(const void* e1, const void* e2)
{
	return (int)(ceil(*(float*)e1 - *(float*)e2));
}
//结构体数组比较函数-by name
int cmp_struct_by_name(const void* e1, const void* e2)
{
	return strcmp(((struct co_workers*)e1)->name, ((struct co_workers*)e2)->name);
}
//结构体数组比较函数-by height
int cmp_struct_by_height(const void* e1, const void* e2)
{
	return (((struct co_workers*)e1)->height - ((struct co_workers*)e2)->height);
}
int main()
{
	int arr1[] = { 1,3,5,7,9,2,4,6,8,10 };
	float arr2[] = { 1.0,2.1,2.2,1.8,3.1,4.5,6.6,9.5,8.7,3.3 };
	struct co_workers arr3[3]= { {"lichao",180},{"zhangyu",190},{"sunyan",175} };
	//void qsort(void* base, size_t nitems, size_t size, int (*compar)(const void*, const void*))
	//			 起点地址	   数组长度	  数组每个元素大小	函数指针(排序元素1的地址，排序元素2的地址）
	//整型排序
	int sz_arr1 = sizeof(arr1) / sizeof(arr1[0]);//元素个数
	int width_arr1 = sizeof(arr1[0]);			//元素字节大小
	qsort(arr1, sz_arr1, width_arr1, cmp_int);

	//浮点型排序
	int sz_arr2 = sizeof(arr2) / sizeof(arr2[0]);//元素个数
	int width_arr2 = sizeof(arr2[0]);			//元素字节大小
	qsort(arr2, sz_arr2, width_arr2, cmp_float);

	//结构体排序-by-name
	//结构体排序-by-heights
	int sz_arr3 = sizeof(arr3) / sizeof(arr3[0]);//元素个数
	int width_arr3 = sizeof(arr3[0]);			//元素字节大小
	qsort(arr3, sz_arr3, width_arr3, cmp_struct_by_name);
	qsort(arr3, sz_arr3, width_arr3, cmp_struct_by_height);

	return 0;
}
```
* **注：**
  * 库函数qsort,支持各种类型数据排序
  * 比较函数自定义，函数指针回调函数
---
* ***自定义my_bubble_sort函数实现类似qsort类似排序功能***
```c
//基于基本冒泡排序思想，自定义实现类似库函数qsort的功能
//支持整型、浮点型、结构体等多种类型数组排序
//flag排序标志位，排序ok后直接break跳出循环
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
struct co_workers
{
	char name[20];//
	int height;	  //cm
};
//整型比较
int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}
//浮点型数组比较函数
int cmp_float(const void* e1, const void* e2)
{
	return (int)(ceil(*(float*)e1 - *(float*)e2));
}
//结构体数组比较函数-by name
int cmp_struct_by_name(const void* e1, const void* e2)
{
	return strcmp(((struct co_workers*)e1)->name, ((struct co_workers*)e2)->name);
}
//结构体数组比较函数-by height
int cmp_struct_by_height(const void* e1, const void* e2)
{
	return (((struct co_workers*)e1)->height - ((struct co_workers*)e2)->height);
}

//可实现多种类型数组排序的扩展型my_bubble_sort
void Swap(char* buf1, char* buf2, int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}
void my_bubble_sort(void* base, int sz, int width, int(*cmp)(const void*, const void*))
{
	int i = 0;
	//比较的趟数
	for (i = 0; i < sz - 1; i++)
	{
		int flag = 1;//假设已经排序ok
		int j = 0;
		//每趟比较的对数
		for (j = 0; j < sz - 1 - i; j++)
		{	//两个元素比较
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)//	(char*)base + j * width //(char*)base+(j+1)*width
			{
				//交换
				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
				//flag = 0;//需要重排
			}
		}
		if (flag == 1)
			break;
	}
}
int main()
{
	//int arr1[] = { 1,3,5,7,9,2,4,6,8,10 };
	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };

	float arr2[] = { 1.0,2.1,2.2,1.8,3.1,4.5,6.6,9.5,8.7,3.3 };
	struct co_workers arr3[3]= { {"lichao",180},{"zhangyu",190},{"sunyan",175} };
	//void qsort(void* base, size_t nitems, size_t size, int (*compar)(const void*, const void*))
	//			 起点地址	   数组长度	  数组每个元素大小	函数指针(排序元素1的地址，排序元素2的地址）
	//整型排序
	int sz_arr1 = sizeof(arr1) / sizeof(arr1[0]);//元素个数
	int width_arr1 = sizeof(arr1[0]);			
	my_bubble_sort(arr1, sz_arr1, width_arr1, cmp_int);

	//浮点型排序
	int sz_arr2 = sizeof(arr2) / sizeof(arr2[0]);//元素个数
	int width_arr2 = sizeof(arr2[0]);			
	my_bubble_sort(arr2, sz_arr2, width_arr2, cmp_float);

	//结构体排序-by-name
	//结构体排序-by-heights
	int sz_arr3 = sizeof(arr3) / sizeof(arr3[0]);//元素个数
	int width_arr3 = sizeof(arr3[0]);			
	my_bubble_sort(arr3, sz_arr3, width_arr3, cmp_struct_by_name);
	my_bubble_sort(arr3, sz_arr3, width_arr3, cmp_struct_by_height);

	return 0;
}
```
* 注：
  * 和基本的冒泡排序思想一致；
  * 函数指针（回调函数）；
  * flag排序标志位
---
### 指针题
#### 题1
```c
int main()
{
	int a[5] = { 1,2,3,4,5 };
	int* ptr = (int*)(&a + 1);
	printf("%d %d\n", *(a + 1), *(ptr - 1));
	return 0;
}
//2 5	*(a+1)=a[1]
```

#### 题2
```c
struct test
{
	int Num;
	char* pcName;
	short sDate;
	char cha[2];
	short sBa[4];
}*p;
//假设p的值为0x10 0000，已知结构体Test类型的变量大小20个字节
int main()
{
	p = (struct Test*)0x100000;
	printf("%p\n", p + 0x1);
	printf("%p\n", (unsigned long)p + 0x1);
	printf("%p\n", (unsigned int*)p + 0x1);

	return 0;
}
//指针+-整数	100014	100001	100004
```
#### 题3
```c
int main()
{
	int a[4] = { 1,2,3,4 };
	int* ptr1 = (int*)(&a + 1);
	int* ptr2 = (int*)((int)a + 1);
	printf("%x %x", ptr1[-1], *ptr2);

	return 0;
}
//4 2000000
//01000000 02000000 03000000 04000000,大小端字节序
```
#### 题4
```c
int main()
{
	int a[3][2] = { (0,1),(2,3),(4,5) };
	int* p;
	p = a[0];
	printf("%d\n", p[0]);

	return 0;
}
//a[0][0],首行首元素
//逗号表达式
```
#### 题5
```c
int main()
{
	int a[5][5];
	int(*p)[4];
	p = a;
	printf("%p %d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);

	return 0;
}
//FFFFFFFC -4
```
#### 题6
```c
int main()
{
	int aa[2][5] = { 1,2,3,4,5,6,7,8,9,10 };
	int* ptr1 = (int*)(&aa + 1);
	int* ptr2 = (int*)(*(aa + 1));
	printf("%d,%d\n", *(ptr1 - 1), *(ptr2 - 1));

	return 0;
}
//☆ 10 5
```

#### 题7
```c
int main()
{
	char* a[] = { "work","at","alibaba" };
	char** pa = a;
	pa++;
	printf("%s\n", *pa);

	return 0;
}
//at
```

#### 题8
```c
int main()
{
	char* c[] = { "ENTER","NEW","POINT","FIRST" };
	char** cp[] = { c + 3,c + 2,c + 1,c };
	char*** cpp = cp;

	printf("%s\n", **++cpp);
	printf("%s\n", *-- * ++cpp + 3);
	printf("%s\n", *cpp[-2] + 3);
	printf("%s\n", cpp[-1][-1] + 1);

	return 0;
}
//POINT ER （此时cpp指向c+1位置）ST EW
```
---
#### ***水仙花数***
```c
//打印水仙花数
//求出0-100000间的水仙花数并输出。水仙花数是指1个n位数，各位数字的n次方之和等于该数本身，如153=1^3+5^3+3^3。
//自幂数
#include<math.h>
int main()
{
	int i = 0;
	for (i = 0; i < 100000; i++)
	{
		//1.位数
		int n = 1;
		int temp = i;
		while (temp /= 10)
		{
			n++;
		}
		//2.自幂数和
		int sum = 0;
		temp = i;
		while (temp)
		{
			sum += pow(temp % 10, n);
			temp /= 10;
		}
		//3.比较
		if (i == sum)
			printf("%d ", i);
	}
	return 0;
}
```
#### ***菱形图案***
```c

//      *			   /6 /1*
//     ***			/5 /3*
//    *****			/4 /5*
//   *******			/3 /7*
//  *********			/2 /9*
// ***********			/1 /11*
//*************			/0 /13*   ////
// ***********			/1 /11*
//  *********				/2 /9*
//   *******
//    *****
//     ***
//      *					/6 /1*
//打印菱形图案
int main()
{
	int line = 0;
	scanf("%d", &line);
	//打印上半部分
	int i = 0;
	for (i = 0; i < line; i++)
	{
		//空格
		int j = 0;
		for (j=0;j<line-1-i;j++)
		{
			printf(" ");
		}
		//*号
		for(j=0;j<2*i+1;j++)	//第一行1个
		{
			printf("*");
		}
		printf("\n");
	}
	//打印下半部分
	for (i = 0; i < line-1; i++)
	{
		//空格
		int j = 0;
		for (j = 0; j <= i; j++)
		{
			printf(" ");
		}
		//*号
		for (j = 0; j < 2 *(line-i-1)-1; j++)	//第一行1个
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
```
#### ***杨辉三角***
```c
//杨辉三角
int main()
{
	int arr[10][10] = { 0 };
	int i = 0;
	int j = 0;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (j == 0)
			{
				arr[i][j] = 1;
			}
			if (i == j)
			{
				arr[i][j] = 1;
			}
			if (i >= 2 && j >= 1)
			{
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			}
		}
		
	}
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
```
#### ***凶杀案***
```c
//凶杀案，凶手为4个嫌疑犯中的1个：
//供词如下：
//A说：不是我。
//B说：是C。
//C说：是D。
//D说：C在胡说。
//已知3个人说了真话，1个人说的假话。

int main()
{
	int killer = 0;
	for (killer = 'a'; killer <= 'd'; killer++)
	{
		if ((killer != 'a')+(killer == 'c')+ (killer == 'd') + (killer != 'd')==3)
			printf("killer=%c\n", killer);
	}
	return 0;
}
```
*注：条件判断*
#### ***烧香问题***
```c
//烧香问题
//有一种香，材质不均匀，但是每一根香燃烧完恰好是1小时。
//给你两根香，确定1个15min的时间段。
//|====================|	A
//|====================|	B
//A从两头烧，B从一头；
//A烧完，B烧了半小时，点B另一头，到B燃尽的时间段为15min.
```
#### ***比赛名次***
```c
//猜名次
//5位运动员参加了10km长跑比赛，他们预测比赛结果：
//A说：B第2，我第3；
//B说：我第2，E第4；
//C说：我第1，D第2；
//D说：C第5，我第3；
//E说：我第4，A第1.
//比赛结束后，每位运动员都说对了1半，实际排名是怎样的？
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	for (a = 1; a <= 5; a++)
	{
		for (b = 1; b <= 5; b++)
		{
			for (c = 1; c <= 5; c++)
			{
				for (d = 1; d <= 5; d++)
				{
					for (e = 1; e <= 5; e++)
						if (((b == 2) + (a == 3) == 1) + ((b == 2) + (e == 4) == 1) + ((c == 1) + (d == 2) == 1) + ((c == 5) + (d == 3) == 1) + ((e == 4) + (a == 1) == 1)==5)
						{
							if (a * b * c * d * e == 120)
								printf("a=%d b=%d c=%d d=%d e=%d\n", a, b, c, d, e);
						}

				}
			}
		}
	}
	return 0;
}
//3 1 5 2 4
//a b c d e
````
*注:三个条件：①各对1半；②和为5；③积为120*
