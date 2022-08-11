#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include<Windows.h>
/*为什么存在动态内存分配
动态内存函数介绍
 malloc
 free
 calloc
 realloc
 常见的动态内存错误
 经典笔试题
 柔性数组*/
//struct s
//{
//	char name[18];
//	int age;
//};
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	//printf("%d\n", sizeof(struct s));//内存对齐
//	struct s arr[n];//50个结构体类型数据//30 60不够				不支持
// //gcc支持c99标准，可使用gcc xxx.c -std=c99编译
//	return 0;
//}

/*内存使用方式
栈区	局部变量、函数形参
堆区	动态内存分配
静态区	全局、静态变量、static int a=10;
*/


/*为什么存在动态内存分配
1.空间开辟大小是固定的；
2.数组在声明时，必须指定数组长度，需要的内存在编译时分配
程序运行时才知道需要的空间大小，试试开辟动态内存
在stdlib.h头文件中
malloc
向内存申请1块连续可用的空间，并返回指向这块空间的指针
①开辟成功，返回指向开辟好的空间的指针；
②开辟失败，返回NULL，malloc返回值务必检查；
③返回类型void*，使用者自己绝对类型
free
做动态内存释放回收
calloc
①为num个大小为size的元素开辟1块空间，并且把空间每个字节初始化为0；
注：与malloc区别是，返回地址之前，把申请的空间每个字节初始化为全0
realloc	调整动态开辟的内存大小
①原空间之后空间足够大，
②原空间之后不够大
注：
1)p指向的空间之后有足够内存空间可以追加，直接追加，返回p;
2)之后没有足够内存空间可以追加，realloc会重新找新区域开辟满足需求的空间，原来内存中的数据也会拷贝走并释放掉，最后返回新开辟空间地址；
3）用新的变量接收realloc返回值
*/

///*常见动态内存错误
//1.对NULL指针解引用；
//2.对动态开辟空间越界访问
//3.对非动态开辟内存使用free释放
//4.使用free释放动态开辟内存的一部分
//5.对同一块动态内存多次释放
//6.内存泄漏（动态开辟内存未释放）——谁开辟谁回收*/
////
//int main()
//{
//	//向内存申请10个整型空间
//	//int* p = (int*)malloc(10 * sizeof(int));	//INT_MAX
//	int* p = (int*)calloc(5, sizeof(int));//整型
//	if (p == NULL)
//		printf("%s\n", strerror(errno));
//	else
//	{
//		//正常使用空间
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			p[i] = i;
//			printf("%d ", p[i]);
//		}
//	}
//	//空间不够了，用realloc调整
//	int* p2 = realloc(p, 10 * sizeof(int));//整型
//	if (p2 != NULL)
//	{
//		p = p2;
//	}
//	//申请的动态空间不再使用时，还给操作系统
//	free(p);
//	p = NULL;
//	return 0;
//}


//int main()
//{
//	int* p = realloc(NULL, 80);//等效为malloc
//	return 0;
//}

//
//int main()
//{
//	/*1.对NULL指针解引用
//	int* p=malloc(40);
//	//p进行相关判断
//	2.越界访问
//	3.对非动态开辟内存使用free释放*/
//	//5.动态内存多次释放
//	//int* p = (int*)malloc(40);
//	//if (p == NULL)
//	//	return 0;
//	//free(p);
//	//p = NULL;
//	//free(p);
//	//6.忘记释放（内存泄漏）,4/8/16G,该本32个
//	while(1)
//	{
//		malloc(10);
//		//sleep(100);
//	}
//	return 0;
//}

////经典笔试题1
//void GetMemory(char* p)
//{
//	p = (char*)malloc(100);
//}
//void test()
//{
//	char* str = NULL;
//	GetMemory(str);
//	strcpy(str, "hello world");
//	printf(str);
//}
//int main()
//{
//	test();
//	return 0;
//}
///*
//1.程序崩溃；
//2.内存泄漏——传值，函数内部有效，返回后内存未释放，内存泄漏*/


////经典笔试题1-改1☆☆☆☆☆
//void GetMemory(char** p)
//{
//	*p = (char*) malloc(100);
//}
//void test()
//{
//	char* str = NULL;
//	GetMemory(&str);
//	strcpy(str, "hello world");
//	printf(str);
//	free(str);
//	str = NULL;
//}
//int main()
//{
//	test();
//	return 0;
//}
///*
//1.传址ok
//2.2级指针
//3.释放内存*/

////经典笔试题1-改正2☆☆☆☆☆
//char* GetMemory(char* p)
//{
//	p = (char*)malloc(100);
//	return p;
//}
//void test()
//{
//	char* str = NULL;
//	str = GetMemory(str);
//	strcpy(str, "汪桑");
//	printf(str);
//	free(str);
//	str = NULL;
//}
//int main()
//{
//	test();
//	return 0;
//}
///*
//1.传址ok
//2.2级指针
//3.释放内存*/

//int main()
//{
//	int* p = NULL;
//	int a = 10;
//	p = &a;
//	printf("%p\n", p);
//	return 0;
//}

//////经典笔试题2 
//char* GetMemory(void)
//{
//	char p[] = "hello world";
//	return p;
//}
//void test(void)
//{
//	char* str = NULL;
//	str = GetMemory();
//	printf(str);
//}
//int main()
//{
//	test();
//	return 0;
//}
/////*问题项*
////1.非法访问内存，返回栈空间地址有风险*/


///*栈空间、静态区空间返回不行，堆区ok*/
//int* test()
//{
//	int* ptr = malloc(100);//堆区
//	return ptr;
//}
//int main()
//{
//	int* p = test();
//	return 0;
//}

/*
int *f1(void)
int x=10;
return (&x);
*/
//非法访问栈空间

/*
int *f2(void)
{
int *ptr;
*ptr=10;
return ptr;
}
*/
//野指针，未初始化；随机值解引用，放入值，易出问题

//高质量的c/c++编程


////经典笔试题3 
//void GetMemory(char**p,int num)
//{
//	*p=(char*)malloc(num);
//}
//void test(void)
//{
//	char* str = NULL;
//	GetMemory(&str,100);
//	strcpy(str, "hello");
//	printf(str);
//	//改
//	free(str);
//	str = NULL;
//}
//int main()
//{
//	test();
//	return 0;
//}
///*问题项*
///*1.能够输出hello
//2.忘记释放动态开辟的内存，内存泄漏*/


////经典笔试题4
//void GetMemory(char**p,int num)
//{
//	*p=(char*)malloc(num);
//}
//void test(void)
//{
//	char* str = (char*)malloc(100);
//	strcpy(str, "hello");
//	free(str);				//考点：free释放后，str不会置为NULL
//	//改
//	//str = NULL;
//
//	if (str != NULL)
//	{
//		strcpy(str, "world");
//		printf(str);
//	}
//}
//int main()
//{
//	test();
//	return 0;
//}
///*问题项*高质量的c c++编程☆
//1. free释放后，str成为野指针，篡改动态内存区的内容*/

//////c/c++程序的内存开辟
//////柔性数组
////struct s
////{
////	int n;
////	int arr[];//两种写法
////};
////int main()
////{
////	printf("%d\n", sizeof(struct s));
////	return 0;
////}
/////*
////int arr[0];//写法1
////int arr[];// 写法2
////*/
////
//struct s
//{
//	int n;
//	int arr[];//两种写法
//};
//int main()
//{
//	struct s* ps = (struct s*)malloc(sizeof(struct s) + 5 * sizeof(int));
//	ps->n = 100;
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		ps->arr[i] = i;//0 1 2 3 4
//	}
//	struct s* ptr = realloc(ps, 44);//加5个
//	if (ptr != NULL)
//		ps = ptr;
//	for (i = 5; i < 10; i++)
//	{
//		ps->arr[i] = i;
//	}
//	return 0;
//}