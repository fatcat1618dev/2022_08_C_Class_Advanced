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
#### Q1：char范围导致的死循环
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

#### Q2：字符串长度
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

#### Q3:无符号int导致的死循环
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

#### Q4.char范围（-128与128关系、char圆圈）
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

#### Q5.负数的原反补（整型提升）
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

#### Q6.系统字节序（大端/小端）
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

#### Q7.负数的原反补（整型提升、截断）
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

#### Q1.计算-2.5浮点型存储序列
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
* p[i][j]等效于*(*(p+i)+j)或(*(p+i))[j]或*(p[i]+j)),[]起到了<font color='red'>**加解**</font>