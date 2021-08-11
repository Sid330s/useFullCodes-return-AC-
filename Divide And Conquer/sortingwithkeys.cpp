#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int arr[10000];
int keys[10000];
int n;
int main(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++) cin>>keys[i];

    int ans=0;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++)
        if(arr[i]>arr[j] && keys[i]<keys[j]) ans++;

    cout<<ans<<endl;

    return 0;
}
