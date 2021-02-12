#include<bits/stdc++.h>
using namespace std;
#define in(n) scanf("%d",&n);
#define lin(n) scanf("%lld",&n);
#define ll long long
int main(){
int t,c=1;
cin>>t;
while(t--){

    int n,m ,i,j,tot=0;

    cin>>n;

    ll arr[n];

    for(i=0;i<n;++i)cin>>arr[i];

    sort(arr,arr+n);
    
    //i=0;j=1;

  for(i=0;i<n-2;++i){

  for(j=i+1;j<n-1;++j){
        ll l=j+1,r=n;
        while(l<=r){
          ll mid=(l+r)/2;
          if(arr[mid]<arr[i]+arr[j])l=mid+1;
          else r=mid-1;
        }
      --l;
      l-=j;
      if(l>0)tot+=l;

  }
}

  cout<<"Case "<<c<<": "<<tot<<"\n";

  ++c;

}
  return 0;
}
