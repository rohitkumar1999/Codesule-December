#include <bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t ; 
while(t--){
int n;
cin>>n ;
double sum=0;
for(int i=1;i<=n;i++ ){
sum+=1/(double)i;
}
double ans=sum*n;
cout<<fixed<<setprecision(2)<<ans<<endl;

}

}
