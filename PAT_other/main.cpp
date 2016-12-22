
/*
#include <stdio.h>
int main() {
	int coef, exp;
	int flag = 0; 	// ����Ƿ���Ҫ�ո�
	char ch;
	do {
		scanf("%d%d", &coef, &exp);
		ch = getchar();
		if (exp) {			// ���Գ�����
			if (flag)
				printf(" ");
	 		printf("%d %d", coef * exp, exp - 1);
	 		flag = 1;
		}
	}while (ch != '\n');
	//���ֻ�г�������0 0
	if (flag == 0)
		printf("0 0");

	return 0;
}
*/


#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
typedef struct Polynomial{
	int data[MAX + 1];
	int highPower;
}*Poly;
void ZeroPoly(Poly poly) {	//������ϵ����0
	for(int i = 0; i < MAX; i++)
		poly->data[i] = 0;
	poly->highPower = 0;
}
void InitPoly(Poly poly) {		//���������ʽ��Ƶĳ�ʼ������ʽ����
	int coef, exp;
	scanf("%d%d", &coef, &exp);
	poly->data[exp] = coef;
	poly->highPower = exp;
	while(scanf("%d%d", &coef, &exp)!= EOF){
		poly->data[exp] = coef;
	}
}
void DerivPoly(Poly poly, Poly retPoly) {	//��
	if(poly->highPower)
		retPoly->highPower = poly->highPower - 1;
	for(int i = 1; i <= poly->highPower; i++)
		if(poly->data[i]) {
			retPoly->data[i - 1] = i * poly->data[i];
		}
}
void Print(Poly poly) {
	if(poly->highPower == 0 && poly->data[0] == 0)
		printf("0 0");
	for(int i = poly->highPower; i >= 0; i--) {
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

