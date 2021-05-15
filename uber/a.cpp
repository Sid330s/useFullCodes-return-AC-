#include <bits/stdc++.h>
using namespace std;

void build(int tree[],long long arr[],int low, int high, int index)
{
    if (low == high) tree[index]=low;
    else {
        int mid = (low + high) / 2;
        build(tree,arr, low, mid, 2 * index + 1);
        build(tree,arr, mid + 1, high, 2 * index + 2);
        if(arr[tree[2 * index + 1]] < arr[tree[2 * index + 2]]) tree[index]=tree[2 * index + 1];
        else tree[index]=tree[2 * index + 2];
      }
}

int query(int tree[],long long arr[],int index, int low,int high, int l, int r)
{
    int result =-1;
    if (r < low || high < l) return -1;
    if (l <= low && high <= r) return tree[index];
    int mid = (low + high) / 2;
    if (l > mid) return query(tree,arr, 2 * index + 2,mid + 1, high, l, r);
    if (r <= mid) return query(tree,arr, 2 * index + 1,low, mid, l, r);
    int left = query(tree,arr, 2 * index + 1,low, mid, l, r);
    int right = query(tree,arr, 2 * index + 2,mid + 1, high, l, r);
    if(arr[left] < arr[right]) result=left;
    else result=right;
    return result;
}

void preCompute(long long arr[], int n, long long pre[])
{
    pre[0] = arr[0];
    for (int i = 1; i < n; i++)
        pre[i] = arr[i] + pre[i - 1];
}


int rangeSum(int i, int j, long long pre[])
{
    if (i == 0) return pre[j];
    return pre[j] - pre[i - 1];
}

long long rec(int tree[],long long arr[],int n,long long pre[],int l, int r){
  if(l==r) return arr[l]*arr[l];
  else {
      int mid =  query(tree,arr, 0, 0, n - 1, l, r);
      long long ans = arr[mid]*rangeSum(l,r,pre);
      if(mid-1>=l) ans=max(ans,rec(tree,arr,n,pre,l, mid-1));
      if(mid+1<=r) ans=max(ans,rec(tree,arr,n,pre,mid+1, r));
      return ans;
    }
}

int main(){

  int t,n;
  cin>>t;
  while(t--){
    cin>>n;
    long long arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int tree[4 * n];
    long long pre[n];
    build(tree,arr,0, n - 1, 0);
    preCompute(arr,n, pre);
    cout<<rec(tree,arr,n,pre,0,n-1)<<endl;
  }
  return 0;
}
