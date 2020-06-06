/*
ID: bandara2
TASK: barn1
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("barn1.in","r",stdin);
    freopen("barn1.out","w",stdout);
    int m,s,c,temp;
    cin>>m>>s>>c;
    int stalls[c];
    for(int i=0;i<c;i++)
    {
        cin>>temp;
        stalls[i] = temp;
    }
    sort(stalls,stalls+c);
    vector<int> dists;
    for(int j=1;j<c;j++)
    {
        dists.push_back(stalls[j]-stalls[j-1]-1);
    }
    sort(dists.begin(),dists.end());

    int result = stalls[c-1]-stalls[0]+1;

    int boards=1;
    for(int k=1;k<m ;k++)
    {
        if(result- dists.back()<0)break;
        result-= dists.back();
        dists.pop_back();
    }
    cout<<result<<endl;
}
