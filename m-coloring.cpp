#include<iostream>
using namespace std;
int G[100][100];
int x[100],n,m=3;

int nextvalue(int k)
{
    int j;
    while(1)
    {
        x[k]=(x[k]+1)%(m+1);
        if(x[k]==0)
            return 0;
        for (j=1; j<=n; j++)
        {
            if(G[k][j]!=0 && x[k]==x[j])
                break;
        }
        if (j==n+1)
            return 0;
    }

}
int mcoloring(int k)
{
    while(1)
    {
        nextvalue(k);
        if(x[k]==0)
            return 0;
        if(k==n)
        {
            for(int i=1; i<=n; i++)
            {
                cout<<x[i];
            }
            cout<<endl;
        }
        else
            mcoloring(k+1);

    }

}

int main()
{
    cout<<"Enter the value of nodes:";
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin>>G[i][j];
        }
    }
    mcoloring(1);
    return 0;
}

