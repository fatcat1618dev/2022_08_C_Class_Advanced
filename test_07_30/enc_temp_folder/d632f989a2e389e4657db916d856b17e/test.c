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

////���� ָ�봫�Ρ�����ָ��
////���鴫��
//void print1(int arr[3][5], int x, int y)
//{
//	int i = 0;
//	for (i = 0; i < x; i++)				//��Χ
//	{
//		int j = 0;
//		for (j = 0; j < y; j++)			//��Χ
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
////ָ�봫��
//void print2(int(*p)[5],int x,int y)
//{
//	int i = 0;
//	for (i = 0; i < x; i++)
//	{
//		int j = 0;
//		for (j = 0; j < y; j++)
//		{
//			printf("%d ", p[i][j]);//����
//			//printf("%d ", *(p[i]+j));//��
//			//printf("%d ", (*(p + i))[j]);//��
//			//printf("%d ", *(*(p + i) + j));//ԭʼ��
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int arr[3][5] = { {1,2,3,4,5},{2,4,6,8,10},{3,5,7,9,11} };
//	print1(arr, 3, 5);//    ���鴫��
//	print2(arr, 3, 5);//����ָ�봫��
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
//	//2022��7��31�� ������
//	//�ַ�ָ��
//	char ch = 'w';
//	char* p = &ch;
//	//ָ������
//	const char* p2 = "abcdef";//����ַ�������ĸ��ַ
//
//	//int *p3//char *p4
//	int arr2[5];//����
//	int(*pa)[5] = &arr2;//ȡ�������ַ��pa����ָ��
//
//	int(*parr[10])[5];//10��Ԫ�ص�����ָ�룬ÿ��ָ��5Ԫ�ص�����
//	return 0;
//}

////һά����
//void test(int arr[])	//��1��д����������С
//{}
//void test(int arr[10])	//��2��д��������С
//{}
//void test(int *arr)//��3��д��
//{}

//int main()
//{
//	int arr[10] = { 0 };
//	int* arr2[20] = { 0 };
//	test(arr);
//	//test2(arr2);
//	return 0;
//}

////1��ָ�봫��
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
////����ָ��
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

////����ָ��
////ָ������ָ��
//int	add(int x, int y)
//{
//	return x + y;
//}
//
//int main()
//{
//	int x = 0;
//	int y = 0;
//	printf("����������:>");
//	scanf("%d%d", &x, &y);
//	printf("%d\n", add(x, y));	//��������
//
//	int(*p)(int, int) = add;	//����ָ��
//	printf("%d\n", (*p)(x, y));	//����ָ�����1
//	printf("%d\n", p(x, y));	//����ָ�����2
//
//	return 0;
//}
//(* (void(*)()0)();
////��0ǿ��תΪvoid(*)()����ָ�����ͣ�����0��ַ���ĸú���
//void(*signal(int, void(*)(int)))(int)////void(*)(int)//signal(int, void(*)(int))
////signal��1��������������2����������1����int����2���Ǻ���ָ�룬�ú���ָ��ָ��������int����������void
////signal�����ķ�������Ҳ��1������ָ�룬�ú���ָ��ָ��ĺ����Ĳ�����int,����������void
//

//��������������ָ���
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
//	printf("����������������:>");
//	scanf("%d%d", &x, &y);
//	printf("%d\n", p(x, y));
//}
//int main()
//{
//	int input = 0;
//	do
//	{
//		menu();
//		printf("��ѡ��:>");
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


////��������������ָ�������
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
//		printf("��ѡ��:>");
//		scanf("%d", &input);
//		int x = 0;
//		int y = 0;
//		int(*pfarr[5])(int, int) = { 0,Add,Sub,Mul,Div };
//		if (input >= 1 && input <= 4)
//		{
//			printf("����������������:>");
//			scanf("%d%d", &x, &y);
//			printf("%d\n", pfarr[input](x, y));
//		}
//		else
//			printf("ѡ�����\n");
//	} while (input);
//
//	return 0;
//}

////�⺯��qsort
////���͡������͡��ṹ������.
//#include<stdlib.h>
//#include<math.h>
//#include<string.h>
//struct co_workers
//{
//	char name[20];//
//	int height;	  //cm
//};
////���ͱȽ�
//int cmp_int(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
////����������ȽϺ���
//int cmp_float(const void* e1, const void* e2)
//{
//	return (int)(ceil(*(float*)e1 - *(float*)e2));
//}
////�ṹ������ȽϺ���-by name
//int cmp_struct_by_name(const void* e1, const void* e2)
//{
//	return strcmp(((struct co_workers*)e1)->name, ((struct co_workers*)e2)->name);
//}
////�ṹ������ȽϺ���-by height
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
//	//			 ����ַ	   ���鳤��	  ����ÿ��Ԫ�ش�С	����ָ��(����Ԫ��1�ĵ�ַ������Ԫ��2�ĵ�ַ��
//	//��������
//	int sz_arr1 = sizeof(arr1) / sizeof(arr1[0]);//Ԫ�ظ���
//	int width_arr1 = sizeof(arr1[0]);			//Ԫ���ֽڴ�С
//	qsort(arr1, sz_arr1, width_arr1, cmp_int);
//
//	//����������
//	int sz_arr2 = sizeof(arr2) / sizeof(arr2[0]);//Ԫ�ظ���
//	int width_arr2 = sizeof(arr2[0]);			//Ԫ���ֽڴ�С
//	qsort(arr2, sz_arr2, width_arr2, cmp_float);
//
//	//�ṹ������-by-name
//	//�ṹ������-by-heights
//	int sz_arr3 = sizeof(arr3) / sizeof(arr3[0]);//Ԫ�ظ���
//	int width_arr3 = sizeof(arr3[0]);			//Ԫ���ֽڴ�С
//	qsort(arr3, sz_arr3, width_arr3, cmp_struct_by_name);
//	qsort(arr3, sz_arr3, width_arr3, cmp_struct_by_height);
//
//	return 0;
//}


//
////���ڻ���ð������˼�룬�Զ���ʵ�����ƿ⺯��qsort�Ĺ���
////֧�����͡������͡��ṹ��ȶ���������������
////flag�����־λ������ok��ֱ��break����ѭ��
//#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
//#include<string.h>
//struct co_workers
//{
//	char name[20];//
//	int height;	  //cm
//};
////���ͱȽ�
//int cmp_int(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
////����������ȽϺ���
//int cmp_float(const void* e1, const void* e2)
//{
//	return (int)(ceil(*(float*)e1 - *(float*)e2));
//}
////�ṹ������ȽϺ���-by name
//int cmp_struct_by_name(const void* e1, const void* e2)
//{
//	return strcmp(((struct co_workers*)e1)->name, ((struct co_workers*)e2)->name);
//}
////�ṹ������ȽϺ���-by height
//int cmp_struct_by_height(const void* e1, const void* e2)
//{
//	return (((struct co_workers*)e1)->height - ((struct co_workers*)e2)->height);
//}
//
////��ʵ�ֶ������������������չ��my_bubble_sort
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
//	//�Ƚϵ�����
//	for (i = 0; i < sz - 1; i++)
//	{
//		int flag = 1;//�����Ѿ�����ok
//		int j = 0;
//		//ÿ�˱ȽϵĶ���
//		for (j = 0; j < sz - 1 - i; j++)
//		{	//����Ԫ�رȽ�
//			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)//	(char*)base + j * width //(char*)base+(j+1)*width
//			{
//				//����
//				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
//				//flag = 0;//��Ҫ����
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
//	//			 ����ַ	   ���鳤��	  ����ÿ��Ԫ�ش�С	����ָ��(����Ԫ��1�ĵ�ַ������Ԫ��2�ĵ�ַ��
//	//��������
//	int sz_arr1 = sizeof(arr1) / sizeof(arr1[0]);//Ԫ�ظ���
//	int width_arr1 = sizeof(arr1[0]);			
//	my_bubble_sort(arr1, sz_arr1, width_arr1, cmp_int);
//
//	//����������
//	int sz_arr2 = sizeof(arr2) / sizeof(arr2[0]);//Ԫ�ظ���
//	int width_arr2 = sizeof(arr2[0]);			
//	my_bubble_sort(arr2, sz_arr2, width_arr2, cmp_float);
//
//	//�ṹ������-by-name
//	//�ṹ������-by-heights
//	int sz_arr3 = sizeof(arr3) / sizeof(arr3[0]);//Ԫ�ظ���
//	int width_arr3 = sizeof(arr3[0]);			
//	my_bubble_sort(arr3, sz_arr3, width_arr3, cmp_struct_by_name);
//	my_bubble_sort(arr3, sz_arr3, width_arr3, cmp_struct_by_height);
//
//	return 0;
//}

//������
int main()
{	//��������Ԫ�ص�ַ
	//1.sizeof(������),��������
	//2.&����������������
	//��ַ4��8��
	int a[] = { 1,2,3,4};	
	printf("%d\n", sizeof(a + 0));		//4/8	��Ԫ�ص�ַ
	printf("%d\n", sizeof(*a));			//4		��Ԫ��
	printf("%d\n", sizeof(a + 1));		//4/8	�ڶ���Ԫ�ص�ַ
	printf("%d\n", sizeof(&a));			//4/8	�ڶ���Ԫ�ص�ַ
	printf("%d\n", sizeof(*&a));		//16����sizeof(a)һ��

	char arr[] = { 'a','b','c','d' };
	
	printf("%d\n", strlen(*arr));		//16����sizeof(a)һ��
	printf("%d\n", sizeof(arr[1]));		//16����sizeof(a)һ��


	return 0;
}