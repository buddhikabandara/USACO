/*
ID: bandara2
LANG: C++
TASK: palsquare
*/
#include<bits/stdc++.h>
using namespace std;

inline char to_char(int c)
{
    if(c >= 10) return c - 10 + 'A';
    return c + '0';
}

string tobase(int num, int base)
{
    string ret;
    int div = base;
    while(div < num)
    div *= base;
    for(div /= base;;)
    {
        ret += to_char(num / div);
        num = num % div;
        if(div < 2) break;
        div /= base;
    }
    return ret;
}

int main()
{
    freopen("palsquare.in","r",stdin);
    freopen("palsquare.out","w",stdout);
    int b;
    cin>>b;
    string converted,rev;
    for(int i=1;i<=300;i++)
    {
        converted = tobase(i*i,b);
        rev  = converted;
        reverse(rev.begin(),rev.end());
        if(converted==rev)
        {
            cout<<tobase(i,b)<<" "<<converted<<endl;
        }
    }
}
