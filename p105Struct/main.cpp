#include <iostream>
#include <stdio.h>

using namespace std;

struct Point{
    int x,y;
    Point(int x=0,int y=0):x(x),y(y){}// == {this->x=x;this->y=y;}
    void test(int t){//this->t=t;
    printf("�����õ���%d\n",t);
    }
};


Point operator - (const Point &A,const Point &B){//operator ������ ��ʾҪ�ض��������
    return Point(A.x+B.x,A.y+B.y);
}//���԰ѡ�-����ɡ�+���Ĺ���

//������������Ҫƥ�� ��
ostream& operator << (ostream &out,const Point &p){
out<<"��"<<p.x <<","<<p.y<<"��";
return out;
}


int main()
{
    Point a,b(1,2);//a=1,b=2;
    //==�ֱ������Piont()��point(1,2);
    a.x = 3;
    cout<<a-b<<"\n";
    a.test(20);
    return 0;
}






