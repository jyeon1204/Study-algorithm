#include <iostream>
using namespace std;
//ī����� �˰��� 

int n, m;
int result;

int main() {
	
    cin >> n >> m;
	for(int i=0; i<n; i++){
		int minV = 10001;
		for(int k=0; k<m; k++){
			int x;
			cin >> x;
			minV = min(minV, x); 
		}
		
		result = max(result, minV);		
	}
	
	cout << result;
}
