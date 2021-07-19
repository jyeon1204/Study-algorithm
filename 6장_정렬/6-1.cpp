#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;

bool compare(int a, int b) {
    return a > b;
}
//정렬을 오름차순 혹은 내림차순이 아니라 특정한 기준에 따라 정렬을 하고 싶을 경우
//(예를 들어 문자열 vector을 문자열의 2번째 글자에 따라서 정렬) 
//정렬의 기준을 갖는 함수를 구현하여 정렬할 수 있다

int main(void) {
    // N을 입력받기
    cin >> n;

    // N개의 정수를 입력받아 리스트에 저장
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    
    sort(v.begin(),v.end(),compare); //vector의 앞,뒤 주소는 v.begin, v.end로 구하기 
    
    for(int i=0; i<n; i++){
    	cout<<v.at(i)<<" ";
		//cout<<v[i]<<" "; 
	}
}
