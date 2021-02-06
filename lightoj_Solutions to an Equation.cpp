#include<iostream>
#define ll long long
ll find_gcd(ll a,ll b){
	while(b^=a^=b^=a%=b);return a;
}
ll gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool solution(ll a, ll b, ll c, ll &x0, ll &y0, ll &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }
    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}
void shift_solution(ll &x, ll &y, ll a, ll b, ll cnt) {
    x += cnt * b;
    y -= cnt * a;
}
ll single_solution(ll a,ll b,ll c,ll minx,ll maxx,ll miny,ll maxy){
   ll ans=0;
   if(a==0 && b!=0){
           ll tmp=c/b;
           if(tmp>=miny && tmp<=maxy && c%b==0)return maxx-minx+1;

           else return 0;
         }

   else if(a!=0 && b==0){
   	ll tmp=c/a;
           if(tmp>=minx && tmp<=maxx && c%a==0)return maxy-miny+1;
           else return 0;
        
   }
   else if(c==0)ans=(maxy-miny+1)*(maxx-minx+1);
   return ans;

}

ll all_solutions(ll a, ll b, ll c, ll minx, ll maxx, ll miny, ll maxy) {
    ll x, y, g;
    if (!solution(a, b, c, x, y, g))
        return 0;
    a /= g;
    b /= g;

    ll sign_a = a > 0 ? +1 : -1;
    ll sign_b = b > 0 ? +1 : -1;

    shift_solution(x, y, a, b, (minx - x) / b);
    if (x < minx)
        shift_solution(x, y, a, b, sign_b);
    if (x > maxx)
        return 0;
    ll lx1 = x;

    shift_solution(x, y, a, b, (maxx - x) / b);
    if (x > maxx)
        shift_solution(x, y, a, b, -sign_b);
    ll rx1 = x;

    shift_solution(x, y, a, b, -(miny - y) / a);
    if (y < miny)
        shift_solution(x, y, a, b, -sign_a);
    if (y > maxy)
        return 0;
    ll lx2 = x;

    shift_solution(x, y, a, b, -(maxy - y) / a);
    if (y > maxy)
        shift_solution(x, y, a, b, sign_a);
    ll rx2 = x;

    if (lx2 > rx2)
       std:: swap(lx2, rx2);
        ll lx=(lx1<lx2)?lx2:lx1;
        ll rx=(rx1<rx2)?rx1:rx2; 
   
    if (lx > rx)
        return 0;
    return (rx - lx) / abs(b) + 1;
}

int main(){
int t;
int cc=1;
scanf("%d",&t);
while(t--){
     ll a,b,c,x1,x2,y1,y2;
     scanf("%lld %lld %lld %lld %lld %lld %lld",&a,&b,&c,&x1,&x2,&y1,&y2);
     c*=-1;
      if(a==0 || b==0){
           printf("Case %d: %lld\n",cc,single_solution(a,b,c,x1,x2,y1,y2));
      }


        else{  
        	
            printf("Case %d: %lld\n",cc,all_solutions(a,b,c,x1,x2,y1,y2));
                  }
     ++cc;

}

	return 0;
}

