#define _CRT_SECURE_NO_WARNINGS 1

/*
���򻷾���Ԥ����
.���뻷��
.ִ�л���
.����+����
.Ԥ�������
.Ԥ����ָ��#define
.��ͺ����ĶԱ�
.Ԥ���������#��##�ڽ���
.�����
.Ԥ����ָ��#include
.Ԥ����ָ��#undef
.��������
*/
/*
���룺Ԥ���롪���ı�������1.ͷ�ļ��İ���;2.ע��ɾ��;3.#define�����滻��		gcc test.c -E���õ�test.i
	  ����  ����c���뷭��Ϊ�����루1.�﷨���ʷ����������4.���Ż��ܣ�		gcc test.c -S���õ�test.s
	  ���  �����γɷ��ű��ѻ�����ת��Ϊ������ָ��									gcc test.c -c���õ�test.o
���ӣ�����1.�ϲ��α� 2.���ű�ĺϲ����ض�λ���γɿ�ִ�г���
����ִ�й��̣�
	1.���������ڴ��У�
	2.��ʼִ�У�����main������
	3.ִ�д��룺��ջ���洢�����ľֲ������ͷ��ص�ַ����̬�ڴ�
	4.��ֹ����������������ֹmain����
	������Ա������������
Ԥ������ţ�
	FILE��LINE��DATE��TIME
#define�����ʶ��
C���ԡ�C����ʵ�����ݽṹ��˳�������ջ�����С�������...����C++���߼����ݽṹ��linux��mysql
��ͺ����ıȽϣ�
	��  ��ִ�м����㡪���������޹أ����ɣ�
	�������Ͻ���
	ע�����ɲ��Ͻ����Ͻ�������
linux:
	ls/ls -a/ls -l/ls -al
�������룺#ifdef #endif
�ļ�������#include<>,#include""
	���ļ���������Ĭ��λ��...
	�Զ��壺��ǰĿ¼...
��ֹͷ�ļ��ظ����룺
	����1��
		#ifndef __TEST_H__
		#define __TEST_H__
		//ͷ�ļ�����
		#endif //__TEST_H__
	����2��
		#pragma once
��C������Ƚ��ʡ�
��д�꣬����ṹ����ĳ��������׵�ַ��ƫ�ƣ�ʵ������offsetof�Ĺ��ܣ�
	
*/
//#include<stdio.h>
//#define DEBUG_FPRINT printf("file:%s line:%d date:%s time:%s\n",__FILE__,__LINE__,__DATE__,__TIME__)
//int main()
//{
//	DEBUG_FPRINT;//��ӡ����Ļ
//	return 0;
//}


//#include<stdio.h>
//#define DEBUG_FPRINT(p) fprintf(p, "file:%s line:%d date:%s time:%s\n", __FILE__, __LINE__, __DATE__, __TIME__);
//int main()
//{
//	//��־�ļ�
//	FILE* pf = fopen("log.txt", "a");
//	//fprintf(pf, "file:%s line:%d date:%s time:%s\n", __FILE__, __LINE__, __DATE__, __TIME__);
//	DEBUG_FPRINT(pf);
//
//	//�ر��ļ�
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

////���Ͽ��ٿռ�
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