#include<bits/stdc++.h>
using namespace std;
char arr[200005];
char str1[200005];
char str2[200005];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin>>t;
  while(t--){
    int n;
    scanf("%d",&n);
    scanf("%s",arr);
    bool flag = true;
    int temp;
    int cnt1=0;
    for(int i=0;i<n;i++) cnt1+=(arr[i]=='1');
    if(cnt1%2==1 || arr[0]!='1' || arr[n-1]!='1' ) printf("NO\n");
    else{
      temp=0;
      int i;
      for(i=0;i<n;i++){
        if(arr[i]=='1' && temp<cnt1/2) {
          str1[i]='(';
          str2[i]='(';
          temp++;
        }
        else if(arr[i]=='1'){
          str1[i]=')';
          str2[i]=')';
        }
        else{
          if(flag){
            str1[i]='(';
            str2[i]=')';
          }
          else{
            str1[i]=')';
            str2[i]='(';
          }
          flag=flag^true;
        }

      }
      str1[i]='\0';
      str2[i]='\0';
      printf("YES\n");
      printf("%s\n",str1);
      printf("%s\n",str2);
    }
 }
  return 0;
}
