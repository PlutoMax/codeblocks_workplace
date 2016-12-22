#ifndef __HASH_TABLE_H__
#define __HASH_TABLE_H__
#include<stdio.h>
#include<stdlib.h>

#define INIT_SIZE 100
#define TRUE 1
#define FALSE 0
#define max_value 10;


typedef char VaType[10];
typedef int boolean;

struct element
{
    int key;
    VaType value;
    int hash;
};

void hash_code(struct element *e);
struct hash_table_node
{
    struct element e;
    struct hash_table_node *next;

};

struct hash_table
{
    struct hash_table_node **slots;
    int count;
    int size;

};

struct hash_table *hash_table_init();

void hash_table_free(struct hash_table *table);

int hash_table_count(struct hash_table *table);
//void hash_table_clear(struct hash_table *table);
void hash_table_clear(struct hash_table *table,struct element *ele);

boolean hash_table_isempty(struct hash_table *table);

void hash_table_put(struct hash_table *table,struct element e);

struct element hash_table_get(struct hash_table *table,int key);

boolean hash_table_remove(struct hash_table *table,int key);

void Print_List(struct hash_table *table,struct element *ele);

void Query(struct hash_table *table,struct element *ele);

void AutoInit(struct hash_table *table,struct element *ele);

void add(struct hash_table *table,struct element *ele);

void menu(struct hash_table *table,struct element *ele);
#endif







void hash_code(struct element *e)
{
    e->hash = 3*e->key;
    return ;

}

//������ϣ��
struct hash_table *hash_table_init()
{
    struct hash_table *table=NULL;
    int i;
    table = (struct hash_table *)malloc(sizeof(struct hash_table));
    if(table == NULL) return NULL;
    table->slots=NULL;
    table->slots=(struct hash_table_node **)malloc(sizeof(struct hash_table_node *)*INIT_SIZE);
    if(table->slots==NULL)
    {
        free(table);    //�����ڴ�ʧ��
        return NULL;
    }
    for(i=0; i<INIT_SIZE; i++)
    {
        table->slots[i]=NULL;
    }
    table->count=0;
    table->size=INIT_SIZE;

    return table;
}

//���ٹ�ϣ��
void hash_table_free(struct hash_table *table)
{
    int i;
    struct hash_table_node *p=NULL;

    for(i=0; i<table->size; i++)
    {
        while(table->slots[i] != NULL)
        {
            p = table->slots[i];
            table->slots[i]=p->next;
            free(p);
        }
    }

    free(table->slots);
    free(table);
    return ;
}

int hash_table_count(struct hash_table *table)
{
    return table->count;

}
void hash_table_clear(struct hash_table *table,struct element *ele)
{
    int i;
    struct hash_table_node *p=NULL;

    for(i=0; i<table->size; i++)
    {
        while(table->slots[i] != NULL)
        {
            p = table->slots[i];
            table->slots[i]=p->next;
            free(p);
        }

        /**
        ��������
        */

    }
    for(i=0;i<=table->count+3;i++){
        ele[i].key=-1;
    }

    table->count=0;
    return;


}

boolean hash_table_isempty(struct hash_table *table)
{

    return (table->count==0);


}

void hash_table_put(struct hash_table *table,struct element e)
{
    struct hash_table_node *node=NULL;

    hash_code(&e);
    //printf("X%o\n",&e);

    node = table->slots[e.hash % table->size];
    while(node!=NULL)
    {
        if(node->e.key==e.key)
        {
            //node->e.value = e.value;
            strcpy(node->e.value,e.value);
            node->e.hash = e.hash;
            return ;
        }
        node = node->next;
    }

    node = NULL;
    node = (struct hash_table_node *)malloc(sizeof(struct hash_table_node));
    node->e = e;
    node->next = NULL;

    node->next = table->slots[e.hash % table->size];
    table->slots[e.hash % table->size] = node;
    return ;

}

struct element hash_table_get(struct hash_table *table,int key)
{
    struct hash_table_node *node=NULL;
    struct element e;
    node = table->slots[(key*3)%table->size];
    while(node!=NULL)
    {
        if (node->e.key == key) return node->e;
        node = node->next;
    }
    e.key=e.hash=-1;
    strcpy(e.value,"NULL");
    return e;

}

boolean hash_table_remove(struct hash_table *table,int key)
{
    struct hash_table_node *p=NULL;
    struct hash_table_node *node=NULL;

    node = table->slots[(key*3)%table->size];

    if(node->e.key == key)
    {
        table->slots[(key*3)%table->size]=node->next;
        free(node);
        return TRUE;
    }

    p = node->next;
    while(p!=NULL)
    {
        if(p->e.key == key)
        {
            node->next = p->next;
            free(p);
            return TRUE;
        }
        node=node->next;
        p = p->next;
    }
    return FALSE;
}




void menu(struct hash_table *table,struct element *ele)
{
    int n;

while(1){
        system("cls");
    printf("���ù�ϣ���������\n");
    printf("------------------------�ƿ�һ��----------------------------\n");
    printf("\t1.���ѧ����Ϣ     \t2.�޸�ѧ����Ϣ\n");
    printf("\t3.��ѯѧ����Ϣ     \t4.ɾ��ѧ����Ϣ\n");
    printf("\t5.��ӡ����ѧ����Ϣ \t6.��ѯѧ������\n");
    printf("\t7.��ձ�         \t8.���Ƿ�Ϊ��\n");
    printf("\t0.�˳�\n");
    printf("------------------------------------------------------------\n");

    printf("������ѡ�");


scanf("%d",&n);
    switch(n)
    {
    case 1:add(table,ele);

        break;
    case 2:MOdify(table,ele);
        break;
    case 3:Query(table,ele);
        break;
    case 4:Delete(table,ele);
        break;
    case 5:Print_List(table,ele);
            break;
    case 6:printf("����ѧ��������%d\n",table->count);break;
    case 7:hash_table_clear(table,ele);printf("����ճɹ���\n");break;
    case 8:if(!hash_table_isempty(table))printf("������\n");
           else printf("��Ϊ�գ�\n");
           break;
    case 0:exit(0);
    default :
        printf("��������\n");
        }
        getchar();
        getchar();
    }
    return ;

}

void Delete(struct hash_table *table,struct element *ele){
    int key;
    VaType name;
    struct element etest;
    printf("������ѧ�� �� ��λ��");
    scanf("%d",&key);
    strcpy(name,ele[key].value);
    etest = hash_table_get(table,key);
    if(etest.key!=-1){
    hash_table_remove(table,ele[key].key);
    printf("ɾ��ѧ��%s��Ϣ�ɹ���\n",name);
    ele[key].key=-1;

    table->count--;
    }else
        printf("���棺��ѧ����Ϣ������\n");
}



void add(struct hash_table *table,struct element *ele)
{
    int i,j,k,n;
    int num,value;
    struct element etest;
    //ele={1,"���ͺ�",10};
    /*
    printf("�������ѧ����ѧ�ź���λ:\n");
    scanf("%d",&num);
    if(num>50){
        printf("���棺һ���༶�������50���ˣ�\n");
    }else{
    ele[num].key = num;
    etest = hash_table_get(table,ele[num].key);
    if(etest.key!=-1){
    printf("��ѧ���Ѿ����ڣ�\n");
    }else{
    hash_code(&ele[num]);//[num]
    */
    printf("�������ѧ��������\n");
    num = table->count+3;

    scanf("%s",&ele[++num].value);//[num]
    ele[num].key=num;
    hash_table_put(table,ele[num]);//[num]
            if(table->count>=10)
                printf("��Ϣ���£�\t\nѧ�ţ�B2010403021%d\t������%s\t\n",ele[num].key,ele[num].value);
            else
                printf("��Ϣ���£�\t\nѧ�ţ�B20104030210%d\t������%s\t\n",ele[num].key,ele[num].value);
    printf("¼����Ϣ�ɹ���");
    table->count++;

    //}
    return ;






/*
    ele[0].key=1;
    strcpy(ele[0].value,"���ͺ�");

    ele[1].key=10;
    strcpy(ele[1].value,"��λ��");

    struct element ele2;


    //printf("������ؼ���");
    // for(i=0;i<)

    hash_code(&ele[0]);
    hash_code(&ele[1]);


    hash_table_put(table,ele[0]);
    hash_table_put(table,ele[1]);
    ele2=hash_table_get(table,10);
    //table->slots[ele->key]
    printf("key:%d\nvalue:%s\nhash:%d\n",ele2.key,ele2.value,ele2.hash);

    hash_table_free(table);

*/

}


void MOdify(struct hash_table *table,struct element *ele){
    int i,j,num,n,newNum;
    VaType newName;//������
    struct element eget;
    printf("��������Ҫ�޸ĵ�ѧ����ѧ�ź���λ��");
    scanf("%d",&num);
    if(num<=50){
    eget = hash_table_get(table,ele[num].key);
    if(eget.key==-1){
        printf("��ѧ����Ϣ��������\n");
    }
    else{
            //printf("�޸ĸ�����ѧ�������� ��1�������������롱2��,һ���޸������롱3��:");
            //scanf("%d",&n);
            /*if(n==1){
                printf("�������µĺ���λѧ�ţ�");
                scanf("%d",&newNum);
                ele[newNum].key=newNum;
                strcpy(ele[newNum].value,eget.value);
                if(num!=newNum)
                    hash_table_remove(table,table->slots[eget.key]);
                printf("�޸�ѧ�ųɹ�.\n");
            }*/
           // else if(n==2){

                printf("�������µ�������");
                scanf("%s",&newName);
                strcpy(ele[num].value,newName);
                hash_table_put(table,ele[num]);
                printf("�޸������ɹ�.\n");
            //}
            /*
            else if(n==3){
                printf("�������µĺ���λѧ�ţ�");
                scanf("%d",&newNum);
                ele[newNum].key=newNum;
                //strcpy(ele[newNum].value,eget.value);

                printf("�޸�ѧ�ųɹ�.\n");

                 printf("�������µ�������");
                scanf("%s",&newName);
                strcpy(ele[newNum].value,newName);

                printf("�޸������ɹ�.\n");
                if(num!=newNum)
                    hash_table_remove(table,eget.key);

            }*/
            //else printf("���棺�������\n");
        }
    }else
        printf("���棺��ע�������ѧ�Ų�Ҫ����50��\n");
}



void Query(struct hash_table *table,struct element *ele){
    int i,j,k,num,value;
    struct element eget;
    printf("������ѧ�ź���λ��");
    scanf("%d",&num);
    eget = hash_table_get(table,ele[num].key);//[num]
    if(ele[num].key==-1||eget.key>50){
        printf("��ѧ��������\n");
    }
    else{
            if(eget.key>=10)
                printf("��Ϣ���£�\t\nѧ�ţ�B2010403021%d\t������%s\t\n",eget.key,eget.value);
            else
                printf("��Ϣ���£�\t\nѧ�ţ�B20104030210%d\t������%s\t\n",eget.key,eget.value);
    }

}


void AutoInit(struct hash_table *table,struct element *ele){
    int i;
    for(i=1;i<=35;i++){
    if(i==2||i==18||i==24)
        continue;
        ele[i].key=i;
        table->count++;
    }
    strcpy(ele[1].value,"ë��");strcpy(ele[3].value,"������");
    strcpy(ele[4].value,"�ܴ���");strcpy(ele[5].value,"�Ž�ѫ");
    strcpy(ele[6].value,"ʯ�߷�");strcpy(ele[7].value,"�ƴ���");
    strcpy(ele[8].value,"����");strcpy(ele[9].value,"ŷ������");
    strcpy(ele[10].value,"����");strcpy(ele[11].value,"������");
    strcpy(ele[12].value,"������");strcpy(ele[13].value,"ʷϰ��");
    strcpy(ele[14].value,"ŷ������");strcpy(ele[15].value,"����");
    strcpy(ele[16].value,"����ƽ");strcpy(ele[17].value,"������");
    strcpy(ele[19].value,"����Ϊ");strcpy(ele[20].value,"��ɺ");
    strcpy(ele[21].value,"������");strcpy(ele[22].value,"������");
    strcpy(ele[23].value,"������");strcpy(ele[25].value,"���й�");
    strcpy(ele[26].value,"����ܿ");strcpy(ele[27].value,"�ֱ�");
    strcpy(ele[28].value,"Ҷ����");strcpy(ele[29].value,"���غ�");
    strcpy(ele[30].value,"��ΰ��");strcpy(ele[31].value,"���彭");
    strcpy(ele[32].value,"���ǻ�");strcpy(ele[33].value,"����ï");
    strcpy(ele[34].value,"���");strcpy(ele[35].value,"������");
 for(i=1;i<=35;i++){
    if(i==2||i==18||i==24)
        continue;
    hash_code(&ele[i]);
    hash_table_put(table,ele[i]);
 }

}
void Print_List(struct hash_table *table,struct element *ele){
    int i,j;
   if(!hash_table_isempty(table)){
    printf("ѧ��\t\t\t����\n\n");
    for(i=1;i<=table->count+3;i++){
            if(i==2||i==18||i==24)
                continue;
        if(ele[i].key!=-1&&ele[i].key<=50){
            if(ele[i].key>=10)
                printf("B2010403021%d\t\t%s\n",ele[i].key,ele[i].value);
            else
                printf("B20104030210%d\t\t%s\n",ele[i].key,ele[i].value);
        } else
            continue;
    }
   }else
    printf("��Ϊ�գ�\n");
}

int main()
{
     struct hash_table *table = NULL;
     struct element ele[51];
     table = hash_table_init();
    AutoInit(table,ele);
    menu(table,ele);
    return 0;
}
