#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

//119-135
//136-146

//
//void test(int arr[])
//{
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	printf("%d\n", sz);
//}
//int main()
//{
//	int arr[] = { 0 };
//	test(arr);
//	return 0;
//}
//
//若改为x64，打印2，64位平台指针8个字节

////指针存首字符地址
//int main()
//{
//	char* p = "abcdef";	//"abcdef"是个常量字符串
//	printf("%c\n", *p);
//	printf("%s\n",p);
//	return 0;
//}

////stackoverflow.com
////segmentfault	内存访问
//int main()
//{
//	const char* p = "abcdef";	//"abcdef"是个常量字符串
//	//*p='W';
//	printf("%s\n", p);
//	return 0;
//}

////字符指针
//int main()
//{
//	char arr1[] = "haomo";
//	char arr2[] = "haomo";
//	const char* p1 = "haomo";
//	const char* p2 = "haomo";
//	if (arr1 == arr2)
//		printf("arr1与arr2相等\n");
//	if (p1 == p2)
//		printf("p1与p2一样\n");
//
//	return 0;
//}

////指针数组
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = 30;
//	int d = 40;
//	int* arr[4] = { &a,&b,&c,&d };
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		printf("%d ", *(arr[i]));
//	}
//	return 0;
//}

/////指针数组2
//int main()
//{
//	int arr1[] = { 1,2,3 };
//	int arr2[] = { 2,3,4 };
//	int arr3[] = { 4,5,6 };
//	int* p[] = { arr1,arr2,arr3 };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 3; j++)
//		{
//			printf("%d ", *(p[i]+j));
//		}
//		printf("\n");
//	}
//	return 0;
//}

////
////数组指针
////
//
//int main()
//{
//	int* p = NULL;	//整型指针
//	char* pc = NULL;//字符指针
//					//数组指针
//	//int arr[10]={0};
//	//arr首元素地址,&arr[0]
//	//&arr	数组地址
//
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int(*p)[10] = &arr;							//p是数组指针
//	return 0;
//}
//

//int main()
//{
//	char* arr[5];
//	char*(*pc)[5]=&arr;
//
//	return 0;
//}

////数组 指针传参、数组指针
////数组传参
//void print1(int arr[3][5], int x, int y)
//{
//	int i = 0;
//	for (i = 0; i < x; i++)				//范围
//	{
//		int j = 0;
//		for (j = 0; j < y; j++)			//范围
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
////指针传参
//void print2(int(*p)[5],int x,int y)
//{
//	int i = 0;
//	for (i = 0; i < x; i++)
//	{
//		int j = 0;
//		for (j = 0; j < y; j++)
//		{
//			printf("%d ", p[i][j]);//最终
//			//printf("%d ", *(p[i]+j));//简化
//			//printf("%d ", (*(p + i))[j]);//简化
//			//printf("%d ", *(*(p + i) + j));//原始版
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int arr[3][5] = { {1,2,3,4,5},{2,4,6,8,10},{3,5,7,9,11} };
//	print1(arr, 3, 5);//    数组传参
//	print2(arr, 3, 5);//数组指针传参
//	return 0;
//}

//int main()
//{
//	unsigned int i = 0;
//	printf("%u\n", i - 1);
//
//	char a = '0';
//	char b = 0;
//	printf("%c", a);
//	printf("%c", b);
//
//	//2022年7月31日 星期日
//	//字符指针
//	char ch = 'w';
//	char* p = &ch;
//	//指针数组
//	const char* p2 = "abcdef";//存放字符串首字母地址
//
//	//int *p3//char *p4
//	int arr2[5];//数组
//	int(*pa)[5] = &arr2;//取出数组地址，pa数组指针
//
//	int(*parr[10])[5];//10个元素的数组指针，每个指针5元素的数组
//	return 0;
//}

////一维传参
//void test(int arr[])	//第1种写法，不带大小
//{}
//void test(int arr[10])	//第2种写法，带大小
//{}
//void test(int *arr)//第3种写法
//{}

//int main()
//{
//	int arr[10] = { 0 };
//	int* arr2[20] = { 0 };
//	test(arr);
//	//test2(arr2);
//	return 0;
//}

////1级指针传参
//void print(int* p, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", p[i]);
//	}
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5 };
//	int* p = arr;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print(p, sz);
//	return 0;
//}

//
////二级指针
//void test(int** p)
//{
//	printf("num=%d\n", **p);
//}
//
//
//int main()
//{
//	int n = 10;
//	int* p = &n;
//	int**pp = &p;
//	test(pp);
//	test(&p);
//	return 0;
//}
//

////函数指针
////指向函数的指针
//int	add(int x, int y)
//{
//	return x + y;
//}
//
//int main()
//{
//	int x = 0;
//	int y = 0;
//	printf("输入两个数:>");
//	scanf("%d%d", &x, &y);
//	printf("%d\n", add(x, y));	//函数调用
//
//	int(*p)(int, int) = add;	//函数指针
//	printf("%d\n", (*p)(x, y));	//函数指针调用1
//	printf("%d\n", p(x, y));	//函数指针调用2
//
//	return 0;
//}
//(* (void(*)()0)();
////把0强制转为void(*)()函数指针类型，调用0地址处的该函数
//void(*signal(int, void(*)(int)))(int)////void(*)(int)//signal(int, void(*)(int))
////signal是1个函数声明，有2个参数，第1个是int，第2个是函数指针，该函数指针指向函数参数int，返回类型void
////signal函数的返回类型也是1个函数指针，该函数指针指向的函数的参数是int,返回类型是void
//

//计算器——函数指针版
//int	Add(int x, int y)
//{
//	return x + y;
//}
//int	Sub(int x, int y)
//{
//	return x - y;
//}
//int	Mul(int x, int y)
//{
//	return x * y;
//}
//int	Div(int x, int y)
//{
//	return x / y;
//}
//void menu()
//{
//	printf("*****************************\n");
//	printf("******  1.Add    2.Sub  *****\n");
//	printf("********3.Mul    4.Div  *****\n");
//	printf("********0.Exit***************\n");
//}
//Calc(int(*p)(int, int))
//{
//	int x = 0;
//	int y = 0;
//	printf("请输入两个操作数:>");
//	scanf("%d%d", &x, &y);
//	printf("%d\n", p(x, y));
//}
//int main()
//{
//	int input = 0;
//	do
//	{
//		menu();
//		printf("请选择:>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			Calc(Add);
//			break;
//		case 2:
//			Calc(Sub);
//			break;
//		case 3:
//			Calc(Mul);
//			break;
//		case 4:
//			Calc(Div);
//			break;
//		default:
//			break;
//		}
//	} while (input);
//
//	return 0;
//}


////计算器——函数指针数组版
//int	Add(int x, int y)
//{
//	return x + y;
//}
//int	Sub(int x, int y)
//{
//	return x - y;
//}
//int	Mul(int x, int y)
//{
//	return x * y;
//}
//int	Div(int x, int y)
//{
//	return x / y;
//}
//void menu()
//{
//	printf("*****************************\n");
//	printf("******  1.Add    2.Sub  *****\n");
//	printf("********3.Mul    4.Div  *****\n");
//	printf("********0.Exit***************\n");
//	printf("*****************************\n");
//
//}
//
//int main()
//{
//	int input = 0;
//	do
//	{
//		menu();
//		printf("请选择:>");
//		scanf("%d", &input);
//		int x = 0;
//		int y = 0;
//		int(*pfarr[5])(int, int) = { 0,Add,Sub,Mul,Div };
//		if (input >= 1 && input <= 4)
//		{
//			printf("请输入两个操作数:>");
//			scanf("%d%d", &x, &y);
//			printf("%d\n", pfarr[input](x, y));
//		}
//		else
//			printf("选择错误！\n");
//	} while (input);
//
//	return 0;
//}

////库函数qsort
////整型、浮点型、结构体排序.
//#include<stdlib.h>
//#include<math.h>
//#include<string.h>
//struct co_workers
//{
//	char name[20];//
//	int height;	  //cm
//};
////整型比较
//int cmp_int(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
////浮点型数组比较函数
//int cmp_float(const void* e1, const void* e2)
//{
//	return (int)(ceil(*(float*)e1 - *(float*)e2));
//}
////结构体数组比较函数-by name
//int cmp_struct_by_name(const void* e1, const void* e2)
//{
//	return strcmp(((struct co_workers*)e1)->name, ((struct co_workers*)e2)->name);
//}
////结构体数组比较函数-by height
//int cmp_struct_by_height(const void* e1, const void* e2)
//{
//	return (((struct co_workers*)e1)->height - ((struct co_workers*)e2)->height);
//}
//int main()
//{
//	int arr1[] = { 1,3,5,7,9,2,4,6,8,10 };
//	float arr2[] = { 1.0,2.1,2.2,1.8,3.1,4.5,6.6,9.5,8.7,3.3 };
//	struct co_workers arr3[3]= { {"lichao",180},{"zhangyu",190},{"sunyan",175} };
//	//void qsort(void* base, size_t nitems, size_t size, int (*compar)(const void*, const void*))
//	//			 起点地址	   数组长度	  数组每个元素大小	函数指针(排序元素1的地址，排序元素2的地址）
//	//整型排序
//	int sz_arr1 = sizeof(arr1) / sizeof(arr1[0]);//元素个数
//	int width_arr1 = sizeof(arr1[0]);			//元素字节大小
//	qsort(arr1, sz_arr1, width_arr1, cmp_int);
//
//	//浮点型排序
//	int sz_arr2 = sizeof(arr2) / sizeof(arr2[0]);//元素个数
//	int width_arr2 = sizeof(arr2[0]);			//元素字节大小
//	qsort(arr2, sz_arr2, width_arr2, cmp_float);
//
//	//结构体排序-by-name
//	//结构体排序-by-heights
//	int sz_arr3 = sizeof(arr3) / sizeof(arr3[0]);//元素个数
//	int width_arr3 = sizeof(arr3[0]);			//元素字节大小
//	qsort(arr3, sz_arr3, width_arr3, cmp_struct_by_name);
//	qsort(arr3, sz_arr3, width_arr3, cmp_struct_by_height);
//
//	return 0;
//}


//
////基于基本冒泡排序思想，自定义实现类似库函数qsort的功能
////支持整型、浮点型、结构体等多种类型数组排序
////flag排序标志位，排序ok后直接break跳出循环
//#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
//#include<string.h>
//struct co_workers
//{
//	char name[20];//
//	int height;	  //cm
//};
////整型比较
//int cmp_int(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
////浮点型数组比较函数
//int cmp_float(const void* e1, const void* e2)
//{
//	return (int)(ceil(*(float*)e1 - *(float*)e2));
//}
////结构体数组比较函数-by name
//int cmp_struct_by_name(const void* e1, const void* e2)
//{
//	return strcmp(((struct co_workers*)e1)->name, ((struct co_workers*)e2)->name);
//}
////结构体数组比较函数-by height
//int cmp_struct_by_height(const void* e1, const void* e2)
//{
//	return (((struct co_workers*)e1)->height - ((struct co_workers*)e2)->height);
//}
//
////可实现多种类型数组排序的扩展型my_bubble_sort
//void Swap(char* buf1, char* buf2, int width)
//{
//	int i = 0;
//	for (i = 0; i < width; i++)
//	{
//		char tmp = *buf1;
//		*buf1 = *buf2;
//		*buf2 = tmp;
//		buf1++;
//		buf2++;
//	}
//}
//void my_bubble_sort(void* base, int sz, int width, int(*cmp)(const void*, const void*))
//{
//	int i = 0;
//	//比较的趟数
//	for (i = 0; i < sz - 1; i++)
//	{
//		int flag = 1;//假设已经排序ok
//		int j = 0;
//		//每趟比较的对数
//		for (j = 0; j < sz - 1 - i; j++)
//		{	//两个元素比较
//			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)//	(char*)base + j * width //(char*)base+(j+1)*width
//			{
//				//交换
//				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
//				//flag = 0;//需要重排
//			}
//		}
//		if (flag == 1)
//			break;
//	}
//}
//int main()
//{
//	//int arr1[] = { 1,3,5,7,9,2,4,6,8,10 };
//	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	float arr2[] = { 1.0,2.1,2.2,1.8,3.1,4.5,6.6,9.5,8.7,3.3 };
//	struct co_workers arr3[3]= { {"lichao",180},{"zhangyu",190},{"sunyan",175} };
//	//void qsort(void* base, size_t nitems, size_t size, int (*compar)(const void*, const void*))
//	//			 起点地址	   数组长度	  数组每个元素大小	函数指针(排序元素1的地址，排序元素2的地址）
//	//整型排序
//	int sz_arr1 = sizeof(arr1) / sizeof(arr1[0]);//元素个数
//	int width_arr1 = sizeof(arr1[0]);			
//	my_bubble_sort(arr1, sz_arr1, width_arr1, cmp_int);
//
//	//浮点型排序
//	int sz_arr2 = sizeof(arr2) / sizeof(arr2[0]);//元素个数
//	int width_arr2 = sizeof(arr2[0]);			
//	my_bubble_sort(arr2, sz_arr2, width_arr2, cmp_float);
//
//	//结构体排序-by-name
//	//结构体排序-by-heights
//	int sz_arr3 = sizeof(arr3) / sizeof(arr3[0]);//元素个数
//	int width_arr3 = sizeof(arr3[0]);			
//	my_bubble_sort(arr3, sz_arr3, width_arr3, cmp_struct_by_name);
//	my_bubble_sort(arr3, sz_arr3, width_arr3, cmp_struct_by_height);
//
//	return 0;
//}

//经典题
int main()
{	//数组名首元素地址
	//1.sizeof(数组名),整个数组
	//2.&数组名，整个数组
	//地址4或8个
	int a[] = { 1,2,3,4};	
	printf("%d\n", sizeof(a + 0));		//4/8	首元素地址
	printf("%d\n", sizeof(*a));			//4		首元素
	printf("%d\n", sizeof(a + 1));		//4/8	第二个元素地址
	printf("%d\n", sizeof(&a));			//4/8	第二个元素地址
	printf("%d\n", sizeof(*&a));		//16，和sizeof(a)一样

	char arr[] = { 'a','b','c','d' };
	
	printf("%d\n", strlen(*arr));		//16，和sizeof(a)一样
	printf("%d\n", sizeof(arr[1]));		//16，和sizeof(a)一样


	return 0;
}