#include <stdio.h>
#include <stdlib.h>


typedef struct LNode{
    int data;
    struct LNode *next;
    int length;
}LNode,*LinkList;

void CreatList_head(LinkList L,int n);
void CreatList_tail(LinkList L,int n);

struct LNode *LNodeList_init(){
    LinkList L = NULL;
    L=(LinkList)malloc(sizeof(LNode));//����ͷ���
    L->length = 0;
    return L;
}

void CreatList_head(LinkList L,int n){//ͷ�巨����
    LinkList p;
    int i;
   // L=(LinkList)malloc(sizeof(LNode));//���ٿռ�
    L->next=NULL; //�ȴ���һ����ͷ���ĵ�����
    for(i=n;i>0;--i){
        p=(LinkList)malloc(sizeof(LNode));
        scanf("%d",&(p->data)); //����Ԫ��ֵ
        L->length++;
        p->next=L->next;//��ͷ���ָ�򿪶�
        L->next = p;
    }
}

//β�巨����
void CreatList_tail(LinkList L,int n){//β�巨��������
    LinkList p,r;
    int i;

   //L=(LinkList)malloc(sizeof(LNode));//���ٿռ�
   r=L;
    L->next=NULL; //�ȴ���һ����ͷ���ĵ�����
    for(i=0;i<n;i++){
        p=(LinkList)malloc(sizeof(LNode));
        scanf("%d",&(p->data));

        r->next=p;
        r=p;

         L->length++;
    }
    r->next=NULL;
    //printf("LIST LENGTH:%d\n",L->length);

}

void printList(LinkList L,int n){
   int i;

   //for(i=0;i<n;i++){
   while(L->next!=NULL){
    L=L->next;
    printf("%d ",L->data);
   }
    printf("\n");
}


int LocateElem(LinkList L,int x){
    int i,count=0;

        while(L->data!=x){
            if(L->next!=NULL){
                L=L->next;
                count++;
            }else
                return 0;
        }

        //i=L->data;
    return count;
}

int LENGTH(LinkList L){
    int length=0;
    while(L->next!=NULL){
        length++;
        L=L->next;
    }
    return length;

}

int list_Length(LinkList L){
    return L->length;
}

int Getelem(LinkList L,int i){
    //LΪ��ͷ���ĵ������ͷָ��
    //����i��Ԫ�ش���ʱ���丳ֵ��e������ok�����򷵻�error
    LinkList p;
    int j,e;
    p=L->next;j=1;//pָ���һ�����
    while(p&&j<i){
        p = p->next;
        j++;
    }
    if(!p||j>i) return 0;
    e=p->data;
    return e;
}


int main()
{
    LinkList L;
    int n,x;
    //L=(LinkList)malloc(sizeof(LNode));
    L = LNodeList_init();//���ٿռ�

    printf("���������Χ��");
    scanf("%d",&n);

    CreatList_tail(L,n);
    printList(L,n);


    printf("���ң�\n");
    scanf("%d",&x);

    if(LocateElem(L,x))
        printf("��ַ��%d\n",LocateElem(L,x));
    else
        printf("���Ҳ�����Ԫ��\n");

    printf("����01:%d\n",LENGTH(L));
    printf("����02:%d\n",list_Length(L));

    //��ȡԪ��
    int i,e,t;
    printf("i:");
    scanf("%d",&i);
   t = Getelem(L,i);
   if(t) printf("��λ��Ԫ���ǣ�%d\n",t);
    else printf("����λ�ò���\n");

/*
    printf("���������Χ��");
    scanf("%d",&n);

    CreatList_head(L,n);
    printList(L,n);
*/
    free(L);
    return 0;
}
