//�����������㷨
#include <stdio.h>
#include <malloc.h>
struct ListNode															//������������
{	int val;																	//��Ž��ֵ
	ListNode *next;														//��ź�̽��ĵ�ַ
	ListNode() : val(0), next(NULL) {}							//Ĭ�Ϲ��캯��
	ListNode(int x) : val(x), next(NULL) {}						//���ع��캯��1
	ListNode(int x, ListNode *next):val(x), next(next) {}	//���ع��캯��2
};
void CreateListF(ListNode *&L,int a[],int n)
//ͷ�巨����������
{
	ListNode *s;
	L=(ListNode *)malloc(sizeof(ListNode));  //����ͷ���
	L->next=NULL;
	for (int i=0;i<n;i++)
	{	
		s=(ListNode *)malloc(sizeof(ListNode));//�����½��s
		s->val=a[i];
		s->next=L->next;			//�����s����ԭ��ʼ���֮ǰ,ͷ���֮��
		L->next=s;
	}
}
void CreateListR(ListNode *&L,int a[],int n)
//β�巨����������
{
	ListNode *s,*r;
	L=(ListNode *)malloc(sizeof(ListNode));  	//����ͷ���
	L->next=NULL;
	r=L;						//rʼ��ָ��β���,��ʼʱָ��ͷ���
	for (int i=0;i<n;i++)
	{	
		s=(ListNode *)malloc(sizeof(ListNode));//�����½��s
		s->val=a[i];
		r->next=s;				//�����s����r���֮��
		r=s;
	}
	r->next=NULL;				//β���next����ΪNULL
}
void InitList(ListNode *&L)		//��ʼ�����Ա�
{
	L=(ListNode *)malloc(sizeof(ListNode));  //����ͷ���
	L->next=NULL;				//��������Ϊ�ձ�
}
void DestroyList(ListNode *&L)	//�������Ա�
{
	ListNode *pre=L,*p=pre->next;
	while (p!=NULL)
	{	free(pre);
		pre=p;					//pre��pͬ������һ�����					
		p=pre->next;
	}
	free(pre);					//��ʱpΪNULL,preָ��β���,�ͷ���
}
bool ListEmpty(ListNode *L)		//�����Ա��Ƿ�Ϊ�ձ�
{
	return(L->next==NULL);
}
int ListLength(ListNode *L)		//�����Ա�ĳ���
{	int i=0;
	ListNode *p=L;				//pָ��ͷ���,n��Ϊ0(��ͷ�������Ϊ0)
	while (p->next!=NULL)
	{	i++;
		p=p->next;
	}
	return(i);					//ѭ������,pָ��β���,�����iΪ������
}

void DispList(ListNode *L)	//������Ա�
{	ListNode *p=L->next;	//pָ���׽��
	while (p!=NULL)			//p��ΪNULL,���p����val��
	{	printf("%d ",p->val);
		p=p->next;			//p������һ�����
	}
	printf("\n");
}

bool GetElem(ListNode *L,int i,int &e)	//�����Ա��е�i��Ԫ��ֵ
{	int j=0;
	if (i<=0) return false;		//i���󷵻ؼ�
	ListNode *p=L;				//pָ��ͷ���,j��Ϊ0(��ͷ�������Ϊ0)
	while (j<i && p!=NULL)		//�ҵ�i�����p
	{	j++;
		p=p->next;
	}
	if (p==NULL)				//�����ڵ�i�����ݽ��,����false
		return false;
	else						//���ڵ�i�����ݽ��,����true
	{	e=p->val;
		return true;
	}
}

int LocateElem(ListNode *L,int e)	//���ҵ�һ��ֵ��Ϊe��Ԫ�����
{	int i=1;
	ListNode *p=L->next;			//pָ���׽��,i��Ϊ1(���׽������Ϊ1)
	while (p!=NULL && p->val!=e)	//����valֵΪe�Ľ��,�����Ϊi
	{	p=p->next;
		i++;
	}
	if (p==NULL)					//������ֵΪe�Ľ��,����0
		return(0);
	else							//����ֵΪe�Ľ��,�������߼����i
		return(i);
}

bool ListInsert(ListNode *&L,int i,int e)	//�����i��Ԫ��
{	int j=0;
	if (i<=0) return false;		//i���󷵻ؼ�
	ListNode *p=L,*s;			//pָ��ͷ���,j��Ϊ0(��ͷ�������Ϊ0)
	while (j<i-1 && p!=NULL)	//���ҵ�i-1�����p
	{	j++;
		p=p->next;
	}
	if (p==NULL)				//δ�ҵ���i-1�����,����false
		return false;
	else						//�ҵ���i-1�����p,�����½�㲢����true
	{	s=(ListNode *)malloc(sizeof(ListNode));
		s->val=e;				//�����½��s,��val����Ϊe
		s->next=p->next;		//�����s���뵽���p֮��
		p->next=s;
		return true;
	}
}

bool ListDelete(ListNode *&L,int i,int &e)	//ɾ����i��Ԫ��
{	int j=0;
	if (i<=0) return false;		//i���󷵻ؼ�
	ListNode *p=L,*q;			//pָ��ͷ���,j��Ϊ0(��ͷ�������Ϊ0)
	while (j<i-1 && p!=NULL)	//���ҵ�i-1�����
	{	j++;
		p=p->next;
	}
	if (p==NULL)				//δ�ҵ���i-1�����,����false
		return false;
	else						//�ҵ���i-1�����p
	{	q=p->next;				//qָ���i�����
		if (q==NULL)			//�������ڵ�i�����,����false
			return false;
		e=q->val;
		p->next=q->next;		//�ӵ�������ɾ��q���
		free(q);				//�ͷ�q���
		return true;			//����true��ʾ�ɹ�ɾ����i�����
	}
}
void f(ListNode* h)
{
	if(h!=NULL)
	{
		printf("%d ",h->val);
		f(h->next);
	}
}

