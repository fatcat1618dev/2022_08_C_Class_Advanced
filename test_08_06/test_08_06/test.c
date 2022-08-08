#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>


////☆ 库函数，strlen输出size_t，无符号
////字符串以'\0'作为结束标志，strlen返回的是字符串中'\0'前面出现的字符个数，不含'\0'
//
//int main()
//{
//	if (strlen("abc") - strlen("abcdef") < 0)
//		printf("小于\n");
//	else
//		printf("大于\n");
//	return 0;
//}


////
////字符串长度模拟实现
////1.计数器；2.递归；3.指针
//
//#include<assert.h>
//
//int my_strlen(char* arr)
//{
//	assert(arr);
//	int count = 0;
//	while (*arr++)
//	{
//		count++;
//	}
//	return count;
//}
//int main()
//{
//	char arr[] = "haomo.ai__";
//	printf("长度：%d\n", my_strlen(arr));
//	return 0;
//}



////左旋字符串//字符子串 strstr
//int is_left_move(char*str1, char*str2)
//{
//	if (strlen(str1) != strlen(str2))
//		return 0;
//	//1.str1追加1个str1字符串
//	strncat(str1, str1, 6);
//	//2.判断str2是不是子串
//	char* ret = strstr(str1, str2);
//	if (ret == NULL)
//		return 0;
//	else
//		return 1;
//}
//int main()
//{
//	char arr1[20]= "abcdef";
//	char arr2[]= "abcd";
//	int ret = is_left_move(arr1, arr2);//判断arr2是否是arr1的子串
//	if (ret == 1)
//		printf("Yes\n");
//	else
//		printf("No\n");
//	return 0;
//}


////strcpy,源字符串需以'\0'结束，'\0'会被拷贝进目标空间
////☆ strcpy及模拟实现
//char* my_strcpy(char* dest, const char* src)
//{
//	//assert(dest!=NULL && src != NULL);//断言
//	assert(dest&& src);//断言
//	char* ret = dest;
//	while (*dest++ = *src++);
//	return ret;					//返回目标空间起始地址
//}
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "abc";
//	//char* arr2 = NULL;
//	//printf("%s\n", strcpy(arr1, arr2));//返回目的空间地址
//	printf("%s\n", my_strcpy(arr1, arr2));
//	return 0;
//}



//
////库函数strcat，追加字符串
////模拟实现☆，
//char* my_strcat(char* dest, const char* src)
//{
//	assert(dest && src);
//	char* ret = dest;
//	while (*dest)						//find end \0
//		dest++;
//	while (*dest++ = *src++);
//	return ret;
//}
//int main()
//{
//	char arr1[30] = "hello";
//	char arr2[] = " haomo.ai";
//	//strcat(arr1, arr2);				//库函数
//	char* ret=my_strcat(arr1, arr2);				//模拟实现
//	printf("%s\n", ret);
//
//	return 0;
//}



//
////strcmp，两个字符串相等，返回0；第1个大返回大于0数字；第1个小返回小于0的数字	<0	=0	>0
////vs2019 不严谨，-1 0 1，参照linux严格的来
////☆模拟实现my_strcmp
//int my_strcmp(const char* p1, const char* p2)
//{
//	while (*p1== *p2)
//	{
//		if (!*p1)
//			return 0;		//相等
//		p1++;
//		p2++;
//	}
//	return *p1 - *p2;
//}
//int main()
//{
//	char* p1 = "abc";
//	char* p2 = "abcd";
//	printf("%d\n", strcmp(p1, p2));
//	printf("%d\n", my_strcmp(p1, p2));
//
//	return 0;
//}



////库函数strncpy
////如果源字符串长度小于num，拷贝完字符串后，追加\0
//int main()
//{
//	char arr1[10] = "abcdef";
//	char arr2[] = "bit";
//	strncpy(arr1,arr2,6);
//	printf("%s\n", arr1);
//	return 0;
//}


////☆strstr,查找字符串
////若有，返回NULL，否则返回起始位置
//int main()
//{
//	char* p1 = "abcdefghi";
//	char* p2 = "abc";
//	char* ret = strstr(p1, p2);
//	if (ret == NULL)
//	{
//		printf("子串不存在\n");
//	}
//	else
//		printf("%s\n", ret);
//	return 0;
//}




////strtok,char *strtok(char*str,const char sep)
//int main()
//{
//	//192.168.31.121
//	//litao@haomo.ai
//	char arr1[]= "192.168.31.121";
//	char* p1 = ".";
//	char arr2[]= "litao@haomo.ai";
//	char* p2 = "@.";
//
//	char buf[1024] = { 0 };
//
//	strcpy(buf, arr1);
//	char* ret = NULL;
//	for (ret = strtok(arr1, p1); ret != NULL; ret = strtok(NULL, p1))
//	{
//		printf("%s ", ret);
//	}
//
//	//strcpy(buf, arr2);
//	//char* ret = NULL;
//	//for (ret = strtok(arr2, p2); ret != NULL; ret = strtok(NULL, p2))
//	//{
//	//	printf("%s ", ret);
//	//}
//
//
//	return 0;
//}


////错误码
////errno是1个全局错误码的变量
////c语言的库函数执行过程中，出现错误，会把对应的错误码，赋值到errno中
////char* str=strerror(errno)
////0	No error
////2	No such file or directory
//int main()
//{
//	//打开文件
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//		printf("%s\n", strerror(errno));
//	else
//		printf("open success\n");
//	//printf("%s\n", strerror(2));
//	return 0;
//}


////memcpy,内存拷贝
//struct S
//{
//	char name[20];
//	int age;
//};
//
//void* my_memcpy(void* dest, const void* src, size_t num)
//{
//	assert(dest && src);
//	while (num--)
//	{
//		*(char*)dest = *(char*)src;
//		++(char*)dest,++(char*)src;
//	}
//}
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[5] = { 0 };								//内存
//	struct S arr3[] = { {"柳慧",25},{"何进",23} };
//	struct S arr4[2] = { 0 };							//内存
//	//memcpy(arr2, arr1, sizeof(arr1));
//	//memcpy(arr4, arr3, sizeof(arr4));
//
//	my_memcpy(arr2, arr1, sizeof(arr1));
//	my_memcpy(arr4, arr3, sizeof(arr3));
//	return 0;
//}

//#include<ctype.h>
//int main()
//{
//	char arr[] = "YOU ARE A HAOMO.AI'S Comates!";
//	printf("%s\n", arr);
//	//大写全转为小写
//	int sz = strlen(arr);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		if (isupper(arr[i]))
//			//arr[i] = arr[i] + 32;
//			arr[i] = tolower(arr[i]);
//	}
//	printf("%s\n", arr);
//
//	return 0;
//}

////memmove，源、目标内存有重叠也可以处理
////☆my_memmove
//void* my_memmove(void* dest, const void* src, size_t count)
//{
//	assert(dest && src);
//	//前->后
//	if (dest < src)
//		while (count--) 
//		{
//			*(char*)dest = *(char*)src;
//			//((char*)dest)++,((char*)src)++;//一样
//			++(char*)dest, ++(char*)src;
//		}
//	else
//		////后->前
//		while (count--)
//		{
//			*((char*)dest+count)=*((char*)src+count);
//		}
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	//memmove(void *_Dst, const void *_Src, size_t _Size)
//	//memmove(arr+2, arr, 4*5);//库函数
//	my_memmove(arr+2, arr, 4 * 5);//自定义
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


////memset,内存初始化
////按字节初始化
//int main()
//{
//	char arr[10] = "";
//	memset(arr, '#', 10);
//	//int arr[10] = { 1 };
//	//memset(arr,1, 40);
//	int i = 0;
//	for (i = 0; i < 10; i++)//未初始化完全
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


//第4节 结构体、枚举、联合

////结构体声明
//struct stu
//{
//	char name[20];
//	char tele[12];
//	char sex[10];
//	int age;
//}s4,s5,s6;
//struct stu s3;
////main 函数外全局变量s3-s6
////main 函数内局部变量s1-s2
//int main()
//{
//	struct stu s1;
//	struct stu s2;
//	return 0;
//}

////结构体自引用
//struct node
//{
//	int data;
//	struct node* next;
//};

//
////定义、初始化
//struct T
//{
//	short age;
//	int height;
//	double weight;
//};
//typedef struct S
//{
//	char name[20];
//	char empno[10];
//	char sex[5];
//	struct T st;
//	char company[20];
//}comates;
//int main()
//{
//	comates s = { "梁琪","00286666","女",{20,175,50.0},"HM.AI" };
//	printf("%s %s %s %s %d %d %lf", s.name, s.empno, s.sex, s.company, s.st.age, s.st.height, s.st.weight);
//	return 0;
//}
//

///*结构体的大小（内存对齐）
// 1.第1个成员在与结构体变量偏移量为0地址处；
// 2.其它成员要对齐到对齐数的整数倍地址处（vs默认对齐数8，gcc无此概念）；
//	注：对齐数=编译器默认对齐数与该成员大小的较小值。
// 3.结构体总大小为最大对齐数的整数倍；
//	注：若嵌套了结构体，嵌套的结构体对齐到自己最大对齐数的整数倍出，结构
//体的整体大小就是所有最大对齐数(含嵌套结构体对齐数）的整数倍。*/
///*结构体内存对齐原因：
//主要是空间换时间，为了性能*/
//struct s1
//{
//	double a;
//	int b;
//	char c;
//};
//struct s2
//{
//	char d;
//	struct s1 e;
//	double f;
//};
//int main()
//{
//	struct s1 s1;
//	struct s2 s2;
//	printf("%d ", sizeof(s1));
//	printf("%d", sizeof(s2));
//	return 0;
//}
////16 32

//
//#pragma pack(4)//设置默认对齐数为4
//struct haomo
//{
//	char name[9];
//	char tele[12];
//	int height;
//};
//#pragma pack()//还原为默认
//int main()
//{
//	struct haomo s1;
//	printf("%d\n", sizeof(s1));
//	return 0;
//}

//
////offsetof，偏移量 #include<stddef.h>
//#include<stddef.h>
//struct s1
//{
//	double a;
//	int b;
//	char c;
//};
//int main()
//{
//	struct s1 s1;
//	printf("结构体大小：%d\n", sizeof(s1));
//	printf("%d\n", offsetof(struct s1, a));
//	printf("%d\n", offsetof(struct s1, b));
//	printf("%d\n", offsetof(struct s1, c));
//
//	return 0;
//}
//

//
////初始化举例
////结构体指针传参——传址
//struct beauty
//{
//	int height;
//	int weight;
//	int age;
//};
//void Init(struct beauty* p)
//{
//	p->age = 20;
//	p->height = 175;
//	p->weight = 50;
//}
//void print(struct beauty* p)
//{
//	printf("年龄：%d\n",p->age);
//	printf("身高：%d\n", p->height);
//	printf("体重：%d\n", p->weight);
//	//printf("体重：%d\n", (*p).weight);
//}
//int main()
//{
//	struct beauty n1 = { 0 };
//	Init(&n1);
//	print(&n1);
//	return 0;
//}

//
////枚举类型
//enum color
//{
//	RED,
//	GREEN,
//	BLUE
//};
//enum sex
//{
//	//枚举的可能取值 0 8 9
//	MALE,
//	FEMALE=8,
//	SECRET
//};
//int main()
//{
//	printf("%d %d %d\n", RED, GREEN, BLUE);
//	printf("%d %d %d\n", MALE, FEMALE, SECRET);
//	return 0;
//}

//源代码-预编译-编译-链接-可执行程序
/*枚举的优点
1.可读性、可维护性；
2.相比#define定义的标识符，有类型检查，更加严谨；
3.防止命名污染；
4.便于调试；
5.方便，1次可以定义多个常量*/

////联合（联合体）
//union haomo
//{
//	char c;//
//	int i;
//};
//int main()
//{
//	union haomo yide;
//	printf("%d\n", sizeof(yide));
//	return 0;
//}
////4
///*联合是一种特殊的自定义类型，包含一系列成员，这些成员共用同一块空间，联合体又称共同体
//成员共用同一块内存空间，联合变量的大小，至少是最大成员的大小
//当最大成员大小不是最大对齐数的整数倍时，要对齐*/
///*大小端存储
//方法1.int a=1,强制转换char*,看返回值0/1 
//方法2.用联合体*/

////////方法1
////int check_sys()
////{
////	int i = 1;
////	return *(char*)&i;
////}
////方法2
//int check_sys()
//{
//	union
//	{
//		char a;
//		int b;
//	}u;
//	u.b = 1;
//	//返回1，小端
//	//返回0，大端
//	return u.a;
//}
//int main()
//{
//	int ret = check_sys();
//	if (1 == ret)
//		printf("小端\n");
//	else
//		printf("大端\n");
//	return 0;
//}
////匿名

////联合体大小
//union u
//{
//	int a;
//	char arr[5];
//};
//int main()
//{
//	union u a;
//	printf("%d\n", sizeof(a));
//	return 0;
//}
////4 4
////5 1
////8