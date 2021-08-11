#include <bits/stdc++.h>
using namespace std;

long long int binarySearch(long long int arr[], long long int l, long long int r, long long int x)
{
    if (r >= l) {
        long long int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}
int main() {
    long long int i, t, n, g, l, r, mid, ans,x,min_ans;
    cin >> t;
    while(t--){
        cin >> n;
        long long int v[n], ls[n+1], rs[n+1];
        for(i=0;i<n;i++) cin >>  v[i];
        cin >> g;
        ls[0] = rs[0] = 0;
        for(i=0;i<n;i++){
            ls[i+1] = ls[i] + v[i];
            rs[i+1] = rs[i] + v[n-i-1];
        }

        min_ans=n+1;
        for(i=0;i<=n;i++){
            x = g-ls[i];
            ans=binarySearch(rs,0,n,x)+i;
            if(ans!=-1) min_ans=min(ans,min_ans);
        }

        min_ans=min_ans%(n+1);
        cout << min_ans << "\n";
    }
    return 0;
}
/*
2
10
2 3 2 5 7 8 2 3 1 1
7
6
5 2 1 4 6 3
2


*/
