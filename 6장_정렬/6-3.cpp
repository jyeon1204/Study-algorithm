#include <bits/stdc++.h>
using namespace std;

int a[100000]={0,}; 
int b[100000]={0,}; //기왕이면 벡터를 사용할 것. 
int n,k;

int main(void){
	cin >> n >> k;
	for(int i=0; i<n; i++)
		cin >> a[i] ;
	for(int i=0; i<n; i++)
		cin >> b[i];
	
	sort(a, a+n);
	sort(b, b+n);
	
	for(int i=0; i<k; i++){
		if(a[i]<b[n-i-1])
			swap(a[i], b[n-i-1]);
	}
	
	int result = 0;
	for(int i=0; i<n; i++)
		result += a[i];
	cout<<result;
}
