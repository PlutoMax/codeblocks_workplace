#include <iostream>
#include <cstdio>
#include <stdlib.h>
#define Max 1000//�ռ俪��̫СҲ��ͨ����
using namespace std;

typedef struct polyminal{
    int date[Max+1];
    int high_exp;
}*Poly;
//��ʼ��
void initList(Poly poly){
    for(int i=0;i<Max+1;i++)
        poly->date[i]=0;

    poly->high_exp=0;
        //�˴��ǶԴ������Ľ����в��� POly->date[i]���Ƕ������Ѹ��Ľ��в�����

    return;
}

//��������
void initGetValue(Poly poly){
    int coef,exp;
    while(scanf("%d%d",&coef,&exp)!=-1){
        poly->date[exp]=coef;
        if(exp>poly->high_exp)
            poly->high_exp=exp;
    }
   // return;
}

//��
void devi(Poly poly,Poly retPoly){
    if(poly->high_exp)//����䲻Ϊ��
        retPoly->high_exp=poly->high_exp-1;
    for(int i=1;i<=poly->high_exp;i++){
        //��� ���������� �������ϲ� 4 2 1
        if(poly->date[i])
            retPoly->date[i-1]=i*poly->date[i];
    }
    return;
}

//��ӡ
void print(Poly poly){
    if(poly->high_exp==0&&poly->date[0]==0)
        printf("0 0");

    for(int i=poly->high_exp;i>=0;i--){
        if(poly->date[i]){
        if(i!=poly->high_exp)
        printf(" ");
            printf("%d %d",poly->date[i],i);
        }
    }
    return;
}

int main()
{
    //while(1){
    Poly poly;
    poly=(Poly)malloc(sizeof(struct polyminal));
    initList(poly);
    initGetValue(poly);
    Poly retPoly=(Poly)malloc(sizeof(struct polyminal));

    initList(retPoly);//������ʼ��
    devi(poly,retPoly);
    print(retPoly);
    free(poly);
    free(retPoly);
    //printf("\n");
   // }
    return 0;
}
