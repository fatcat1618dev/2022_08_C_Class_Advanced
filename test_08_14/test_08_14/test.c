#define _CRT_SECURE_NO_WARNINGS 1

/*
程序环境和预处理
.翻译环境
.执行环境
.编译+链接
.预定义符号
.预处理指令#define
.宏和函数的对比
.预处理操作符#和##在介绍
.命令定义
.预处理指令#include
.预处理指令#undef
.条件编译
*/
/*
编译：预编译——文本操作（1.头文件的包含;2.注释删除;3.#define内容替换）		gcc test.c -E，得到test.i
	  编译  ——c代码翻译为汇编代码（1.语法、词法、语义分析4.符号汇总）		gcc test.c -S，得到test.s
	  汇编  ——形成符号表，把汇编代码转换为二进制指令									gcc test.c -c，得到test.o
链接：——1.合并段表 2.符号表的合并和重定位，形成可执行程序
程序执行过程：
	1.程序载入内存中；
	2.开始执行，调用main函数；
	3.执行代码：堆栈，存储函数的局部变量和返回地址；静态内存
	4.终止程序，正常、意外终止main函数
	《程序员的自我修养》
预定义符号：
	FILE、LINE、DATE、TIME
#define定义标识符
C语言、C语言实现数据结构（顺序表、链表、栈、队列、二叉数...）、C++、高级数据结构、linux、mysql
宏和函数的比较：
	宏  ：执行简单运算——宏类型无关，自由；
	函数：严谨；
	注：自由不严谨、严谨不自由
linux:
	ls/ls -a/ls -l/ls -al
条件编译：#ifdef #endif
文件包含：#include<>,#include""
	库文件：编译器默认位置...
	自定义：当前目录...
防止头文件重复引入：
	方法1：
		#ifndef __TEST_H__
		#define __TEST_H__
		//头文件内容
		#endif //__TEST_H__
	方法2：
		#pragma once
《C语言深度解剖》
编写宏，计算结构体中某变量相对首地址的偏移（实现类似offsetof的功能）
	
*/
//#include<stdio.h>
//#define DEBUG_FPRINT printf("file:%s line:%d date:%s time:%s\n",__FILE__,__LINE__,__DATE__,__TIME__)
//int main()
//{
//	DEBUG_FPRINT;//打印到屏幕
//	return 0;
//}


//#include<stdio.h>
//#define DEBUG_FPRINT(p) fprintf(p, "file:%s line:%d date:%s time:%s\n", __FILE__, __LINE__, __DATE__, __TIME__);
//int main()
//{
//	//日志文件
//	FILE* pf = fopen("log.txt", "a");
//	//fprintf(pf, "file:%s line:%d date:%s time:%s\n", __FILE__, __LINE__, __DATE__, __TIME__);
//	DEBUG_FPRINT(pf);
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

//
//#include<stdio.h>
//#define SQUARE(X) X*X
//int main()
//{
//	int ret = SQUARE(5 + 1);
//	printf("%d\n", ret);
//	return 0;
//}
//
////5+1*5+1=11

//
//#include<stdio.h>
//#define PRINT(X) printf("the value of "#X" is %d\n",X)
//int main()
//{
//	int a = 10;
//	int b = 20;
//	PRINT(a);
//	PRINT(b);
//	return 0;
//}

//#include<stdio.h>	
//#define MAX(X,Y) (X>Y?X:Y)
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int max = MAX(a++, b++);
//	printf("%d %d %d\n", max, a, b);
//
//	max = MAX(++a, ++b);
//	printf("%d %d %d\n", max, a, b);
//
//	return 0;
//}
////21 11 22
////24 12 24

//#include<stdio.h>
//#define cat(x,y) x##y
//int main()
//{
//	int class1122 = 2020;
//	printf("%d\n", cat(class11, 22));
//	return 0;
//}

////堆上开辟空间
//#include<stdio.h>
//#include<stdlib.h>
//#define MALLOC(num,type) (type*)malloc(num*sizeof(type))
//int main()
//{
//	int* p = MALLOC(10, int);
//
//	return 0;
//}


//#include<stdio.h>	
//#define DEBUG
//int main()
//{
//	#ifndef DEBUG
//	printf("hehe\n");
//	#else
//	printf("heihei\n");
//	#endif
//	return 0;
//}

#include<stdio.h>
#include<stddef.h>
#define my_offsetof(type,member) (int)(&(((type*)0)->member))
#define PRINT_OFFSET(type,member) printf("%d\n",my_offsetof(type,member));

//#define PRINT_OFFSET(type,member) printf("%d\n",offsetof(type,member));
struct s
{
	char a;
	int b;
	char c;
};
int main()
{
	PRINT_OFFSET(struct s, a);
	PRINT_OFFSET(struct s, b);
	PRINT_OFFSET(struct s, c);
	printf("%d\n", sizeof(struct s));
	return 0;
}
//0 4 8 12
//