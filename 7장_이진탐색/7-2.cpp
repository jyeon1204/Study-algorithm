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
	} //n,m �׸��� ���� ���� �Է¹ޱ� 
	
	sort(v.begin(), v.end()); //����Ž���� ���� ���� 
	
	int start = 0, end = v[n-1]; //������ ���� ���̸� ���������鼭 Ž�� 
	int result = 0; //�������� ���ܱ��� ���� 
	
	while(start <= end){
		int total = 0;
		int mid = (start+end)/2;
		for(int i=0; i<n; i++)
			if (v[i] > mid) total += v[i] - mid;  //total�� �߸� ���� ������ ����  
		if(total<m) //���� ���� ������� ���� ���  
			end = mid-1;
		else{ // ���� ���� ����� ��� �� �ڸ���(������ �κ� Ž��), ����� ��쿡�� ���� ���  
			result = mid;
			start = mid+1;
		}
	}
	
	cout<<result;
} 






