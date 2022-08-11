#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

void InitContact(struct Contact* p)
{
	//memset(p->data, 0, sizeof(p->data)); //初始化置0
	//p->size = 0;						//初始零元素
	p->data = (PersonalInfo*)malloc(sizeof(PersonalInfo) * DEFAULT_SZ);
	if (p->data == NULL)
		return;
	else
	{
		p->size = 0;
		p->capacity = DEFAULT_SZ;
	}
}
void CheckCapacity(struct Contact* p)
{
	//增容
	if (p->size == p->capacity)
	{
		PersonalInfo* ptr = realloc(p->data, (p->capacity + SelfPlus) * sizeof(PersonalInfo));
		if (ptr != NULL)
		{
			p->data = ptr;
			p->capacity += SelfPlus;
			printf("扩容成功\n");
		}
		else
			printf("扩容失败\n");
	}
}
void AddContact(struct Contact* p)
{
	//检测容量
	CheckCapacity(p);
	printf("姓名:>");
	scanf("%s", p->data[p->size].name);
	printf("性别:>");
	scanf("%s", p->data[p->size].sex);
	printf("年龄:>");
	scanf("%d", &(p->data[p->size].age));		//地址
	printf("电话:>");
	scanf("%s", p->data[p->size].tele);
	printf("地址:>");
	scanf("%s", p->data[p->size].addr);

	p->size++;
	printf("添加成功");
	//if (p->size == MAX)
	//	printf("通讯录已满，无法增加\n");
	//else
	//{
	//	printf("姓名:>");
	//	scanf("%s", p->data[p->size].name);
	//	printf("性别:>");
	//	scanf("%s", p->data[p->size].sex);
	//	printf("年龄:>");
	//	scanf("%d", &(p->data[p->size].age));		//地址
	//	printf("电话:>");
	//	scanf("%s", p->data[p->size].tele);
	//	printf("地址:>");
	//	scanf("%s", p->data[p->size].addr);

	//	p->size++;
	//	printf("添加成功");
	//}
}
void ShowContact(const struct Contact* p)
{
	if (p->size == 0)
		printf("通讯录为空\n");
	else
	{
		int i = 0;
		//表头,全%s
		printf("%-8s\t%-4s\t%-4s\t%-12s\t%-16s\n", "名字", "性别", "年龄", "电话", "地址");
		for (i = 0; i < p->size; i++)
		{
			printf("%-8s\t%-4s\t%-4d\t%-12s\t%-16s\n",
				p->data[i].name,
				p->data[i].sex,
				p->data[i].age,
				p->data[i].tele,
				p->data[i].addr);
		}
	}
}
static int FindByName(const struct Contact* p, char name[MAX_NAME])//
{
	//for循环遍历,定位位置
	int i = 0;
	for (i = 0; i < p->size; i++)
	{
		if (!strcmp(p->data[i].name, name))
			return i;
	}
	return -1;//查不到
}
void DelContact(struct Contact* p)
{
	char name[MAX_NAME];
	printf("请输入要删除人的名字:>");
	scanf("%s", name);
	int ret = FindByName(p, name);
	if(-1==ret)
		printf("联系不存在\n");
	//删除
	else
	{
		int j = 0;
		for (j = ret; j < p->size-1; j++)
		{
			p->data[j] = p->data[j + 1];		//整个信息删除
		}
	}

	p->size--;
	printf("删除成功\n");
}

void SearchContact(const struct Contact* p)
{
	char name[MAX_NAME];
	printf("请输入要查找的人的名字:>");
	scanf("%s", name);
	int ret = FindByName(p, name);
	if (ret == -1)
		printf("联系人不存在\n");
	else
	{
		//表头,全%s
		printf("%-8s\t%-4s\t%-4s\t%-12s\t%-16s\n", "名字", "性别", "年龄", "电话", "地址");
		printf("%-8s\t%-4s\t%-4d\t%-12s\t%-16s\n",
			p->data[ret].name,
			p->data[ret].sex,
			p->data[ret].age,
			p->data[ret].tele,
			p->data[ret].addr);
	}
}

void ModifyContact(struct Contact* p)
{
	char name[MAX_NAME];
	printf("请输入要修改的人的名字:>");
	scanf("%s", name);
	int ret = FindByName(p, name);
	if (ret == -1)
		printf("联系人不存在\n");
	else
	{
		printf("姓名:>");
		scanf("%s", p->data[ret].name);
		printf("性别:>");
		scanf("%s", p->data[ret].sex);
		printf("年龄:>");
		scanf("%d", &(p->data[ret].age));		//age，&取地址
		printf("电话:>");
		scanf("%s", p->data[ret].tele);
		printf("地址:>");
		scanf("%s", p->data[ret].addr);
	}
}

int StructCmp_By_Name(const void* e1, const void* e2)
{
	return strcmp(((struct PersonalInfo*)e1)->name, ((struct PersonalInfo*)e2)->name);
};
void SortContact(struct Contact* p1)
{
	//qsort(void* _Base, size_t _NumOfElements, size_t _SizeOfElements, CompareFunction)
	qsort(p1->data,p1->size,sizeof(p1->data[0]), StructCmp_By_Name);
}

void DestroyContact(Contact* p)
{
	free(p->data);
	p->data = NULL;
}