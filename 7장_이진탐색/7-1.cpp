#include <bits/stdc++.h>
using namespace std;

// N(가게의 부품 개수)와 M(손님이 확인 요청한 부품 개수)
int n, m;
// 가게에 있는 전체 부품 번호들
vector<int> arr;
// 손님이 확인 요청한 부품 번호들
vector<int> targets; 

//이진탐색 함수 구현 
int binarysearch(vector<int>& arr, int target, int start, int end){
	while(start <= end){
		int mid = (start+end)/2;
		if(arr[mid] == target)
			return mid;
		else if(arr[mid] > target)
			end = mid-1;
		else
			start = mid+1;
		
	}
	return -1;
}

int main(void){
	
	//두 함수를 입력받음 
	cin >> n;
	for(int i=0; i<n;i++){
		int x;
		cin>>x;
		arr.push_back(x);	
	}
	
	cin >> m;
	for(int i=0; i<m;i++){
		int x;
		cin>>x;
		targets.push_back(x);	
	}
	
	//***이진탐색을 위해선 정렬이 필요함 중요!*** 
	sort(arr.begin(), arr.end());
	
	for(int i=0; i<m; i++)
	{
		if(binarysearch(arr, targets[i], 0, n-1)>=0)
			cout<<"yes ";
		else
			cout<<"no ";
	}
		
}
