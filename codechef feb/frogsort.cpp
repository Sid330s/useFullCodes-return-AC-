#include<bits/stdc++.h>
using namespace std;
int t,n,ans,x;
struct frog{
  int w;
  int l;
  int base_idx;
};
frog arr[100];
bool comparator(frog a, frog b)
{
    return (a.w < b.w);
}
int main()
{

    cin>>t;
    while(t--)
    {
        ans=0;
        cin>>n;
        for(int i=0;i<n;i++) cin>>arr[i].w;
        for(int i=0;i<n;i++) cin>>arr[i].l;
        for(int i=0;i<n;i++) arr[i].base_idx=i+1;
        sort(arr,arr+n,comparator);
        for(int i=1;i<n;i++)
            if(arr[i-1].base_idx>=arr[i].base_idx)
            {
                x=ceil((double)(arr[i-1].base_idx-arr[i].base_idx+1)/arr[i].l);
                arr[i].base_idx=arr[i].base_idx+x*arr[i].l;
                ans=ans+x;
            }

        cout<<ans<<endl;
    }
    return 0;
}
