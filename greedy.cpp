#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int x,a,b,c;
        cin>>x>>a>>b>>c;
        int array[3];
        array[0]=a;
        array[1]=b;
        array[2]=c;
        sort(array,array+3);
        for(int i=0;i<3;i++){
            cout<<array[i]<<"  ";
        }
        cout<<endl;
        int result=(x-1)*array[0];
        result=result+array[1];
        cout<<result<<endl;
    }
return 0;
}
