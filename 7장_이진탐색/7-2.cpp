#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> v;

int main(void){
	cin >>n>>m;
	for(int i=0; i<n; i++){
		int x;
		cin>>x;
		v.push_back(x);
	} //n,m 그리고 떡의 길이 입력받기 
	
	sort(v.begin(), v.end()); //이진탐색을 위한 정렬 
	
	int start = 0, end = v[n-1]; //절단할 떡의 길이를 좁혀나가면서 탐색 
	int result = 0; //최종적인 절단기의 길이 
	
	while(start <= end){
		int total = 0;
		int mid = (start+end)/2;
		for(int i=0; i<n; i++)
			if (v[i] > mid) total += v[i] - mid;  //total은 잘린 떡의 길이의 총합  
		if(total<m) //떡의 양이 충분하지 않은 경우  
			end = mid-1;
		else{ // 떡의 양이 충분한 경우 덜 자르기(오른쪽 부분 탐색), 충분한 경우에만 정답 기록  
			result = mid;
			start = mid+1;
		}
	}
	
	cout<<result;
} 






