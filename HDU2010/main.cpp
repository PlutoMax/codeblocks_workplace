/*
�������ʻ��ļ��ڣ�ˮ�ɻ��������������˵Ĵ�����ѧ���и�ˮ�ɻ�����������������ģ�
��ˮ�ɻ�������ָһ����λ�������ĸ�λ���ֵ������͵����䱾�����磺153=1^3+5^3+3^3��
����Ҫ�����������m��n��Χ�ڵ�ˮ�ɻ�����


Input
���������ж��飬ÿ��ռһ�У�������������m��n��100<=m<=n<=999����


Output
����ÿ������ʵ����Ҫ����������ڸ�����Χ�ڵ�ˮ�ɻ���������˵�������ˮ�ɻ���������ڵ���m,����С�ڵ���n������ж������Ҫ���С����������һ���������֮����һ���ո����;
��������ķ�Χ�ڲ�����ˮ�ɻ����������no;
ÿ������ʵ�������ռһ�С�


Sample Input

100 120
300 380



Sample Output

no
370 371



Author
*/
#include <iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
    int m,n;
    while(scanf("%d%d",&m,&n)!=-1){
            int a,b,c;
            int count = 0;
           // bool flag;
        for(int i = m;i <= n;i++){
            //flag = false;
            a=i%10;//ȡ��λ
            b=i/10%10;//ȡʮλ
            c=i/100;//ȥ��λ
            if(i==a*a*a+b*b*b+c*c*c){
                if(count!=0)
                    printf(" ");
                printf("%d",i);
                count += 1;
            }
        }
        if(count!=0)
            printf("\n");
        //if(count == 0)
        else
            printf("no\n");

    }
    //cout << "Hello world!" << endl;
    return 0;
}
