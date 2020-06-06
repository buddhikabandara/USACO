/*
ID: bandara2
LANG: C++
TASK: dualpal
*/
#include<bits/stdc++.h>
using namespace std;
bool check(int num);
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
    freopen("dualpal.in","r",stdin);
    freopen("dualpal.out","w",stdout);
    int n,s;
    cin>>n>>s;
    int counter=0;
    int i=0;
    while(counter<n)
    {
        i++;
        if(check(s+i))
        {
            counter++;
            cout<<s+i<<endl;
        }
    }

}
bool check(int num)
{
    int c = 0;
    string temp,rev;
    for(int i=2;i<11;i++)
    {
        temp = tobase(num,i);
        rev = temp;
        reverse(rev.begin(),rev.end());
        if(temp == rev)
        {
            //cout<<temp<<"  "<<rev<<" "<<i<<endl;
            c++;
        }
        if(c>1) return 1;


    }return 0;
}
