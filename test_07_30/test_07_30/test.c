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
//����Ϊx64����ӡ2��64λƽָ̨��8���ֽ�

////ָ������ַ���ַ
//int main()
//{
//	char* p = "abcdef";	//"abcdef"�Ǹ������ַ���
//	printf("%c\n", *p);
//	printf("%s\n",p);
//	return 0;
//}

////stackoverflow.com
////segmentfault	�ڴ����
//int main()
//{
//	const char* p = "abcdef";	//"abcdef"�Ǹ������ַ���
//	//*p='W';
//	printf("%s\n", p);
//	return 0;
//}

////�ַ�ָ��
//int main()
//{
//	char arr1[] = "haomo";
//	char arr2[] = "haomo";
//	const char* p1 = "haomo";
//	const char* p2 = "haomo";
//	if (arr1 == arr2)
//		printf("arr1��arr2���\n");
//	if (p1 == p2)
//		printf("p1��p2һ��\n");
//
//	return 0;
//}

////ָ������
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

/////ָ������2
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
////����ָ��
////
//
//int main()
//{
//	int* p = NULL;	//����ָ��
//	char* pc = NULL;//�ַ�ָ��
//					//����ָ��
//	//int arr[10]={0};
//	//arr��Ԫ�ص�ַ,&arr[0]
//	//&arr	�����ַ
//
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int(*p)[10] = &arr;							//p������ָ��
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

//���� ָ�봫�Ρ�����ָ��
//���鴫��
void print1(int arr[3][5], int x, int y)
{
	int i = 0;
	for (i = 0; i < x; i++)				//��Χ
	{
		int j = 0;
		for (j = 0; j < y; j++)			//��Χ
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
//ָ�봫��
void print2(int(*p)[5],int x,int y)
{
	int i = 0;
	for (i = 0; i < x; i++)
	{
		int j = 0;
		for (j = 0; j < y; j++)
		{
			printf("%d ", p[i][j]);//����
			//printf("%d ", *(p[i]+j));//��
			//printf("%d ", (*(p + i))[j]);//��
			//printf("%d ", *(*(p + i) + j));//ԭʼ��
		}
		printf("\n");
	}
}
int main()
{
	int arr[3][5] = { {1,2,3,4,5},{2,4,6,8,10},{3,5,7,9,11} };
	print1(arr, 3, 5);//    ���鴫��
	print2(arr, 3, 5);//����ָ�봫��
	return 0;
}