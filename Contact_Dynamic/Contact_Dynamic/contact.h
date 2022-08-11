#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#define MAX 1000
#define DEFAULT_SZ 3	//Ĭ������
#define SelfPlus 2		//ÿ������

#define MAX_NAME 8
#define MAX_SEX 4
#define MAX_TELE 12
#define	MAX_ADDR 16

enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT,
};

typedef struct PersonalInfo
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PersonalInfo;
//ͨѶ¼
typedef struct Contact
{
	struct PersonalInfo *data;//��Ϣָ��
	int size;//ͨѶ¼����
	int capacity;//����
}Contact;

//��ʼ��ͨѶ¼
void InitContact(struct Contact* p);

//����ͨѶ¼��Ϣ
void AddContact(struct Contact* p);

//��ʾͨѶ¼
void ShowContact(const struct Contact* p);

//ɾ��ͨѶ¼
void DelContact(struct Contact* p);

//����ͨѶ¼
void SearchContact(const struct Contact* p);

//��Ϣ�޸�
void ModifyContact(struct Contact* p);

//����������
void SortContact(struct Contact* p1);

//�ͷ��ڴ�
void DestroyContact(Contact* p);