#include<bits/stdc++.h>
#define ll long long
using namespace std;




ll calculatens(ll c,ll k,ll p){
    if(k==1){
        return c;
    }
    ll ans=calculatens(c,k/2,p);
    if(k%2)
    return ((ans%p)*(ans%p)*c)%p;
    return ((ans%p)*(ans%p))%p;
}

int main() {
    int t1;
    cin>>t1;
    while(t1--){
        ll a1,n,p;
        cin>>a1>>n>>p;
        ll ans=1;
        while(n){
            a1=calculatens(a1,n,p)%p;
            n--;
        }
        cout<<a1<<endl;
    }
	return 0;
}
