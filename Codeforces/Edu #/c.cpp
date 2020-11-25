#include<bits/stdc++.h>
using namespace std;
int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        map<int, long long int> mp;
        int sum = 0;
        mp[1] += 1;
        long long int ans = 0;
        for(int i = 0; i < n; i += 1){
            sum += s[i] - '0';
            ans=ans+mp[sum - i];
            mp[sum - i] += 1;

        }

        //for(auto [x, y] : mp) ans += y * (y - 1) / 2;
        cout << ans << "\n";
    }
    return 0;
}
