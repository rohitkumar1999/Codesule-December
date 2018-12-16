#include<iostream>
#define mod 1000000007
#define MAX 100000000
using namespace std;
long long tree[1000050];
long long arr[100010];
long long gcd(long long a, long long b){
	if(b==0){
		return a;
	}else{
		return gcd(b,a%b);
	}
}
 
void build(int node,int start, int end){
	if(start==end){
		tree[node]=arr[start];
		return;
	}
	else{
		int mid=(start+end)>>1;
		build(2*node+1,start,mid);
		build(2*node+2,mid+1,end);
		tree[node]=gcd(tree[node*2+1],tree[node*2+2]);
		return;
	}
}
 
 
long long query(int node, int ql,int qh, int start, int end ){
	if(ql<=start && qh>=end) 
		return tree[node]; //total overlap between range and nodes
	if(ql>end || qh<start)
		return -1;	// no overlap
	int mid=(start+end)>>1;
	long long t1=query(2*node+1,ql,qh,start,mid);
	long long t2=query(2*node+2,ql,qh,mid+1,end);
	if(t1==-1 && t2==-1){
		return 1;
	}
	else if(t1==-1){
		return t2;
	}
	else if(t2==-1){
		return t1;
	}else{
		return gcd(t1,t2);
	}
}
void multiply(long long f[2][2], long long m[2][2])
{
  long long x =  (f[0][0]*m[0][0] + f[0][1]*m[1][0])%mod;
  long long y =  (f[0][0]*m[0][1] + f[0][1]*m[1][1])%mod;
  long long z =  (f[1][0]*m[0][0] + f[1][1]*m[1][0])%mod;
  long long w =  (f[1][0]*m[0][1] + f[1][1]*m[1][1])%mod;
 
  f[0][0] = x;
  f[0][1] = y;
  f[1][0] = z;
  f[1][1] = w;
}
 
void power(long long f[2][2], long long n){
	if(n==0 || n==1){
		return;
	}
	long long m[2][2]={{1,1},{1,0}};
	power(f,n/2);
	multiply(f,f);
	if(n%2!=0){
		multiply(f,m);
	}
}
long long fib(long long n){
	long long f[2][2]={{1,1},{1,0}};
	if(n==0){
		return 0;
	}
	power(f,n-1);
	return (f[0][0]%mod);
}
int main()
{
	int n,q,a,b;
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	build(0,0,n-1);
	while(q--)
	{
	  	scanf("%d%d",&a,&b);
	  	a--;
	  	b--;
	  	int t1=query(0,a,b,0,n-1);
	  	cout<<fib(t1)%mod<<endl;
	}	
  	return 0;
}
