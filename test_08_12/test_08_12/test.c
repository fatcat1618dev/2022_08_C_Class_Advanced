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
//		perror("open ���ϼ�test�ļ�ʧ�ܣ�\n");
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

//��������ʽд�����ļ�
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


/*
fseek	�ļ��������д,�����ļ�ָ���λ�ú�ƫ��������λָ��
		fseek(FILE *stream,long offset,int origin);//SEEK_CUR,SEEK_END,SEEK_SET
ftell	�����ļ�ָ���������ʼλ�õ�ƫ����
		long int ftell(FILE*stream)
rewind	���ļ�ָ���λ�ûص��ļ���ʼλ��
		void rewind(FILE*stream)
�ļ������ж�
feof	feof���ڵ��ļ���ȡ������ʱ���ж��Ƕ�ȡʧ�ܡ����������ļ�β����
	1.�ı��ļ���ȡ�Ƿ�������жϷ���ֵ�Ƿ�ΪEOF��fgetc),����NULL��fgets)
	2.�������ļ��Ķ�ȡ�����жϣ��жϷ���ֵ�Ƿ�С��ʵ��Ҫ���ĸ��� fread

perror	���ô�ͷ�ļ���strerror�򻯰棿
*/
int main()
{
	//perror
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		perror("Open Haomo.txt Error\n");
		return 0;
	}
	//���ļ�
	int ch = 0;
	while ((ch = fgetc(pf)) != EOF)
	{
		putchar(ch);
	}
	if (ferror(pf))
		printf("error\n");
	else if (feof(pf))
		printf("end of file!\n");
	//���ļ�
	fclose(pf);
	pf = NULL;
}

//#pragma pack(4)/*4�ֽڶ��� ƽ̨vs2019 c*/
//int main(int argc, char* argv[])
//{
//	struct tagTest1
//	{
//		short a;//0 1
//		char d;//2
//		//3 
//		long b;//4-7
//		long c;//8-11
//	};//12
//	struct tagTest2
//	{
//		long b;//0-3
//		short c;//4-5
//		char d;//6
//		long a;//8-11
//	};//12
//	struct tagTest3
//	{
//		short c;//0-1
//		long b;//4-7
//		char d;//8
//		long a;//12-15
//	};//16
//	struct tagTest1 stT1;
//	struct tagTest2 stT2;
//	struct tagTest3 stT3;
//
//	printf("%d %d %d", sizeof(stT1), sizeof(stT2), sizeof(stT3));//12 12 16
//
//	return 0;
//}