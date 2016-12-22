#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int Date;
    struct Node*Next;//ָ����һ���ڵ��ָ��
}List;
List L,*PtrL;

//1.���
int length(List *PtrL){//�������ݵ��ǽṹ��
    List *p=PtrL;//��p���и�ֵ��ʼ�� pָ���ĵ�һ�����
    int j=0;    //j��������ʱ
    while(p){
        p=p->Next;
        j++;        /*��ǰpָ����ǵ�j�����*/
    }
    return j;
}

//2.����
//��1������Ų���
List *FindKth(int k,List *PtrL){
    List *p=PtrL;//ͷָ��
    int i=1;//���³�ʼ���
    while(p!=NULL&&i<k){
        p=p->Next;
        i++;
    }
    if(i==k)
        return p;/*�ҵ���k����������ָ��*/
    else
        return NULL;
}

//��ֵ����
List *Find(int x,List*PtrL){
    List*p=PtrL;
    while(p!=NULL&&p->Date!=x){
        p=p->Next;
    }
    return p;
}

//����
List *insert(int x,int i,List*PtrL){
    List*p,*s;
    if(i==1){                               /*�½����뵽��ͷ*/
        s=(List*)malloc(sizeof(List));  /*���� ��װ���*/
        s->Date=x;
        s->Next=PtrL;
        return s;
    }
    p=FindKth(i-1,PtrL);//���ҵ�i-1�����
    if(p==NULL){
        printf("����i����");
        return NULL;
    }
    else{
        s=(List*)malloc(sizeof(List));//����һ���½�㡣
        s->Date=x;
        s->Next=p->Next; /*�½������ڵ�i-1�����ĺ���*/
        p->Next=s;
        return PtrL; /*���ز���������*/
    }
}

//ɾ�����
List *Delete(int i,List* PtrL){
    List *p,*s;
    if(i==1){
        s=PtrL;
        if(PtrL!=NULL)
            PtrL=PtrL->Next;
        else
            return NULL;
        free(s);
        return PtrL;
    }
    p=FindKth(i-1,PtrL);/*����i-1�����*/
    if(p==NULL){
        printf("��%d����㲻����\n",i-1);
        return NULL;
    }else if(p->Next==NULL){
        printf("��%d����㲻����\n",i);
    }else{
        s=p->Next;
        p->Next=s->Next;
        s=p->Next;
        free(s);
    }
}

List *creatList(){
    List*pjiewei,*PtrL,*pDangQian;
    int i;
    if((PtrL=(List*)malloc(sizeof(List)))==NULL){
        printf("���ܷ����ڴ�ռ�");
        exit(0);
    }
    PtrL->Date=0;
    PtrL->Next=NULL;
    i=0;
    do{

    }while(1);
    return PtrL;
}

int main()
{
    List*PtrL=NULL;
    PtrL=creatList();
    return 0;
}
