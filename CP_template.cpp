#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define mod 1000000007
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define MAXN 1e6+3

ll gcd(ll q, ll p){ return p == 0 ? q : gcd(p, q%p); }
ll lcm(ll q, ll p){ return q*p / gcd(q, p); }

vector<ll> sPrimeF(MAXN,1);
void sieve(){
  sPrimeF[0]=0;
for(int i=2;i<MAXN;i++){
  if(sPrimeF[i]==1){
    for(int j=i;j<MAXN;j+=i){
      if(sPrimeF[j]==1)sPrimeF[j]=i;
    }
  }
}
}

void solve(){
    
}
  

signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

//sieve();
ll t=1;
cin>>t;
while (t--)
{
solve();
}



}