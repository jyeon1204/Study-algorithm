#include <iostream>
using namespace std;

int main(){
	int n,k;
	int count = 0;
	int tmp = 0;
	
	cin >> n >> k;
	
	while(true){
		tmp = n % k;
		n -= tmp;
		count += tmp;
		
		if(n < k){
			count += n-1;
			break;
		}
		
		n /= k;	
		count++;
	}
	
	cout << count;
	
}
