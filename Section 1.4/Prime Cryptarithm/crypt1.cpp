/*
ID: bandara2
TASK: crypt1
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
set<int> nums;
bool isSafe(int n,int len)
{
    string str = to_string(n);
    if(str.size()!=len)return false;
    for(int n:nums)
    {

        for(int i=0;i<len;i++)
        {
            auto it = nums.find(str[i]-'0');
            if(it==nums.end())return false;
        }
        return true;
    }
}

 int main()
 {
     freopen("crypt1.in","r",stdin);
     freopen("crypt1.out","w",stdout);
     int n,t,c=0;
     cin>>n;
     for(int x=0;x<n;x++)
     {
         cin>>t;
         nums.insert(t);
     }

     for(int i=100;i<1000;i++)
     {
         //cout<<"-";
         for(int j=10;j<100;j++)
         {
             if(isSafe(i,3)&&isSafe(j,2)&&isSafe(i*(j%10),3)&&isSafe(i*(j/10),3)&&isSafe(i*j,4)) c++;
         }
     }
     cout<<c<<endl;
 }
