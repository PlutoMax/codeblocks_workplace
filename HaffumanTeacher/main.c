#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<malloc.h>
#include<io.h>
#include<math.h>/*floor(),ceil(),abs()*/
#include<process.h>/*exit()*/

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
/*#define OVERFLOW -2  math.c����*/
typedef int Status;/*�������ͣ�ֵ�Ǻ����״̬*/
typedef int Boolean;/*Boolean���ͣ�ֵ��TURE��FALSE*/

typedef struct{
	unsigned int weight;
	unsigned int parent,lchild,rchild;
}HTNode,*HuffmanTree;
typedef char * *HuffmanCode;/*��̬��������洢�շ��������*/

void HuffmanCoding(HuffmanTree *HT,HuffmanCode *HC,int *w,int n);
/*w���n���ַ���Ȩֵ(��>0),����շ�����HT�������n���ַ��ĺշ�������HC*/
int minl(HuffmanTree t,int i);
/*����һ���ڵ���Ȩֵ��С�����ĸ��ڵ���ţ�����select��������*/
void select(HuffmanTree t,int i,int *s1,int *s2);
/*��i���ڵ���ѡ��2��Ȩֵ��С�����ĸ��ڵ���ţ�s1Ϊ���������С���Ǹ�*/





/*

#include<stdio.h>
#include<stdlib.h>
#include"Huffman.h"
*/

int minl(HuffmanTree t,int i)
{
	int j,flag;
	unsigned int k=UINT_MAX;
	for(j=1;j<=i;j++)
		if(t[j].weight<k&&t[j].parent==0)
			k=t[j].weight,flag=j;
		t[flag].parent=1;
		return flag;
}

void select(HuffmanTree t,int i,int *s1,int *s2)
{
	int j;
	*s1=minl(t,i);
	*s2=minl(t,i);
	if(*s1>*s2)
	{
		j=*s1;
		*s1=*s2;
		*s2=j;
	}
}

void HuffmanCoding(HuffmanTree *HT,HuffmanCode *HC,int *w,int n)
{
	int m,i,s1,s2,start;
	unsigned c,f;
	HuffmanTree p;
	char *cd;

	if(n<=1)
		return;
	m=2*n-1;

	*HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode));

	for(p=HT+1,i=1;i<=n;++i,++p,++w)
	{
		(*p).weight=*w;
		(*p).parent=0;
		(*p).lchild=0;
		(*p).rchild=0;
	}
	for(;i<=m;++i,++p)
		(*p).parent=0;

	for(i=n+1;i<=m;++i)
	{
		select(*HT,i-1,&s1,&s2);
		(*HT)[i].parent=(*HT)[s2].parent=i;
		(*HT)[i].rchild=s2;
		(*HT)[i].lchild=s1;
		(*HT)[i].weight=(*HT)[s1].weight+(*HT)[s2].weight;
	}

	HC = (HuffmanCode)malloc((n+1)*sizeof(char *));
	cd = (char *)malloc(n * sizeof(char));
	cd[n-1] = '\0';

	for(i=1li<=n;i++)
	{
		start=n-1;
		for(c=i;f=(*HT)[i].parent;f!=0;c=f,f=(*HT)[f].parent)
			if(((*HT)[f].lchild==c)
				cd[--start]='0';
			else
				cd[--start]='1';
			HC[i] = (char *)malloc((n-start)*sizeof(char));
			strcpy(HC[i],&cd[start]);
	}
	free(cd);
}













/*
#include<stdio.h>
#include<stdlib.h>
#include"Huffman.h"
*/

int main()
{
	HuffmanTree HT;
	HuffmanCode HC;
	int *w,n,i;

	printf("������Ȩֵ�ĸ���(>1):");
	scanf("%d",&n);

	w=(int *)malloc(n*sizeof(int));

	printf("����������%d��Ȩֵ(����)��\n",n);
	for(i=0;i<=n-1;i++)
		scanf("%d",w+i);

	HuffmanCoding(HT,HC,w,n);

	for(i=1;i<=n;i++)
		push(HC[i]);

	return 0;
}
