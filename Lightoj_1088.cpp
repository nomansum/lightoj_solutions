#include<bits/stdc++.h>
using namespace std;
#define in(n) scanf("%d",&n);
#define lin(n) scanf("%lld",&n);
#define ll long long
 int bns(int arr[],int val,int n){
    int l=0,r=n-1;
    while(l<=r){
            int mid=(l+r)/2;
            if(arr[mid]<val)l=mid+1;
            else if(arr[mid]==val)return mid+1;
            else r=mid-1;
    }
return l;
 }

int main(){
int t,c=1;
cin>>t;
while(t--){
    int n,q,m,i,j,tot=0;
    cin>>n>>q;
    int arr[n];
    for(i=0;i<n;++i)cin>>arr[i];
      sort(arr,arr+n);
  cout<<"Case "<<c<<":\n";
  for(i=0;i<q;++i){
    int l,r;
    cin>>l>>r;
   tot=bns(arr,r,n);
  j=bns(arr,l,n);
  if(arr[j-1]==l)j--;
  if(j<0)j=0;
  cout<<tot-j<<"\n";
  }
  ++c;

}
  return 0;
}

