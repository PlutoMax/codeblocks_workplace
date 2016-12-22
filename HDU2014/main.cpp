/*
������ִ����У���ί�������ѡ�ִ�֡�ѡ�ֵ÷ֹ���Ϊȥ��һ����߷ֺ�һ����ͷ֣�Ȼ�����ƽ���÷֣��������ĳѡ�ֵĵ÷֡�


Input
���������ж��飬ÿ��ռһ�У�ÿ�еĵ�һ������n(2<n<=100)����ʾ��ί��������Ȼ����n����ί�Ĵ�֡�


Output
����ÿ���������ݣ����ѡ�ֵĵ÷֣��������2λС����ÿ�����ռһ�С�


Sample Input

3 99 98 97
4 100 99 98 97



Sample Output

98.00
98.50



Author
lcy
*/
#include <iostream>
#include<cstdio>
using namespace std;

int main()
{
    int n,t;

    while(scanf("%d",&n)!=-1){
        int num[100];//OJ�������ñ�����������
        double sum = 0;
        for(int i = 0;i < n;i++){
            num[i]=0;
            scanf("%d",&t);
            num[i]=t;
        }
        //ð������
        for(int i = 0;i<n-1;i++)
            for(int j = 0;j<n-i-1;j++){
                if(num[j]>num[j+1])
                    swap(num[j],num[j+1]);
            }
        //�����
        for(int i = 1;i<n-1;i++){
            sum += num[i];
        }
        printf("%.2lf\n",sum/(n-2));
    }
    return 0;
}
