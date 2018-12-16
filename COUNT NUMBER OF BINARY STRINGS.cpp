#include <iostream> 
using namespace std; 
  
int countit(int a) 
{ 
    int arr[a], brr[a]; 
    arr[0] = brr[0] = 1; 
    for (int i = 1; i < a; i++) 
    { 
        arr[i] = arr[i-1] + brr[i-1]; 
        brr[i] = arr[i-1]; 
    } 
    return arr[a-1] + brr[a-1]; 
} 
  
  
int main() 
{ 
	int t,n ; 
	cin>>t ; 
	while(t>0)
	{
		cin>>n  ;
		cout<<countit(n)<<endl ; 
		t-- ; 
		
	}
   return  0 ; 
}
