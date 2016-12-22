/*
Problem Description
����ʽ���������£�
1 - 1/2 + 1/3 - 1/4 + 1/5 - 1/6 + ...
������������ö���ʽ��ǰn��ĺ͡�


Input
����������2����ɣ�������һ��������m��m<100������ʾ����ʵ���ĸ������ڶ��а���m��������������ÿһ������(������Ϊn,n<1000������ö���ʽ��ǰn��ĺ͡�


Output
����ÿ������ʵ��n��Ҫ���������ʽǰn��ĺ͡�ÿ������ʵ�������ռһ�У��������2λС����


Sample Input

2
1 2



Sample Output

1.00
0.50



Author
lcy

*/
#include <iostream>
#include<cstdio>
using namespace std;

int main()
{
    int m,n;
    //int t;
    while(scanf("%d",&m)!=-1){

        for(int i = 0;i < m; i++){
            double sum = 0;
            scanf("%d",&n);
            for(int j = 1;j <= n;j++){//һ��ע���ڲ�ѭ�������⣡
                if(j%2!=0)
                    sum +=1.0/j;
                else
                    sum -= 1.0/j;
            }
            printf("%.2lf\n",sum);
        }
    }
    //cout << "Hello world!" << endl;
    return 0;
}
