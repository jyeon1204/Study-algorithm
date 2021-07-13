#include <iostream>
using namespace std; 
//큰 수의 법칙 

int n, m, k;
vector<int> v;

int main() {
    // N, M, K를 공백을 기준으로 구분하여 입력 받기
    cin >> n >> m >> k;

    // N개의 수를 공백을 기준으로 구분하여 입력 받기
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end()); // 입력 받은 수들 정렬하기
    int first = v[n-1];
    int second = v[n-2];
	int result = 0;
	
	int count = (m/(k+1))*k;
	count += m % (k+1);
	
	result = first*count;
	result += (m-count)*second;
	
	
	cout<<result<<endl;
    
    
    
}
