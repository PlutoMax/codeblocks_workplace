#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

map<string,int> cnt;
vector<string> words;


string repr(const string& s){
    string ans = s;//������ԭ�ļ�
    for(int i=0;i<ans.length();i++)
        ans[i] = tolower(ans[i]);
    sort(ans.begin(),ans.end());
    return ans;
}

int main()
{
    string s;
    while(cin>>s){
        if(s[0]=='#')
            break;
        //�ȱ���һ������
    words.push_back(s);
    string r = repr(s);//�������

    if(!cnt.count(r))//��������ڸ�Կ��
        cnt[r]=0;
    cnt[r]++;//������++
    }
    vector<string> save;
    set<string> words02;
    for(int i=0;i<words.size();i++){
       // cout<<words[i]<<endl;//ords[i]�д洢ÿ������ĵ���
       if(cnt[repr(words[i])]==1) //save.push_back(words[i]);//����������� (���Һ󲻴���) �ʹ��vector
            words02.insert(words[i]);
    }
   // sort(save.begin(),save.end());
    //for(int i=0;i<save.size();i++)
     //   cout<<save[i]<<endl;
     for(set<string>::iterator it=words02.begin();it!=words02.end();it++)
        cout<<*it<<endl;

    return 0;
}
