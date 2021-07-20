#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr; // 창고의 정보 
int d[1000] = {0, }; //다이나믹 프로그래밍을 위한 배열 

int main(void){
	
	cin >> n;
	for(int i=0; i<n; i++)
	{
		int x;
		cin >> x;
		arr.push_back(x); //창고의 정보 입력받음 
	}
	
	d[0] = arr[0];
	d[1] = max(arr[0], arr[1]); //a-1, a-2를 구하기 위해 첫번째 두번째 항목을 정의함 
	for(int i=2; i<n; i++) //보텀업 방식 
		d[i] = max(arr[i-1], arr[i-2]+arr[i]); //점화식 그대로 옮겨옴. 
	
	
	cout<<d[n-1];
	
}
