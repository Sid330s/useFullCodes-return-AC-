#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,a[200005];
    cin>>t;
    while(t--)
    {
        long long int flag=0;int pos;
        unordered_map<int,int> m;
        vector<pair<int, int> > v;
        int n;
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) m[a[i]]++;

        for (auto it = m.begin(); it != m.end(); it++) v.push_back(make_pair(it->first, it->second));

        for(int i=0;i<v.size();i++)
        {
            if(v[i].second==1)
            {
                pos=v[i].first;
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            for(int i=0;i<n;i++)
            {
                if(pos==a[i])
                {
                    pos=i;
                    break;
                }
            }
            cout<<pos+1<<endl;
        }
        else cout<<-1<<endl;

    }
    return 0;
}
