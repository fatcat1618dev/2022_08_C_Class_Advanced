#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include<Windows.h>
/*Ϊʲô���ڶ�̬�ڴ����
��̬�ڴ溯������
 malloc
 free
 calloc
 realloc
 �����Ķ�̬�ڴ����
 ���������
 ��������*/
//struct s
//{
//	char name[18];
//	int age;
//};
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	//printf("%d\n", sizeof(struct s));//�ڴ����
//	struct s arr[n];//50���ṹ����������//30 60����				��֧��
// //gcc֧��c99��׼����ʹ��gcc xxx.c -std=c99����
//	return 0;
//}

/*�ڴ�ʹ�÷�ʽ
ջ��	�ֲ������������β�
����	��̬�ڴ����
��̬��	ȫ�֡���̬������static int a=10;
*/


/*Ϊʲô���ڶ�̬�ڴ����
1.�ռ俪�ٴ�С�ǹ̶��ģ�
2.����������ʱ������ָ�����鳤�ȣ���Ҫ���ڴ��ڱ���ʱ����
��������ʱ��֪����Ҫ�Ŀռ��С�����Կ��ٶ�̬�ڴ�
��stdlib.hͷ�ļ���
malloc
���ڴ�����1���������õĿռ䣬������ָ�����ռ��ָ��
�ٿ��ٳɹ�������ָ�򿪱ٺõĿռ��ָ�룻
�ڿ���ʧ�ܣ�����NULL��malloc����ֵ��ؼ�飻
�۷�������void*��ʹ�����Լ���������
free
����̬�ڴ��ͷŻ���
calloc
��Ϊnum����СΪsize��Ԫ�ؿ���1��ռ䣬���Ұѿռ�ÿ���ֽڳ�ʼ��Ϊ0��
ע����malloc�����ǣ����ص�ַ֮ǰ��������Ŀռ�ÿ���ֽڳ�ʼ��Ϊȫ0
realloc	������̬���ٵ��ڴ��С
��ԭ�ռ�֮��ռ��㹻��
��ԭ�ռ�֮�󲻹���
ע��
1)pָ��Ŀռ�֮�����㹻�ڴ�ռ����׷�ӣ�ֱ��׷�ӣ�����p;
2)֮��û���㹻�ڴ�ռ����׷�ӣ�realloc�������������򿪱���������Ŀռ䣬ԭ���ڴ��е�����Ҳ�´���߲��ͷŵ�����󷵻��¿��ٿռ��ַ��
3�����µı�������realloc����ֵ
*/

///*������̬�ڴ����
//1.��NULLָ������ã�
//2.�Զ�̬���ٿռ�Խ�����
//3.�ԷǶ�̬�����ڴ�ʹ��free�ͷ�
//4.ʹ��free�ͷŶ�̬�����ڴ��һ����
//5.��ͬһ�鶯̬�ڴ����ͷ�
//6.�ڴ�й©����̬�����ڴ�δ�ͷţ�����˭����˭����*/
////
//int main()
//{
//	//���ڴ�����10�����Ϳռ�
//	//int* p = (int*)malloc(10 * sizeof(int));	//INT_MAX
//	int* p = (int*)calloc(5, sizeof(int));//����
//	if (p == NULL)
//		printf("%s\n", strerror(errno));
//	else
//	{
//		//����ʹ�ÿռ�
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			p[i] = i;
//			printf("%d ", p[i]);
//		}
//	}
//	//�ռ䲻���ˣ���realloc����
//	int* p2 = realloc(p, 10 * sizeof(int));//����
//	if (p2 != NULL)
//	{
//		p = p2;
//	}
//	//����Ķ�̬�ռ䲻��ʹ��ʱ����������ϵͳ
//	free(p);
//	p = NULL;
//	return 0;
//}


//int main()
//{
//	int* p = realloc(NULL, 80);//��ЧΪmalloc
//	return 0;
//}

//
//int main()
//{
//	/*1.��NULLָ�������
//	int* p=malloc(40);
//	//p��������ж�
//	2.Խ�����
//	3.�ԷǶ�̬�����ڴ�ʹ��free�ͷ�*/
//	//5.��̬�ڴ����ͷ�
//	//int* p = (int*)malloc(40);
//	//if (p == NULL)
//	//	return 0;
//	//free(p);
//	//p = NULL;
//	//free(p);
//	//6.�����ͷţ��ڴ�й©��,4/8/16G,�ñ�32��
//	while(1)
//	{
//		malloc(10);
//		//sleep(100);
//	}
//	return 0;
//}

////���������1
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
//1.���������
//2.�ڴ�й©������ֵ�������ڲ���Ч�����غ��ڴ�δ�ͷţ��ڴ�й©*/


////���������1-��1������
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
//1.��ַok
//2.2��ָ��
//3.�ͷ��ڴ�*/

////���������1-����2������
//char* GetMemory(char* p)
//{
//	p = (char*)malloc(100);
//	return p;
//}
//void test()
//{
//	char* str = NULL;
//	str = GetMemory(str);
//	strcpy(str, "��ɣ");
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
//1.��ַok
//2.2��ָ��
//3.�ͷ��ڴ�*/

//int main()
//{
//	int* p = NULL;
//	int a = 10;
//	p = &a;
//	printf("%p\n", p);
//	return 0;
//}

//////���������2 
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
/////*������*
////1.�Ƿ������ڴ棬����ջ�ռ��ַ�з���*/


///*ջ�ռ䡢��̬���ռ䷵�ز��У�����ok*/
//int* test()
//{
//	int* ptr = malloc(100);//����
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
//�Ƿ�����ջ�ռ�

/*
int *f2(void)
{
int *ptr;
*ptr=10;
return ptr;
}
*/
//Ұָ�룬δ��ʼ�������ֵ�����ã�����ֵ���׳�����

//��������c/c++���


////���������3 
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
//	//��
//	free(str);
//	str = NULL;
//}
//int main()
//{
//	test();
//	return 0;
//}
///*������*
///*1.�ܹ����hello
//2.�����ͷŶ�̬���ٵ��ڴ棬�ڴ�й©*/


////���������4
//void GetMemory(char**p,int num)
//{
//	*p=(char*)malloc(num);
//}
//void test(void)
//{
//	char* str = (char*)malloc(100);
//	strcpy(str, "hello");
//	free(str);				//���㣺free�ͷź�str������ΪNULL
//	//��
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
///*������*��������c c++��̡�
//1. free�ͷź�str��ΪҰָ�룬�۸Ķ�̬�ڴ���������*/

//////c/c++������ڴ濪��
//////��������
////struct s
////{
////	int n;
////	int arr[];//����д��
////};
////int main()
////{
////	printf("%d\n", sizeof(struct s));
////	return 0;
////}
/////*
////int arr[0];//д��1
////int arr[];// д��2
////*/
////
//struct s
//{
//	int n;
//	int arr[];//����д��
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
//	struct s* ptr = realloc(ps, 44);//��5��
//	if (ptr != NULL)
//		ps = ptr;
//	for (i = 5; i < 10; i++)
//	{
//		ps->arr[i] = i;
//	}
//	return 0;
//}