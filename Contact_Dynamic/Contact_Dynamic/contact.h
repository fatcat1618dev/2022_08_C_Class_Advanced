#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#define MAX 1000
#define DEFAULT_SZ 3	//默认容量
#define SelfPlus 2		//每次扩容

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
//通讯录
typedef struct Contact
{
	struct PersonalInfo *data;//信息指针
	int size;//通讯录人数
	int capacity;//容量
}Contact;

//初始化通讯录
void InitContact(struct Contact* p);

//增加通讯录信息
void AddContact(struct Contact* p);

//显示通讯录
void ShowContact(const struct Contact* p);

//删除通讯录
void DelContact(struct Contact* p);

//查找通讯录
void SearchContact(const struct Contact* p);

//信息修改
void ModifyContact(struct Contact* p);

//按姓名排序
void SortContact(struct Contact* p1);

//释放内存
void DestroyContact(Contact* p);