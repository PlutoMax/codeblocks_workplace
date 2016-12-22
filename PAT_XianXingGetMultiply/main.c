
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max 100
//��ɢ�б�Ľ�
typedef struct Polynomial{
    int date[Max+1];
    int highPower;
}*Poly;

//��ʼ��
void initList(Poly poly){

    //poly->highPower=0;//��߽׳�ʼ��Ϊ0
    int coef,exp;//coefϵ�� expָ��
    //scanf("%d%d",&coef,&exp);
   // poly->date[exp]=coef;
   // poly->highPower=exp;//������ָ��

    while(scanf("%d%d",&coef,&exp),exp){
          if(exp>poly->highPower)
                poly->highPower=exp;
          poly->date[exp]=coef;//ָ����¼ϵ��
    }
    return ;
}

//���ٿ���һ�����洢
void derivPoly(Poly poly,Poly retPoly){//���������ṹ��ָ�� ����retPoly���¿���һ����� �������Ԫ����
        int i;
        if(poly->highPower)
            retPoly->highPower=poly->highPower-1;//��¼���󵽺�����ָ��
        for(i=1;i<=poly->highPower;i++){
            if(poly->date[i])
                retPoly->date[i-1]=i * poly->date[i];
        }
}

void print(Poly poly){
    int i;
    if(poly->highPower==0&&poly->date[0]==0)
        printf("0 0");
    for(i=poly->highPower;i>=0;i--){
        if(poly->date[i]){
        if(i!=poly->highPower)
            printf(" ");
        printf("%d %d",poly->date[i],i);
    }
    }
}

int main()
{
    while(1){
    Poly poly;

    poly=(Poly)malloc(sizeof(struct Polynomial));
     memset(poly->date,0,Max);//��ʼ��Ϊ0���ٿռ����ܳ�ʼ��
    poly->highPower=0;

    initList(poly);
    Poly retPoly=(Poly)malloc(sizeof(struct Polynomial));
    memset(retPoly->date,0,Max);//��ʼ��Ϊ0
    retPoly->highPower=0;

    derivPoly(poly,retPoly);
    print(retPoly);
    printf("\n");
    free(poly);
    free(retPoly);
  }
    return 0;
}



/*
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
typedef struct Polynomial{
	int data[MAX + 1];
	int highPower;
}*Poly;

void ZeroPoly(Poly poly) {	//������ϵ����0
    int i;
	for( i = 0; i < MAX; i++)
		poly->data[i] = 0;
	poly->highPower = 0;
}
void InitPoly(Poly poly) {		//���������ʽ��Ƶĳ�ʼ������ʽ����
	int coef, exp;
	scanf("%d%d", &coef, &exp);
	poly->data[exp] = coef;
	poly->highPower = exp;
	while(scanf("%d%d", &coef, &exp) != EOF){
		poly->data[exp] = coef;
	}
}
void DerivPoly(Poly poly, Poly retPoly) {	//��
    int i;
	if(poly->highPower)
		retPoly->highPower = poly->highPower - 1;
	for(i = 1; i <= poly->highPower; i++)
		if(poly->data[i]) {
			retPoly->data[i - 1] = i * poly->data[i];
		}
}
void Print(Poly poly) {
    int i;
	if(poly->highPower == 0 && poly->data[0] == 0)
		printf("0 0");
	for(i = poly->highPower; i >= 0; i--) {
		if(poly->data[i]) {
			if(i != poly->highPower)
				printf(" ");
			printf("%d %d", poly->data[i], i);
		}
	}
}
int main() {
	Poly poly = (Poly)malloc(sizeof(struct Polynomial));
	ZeroPoly(poly);
	InitPoly(poly);		//��������
	Poly retPoly = (Poly)malloc(sizeof(struct Polynomial));
	ZeroPoly(retPoly);
	DerivPoly(poly, retPoly);	//��
	Print(retPoly);		//������
	free(poly);
	free(retPoly);

	return 0;
}
*/
