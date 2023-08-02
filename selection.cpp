#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define size 10000
int ar[size];
int selection_sort(int ar[],int n)
{
    for (int i=0; i<n-1; i++)
    {
        int min_index=i;
        for(int j=i+1; j<n; j++)
        {
            if(ar[j]<ar[min_index])
            {
                min_index=j;
            }
        }
        swap(ar[i],ar[min_index]);
    }
}
int main()
{
    int n=10000;
    for(int i=1; i<=n; i++)
    {
        ar[i]=i;
    }
    for(int i=1; i<=n; i++)
    {
        cout<<ar[i]<<" ";
    }
    for(int i=1; i<=n; i++)
    {
        ar[i]=rand();
    }
    auto start = high_resolution_clock::now();
    selection_sort(ar,size);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds> ( stop - start );
    cout<<endl;
    cout<<"Time is millisecond: "<<duration.count()<<endl;
}
