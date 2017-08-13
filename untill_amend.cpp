/*����������дһ��ͨѶ¼���򣬰���������Ϣ��
(1)���� char[9](�������4����)
(2)�ֻ���(11λ)
(3)��ÿ��Ԫ�����һ��ID
ʵ�����¹���
��� �༭ ���� ɾ�� ���� ���� ����
*/
#include "myhead.h"
//**********************************************************************
//**********************************************************************
char directory[30];//�ļ�Ŀ¼��ַ��
FILE *address;//�ݴ��ļ���ַ��Ϣ��

NODE * load()
{
	int i=0;
	NODE * head,* tail,* p;
	
	head=tail=(NODE *)malloc(sizeof(NODE));

	//����β�巨
	tail->next=NULL;
	
	//���ļ�
	FILE *fp;
	fp=fopen(directory,"r+");
	if(fp==NULL) 
	{
		printf("��ȡʧ��!�ļ���ʧ��!\n");
		return(NULL);
	}
	if(feof(fp)!=NULL)//����ļ�Ϊ��,��ʹ�ļ�����Ϊ�գ��ļ�Ҳ��һ���ļ�����������ȡ�ļ�������֮���ٿ��Ƿ�Ϊ��
	{
		p=(NODE *)malloc(sizeof(NODE));

		fread(p,sizeof(p->info),1,fp);
		if(feof(fp)!=NULL)
		{
			printf("��ȡʧ��!�ļ�Ϊ��!\n");
			free(p);
		}
		return(NULL);
		
	}
	address=fp;

	//��ֵ
	while(feof(fp)==NULL)
	{
		p=(NODE *)malloc(sizeof(NODE));
		
		fread(p,sizeof(p->info),1,fp);
		
		printf("���ڶ�ȡ��%d������\n",i);
		i++;
		if(feof(fp)!=NULL) 
		{
			free(p);
			break;
		}

	//��������
	p->next=NULL;
	tail->next=p;
	tail=p;
	}
	fclose(fp);
	return(head);
}
NODE * creat() //ͷ�巨
{
	//����ͷ���--???
	//�����ڴ�ռ䣬������headȥָ����
	NODE *head,*tail;
	head=tail=(NODE *)malloc(sizeof(NODE));
	tail->next=NULL;
	
	while(1)
	{
	//��������
	NODE *p=(NODE *)malloc(sizeof(NODE));
	printf("����������:\n");
	fflush(address);
	scanf("%s",p->info.no);
	printf("�������ֻ���:\n");
	fflush(address);
	scanf("%s",p->info.tele);

	//��������
	p->next=NULL;
	tail->next=p;
	tail=p;

	printf("�Ƿ�������?<y/n>?\n");
	fflush(stdin);
	if(getchar()=='n') break;
	}
	/*//��ʼ����Ԫ���,��pȥָ��
	NODE *p;
	p=(NODE *)malloc(sizeof(NODE));
	//��ʼ��������
	p->no="��Խ";
	p->tele="15223530300";
	//�޸�ָ����
	head->next=p;
	p->next=NULL;
	*/
	return(head);
}
//**********************************************************************
//**********************************************************************
int view(NODE * head)
{
	//��λ��Ԫ���:???
	//��ӡ����ֵ
	//�ƶ�ָ�룬�ƶ�����һ�����:  p=p->next;
	//�ƶ���ʲôʱ��Ϊֹ?
	//��λ��Ԫ���
	NODE *p1,*p2;
	p1=p2=head;
	//����ǿ�����ֱ���������Ϊ�վͿ�����
	if(head->next==NULL)
	{
		printf("����Ϊ��!\n");
		printf("\n");
		return(0);
	}
	//��ӡ��Ԫ���
	printf("------------------------------------\n");
	printf("����         �ֻ�����\n");
	printf("------------------------------------\n");
	//�����￪ʼѭ��
	p1=head->next;
	while(p1!=NULL)
	{
		printf("%-11s  %s\n",p1->info.no,p1->info.tele);
		//�ƶ�ָ��
		p2=p1;
		p1=p1->next;
	}
	return(0);
}
//**********************************************************************
//**********************************************************************
int search(NODE * head)
{
	//�ж��Ƿ��ǿձ��ǿձ��ֱ�ӷ���
	if(head->next==NULL)
	{
		printf("����Ϊ��!\n");
		printf("\n");
		return(0);
	}

	//����һ�㣬���ȿ���ѡ��������ַ�ʽ�����в���
	NODE * p1,*p2;
	p1=head->next;
	p2=head;
	//����һ������������������û�ҵ�
	int i=0;
	printf("��ϣ��ͨ�����������һ����ֻ�����������?(Y=����/N=�ֻ�����)?\n");
	fflush(stdin);
	char ch=getchar();
	if(ch=='Y')
	{
		//ͨ������������
		//����Ҫ���ҵ�����
		printf("����������Ҫ���ҵ�����:\n");
		char name[9];
		fflush(stdin);
		gets(name);
		//��ʼ���ң����ҵĽ�������ж����ÿ���ҵ�һ���������
		while(p1!=NULL)
		{
		    if(strcmp(p1->info.no,name)==0)
			{	
				printf("\n");
				printf("%-11s  %s\n",p1->info.no,p1->info.tele);
				i=1;
			}
			//�ƶ�ָ��
			p2=p1;
			p1=p1->next;

		}
		//������� һ����ѭ�����˳����ģ�һ����ֱ������ѭ���ģ��ж�����һ�����
		if(i==0)
		{
			//˵��������ѭ���������û���ҵ�
			printf("û���ҵ�����Ϣ!�������������Ƿ�����!\n");
			return(0);
		}
		//����ľ���ѭ�����˳�����
		return(0);
	}
	else if(ch=='N')
	{
		//ͨ���ֻ�����������
		printf("����������Ҫ���ҵ��ֻ�����:\n");
		char tele1[12];
		fflush(stdin);
		gets(tele1);
		i=0;
		//��ʼ���ң����ҵĽ�������ж����ÿ���ҵ�һ���������
		while(p1!=NULL)
		{
		    if(strcmp(p1->info.tele,tele1)==0)
			{	
				printf("\n");
				printf("%-11s  %s\n",p1->info.no,p1->info.tele);
				i=1;
			}
			//�ƶ�ָ��
			p2=p1;
			p1=p1->next;
		}
		//������� һ����ѭ�����˳����ģ�һ����ֱ������ѭ���ģ��ж�����һ�����
		if(i==0)
		{
			//˵��������ѭ���������û���ҵ�
			printf("û���ҵ�����Ϣ!�������������Ƿ�����!\n");
			return(0);
		}
		//����ľ���ѭ�����˳�����
		return(0);
	}
	return(0);
}
//**********************************************************************
//**********************************************************************
int add(NODE * head)
{
	/*	
	//��������½��
	//(1)�����½�㣺Ϊ�½�㿪���ڴ�ռ�
	//(2)Ϊ�½���������ֵ
	//(3)���½����뵽ͷ�������Ԫ���֮��:  head->next:  a,b
	*/
	printf("�������Ƿ�Ҫ�����ϵ��?<Y/N>?\n");
	char ch;
	fflush(stdin);
	ch=getchar();
	if(ch=='Y'||ch=='y')
	{
		//����ͷ�巨
		NODE *p1;
		while(ch=='Y'||ch=='y')
		{
		//ִ������½�����	
		p1=(NODE *)malloc(sizeof(NODE));
		printf("����������:\n");
		fflush(address);
		scanf("%s",p1->info.no);
		printf("�������ֻ���:\n");
		fflush(address);
		scanf("%s",p1->info.tele);
		//���½������
		p1->next=head->next;//���¿��ٵ��ڴ�ռ����ӵ���Ԫ���
		head->next=p1;
		//���Ƿ�������
		printf("�����Ƿ�Ҫ�����ϵ��?<Y/N>?\n");
		fflush(stdin);
		//ͨ������ѭ���ṹ���ж�
		ch=getchar();
		}
		return(0);
	}
	return(0);
}
//**********************************************************************
//**********************************************************************
int del(NODE * head)
{
	if(head->next==NULL)
	{
		printf("����Ϊ��!\n");
		printf("\n");
		return(0);
	}

	//��������Ҫɾ�����˵����������ֻ���
	NODE * p1,*p2;
	p1=head->next;
	p2=head;
	printf("��ϣ��ͨ�����������һ����ֻ�����������?(Y=����/N=�ֻ�����)?\n");
	fflush(stdin);
	char ch=getchar();
	if(ch=='Y')
	{
		//ͨ������������
		//����Ҫ���ҵ�����
		printf("����������Ҫ���ҵ�����:\n");
		char name[9];
		fflush(stdin);
		gets(name);
		//��ʼ���ң����ҵĽ�������ж����ÿ���ҵ�һ�����������ѯ���û��Ƿ�Ҫɾ��
		while(p1!=NULL)
		{
		    if(strcmp(p1->info.no,name)==0)
			{	
				printf("\n");
				printf("%-11s  %s\n",p1->info.no,p1->info.tele);
				printf("�����Ƿ�Ҫɾ��?<Y/N>?\n");
				ch=getchar();
				if(ch=='Y'||ch=='y')
				{
					//����ɾ������,��Ҫ����һ��ָ��
					NODE *p3=(NODE *)malloc(sizeof(NODE));
					p3=p1;
					p2->next=p1->next;
					p1=p1->next;
					free(p3);
				}
			}
			//�ƶ�ָ��
			p2=p1;
			p1=p1->next;
		}
		return(0);
	}
	else if(ch=='N')
	{
		//ͨ���ֻ�����������
		printf("����������Ҫ���ҵ��ֻ�����:\n");
		char tele1[12];
		fflush(stdin);
		gets(tele1);
		//��ʼ���ң����ҵĽ�������ж����ÿ���ҵ�һ���������
		while(p1!=NULL)
		{
		    if(strcmp(p1->info.tele,tele1)==0)
			{	
				printf("\n");
				printf("%-11s  %s\n",p1->info.no,p1->info.tele);
				printf("�����Ƿ�Ҫɾ��?<Y/N>?\n");
				ch=getchar();
				if(ch=='Y')
				{
					//����ɾ������
					p2->next=p1->next;
					p1=p1->next;
				}
				else return(0);

			}
			//�ƶ�ָ��
			p2=p1;
			p1=p1->next;
		}
		return(0);

	}
	return(0);
}
//**********************************************************************
//**********************************************************************
int freelist(NODE * head)
{
	//˼·����������ָ��p1,p2�����ҵ�ͷָ�룬p2ָ��ͷָ�룬p1ָ���̽�㣬Ȼ��ɾ��ͷָ��,Ȼ������p2=p1��
	NODE *p1,*p2;
	p1=p2=head;
	//�ȿ��ǲ��ǿ���������ǿ�����ֻ��Ҫɾ��ͷ���Ϳ����ˡ�
	if(head->next==NULL)
	{
		free(head);
		return(0);
	}
	//������ǿ�����
	p1=p1->next;
	while(p1!=NULL)
	{
		free(p2);
		p2=p1;
		p1=p1->next;
	}
	free(p2);
	return(0);
}
//**********************************************************************
//**********************************************************************
int save(NODE * head)
{
	NODE *p1;
	p1=head->next;

	//�������������е���Ϣ
	//��д��ķ�ʽ��һ���ļ������ж��Ƿ�򿪳ɹ�
	FILE *fp;
	fp=fopen(directory,"w");
	if(fp==NULL)
	{
		printf("�ļ���ʧ��!��Ϣ����ʧ��!\n");
		return(0);
	}
	if(head->next==NULL)
	{
		printf("ͨѶ¼Ϊ��!��Ϣ����ʧ��!\n");
		return(0);
	}
	while(p1!=NULL)
	{
		fwrite(p1,sizeof(p1->info),1,fp);
		//�ƶ�ָ��
		p1=p1->next;
	}
	fclose(fp);
	printf("���̳ɹ�!\n");
	return(0);
}
//**********************************************************************
//**********************************************************************

int clearlist( NODE * head)
{
	//һ���������ֻ����ͷ��㣬����1��ʾ��ճɹ�������0��ʾ���ʧ��
	int i=0;
	NODE *p1,*p2;
	p1=p2=head->next;
	while(p2!=NULL)
	{
		i=1;
		//ɾ������
		p1=p1->next;
		free(p2);
		p2=p1;
	}
	if(i) head->next=NULL;
	return(i);
}
//**********************************************************************
//**********************************************************************

void menu()
{
	printf("������ͨѶ¼�ļ���ַ��\n");
	scanf("%s",directory);
	NODE * head;
	//����������
	//head=creat();
	//���������
	
	printf("���ڶ�ȡ���ݣ����Ժ�....\n");
	head = load();
	while(1)
	{
		if(head==NULL) 
		{
			printf("�ļ���ȡʧ��\n"); break;
		}
		else
		{
			printf("��ȡ���ݳɹ�!\n");break;
		}
	}
	while(1)
	{
	printf("������������������������������������\n");
	printf("            ͨѶ¼����ϵͳ\n");
	printf("������������������������������������\n");
	printf("��ӭ���뱾ϵͳ!");
	printf("��ѡ��\n");
	printf("(1)-----���ͨѶ¼\n");
	printf("(2)-----������ϵ��\n");
	printf("(3)-----������ϵ��\n");
	printf("(4)-----ɾ����ϵ��\n");
	printf("(5)-----ͨѶ¼����\n");
	printf("(6)-----ɾ��������ϵ��\n");
	//�˳�ϵͳ֮ǰ��Ҫ�ͷ��ڴ�!!!!!!!!!!!
	printf("(7)-----�˳���ϵͳ\n");//!!!!!!!!
	int s;
	scanf("%d",&s);
	switch(s)
	{
	case 1:view(head);break;
	case 2:search(head);break;
	case 3:add(head);break;
	case 4:del(head);break;
	case 5:save(head);break;
	case 6:
		{
			if(clearlist(head))
				printf("ɾ��������ϵ�˳ɹ�!\n");
			else printf("ɾ��������ϵ��ʧ��!\n");
		}break;
		
	case 7:freelist(head);exit(0);
	default:printf("error!����������!\n");
	}
	//ÿ��������֮�������Ļ
	}
}

//**********************************************************************
//**********************************************************************
void main()
{
	menu();
}
//**********************************************************************
//**********************************************************************
//**********************************************************************
