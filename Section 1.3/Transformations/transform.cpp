/*
ID: bandara2
LANG: C++
TASK: transform
*/
#include<bits/stdc++.h>
using namespace std;
vector<vector<bool> > turn90(vector<vector<bool> > arr);
vector<vector<bool> > turn180(vector<vector<bool> > arr);
vector<vector<bool> > turn270(vector<vector<bool> > arr);
vector<vector<bool> > reflect(vector<vector<bool> > arr);

int main()
{
    freopen("transform.in","r",stdin);
    freopen("transform.out","w",stdout);
    int n;
    cin>>n;
    string temp;
    vector<vector<bool>>first,last;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        vector<bool> tp;
        for(int j=0;j<n;j++)
        {
            if(temp[j]=='@' )tp.push_back(1);
            else tp.push_back(0);
        }
        first.push_back(tp);
    }
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        vector<bool> tp;
        for(int j=0;j<n;j++)
        {
            if(temp[j]=='@' )tp.push_back(1);
            else tp.push_back(0);
        }
        last.push_back(tp);
    }
    auto reflected = reflect(first);

    if(last == turn90(first))cout<<1;
    else if(last == turn180(first))cout<<2;
    else if(last == turn270(first))cout<<3;
    else if(last == reflect(first))cout<<4;
    else if(last == turn90(reflected))cout<<5;
    else if(last == turn180(reflected))cout<<5;
    else if(last == turn270(reflected))cout<<5;
    else if(first == last)cout<<6;
    else cout<<7;
    cout<<endl;
    return 0;

}

vector<vector<bool> >turn90(vector<vector<bool> > arr)
{
    vector<vector<bool> >temp;
    int n = arr.size();
    int ar[n][n]= {};
    for(int x = 0;x< arr.size();x++)
    {
        for(int y=0;y<arr.size();y++)
        {
            ar[y][n-1-x] = arr[x][y];
        }
    }
    for(auto x: ar)
    {

        vector<bool> tmp(x,x+n);
        temp.push_back(tmp);
    }
    return(temp);


}
vector<vector<bool> >reflect(vector<vector<bool> > arr)
{
    vector<vector<bool> >temp;
    int n = arr.size();
    int ar[n][n]= {};
    for(int x = 0;x< arr.size();x++)
    {
        for(int y=0;y<arr.size();y++)
        {
            ar[x][n-1-y] = arr[x][y];
        }
    }
    for(auto x: ar)
    {

        vector<bool> tmp(x,x+n);
        temp.push_back(tmp);
    }
    //print(temp);
    return(temp);


}
vector<vector<bool> > turn180(vector<vector<bool> > arr)
{
    return turn90(turn90(arr));
}
vector<vector<bool> >turn270(vector<vector<bool> > arr)
{
    return turn90(turn90(turn90(arr)));
}

