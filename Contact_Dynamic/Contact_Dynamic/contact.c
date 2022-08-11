#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

void InitContact(struct Contact* p)
{
	//memset(p->data, 0, sizeof(p->data)); //��ʼ����0
	//p->size = 0;						//��ʼ��Ԫ��
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
	//����
	if (p->size == p->capacity)
	{
		PersonalInfo* ptr = realloc(p->data, (p->capacity + SelfPlus) * sizeof(PersonalInfo));
		if (ptr != NULL)
		{
			p->data = ptr;
			p->capacity += SelfPlus;
			printf("���ݳɹ�\n");
		}
		else
			printf("����ʧ��\n");
	}
}
void AddContact(struct Contact* p)
{
	//�������
	CheckCapacity(p);
	printf("����:>");
	scanf("%s", p->data[p->size].name);
	printf("�Ա�:>");
	scanf("%s", p->data[p->size].sex);
	printf("����:>");
	scanf("%d", &(p->data[p->size].age));		//��ַ
	printf("�绰:>");
	scanf("%s", p->data[p->size].tele);
	printf("��ַ:>");
	scanf("%s", p->data[p->size].addr);

	p->size++;
	printf("��ӳɹ�");
	//if (p->size == MAX)
	//	printf("ͨѶ¼�������޷�����\n");
	//else
	//{
	//	printf("����:>");
	//	scanf("%s", p->data[p->size].name);
	//	printf("�Ա�:>");
	//	scanf("%s", p->data[p->size].sex);
	//	printf("����:>");
	//	scanf("%d", &(p->data[p->size].age));		//��ַ
	//	printf("�绰:>");
	//	scanf("%s", p->data[p->size].tele);
	//	printf("��ַ:>");
	//	scanf("%s", p->data[p->size].addr);

	//	p->size++;
	//	printf("��ӳɹ�");
	//}
}
void ShowContact(const struct Contact* p)
{
	if (p->size == 0)
		printf("ͨѶ¼Ϊ��\n");
	else
	{
		int i = 0;
		//��ͷ,ȫ%s
		printf("%-8s\t%-4s\t%-4s\t%-12s\t%-16s\n", "����", "�Ա�", "����", "�绰", "��ַ");
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
	//forѭ������,��λλ��
	int i = 0;
	for (i = 0; i < p->size; i++)
	{
		if (!strcmp(p->data[i].name, name))
			return i;
	}
	return -1;//�鲻��
}
void DelContact(struct Contact* p)
{
	char name[MAX_NAME];
	printf("������Ҫɾ���˵�����:>");
	scanf("%s", name);
	int ret = FindByName(p, name);
	if(-1==ret)
		printf("��ϵ������\n");
	//ɾ��
	else
	{
		int j = 0;
		for (j = ret; j < p->size-1; j++)
		{
			p->data[j] = p->data[j + 1];		//������Ϣɾ��
		}
	}

	p->size--;
	printf("ɾ���ɹ�\n");
}

void SearchContact(const struct Contact* p)
{
	char name[MAX_NAME];
	printf("������Ҫ���ҵ��˵�����:>");
	scanf("%s", name);
	int ret = FindByName(p, name);
	if (ret == -1)
		printf("��ϵ�˲�����\n");
	else
	{
		//��ͷ,ȫ%s
		printf("%-8s\t%-4s\t%-4s\t%-12s\t%-16s\n", "����", "�Ա�", "����", "�绰", "��ַ");
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
	printf("������Ҫ�޸ĵ��˵�����:>");
	scanf("%s", name);
	int ret = FindByName(p, name);
	if (ret == -1)
		printf("��ϵ�˲�����\n");
	else
	{
		printf("����:>");
		scanf("%s", p->data[ret].name);
		printf("�Ա�:>");
		scanf("%s", p->data[ret].sex);
		printf("����:>");
		scanf("%d", &(p->data[ret].age));		//age��&ȡ��ַ
		printf("�绰:>");
		scanf("%s", p->data[ret].tele);
		printf("��ַ:>");
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