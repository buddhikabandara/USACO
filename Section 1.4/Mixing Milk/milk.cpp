/*
ID: bandara2
TASK: milk
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("milk.in","r",stdin);
    freopen("milk.out","w",stdout);
    int need,m,t1,t2,cost=0;

    pair<int,int> lastfarmer;
    cin>>need>>m;
    int needMore = need;
    vector<pair<int,int>> farmers;  // first-> unit price  | second -> amount
    for(int i=0;i<m;i++)
    {
        cin>>t1>>t2;
        farmers.push_back(make_pair(t1,t2));

    }
    sort(farmers.begin(),farmers.end()); // sort by pair.first (unit price)
    reverse(farmers.begin(),farmers.end());
    while(needMore>0)
    {
        cost += farmers.back().first*farmers.back().second;
        needMore-= farmers.back().second;
        lastfarmer = farmers.back();
        farmers.pop_back();


    }
    if(needMore<0)cost+= needMore*lastfarmer.first;
    cout<<cost<<endl;
    return 0;



}
