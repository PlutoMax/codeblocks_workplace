#include <iostream>
#include <cstdio>
using namespace std;
void printN2(int n){
    if(n){
        printN2(n-1);
        printf("%d ",n);
    }
    return ;
}

void printN(int n){
    printf("ѭ������\n");
    for(int i=1;i<=n;i++){
        //printf("ѭ������\n");
        printf("%d%c",i,i<n?' ':'\n');
    }


    return ;
}

int main()
{
    int n;
    while(scanf("%d",&n),n){
       // printN(n);
         //printf("�ݹ����\n");
    printN2(n);
    }

    return 0;
}
