/*
����һ�����ڣ������������Ǹ���ĵڼ��졣


Input
���������ж��飬ÿ��ռһ�У����ݸ�ʽΪYYYY/MM/DD��ɣ�
����μ�sample input ,���⣬��������ȷ�����е����������ǺϷ��ġ�


Output
����ÿ���������ݣ����һ�У���ʾ�������Ǹ���ĵڼ��졣

Sample Input

1985/1/20
2006/3/12



Sample Output

20
71

if(year%400 == 0 || year%100 != 0 && year % 4 == 0)������
*/
#include <iostream>
#include<cstdio>
#include<cstring>
//#include<string.h>
using namespace std;

int is_runYear(int year){
    if(year%400 == 0|| year %100 !=0 && year % 4 == 0)//����366
        return true;
    else
        return false;
}
int main()
{
int year,mon,day;
int monA[]={1,3,5,7,8,10,12};
int monB[]={4,6,9,11};
while(scanf("%d/%d/%d/",&year,&mon,&day)!=-1){
        int count=0;

               count += day;

                for(int i = 1;i<mon;i++){
                        if(i==2) {
                            if(is_runYear(year))
                                count += 29;
                            else
                                count +=28;
                        }
                        for(int j=0;j<7;j++){
                            if(i==monA[j])
                                count += 31;
                        }
                        for(int j = 0;j<4;j++){
                            if(i==monB[j])
                                count += 30;
                        }

                    }

     printf("%d\n",count);
}

    return 0;
}
