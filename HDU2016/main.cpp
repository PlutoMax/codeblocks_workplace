/*
Problem Description
����n(n<100)�������ҳ�������С��������������ǰ����������������Щ����


Input
���������ж��飬ÿ��ռһ�У�ÿ�еĿ�ʼ��һ������n����ʾ�������ʵ������ֵ�ĸ��������ž���n��������
n=0��ʾ����Ľ�������������(��������)��
 ע�⣡������������ظ���������С��Ԫ�أ�һ��Ҫ�����һ����С��Ԫ�����һ�������������� Ӧ >=(<=)

Output
����ÿ���������ݣ��������������У�ÿ�����ռһ�С�


Sample Input

4 2 1 3 4
5 5 4 3 2 1
0



Sample Output

1 2 3 4
1 4 3 2 5



Author
lcy

*/
#include <iostream>
#include<cstdio>
using namespace std;

int main()
{
    int n;
    int t;//���ڼ�¼mini����
    while(scanf("%d",&n),n!=0){
        int num[100],sta=0;
        t=0;
        for(int i = 0;i<n;i++){
            scanf("%d",&num[i]);
        }
        int mini=num[0];
        for(int i =0;i<n;i++){
            if(mini>=num[i]){
                mini = num[i];
                t = i;
            }
        }
        swap(num[t],num[0]);//��С���͵�һ��������
        //����ѭ������һ�¼���
        for(int i = 0;i<n;i++){
                if(i!=0)
                    printf(" ");
                printf("%d",num[i]);
        }
        printf("\n");
    }
    return 0;
}
