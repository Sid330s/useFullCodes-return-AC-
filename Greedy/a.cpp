#include <bits/stdc++.h>
using namespace std;
long long int n, m, hospitals,a,b,c;
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    long long int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<vector<pair<long long int, long long int> > > graph(n + 1);
        for (long long int i = 0; i < m; i++) {
            cin >> a >> b >> c;
            graph[a].push_back({b, c});
            graph[b].push_back({a, c});
        }
        cin >> hospitals;
        vector<long long int> dis(n + 1);
        for (long long int i = 0; i <= n; i++) dis[i] = 1e17;
        long long int hos[hospitals];
        for (long long int i = 0; i < hospitals; i++) cin >> hos[i];
        set<pair<long long int, long long int> > s;
        for (long long int i = 0; i < hospitals; i++) {
            long long int h = hos[i];
            if (h <= n) dis[h] = 0;
        }
        for (long long int i = 0; i < hospitals; i++)   s.insert({dis[hos[i]], hos[i]});
        long long int vis[n + 1];
        for (long long int i = 0; i < n + 1; i++) vis[i] = 0;
        while (!s.empty()) {
            pair<long long int, long long int> cur_station = *s.begin();
            s.erase(s.begin());
            long long int diss = cur_station.first;
            long long int city = cur_station.second;
            vis[city] = 1;
            for (auto j : graph[city]) {
                if (dis[j.first] > dis[city] + j.second and !vis[j.first]) {
                    if (s.find({dis[j.first], j.first}) != s.end()) {
                        s.erase(s.find({dis[j.first], j.first}));
                    }
                    dis[j.first] = dis[city] + j.second;
                    s.insert({dis[j.first], j.first});
                }
            }
        }
        for (long long int i = 1; i <= n; i++) cout << dis[i] << " ";
        cout << endl;
    }
}
