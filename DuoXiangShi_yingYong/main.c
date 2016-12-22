#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


typedef struct PolyNode{
    int coef;//ϵ��
    int expon;//ָ��
    struct node*link;//ָ�������ṹ��
}*Polynomial;

Polynomial p1,p2;//���������ṹ������

//����ʽ�ӷ�ʵ�ֹ���
Polynomial PolyAdd(Polynomial p1,Polynomial p2){
    Polynomial front,rear,temp;
    int sum;
    Polynomial PolyNode;
    rear=(Polynomial)malloc(sizeof(PolyNode));
    front=rear;
    while(p1&&p2)
        switch(strcmp(p1->expon,p2->expon)){
    case 1:
        Attach(p1->coef,p1->expon,&rear);
        p1=p1->link;//ָ����һ�����
        break;

    case -1:
        Attach(p2->coef,p2->expon,&rear);
        p2=p2->link;
        break;
    case 0:
        sum=p1->coef+p2->coef;
        if(sum)Attach(sum,p1->expon,&rear);
        p1=p1->link;
        p2=p2->link;
        break;

/*��δ������Ķ���ʽ������θ��Ƶ��������ʽ��*/
for(;p1;p1=p1->link) Attach(p1->coef,p1->expon,&rear);
for(;p2;p2=p2->link) Attach(p2->coef,p2->expon,&rear);
rear->link=NULL;
temp=front;
front=front->link;
free(temp);
return front;
    }
}

void Attach(int coef,int expon,Polynomial*PtrRear){
    Polynomial p,PolyNode;

    p=(Polynomial)malloc(sizeof(PolyNode));
    p->coef=coef;
    p->expon=expon;
    (*PtrRear)->link=p;

    *PtrRear=p;
}

int main()
{
    Polynomial p1,p2,front;
    p1->coef=2;
    p1->expon=4;
    p2->coef=8;
    p2->expon=4;
    front=PolyAdd(p1,p2);
    //printf("Hello world!\n");
    return 0;
}
