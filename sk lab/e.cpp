#include<bits/stdc++.h>
using namespace std;
long long int n,ans;
string str1,str2;
bool isRequired[26]={false};
int main(){
    cin>>n>>d;
    ans=0;
    for(int i=n-1;i>=0;i--) isRequired[str2[i]-'a']=false,isRequired[str1[i]-'A']=true;
    for(int i=0;i<=25;i++) if(isRequired[i]) ans++;
    cout<<ans<<endl;
    return 0;
}
