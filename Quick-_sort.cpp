#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define size 50000
int ar[size];
int partition(int ar[], int start, int end)
{

    int pivot = ar[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (ar[i] <= pivot)
            count++;
    }
    int pivotIndex = start + count;
    swap(ar[pivotIndex], ar[start]);
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex) {

        while (ar[i] <= pivot) {
            i++;
        }

        while (ar[j] > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            swap(ar[i++], ar[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(int ar[], int start, int end)
{

    if (start >= end)
        return;
    int p = partition(ar, start, end);
    quickSort(ar, start, p - 1);
    quickSort(ar, p + 1, end);
}
int main()
{
    int n=50000;
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
     quickSort(ar, 0, n - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds> ( stop - start );
    cout<<endl;
    cout<<"Time is millisecond: "<<duration.count()<<endl;
}
