#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>

using namespace std;

int main()
{
   map <string,int>colorBall;
   int maxV,n;
   string maxColor,color;
   printf("������������Ŀ(��������Ӣ��)��\n");
   while(cin>>n,n){//scanf("%d",&n)!=-1
        colorBall.clear();
        for(int i=0;i<n;i++){
        //scanf("%s",&color);
        cin>>color;

        colorBall[color]++;//ͳ����������
    }
    map<string,int>::iterator it;//���������
    maxV=0;
    for(it=colorBall.begin();it!=colorBall.end();it++)
        if(it->second>maxV){
            maxV=it->second;
            maxColor=it->first;
        }
    //cout<<maxColor;
     cout<<maxColor<<"��ɫ���������"<<maxV<<"��"<<endl;
     cout<<"����ֻ����������ż��ͬ�����ȿ��ǵ�һ�ֳ��ֵĽ��";
   }
    return 0;
}
