#include<bits/stdc++.h>
using namespace std;

int parent[1000];


void make(int n){
    parent[n]=n;

}

int findp(int n)
{
    if(parent[n]==n)return n;
    return findp(parent[n]);
}

void uniond(int v,int u)
{
    v = findp(v);
    u = findp(u);

    if(u==v)return;
    parent[v]=u;
}

int main()
{
    int v,e;
    for(int i=0; i<100; i++){
            parent[i]=i;
    }

    vector<pair< int, pair<int,int>>>edges;

    cin >> v >> e;

    for(int i=1; i<=e; i++)
    {
        int w,uu,vv;
        cin >> uu>> vv>> w;
        edges.push_back({w,{uu,vv}});
    }
    int cost=0;

    sort(edges.begin(),edges.end());
    cout<<"weight " <<" "<<"source "<<" "<<"destination"<<endl;
    for(auto i :edges){
        cout<<i.first<<"         ";
        cout<<i.second.first<<"          " ;
        cout<<i.second.second<<"          ";
        cout<<endl<<"____________________________________\n"<<endl;
    }
    for(auto i:edges)
    {
        int u,v,w;
        w = i.first;
        v = i.second.first;
        u = i.second.second;

        if(findp(u)!=findp(v))
        {
            uniond(u,v);
            cout<<u<<" "<<v<<endl;
            cost+=w;
        }
    }
    cout<<cost<<endl;
}
/*
6 9
5 4 9
1 4 1
5 1 4
4 3 5
4 2 5
1 2 2
3 2 3
3 6 8
2 6 7
*/

