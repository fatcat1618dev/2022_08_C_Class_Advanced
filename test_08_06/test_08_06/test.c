#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>


////�� �⺯����strlen���size_t���޷���
////�ַ�����'\0'��Ϊ������־��strlen���ص����ַ�����'\0'ǰ����ֵ��ַ�����������'\0'
//
//int main()
//{
//	if (strlen("abc") - strlen("abcdef") < 0)
//		printf("С��\n");
//	else
//		printf("����\n");
//	return 0;
//}


////
////�ַ�������ģ��ʵ��
////1.��������2.�ݹ飻3.ָ��
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
//	printf("���ȣ�%d\n", my_strlen(arr));
//	return 0;
//}



////�����ַ���//�ַ��Ӵ� strstr
//int is_left_move(char*str1, char*str2)
//{
//	if (strlen(str1) != strlen(str2))
//		return 0;
//	//1.str1׷��1��str1�ַ���
//	strncat(str1, str1, 6);
//	//2.�ж�str2�ǲ����Ӵ�
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
//	int ret = is_left_move(arr1, arr2);//�ж�arr2�Ƿ���arr1���Ӵ�
//	if (ret == 1)
//		printf("Yes\n");
//	else
//		printf("No\n");
//	return 0;
//}


////strcpy,Դ�ַ�������'\0'������'\0'�ᱻ������Ŀ��ռ�
////�� strcpy��ģ��ʵ��
//char* my_strcpy(char* dest, const char* src)
//{
//	//assert(dest!=NULL && src != NULL);//����
//	assert(dest&& src);//����
//	char* ret = dest;
//	while (*dest++ = *src++);
//	return ret;					//����Ŀ��ռ���ʼ��ַ
//}
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "abc";
//	//char* arr2 = NULL;
//	//printf("%s\n", strcpy(arr1, arr2));//����Ŀ�Ŀռ��ַ
//	printf("%s\n", my_strcpy(arr1, arr2));
//	return 0;
//}



//
////�⺯��strcat��׷���ַ���
////ģ��ʵ�֡
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
//	//strcat(arr1, arr2);				//�⺯��
//	char* ret=my_strcat(arr1, arr2);				//ģ��ʵ��
//	printf("%s\n", ret);
//
//	return 0;
//}



//
////strcmp�������ַ�����ȣ�����0����1���󷵻ش���0���֣���1��С����С��0������	<0	=0	>0
////vs2019 ���Ͻ���-1 0 1������linux�ϸ����
////��ģ��ʵ��my_strcmp
//int my_strcmp(const char* p1, const char* p2)
//{
//	while (*p1== *p2)
//	{
//		if (!*p1)
//			return 0;		//���
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



////�⺯��strncpy
////���Դ�ַ�������С��num���������ַ�����׷��\0
//int main()
//{
//	char arr1[10] = "abcdef";
//	char arr2[] = "bit";
//	strncpy(arr1,arr2,6);
//	printf("%s\n", arr1);
//	return 0;
//}


////��strstr,�����ַ���
////���У�����NULL�����򷵻���ʼλ��
//int main()
//{
//	char* p1 = "abcdefghi";
//	char* p2 = "abc";
//	char* ret = strstr(p1, p2);
//	if (ret == NULL)
//	{
//		printf("�Ӵ�������\n");
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


////������
////errno��1��ȫ�ִ�����ı���
////c���ԵĿ⺯��ִ�й����У����ִ��󣬻�Ѷ�Ӧ�Ĵ����룬��ֵ��errno��
////char* str=strerror(errno)
////0	No error
////2	No such file or directory
//int main()
//{
//	//���ļ�
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//		printf("%s\n", strerror(errno));
//	else
//		printf("open success\n");
//	//printf("%s\n", strerror(2));
//	return 0;
//}


////memcpy,�ڴ濽��
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
//	int arr2[5] = { 0 };								//�ڴ�
//	struct S arr3[] = { {"����",25},{"�ν�",23} };
//	struct S arr4[2] = { 0 };							//�ڴ�
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
//	//��дȫתΪСд
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

////memmove��Դ��Ŀ���ڴ����ص�Ҳ���Դ���
////��my_memmove
//void* my_memmove(void* dest, const void* src, size_t count)
//{
//	assert(dest && src);
//	//ǰ->��
//	if (dest < src)
//		while (count--) 
//		{
//			*(char*)dest = *(char*)src;
//			//((char*)dest)++,((char*)src)++;//һ��
//			++(char*)dest, ++(char*)src;
//		}
//	else
//		////��->ǰ
//		while (count--)
//		{
//			*((char*)dest+count)=*((char*)src+count);
//		}
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	//memmove(void *_Dst, const void *_Src, size_t _Size)
//	//memmove(arr+2, arr, 4*5);//�⺯��
//	my_memmove(arr+2, arr, 4 * 5);//�Զ���
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


////memset,�ڴ��ʼ��
////���ֽڳ�ʼ��
//int main()
//{
//	char arr[10] = "";
//	memset(arr, '#', 10);
//	//int arr[10] = { 1 };
//	//memset(arr,1, 40);
//	int i = 0;
//	for (i = 0; i < 10; i++)//δ��ʼ����ȫ
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}