#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mp make_pair
#define cps CLOCKS_PER_SEC
#define mod (ll)1000000007
#define f first
#define s second
#define debug1(x) cout<<x<<"\n"
#define debug2(x,y) cout<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n"
#define nl cout<<"\n";
#define priority_queue pq
#define inf (ll)1e15
#define test cout<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define mxn 5000001

vector<int> v(mxn);
vector<ll> b;

void sieve(){
    for(int i=4; i<mxn; i+=2)
        v[i]=1;
for(int i=3; i*i<=mxn; i+=2){
    if(!v[i]){
        for(int j=i*i; j<mxn; j+=2*i)
            v[j]=1;
    }
}
b.push_back(2LL);
for(ll i=3LL; i<mxn; i+=2LL)
    if(!v[i])
        b.push_back(i);
}

ll mulmod(ll a,ll b,ll m){
ll r=0;
a=a%m;
while(b){
    if(b&1)
        r=(r+a)%m;
    a=(a+a)%m;
    b=b>>1;
}
return r;
}

ll modexp(ll x,ll n,ll m){
ll r=1LL;
while(n){
    if(n&1)
        r=mulmod(r,x,m);
    x=mulmod(x,x,m);
    n=n>>1LL;
}
return r;
}

bool millerrabin(ll d,ll n){
    ll a=1+rand()%(n-1);
    ll x=modexp(a,d,n);
    if(x==1||x==n-1)
        return true;
    while(d!=n-1&&x!=n-1){
        x=mulmod(x,x,n);
        d<<=1LL;
    }
    if(x!=n-1)
        return false;
return true;
}

bool isprime(ll n){
    if(n<=1)
        return false;
if(n==2||n==3||n==5)
    return true;
if(n%2==0||n%3==0||n%5==0)
    return false;
ll d=n-1;
while(d%2==0)
    d>>=1;
for(int i=0; i<4; ++i){
    if(!millerrabin(d,n))
        return false;
}
return true;
}


ll pollardrho(ll n,ll c) {
    ll x=2LL,y=2LL,i=1,k=2,d;
    while (1) {
        x=mulmod(x,x,n)+c;
        if(x>=n)
            x-=n;
        ll p1=x-y;
         if(p1<0)
            p1*=-1;
     ll d=__gcd(p1,n);
        if (d>1)
            return d;
        if (++i==k)
            y = x,k <<= 1;
    }
    return n;
}

bool sqrprime(ll n){
ll p=sqrt(n);
if(isprime(p)&&(p*p)==n)
    return true;
return false;
}
int main(){
    //sp;
    sieve();
    int l=b.size();
ll n=1LL;
while(n){
cin>>n;
if(!n) return 0;
vector<pair<ll,ll> > factor;
for(int i=0; i<l; ++i){
if(b[i]*b[i]*b[i]>n)
    break;
ll c=0;
while(n%b[i]==0){
    ++c;
    n/=b[i];
}
if(c)
    factor.pb(mp(b[i],c));
}
if(isprime(n))
factor.pb(mp(n,1LL));
else if(sqrprime(n))
factor.pb(mp(n,2LL));
else if(n>1){
    ll d=n;
    for(ll i=2; d==n; ++i)
        d=pollardrho(n,i);
    ll d1=n/d;
    if(d1<d)
        swap(d,d1);

    factor.pb(mp(d,1LL));
    factor.pb(mp(d1,1LL));
}
for(int i=0; i<factor.size(); ++i)
    cout<<factor[i].f<<"^"<<factor[i].s<<" ";
    cout<<"\n";
    }
    return 0;
}
