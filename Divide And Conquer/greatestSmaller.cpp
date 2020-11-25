#include<bits/stdc++.h>
using namespace std;
int t,a[100005],n,key;
int greatestlesser(int low, int high, int key)
{
    int ans = -1;
    while (low <= high) {
        int mid = low + (high - low + 1) / 2;
        int midVal = a[mid];
        if (midVal < key) ans = mid,low = mid + 1;
        else if (midVal > key) high = mid - 1;
        else if (midVal == key) high = mid - 1;
    }
    return ans;
}
int contains(int low, int high, int key)
{
    int ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int midVal = a[mid];
        if (midVal < key) low = mid + 1;
        else if (midVal > key) high = mid - 1;
        else if (midVal == key) {
            ans = mid;
            break;
        }
    }

    return ans;
}

int main(){
   cin>>n;
   for(int i=0;i<n;i++) cin>>a[i];
   cin>>t;
   while(t--){
     cin>>key;
     cout<<greatestlesser(0,n-1,key)<<endl;
     cout<<contains(0,n-1,key)<<endl;
   }
}
