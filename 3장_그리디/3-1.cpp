#include <iostream>
using namespace std;
//거스름돈 알고리즘 

int main(){
	int coin[] = {500, 100, 50, 10};
	int n = 1260;
	int count = 0;
	
	for(int i=0; i<4; i++){
		count += n/coin[i];
		n %= coin[i];		
	}
	
	cout<<count;	
	
	return 0;
}
