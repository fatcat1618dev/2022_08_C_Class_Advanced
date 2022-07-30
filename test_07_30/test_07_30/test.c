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