#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//��ҵר��
//147-159
//6 ָ�루���ף�_��ҵ

//int main()
//{
//	unsigned long pulArray[] = { 6,7,8,9,10 };
//	unsigned long* pulPtr;
//	pulPtr = pulArray;
//	*(pulPtr + 3) += 3;
//	printf("%d %d\n", *pulPtr, *(pulPtr + 3));
//
//	return 0;
//}
////6 12

//����ָ�������һ��ָ��ĵ�ַ

//ָ������
//int* arr[10],Ҫָ����С

////дһ�������������ַ���������
////���鴫��
//#include<string.h>
//void reverse(char arr[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left < right)
//	{
//		char temp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = temp;
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	char arr[] = "haomo.ai";
//	printf("%s\n", arr);
//	int sz = sizeof(arr) / sizeof(arr[0])-1;
//	//int sz = strlen(arr);
//	reverse(arr,sz);
//	printf("�����:>%s\n", arr);
//	return 0;
//}
////��sizeof��Ҫ-1ȥ��'\0'

////��дһ�������������ַ���������
////������ֵ
////ָ�봫��
//#include<string.h>
//#include<assert.h>
//char* reverse(char* str)
//{
//	assert(str);
//	int sz = strlen(str);
//	char* left = str;
//	char* right = str + sz - 1;
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//	return str;
//}
//
//int main()
//{
//	char arr[256] = { 0 };
//	//scanf("%s", arr);	//�ո��Զ�����
//	gets(arr);			//��1��
//	printf("�����:> %s\n", reverse(arr));		//������ֵ
//	return 0;
//}


//int main()
//{
//	int a = 0;
//	int n = 0;
//	scanf("%d%d", &a, &n);//2 5
//	int sum = 0;
//	int ret = 0;
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		ret = ret * 10 + a;//
//		sum +=ret;
//	}
//	printf("%d\n", sum);
//	return 0;
//}

////��ӡˮ�ɻ���
////���0-100000���ˮ�ɻ����������ˮ�ɻ�����ָ1��nλ������λ���ֵ�n�η�֮�͵��ڸ���������153=1^3+5^3+3^3��
////������
//#include<math.h>
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 100000; i++)
//	{
//		//1.λ��
//		int n = 1;
//		int temp = i;
//		while (temp /= 10)
//		{
//			n++;
//		}
//		//2.��������
//		int sum = 0;
//		temp = i;
//		while (temp)
//		{
//			sum += pow(temp % 10, n);
//			temp /= 10;
//		}
//		//3.�Ƚ�
//		if (i == sum)
//			printf("%d ", i);
//	}
//	return 0;
//}

//
////      *			/6 /1*
////     ***			/5 /3*
////    *****			/4 /5*
////   *******		/3 /7*
////  *********		/2 /9*
//// ***********		/1 /11*
////*************		/0 /13* /////////
//// ***********		/1 /11*
////  *********		/2 /9*
////	 *******
////	  *****
////	   ***
////		*
////��ӡ����ͼ��
//int main()
//{
//	int line = 0;
//	scanf("%d", &line);
//	//��ӡ�ϰ벿��
//	int i = 0;
//	for (i = 0; i < line; i++)
//	{
//		//�ո�
//		int j = 0;
//		for (j=0;j<line-1-i;j++)
//		{
//			printf(" ");
//		}
//		//*��
//		for(j=0;j<2*i+1;j++)	//��һ��1��
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	//��ӡ�°벿��
//	for (i = 0; i < line-1; i++)
//	{
//		//�ո�
//		int j = 0;
//		for (j = 0; j <= i; j++)
//		{
//			printf(" ");
//		}
//		//*��
//		for (j = 0; j < 2 *(line-i-1)-1; j++)	//��һ��1��
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	for (i = 0; i <= 30; i++)
//	{
//		arr[i] = 0;
//		printf("hello\n");
//	}
//	return 0;
//}

////�������
//int main()
//{
//	int arr[10][10] = { 0 };
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < 10; i++)
//	{
//		for (j = 0; j < 10; j++)
//		{
//			if (j == 0)
//			{
//				arr[i][j] = 1;
//			}
//			if (i == j)
//			{
//				arr[i][j] = 1;
//			}
//			if (i >= 2 && j >= 1)
//			{
//				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//			}
//		}
//		
//	}
//	for (i = 0; i < 10; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

////��ɱ��������Ϊ4�����ɷ��е�1����
////�������£�
////A˵�������ҡ�
////B˵����C��
////C˵����D��
////D˵��C�ں�˵��
////��֪3����˵���滰��1����˵�ļٻ���
//
//int main()
//{
//	int killer = 0;
//	for (killer = 'a'; killer <= 'd'; killer++)
//	{
//		if ((killer != 'a')+(killer == 'c')+ (killer == 'd') + (killer != 'd')==3)
//			printf("killer=%c\n", killer);
//	}
//	return 0;
//}

//��������
//��һ���㣬���ʲ����ȣ�����ÿһ����ȼ����ǡ����1Сʱ��
//���������㣬ȷ��1��15min��ʱ��Ρ�
//|====================|	A
//|====================|	B
//A����ͷ�գ�B��һͷ��
//A���꣬B���˰�Сʱ����B��һͷ����Bȼ����ʱ���Ϊ15min.

//������
//5λ�˶�Ա�μ���10km���ܱ���������Ԥ����������
//A˵��B��2���ҵ�3��
//B˵���ҵ�2��E��4��
//C˵���ҵ�1��D��2��
//D˵��C��5���ҵ�3��
//E˵���ҵ�4��A��1.
//����������ÿλ�˶�Ա��˵����1�룬ʵ�������������ģ�
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	for (a = 1; a <= 5; a++)
	{
		for (b = 1; b <= 5; b++)
		{
			for (c = 1; c <= 5; c++)
			{
				for (d = 1; d <= 5; d++)
				{
					for (e = 1; e <= 5; e++)
						if (((b == 2) + (a == 3) == 1) + ((b == 2) + (e == 4) == 1) + ((c == 1) + (d == 2) == 1) + ((c == 5) + (d == 3) == 1) + ((e == 4) + (a == 1) == 1)==5)
						{
							if (a * b * c * d * e == 120)
								printf("a=%d b=%d c=%d d=%d e=%d\n", a, b, c, d, e);
						}

				}
			}
		}
	}
	return 0;
}
//3 1 5 2 4
//a b c d e