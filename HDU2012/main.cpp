/*
���ڱ��ʽn^2+n+41����n�ڣ�x,y����Χ��ȡ����ֵʱ������x,y��(-39<=x<y<=50)���ж��ñ��ʽ��ֵ�Ƿ�Ϊ������


Input
���������ж��飬ÿ��ռһ�У�����������x��y��ɣ���x=0,y=0ʱ����ʾ������������в�������


Output
����ÿ��������Χ�ڵ�ȡֵ��������ʽ��ֵ��Ϊ�����������"OK",�����������Sorry��,ÿ�����ռһ�С�


Sample Input

0 1
0 0



Sample Output

OK



Author
lcy

*/
#include <iostream>
#include<cstdio>
using namespace std;
//��������1�����������ⲻ���������������������Ϊ������
bool is_or(int num){

    for(int i = 2;i < num; i++){
        if(num%i==0)
            return false;
    }

    return true;

}


int main()
{
    int x,y;
/*
    while(scanf("%d",&x)!=-1){
        if(is_or(x))
            printf("��������\n");
        else
            printf("����������\n");
    }
    */

    while(scanf("%d%d",&x,&y),x!=0||y!=0){
        int sum = 0;
        int count = 0;
        for(int n = x;n <= y;n++){
            sum = n*n + n + 41;
            if(is_or(sum))
                count += 1;
            else
                break;
        }
        if(count ==(y-x+1))
            printf("OK\n");
        else
            printf("Sorry\n");
    }

    return 0;
}
