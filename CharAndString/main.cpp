#include <iostream>
#include <stdio.h>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    /*
    //<stdio.h>��sprintf����(s,%d,n) n����%d�ĸ�ʽת����s
    int n = 100000;
    char s[10];
    sprintf(s,"%d",n);
    //���׷�����������sprintf(s,"%f",n);
    puts(s);
    */


    //<sstream>����
    string result = "10000",result2="100 001";
    int n = 0,n2=0;
    stringstream stream(result);
    stringstream stream2(result2);//�Կո񻺳� ��Ҫ������� ����ѭ��
    stream>>n;

    cout<<"n:"<<n<<endl;

    //stream2>>n2;
    //cout<<"n2:"<<n2<<endl;
    //�����100
    cout<<"n2:";
    while(stream2>>n2)
        cout<<n2;



    return 0;
}
