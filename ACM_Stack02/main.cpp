//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <stack>
#include <map>
#include <list>
//#include <stdafx.h>

using namespace std;

//vector��װ���飬list��װ������map��set��װ�˶�������

typedef set<int> Set;
map<Set,int> IDcache;//�Ѽ���ӳ���ID
vector<Set> Setcache;//����IDȡ����

//����ָ������x��ID.����Ҳ���������һ���µ�ID


int ID (Set x){
    //����set���� count�������ж��Ƿ����ĳ��Ԫ�ء���Ϊset��Ԫ�ز��ظ���count���ֻ����1��0.
    if(IDcache.count(x)) return IDcache[x];
    Setcache.push_back(x); //����¼��ϡ�
    return IDcache[x] = Setcache.size() - 1;
}

#define ALL(X) x.begin(),x.end()
#define INS(X) inserter(x,x.begin())
int main()
{
    stack<int>s;
    int n;
    cout<<"n:";
    cin>>n;
    for(int i = 0;i < n;i++){
        string op;
        cout<<"op�ַ���:";
        cin>>op;
        if(op[0] == 'p') s.push(ID(Set()));//
        else if(op[0] == 'D') s.push(s.top());
        else{
            Set x1 = Setcache[s.top()];s.pop();
            Set x2 = Setcache[s.top()];s.pop();

            Set x;
           // if(op[0]=='U') set_union (ALL(x1),ALL(x2),INS(x));
            //if(op[0]=='I') set_intersection (ALL(x1),ALL(x2),INS(x));
            //if(op[0]=='A') {x = x2;x.insert(ID(x1));}
            s.push(ID(x));
        }
        cout<<Setcache[s.top()].size() <<endl;
    }
    return 0;
}
