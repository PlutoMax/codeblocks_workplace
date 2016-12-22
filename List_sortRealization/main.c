#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIST_INIT_SIZE 100
#define LISTCEREMENT 10

typedef struct SqList{
    int *ele;//[LIST_INIT_SIZE];
    int length;
    int listSize;
}*SqL;

//��ʼ���� ��
void initList(SqL list){
    list->ele = (int*)malloc(LIST_INIT_SIZE*sizeof(int));//����ռ䡣
    //memset(list->ele,0,sizeof());
    if(!list->ele){
        printf("�����ڴ�ʧ��\n");
        return ;
    }

    list->length=0;
    list->listSize=LIST_INIT_SIZE;
    return ;
}

//��ձ�
void clearList(SqL list){
    //memset(list->ele,0,sizeof(LIST_INIT_SIZE));//�ÿ�
    int i;
    for(i=0;i<list->listSize;i++)
        list->ele[i]=0;
    return;
}


//�жϿձ�
int IsEmptyList(SqL list){
   return list->length==0?0:1;
}

//����
int listLength(SqL list){
    return list->length;
}

//������
void creatList(SqL list){
    int i,sur;
    int *newBase;
    printf("������һ����������Χ\n");
    scanf("%d",&sur);

    while(sur>=list->listSize){
        //��ǰ�ռ����� ���ӷ���
        newBase=(int*)realloc(list->ele,(list->listSize + LISTCEREMENT)*sizeof(int));
        if(!newBase) {printf("�ڴ����ʧ�ܣ�\n");return;}
        list->ele=newBase;//�»�ַ
        list->listSize += LISTCEREMENT;//�����ӵ�������
    }


    for(i=0;i<sur;i++){//ע��Խ������
        list->ele[i]=i;
        list->length++;
    }

}

//�������
int listInsert(SqL list,int q,int e){//��˳���Ա�list�е�i��λ��֮ǰ������Ԫ��i.
    //i��λ���Ƿ�Ϸ�
    int *newBase;

    if(q<1||q>list->listSize){
        printf("����λ�ò��Ϸ���\n");

        return 0;
    }

    if(list->length>=list->listSize){
        //��ǰ�ռ����� ���ӷ���
        newBase=(int*)realloc(list->ele,(list->listSize + LISTCEREMENT)*sizeof(int));
        if(!newBase) {printf("�ڴ����ʧ�ܣ�\n");return 0;}
        list->ele=newBase;//�»�ַ
        list->listSize += LISTCEREMENT;//�����ӵ�������
    }

    if(q>list->length&&q<=list->listSize){
        list->ele[list->length]=e;
        list->length++;
        return 1;
    }

    int p;//=list->ele[i-1];//qΪҪ�����Ԫ�ء�

    for(p=list->ele[list->length-1];p >= q-1; --p)
           list->ele[p+1]=list->ele[p];
    list->ele[q-1]=e;
    ++list->length;
    return 1;

}

//��ӡ��
void printList(SqL list){
    int i;
    printf("��ӡ������£�\n");
    for(i=0;i<list->length;i++){
            //arr[%d]:(i),
        printf("%d%c",list->ele[i],i<list->length-1?' ':'\n');
    }
}

//ɾ��
int listDelete(SqL list,int q,int de){//ɾ����i��Ԫ�ز���e���ء�
    int i;
    if(q<1||q>list->length){
        printf("ָ��λ�ò��Ϸ�\n");
        return -1;
    }

/*
    int p;
    p=list->ele[i-1];
    de=p;
    q=list->ele+list->length - 1;
    for(++p;p <= q;++p)
        list->ele[p-1]=list->ele[p];
    --list->length;
    */


    de=list->ele[q-1];
    for(i=q;i<list->length;i++)
        list->ele[i-1]=list->ele[i];

    list->length--;

    return de;
}

//����Ԫ��ƥ��Ԫ��λ��
int listFindKth(SqL list,int e){
    int i;
    for(i=0;i<list->length;i++)
        if(list->ele[i] == e)
            return i+1;
    printf("δ���ҵ���Ԫ��\n");
    return 0;
}

//���Ұ�λ��getԪ��
int listFindEle(SqL list,int k){
    int i;
    if(k<1||k>list->length){
        printf("����λ�ò��Ϸ�\n");
        return -1;
    }
    for(i=0;i<list->length;i++){
        if(i==(k-1))
            return list->ele[k-1];
    }
}

int main()
{
    while(1){
    SqL list1;
    list1=(SqL)malloc(sizeof(struct SqList));
    //��ʼ����
    initList(list1);
    //��ձ�
    clearList(list1);
    //������
    creatList(list1);
    //��ӡ��

    printList(list1);


    int len=listLength(list1);
    printf("˳���Ԫ�ظ�����%d\n",len);
    //����
    int i,e;
    printf("����λ��:");
    scanf("%d",&i);
    printf("����Ԫ��:");
    scanf("%d",&e);

    //��ӡ��
    if(listInsert(list1,i,e))
        printList(list1);

     printf("˳���Ԫ�ظ�����%d\n",listLength(list1));


     int q,de=0;
    printf("ɾ��λ��:");
    scanf("%d",&q);
    de=listDelete(list1,q,de);
     //if(de||list1->ele[0]==0){
     if(de>=0)
        printf("ɾ��Ԫ�أ�%d\n",de);

        printList(list1);
        printf("˳���Ԫ�ظ�����%d\n",listLength(list1));
     //}
     //���ҷ���λ��
     int kth,elememt;
     printf("������Ҫ���ҵ�Ԫ��\n");
     scanf("%d",&kth);
     elememt=listFindKth(list1,kth);
     if(elememt)
            printf("��Ԫ��λ���ǣ�%d\n",elememt);

    //���ҷ���Ԫ��
    int kth2,th;
     printf("������Ҫ���ҵ�λ��\n");
     scanf("%d",&kth2);
     th=listFindEle(list1,kth2);
     if(th>=0)
        printf("��Ԫ���ǣ�%d\n",th);

    free(list1);

    }
    return 0;
}
