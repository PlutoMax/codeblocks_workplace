//Ͱ���� ע���ʼ��Ϊ0
#include <iostream>
#include <cstdio>
#include <cstring>
//#define Max 9999
using namespace std;
//��ʱ��������
int main()
{
    int a[11],t;//����һ��Ҫ��λ
    memset(a,0,sizeof(a));//��ʼ��a
    for(int i=0;i<5;i++){
        scanf("%d",&t);
        //t+=Max;
        a[t]++;
    }

    for(int i=0;i<=10;i++)
        for(int j=1;j<=a[i];j++)
                printf("%d ",i);
        //getchar();getchar();

    return 0;
}
