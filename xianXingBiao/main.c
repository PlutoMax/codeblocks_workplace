#include <stdio.h>
#include <stdlib.h>
#define maxSize 40
typedef struct{
    int Data[maxSize];
    int last;
}List;
//={2,4,6,9,3,40,12}
List L,*PtrL;
//�����±�Ϊi��Ԫ�أ�L.Data[i]��PtrL->Data[i]
//���Ա�ĳ���:L.last=1��PtrL->last+1;

//1.��ʼ�����Ա������յ�˳���
List *makeEmpty(){
    List *PtrL;
    PtrL =(List*)malloc(sizeof(List));//���붯̬�ڴ����ռ�
    PtrL->last=0;
    return PtrL;
}

//����
void add(List*PtrL){
    int i;
    if(PtrL->last+1>=maxSize){
        printf("��������");
    }
    else{
            //if(PtrL->last<)
          for(i=0;i<maxSize;i++)
        PtrL->Data[PtrL->last]=i+1;
        PtrL->last++;
    }
    return;
}

void show(List*PtrL){
    int i;
    if(PtrL->last==-1)
    {
        printf("��Ϊ�գ�");
        return ;
    }
    else
        for(i=0;i<PtrL->last;i++){
            printf("%d ",PtrL->Data[i]);
        }
    return ;
}

//����
int find(int x,List *PtrL){
    int i=0;//�����0��ʼ
    while(i<=PtrL->last&&PtrL->Data[i]!=x)
        i++;
    if(i>PtrL->last)
        return -1;//���û�ҵ�����-1.
    else
        return i;
}

//�������
void insert(int x,int i,List* PtrL){//x:����Ԫ��,i:����λ�ã�PtrL:Ҫ���������Ա�
    int j;
    if(PtrL->last==maxSize-1){
        printf("���Ա�������");
        return;
    }
    if(i<1||i>PtrL->last+2){//�����0�����뵽0-1��λ��
       printf("λ�ò��Ϸ���");
       return;
    }
    for(j=PtrL->last;j>=i-1;j--)
        PtrL->Data[j+1]=PtrL->Data[j];/*�� ai�� an��������ƶ�*/
    PtrL->Data[i-1]=x;/*��Ԫ�ز���*/
    PtrL->last++;/*lastҲҪ����һλָ�����һλ*/
    return;
}

void Delete(int i,List*PtrL){//��ָ��λ��ɾ��ָ��Ԫ��
    int j;
    if(i<1||i>PtrL->last+1){
        printf("�����ڵ�%d��Ԫ��",i);
        return ;
    }
    for(j=i;j<=PtrL->last;j++)
        PtrL->Data[j-1]=PtrL->Data[j];//��i-1��ֵ������
    PtrL->last--;
    return;
}

int main()
{
    while(1){
printf("1.��ʼ��   2.����    3.����    4.ɾ��    5.����Ԫ�� 6.��ʾ��\n");
int n;
int l,x;
scanf("%d",&n);
switch(n){
case 1: makeEmpty();break;
case 2: printf("������Ҫ���ҵ�Ԫ��\n");int x;
        scanf("%d",&x);find(x,PtrL);break;
case 3:printf("������Ҫ�����Ԫ�غ�λ��\n");
        scanf("%d%d",&l,&x);insert(l,x,PtrL);break;
case 4:printf("������Ҫɾ��Ԫ�ص�λ��\n");int l;
        scanf("%d",&l);Delete(l,PtrL);break;
case 5://printf("������Ҫ���ӵ�Ԫ�أ�\n");scanf("%d",&x);
        add(PtrL);break;
case 6:show(PtrL);break;
default :printf("��������\n");break;
}
    }
    return 0;
}
