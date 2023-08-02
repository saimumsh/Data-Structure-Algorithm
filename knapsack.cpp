#include<bits/stdc++.h>
using namespace std;
float w[1000],p[1000],x[1000];

void knapsack(int m,int n)
{
    for(int i=0; i<n; i++)
    {
        int Max=i;
        for(int j=i+1; j<n; j++)
        {
            if(p[j]/w[j]>p[Max]/w[Max])
            {
                Max=j;
            }
            swap(p[Max],p[i]);
            swap(w[Max],w[i]);
        }

    }
    int i;
    int u=m;
    for( i=0; i<n; i++)
    {
        if(w[i]>u)
            break;
        x[i]=1;
        u=u-w[i];
    }
    if ( i<n)
    {
        x[i]=u/w[i];
    }
}

void profit_calculation(int n)
{
    float sum=0;
    for(int i=0; i<n; i++)
    {
        sum=sum+(x[i]*p[i]);
    }
    cout<<sum;
}
int main()
{
    int n;
    cout<<"Enter the number of item:";
    cin>>n;
    cout<<endl<<"The set of weight:";
    for(int i=0; i<n; i++)
    {
        cin>>w[i];
    }
    cout<<endl;
    cout<<endl<<"The set of profite:";
    for(int i=0; i<n; i++)
    {
        cin>>p[i];
    }
    knapsack(60,n);
    cout<<endl;
    cout<<"The set of weight of unite per profite::";
    for(int i=0; i<n; i++)
    {
        cout<<w[i]<<"  ";
    }

    cout<<endl<<"The set of profit of unite per profite::";
    for(int i=0; i<n; i++)
    {
        cout<<p[i]<<"  ";
    }
    cout<<endl<<"Total profit is:";
    profit_calculation(4);
    return 0;
}

