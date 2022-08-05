#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//作业专题
//147-159
//6 指针（初阶）_作业

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

//二级指针来存放一级指针的地址

//指针数组
//int* arr[10],要指定大小

////写一个函数，逆序字符串的内容
////数组传参
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
//	printf("逆序后:>%s\n", arr);
//	return 0;
//}
////用sizeof求，要-1去掉'\0'

////☆写一个函数，逆序字符串的内容
////带返回值
////指针传参
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
//	//scanf("%s", arr);	//空格自动结束
//	gets(arr);			//读1行
//	printf("逆序后:> %s\n", reverse(arr));		//带返回值
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

////打印水仙花数
////求出0-100000间的水仙花数并输出。水仙花数是指1个n位数，各位数字的n次方之和等于该数本身，如153=1^3+5^3+3^3。
////自幂数
//#include<math.h>
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 100000; i++)
//	{
//		//1.位数
//		int n = 1;
//		int temp = i;
//		while (temp /= 10)
//		{
//			n++;
//		}
//		//2.自幂数和
//		int sum = 0;
//		temp = i;
//		while (temp)
//		{
//			sum += pow(temp % 10, n);
//			temp /= 10;
//		}
//		//3.比较
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
////打印菱形图案
//int main()
//{
//	int line = 0;
//	scanf("%d", &line);
//	//打印上半部分
//	int i = 0;
//	for (i = 0; i < line; i++)
//	{
//		//空格
//		int j = 0;
//		for (j=0;j<line-1-i;j++)
//		{
//			printf(" ");
//		}
//		//*号
//		for(j=0;j<2*i+1;j++)	//第一行1个
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	//打印下半部分
//	for (i = 0; i < line-1; i++)
//	{
//		//空格
//		int j = 0;
//		for (j = 0; j <= i; j++)
//		{
//			printf(" ");
//		}
//		//*号
//		for (j = 0; j < 2 *(line-i-1)-1; j++)	//第一行1个
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

////杨辉三角
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

////凶杀案，凶手为4个嫌疑犯中的1个：
////供词如下：
////A说：不是我。
////B说：是C。
////C说：是D。
////D说：C在胡说。
////已知3个人说了真话，1个人说的假话。
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

//烧香问题
//有一种香，材质不均匀，但是每一根香燃烧完恰好是1小时。
//给你两根香，确定1个15min的时间段。
//|====================|	A
//|====================|	B
//A从两头烧，B从一头；
//A烧完，B烧了半小时，点B另一头，到B燃尽的时间段为15min.

//猜名次
//5位运动员参加了10km长跑比赛，他们预测比赛结果：
//A说：B第2，我第3；
//B说：我第2，E第4；
//C说：我第1，D第2；
//D说：C第5，我第3；
//E说：我第4，A第1.
//比赛结束后，每位运动员都说对了1半，实际排名是怎样的？
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