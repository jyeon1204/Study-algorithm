#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> arr;

int main(void){
	cin>>n>>m;
	for(int i=0; i<n; i++)
	{
		int x;
		cin >> x;
		arr.push_back(x);
	} //화폐 목록 받기 
	
	vector<int> d(m + 1, 10001); //점화식을 위한 배열을 vector로 선언 
	
	d[0] = 0; //0은 화폐로 만들 수 없음
	 
	for(int i=0; i<n; i++)
	{
		for(int j=arr[i]; j<=m; j++) 
			d[j] = min(d[j], d[j-arr[i]]+1); 
			//j-arr[i]를 하는 이유는 화폐 단위만큼 뺀 금액에선, 화폐를 하나 더하기만 하면 되기 때문임. 이를 d[j]와 비교하여 최소값을 d[j]에 삽입함. 
			//이를 i<n 동안 실행하므로, 화폐 단위의 갯수만큼 반복하면서 d의 값들을 갱신하는 것임. 
			//점화식: ai = min(a(k-1)+1, ai) 
		
	}
	
	if(d[m] == 10001)
		cout<<-1;
	else
		cout<<d[m];
	
}
