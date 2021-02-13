#include<bits/stdc++.h>
using namespace std;
#define in(n) scanf("%d",&n);
#define lin(n) scanf("%lld",&n);
#define ll long long
 unsigned ll number_of_trailing_zeroes(unsigned ll n){
     unsigned ll cnt=0,i=2,j,cnt1=0,val=2;
     cnt+=(n/2);cnt1+=(n/5);
     while(val*i<=n){
      cnt+=(n/(val*i));
      val=val*i;
     }
     val=5;i=5;
      while(val*i<=n){
      cnt1+=(n/(val*i));
      val=val*i;
     }
     return cnt<cnt1?cnt:cnt1;
 }

int main(){
int t,c=1;
cin>>t;
while(t--){
    unsigned long long n,q,m,i,j,l,r;
    cin>>q;
bool fl=false;
    l=1,r=1000000000000000000;
  while(l<=r){
      unsigned ll mid=(l+r)/2;
      m=number_of_trailing_zeroes(mid);
     if(m==q){ i=mid;fl=true;r=mid-1;}
     else if(m<q)l=mid+1;
     else r=mid-1;
  
  }
if(fl)cout<<"Case "<<c<<": "<<i<<"\n";
else cout<<"Case "<<c<<": impossible\n";


  ++c;

}
  return 0;
}

