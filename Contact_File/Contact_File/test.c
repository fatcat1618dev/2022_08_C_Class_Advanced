#define _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"
//		system("cls");	//stdlib.h	清屏
void menu()
{
	printf("*********************************************\n");
	printf("******** 1.add     2.del       **************\n");
	printf("******** 3.search  4.modify    **************\n");
	printf("******** 5.show    6.sort_byname ************\n");
	printf("******** 7.save    0.exit      **************\n");
	printf("*********************************************\n");
}
int main()
{
	int input = 0;
	//创建通讯录
	struct Contact con;//con中包含1000个人数信息
	//初始化通讯录
	InitContact(&con);
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case EXIT:					//释放内存
			SaveContact(&con);		//保存文件
			DestroyContact(&con);
			printf("退出\n");
			break;
		case SAVE:
			SaveContact(&con);
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	return 0;
}

