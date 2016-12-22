#include <iostream>
#include <set>
#include <string>
#include <sstream>
using namespace std;

set<string> dict;

int main()
{
    string s,buf;//bufΪ��ʱ����
    while(cin>>s){
        if (s=="EOF"||s=="eof")
            break;

        for(int i=0;i<s.length();i++){
            //cout<<"s[i]:"<<s[i]<<endl;
            if(isalpha(s[i]))//���s[i]����ĸ
                s[i] = tolower(s[i]);
            else
                s[i] = ' ';
        }
        //��ʱ�ٰ�sɨ����
        //cout<<s<<endl;
         stringstream ss(s);
         while(ss>>buf)
            dict.insert(buf);//set��insert���Զ�����
    }
    //�õ���������
    for(set<string>::iterator it=dict.begin();it!=dict.end();it++)
        cout<<*it<<endl;

    return 0;
}
