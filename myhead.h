#ifndef _MYHEAD_H_
#define _MYHEAD_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//**********************************************************************
//**********************************************************************
struct date
{
	char no[9];
	char tele[12];		
};

typedef struct node
{
	//Ϊ���ܹ���д�ṹ�壬�����ﶨ��Ľṹ���һ��
	struct date info;	
	struct node * next;
}NODE; 

#endif