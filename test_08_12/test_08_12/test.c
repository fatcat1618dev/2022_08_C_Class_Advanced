#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<errno.h>
#include<string.h>
//C�����ļ�����
/*ʲô���ļ�
�ļ���
�ļ�����
�ļ�������
�ļ�ָ��
�ļ��Ĵ򿪺͹ر�
�ļ���˳���д
�ļ��������д
�ļ��������ж�
*/
/*
�����ϵ��ļ����ļ��������ļ��������ļ�
�ļ�������������->����->���뻺����->����������
			����<-���<-���������<-����������
�ļ�ָ�룺�����ļ�ϵͳ�У��ؼ��������ļ�����ָ�룬����ļ�ָ��;
	ÿ����ʹ�õ��ļ������ڴ��п�����һ����Ӧ ���ļ���Ϣ��������ļ�
	��ص���Ϣ���ṹ������У�ϵͳ�����ģ�ȡ��FILE;
"r","w","a",	����򿪡�����򿪡����ļ�β�������;
"rb","wb","ab";	������
../../	���ϼ�·��
..		��һ��·��
.		��ǰ·��
������Ϣ��printf("%s\n",strerror(errno));//������errno.h
		  perror(pf);					//ֱ��ʹ��
������	������	  ����		  ������
		fgetc	�ַ�����	����������	��stdio�����̡���ʾ��
		fputc	�ַ����	���������
		fgets	�ı�������	����������
		fputs	�ı������	���������
		fscanf	��ʽ������	����������
		fprintf	��ʽ�����	���������
		fread	����������	�ļ�
		fwrite	���������	�ļ�
scanf/printf	��Ա�׼���������
fscanf/fprintf	����������������
sscanf/sprintf	���ַ�����������洢���ַ���
*/

//int main()
//{
//	int a = 255;
//	FILE* pf = fopen("test.txt", "wb");//��������ʽд���ļ���
//	fwrite(&a, sizeof(a), 1, pf);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//int main()
//{
//	FILE* pf = fopen("../../test.txt", "r");
//	if (pf == NULL)
//	{
//		//printf("%s\n",strerror(errno));
//		perror(pf);
//		return 0;
//	}
//}

////д�ļ�
//int main()
//{
//	FILE* pf_Write = fopen("test.txt", "w");//д
//	if (pf_Write == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	//д�ļ�
//	fputc('b', pf_Write);
//	fputc('i', pf_Write);
//	//�ر��ļ�
//	fclose(pf_Write);
//	pf_Write = NULL;
//	return 0;
//}


//���ļ�
//int main()
//{
//	FILE* pf_Read = fopen("test.txt", "r");//��
//	if (pf_Read == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	//���ļ�
//	printf("%c", fgetc(pf_Read));
//	printf("%c", fgetc(pf_Read));
//
//	//�ر��ļ�
//	fclose(pf_Read);
//	pf_Read = NULL;
//	return 0;
//}

////fputs,fgets�ļ�
//int main()
//{
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//		return 0;
//	//д�ļ�
//	fputs("hello world!\n", pf);
//	//�ر�
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

////�Ӽ��̶�ȡһ���ı���Ϣ
//int main()
//{
//	char buf[1024] = { 0 };
//	fgets(buf, 1024, stdin);
//	fputs(buf, stdout);
//
//	gets(buf);
//	puts(buf);
//	return 0;
//}

////��ʽ�������롢���
////ͬ����stdin/out�����ļ�һ��
//struct s
//{
//	int n;
//	float score;
//	char arr[10];
//};
//int main()
//{
//	struct s s = { 0 };
//	fscanf(stdin, "%d %f %s", &(s.n), &(s.score), (s.arr));//��������
//	fprintf(stdout, "%d %f %s", s.n, s.score, s.arr);
//	return 0;
//}

////��ʽ�������롢���222222
////ͬ����stdin/out�����ļ�һ��
//struct s
//{
//	int n;
//	float score;
//	char arr[10];
//};
//int main()
//{
//	struct s s = { 100,3.14,"abcdef" };
//	struct s tmp = { 0 };
//	char buf[1024] = { 0 };
//	//��ʽ�����ݵ��ַ������浽buf
//	sprintf(buf, "%d %f %s", s.n, s.score, s.arr);
//	//��buf��ȡ��ʽ�����ݵ�tmp
//	sscanf(buf, "%d %f %s", &(tmp.n), &(tmp.score), (tmp.arr));//��������
//	
//	printf("%d %f %s", tmp.n, tmp.score, tmp.arr);
//	return 0;
//}

////��������ʽд�����ļ�
//struct s
//{
//	char name[10];
//	int age;
//	double score;
//};
//int main()
//{
//	struct s s = { "���",18,99.5};
//	FILE* pf = fopen("text.txt", "wb");
//	if (pf == NULL)
//	{
//		return 0;
//	}
//	//������д��
//	fwrite(&s, sizeof(struct s), 1, pf);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


////��������ʽд�����ļ�
//struct s
//{
//	char name[10];
//	int age;
//	double score;
//};
//int main()
//{
//	struct s tmp = { 0 };
//	FILE* pf = fopen("text.txt", "rb");
//	if (pf == NULL)
//	{
//		return 0;
//	}
//	//�����ƶ�
//	fread(&tmp, sizeof(struct s), 1, pf);
//	printf("%s %d %lf\n", tmp.name, tmp.age, tmp.score);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

