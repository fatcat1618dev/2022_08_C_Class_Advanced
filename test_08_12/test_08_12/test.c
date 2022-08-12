#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<errno.h>
#include<string.h>
//C语言文件操作
/*什么是文件
文件名
文件类型
文件缓冲区
文件指针
文件的打开和关闭
文件的顺序读写
文件的随机读写
文件结束的判定
*/
/*
磁盘上的文件是文件：程序文件、数据文件
文件缓冲区：磁盘->输入->输入缓冲区->程序数据区
			磁盘<-输出<-输出缓冲区<-程序数据区
文件指针：缓冲文件系统中，关键概念是文件类型指针，简称文件指针;
	每个被使用的文件都在内存中开辟了一个相应 的文件信息区，存放文件
	相关的信息，结构体变量中，系统声明的，取名FILE;
"r","w","a",	输入打开、输出打开、向文件尾添加数据;
"rb","wb","ab";	二进制
../../	上上级路径
..		上一级路径
.		当前路径
报错信息：printf("%s\n",strerror(errno));//需引用errno.h
		  perror(pf);					//直接使用
函数：	函数名	  功能		  适用于
		fgetc	字符输入	所有输入流	如stdio，键盘、显示器
		fputc	字符输出	所有输出流
		fgets	文本行输入	所有输入流
		fputs	文本行输出	所有输出流
		fscanf	格式化输入	所有输入流
		fprintf	格式化输出	所有输出流
		fread	二进制输入	文件
		fwrite	二进制输出	文件
scanf/printf	针对标准输入输出流
fscanf/fprintf	针对所有输入输出流
sscanf/sprintf	从字符串读、输出存储到字符串
*/

//int main()
//{
//	int a = 255;
//	FILE* pf = fopen("test.txt", "wb");//二进制形式写入文件中
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

////写文件
//int main()
//{
//	FILE* pf_Write = fopen("test.txt", "w");//写
//	if (pf_Write == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	//写文件
//	fputc('b', pf_Write);
//	fputc('i', pf_Write);
//	//关闭文件
//	fclose(pf_Write);
//	pf_Write = NULL;
//	return 0;
//}


//读文件
//int main()
//{
//	FILE* pf_Read = fopen("test.txt", "r");//读
//	if (pf_Read == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	//读文件
//	printf("%c", fgetc(pf_Read));
//	printf("%c", fgetc(pf_Read));
//
//	//关闭文件
//	fclose(pf_Read);
//	pf_Read = NULL;
//	return 0;
//}

////fputs,fgets文件
//int main()
//{
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//		return 0;
//	//写文件
//	fputs("hello world!\n", pf);
//	//关闭
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

////从键盘读取一行文本信息
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

////格式化的输入、输出
////同样，stdin/out换成文件一样
//struct s
//{
//	int n;
//	float score;
//	char arr[10];
//};
//int main()
//{
//	struct s s = { 0 };
//	fscanf(stdin, "%d %f %s", &(s.n), &(s.score), (s.arr));//键盘输入
//	fprintf(stdout, "%d %f %s", s.n, s.score, s.arr);
//	return 0;
//}

////格式化的输入、输出222222
////同样，stdin/out换成文件一样
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
//	//格式化数据到字符串，存到buf
//	sprintf(buf, "%d %f %s", s.n, s.score, s.arr);
//	//从buf读取格式化数据到tmp
//	sscanf(buf, "%d %f %s", &(tmp.n), &(tmp.score), (tmp.arr));//键盘输入
//	
//	printf("%d %f %s", tmp.n, tmp.score, tmp.arr);
//	return 0;
//}

////二进制形式写、读文件
//struct s
//{
//	char name[10];
//	int age;
//	double score;
//};
//int main()
//{
//	struct s s = { "李飞",18,99.5};
//	FILE* pf = fopen("text.txt", "wb");
//	if (pf == NULL)
//	{
//		return 0;
//	}
//	//二进制写入
//	fwrite(&s, sizeof(struct s), 1, pf);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


////二进制形式写、读文件
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
//	//二进制读
//	fread(&tmp, sizeof(struct s), 1, pf);
//	printf("%s %d %lf\n", tmp.name, tmp.age, tmp.score);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

