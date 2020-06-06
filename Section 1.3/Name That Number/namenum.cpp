/*
ID: bandara2
LANG: C++
TASK: namenum
*/
#include<bits/stdc++.h>
using namespace std;
vector<string>dict;
string temp;
map<char,char> mp;
string conv(string name)
{
    for(int i=0;i<name.size();i++)
    {
        name[i] = mp[name[i]];
    }
    return name;
}
int main()
{
    ifstream fin("dict.txt");

    while(fin>>temp) dict.push_back(temp);
    freopen("namenum.in","r",stdin);
    freopen("namenum.out","w",stdout);
    cin>>temp;
    mp['A']=mp['B']=mp['C'] = '2';
    mp['D']=mp['E']=mp['F'] = '3';
    mp['G']=mp['H']=mp['I'] = '4';
    mp['J']=mp['K']=mp['L'] = '5';
    mp['M']=mp['N']=mp['O'] = '6';
    mp['P']=mp['R']=mp['S'] = '7';
    mp['T']=mp['U']=mp['V'] = '8';
    mp['W']=mp['X']=mp['Y'] = '9';
    int count=0;
    for(string name : dict)
    {
     if(conv(name) == temp )
     {
         cout<<name<<endl;;
         count++;
     }
    }
    if(count==0)cout<<"NONE"<<endl;
    return 0;


}
