/*
��һ������Ϊn(n<=100)�����У������ж���Ϊ��2��ʼ�ĵ�������ż��������Ҫ���㰴��˳��ÿm�������һ��ƽ��ֵ����������m��������ʵ��������ƽ��ֵ����������ƽ��ֵ���С�


Input
���������ж��飬ÿ��ռһ�У���������������n��m��n��m�ĺ�������������


Output
����ÿ���������ݣ����һ��ƽ��ֵ���У�ÿ�����ռһ�С�


Sample Input

3 2
4 2



Sample Output

3 6
3 7
ע�⣺1.�����������пո�
      2.�����ʵ�ʼ����ж������������Щ����ƽ������
*/
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
   int n,m;
   while(scanf("%d%d",&n,&m)!=-1){
        int num[100];
        int all=0,t=0,i2=0,test=0;
    for(int i=0;i<n;i++){
            t += 2;
            num[i]=t;
            all += num[i];
    }
    for(int i = 0;i<n/m;i++){
            int sum=0,count=0;
        for(int j=i2;count<m;j++,i2++){
            sum +=num[j];
            count += 1;
        }
            if(test!=0){
                printf(" ");
            }
            printf("%d",sum/m);
            test++;
    }
    if(n%m==0)
        printf("\n");
    else{
        int sum2=0;
        for(int i=i2;i<n;i++) sum2 += num[i];
        printf(" %d\n",sum2/(n-i2));
        }
   }
    return 0;
}
