#include <stdio.h>
#include <stdlib.h>

void Hanoi(int n,char x,char y,char z){
    if(n == 1)
        move (x,n,z);// == move(x,1,z);
    else{
        Hanoi(n-1,x,z,y);
        move(x,n,z);//�����ļ���n�Ƶ�z��
        Hanoi(n-1,y,x,z);
    }
}

void move(char m,int t,char n){
    printf("���Ϊ%d:%c->%c\n",t,m,n);
}

int main()
{
    int n;
    char a,b,c;
    printf("���뺺ŵ����Ŀ��");
    scanf("%d",&n);
    Hanoi(n,'a','b','c');
    return 0;
}
