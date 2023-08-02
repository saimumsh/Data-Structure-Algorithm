#include<bits/stdc++.h>
using namespace std;

int visited[1000];
int dist[1000];
int cost[1000][1000];

vector<int>v[1000];

int main()
{
    int n,e;
    cin >> n >> e;

    for(int i=1; i<=e; i++)
    {
        int x,y,w;
        cin >> x  >> y >> w;
        cost[x][y]=w;
        cost[y][x]=w;

        v[x].push_back(y);
        v[y].push_back(x);
    }

    for(int i=1; i<=n+3; i++)dist[i]=1000;

    dist[1]=0;

    set<pair<int,int>>st;
    st.insert({0,1});

    while(st.size()>0)
    {
        int nod = (*st.begin()).second;
        st.erase(st.begin());

        if(visited[nod]==0)
        {
            visited[nod]=1;
            for(int i:v[nod])
            {
                if(visited[i]==1)continue;
                if(dist[i]>dist[nod]+cost[nod][i])
                {
                    dist[i] = dist[nod]+cost[i][nod];
                    st.insert({dist[i],i});

                }
            }
        }
    }
    cout<<"\n";
    for(int i=1; i<=n ;i++)
        cout<<i<<": "<<dist[i]<<"\n";
}

