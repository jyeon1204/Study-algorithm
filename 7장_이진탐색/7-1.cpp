#include <bits/stdc++.h>
using namespace std;

// N(������ ��ǰ ����)�� M(�մ��� Ȯ�� ��û�� ��ǰ ����)
int n, m;
// ���Կ� �ִ� ��ü ��ǰ ��ȣ��
vector<int> arr;
// �մ��� Ȯ�� ��û�� ��ǰ ��ȣ��
vector<int> targets; 

//����Ž�� �Լ� ���� 
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
	
	//�� �Լ��� �Է¹��� 
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
	
	//***����Ž���� ���ؼ� ������ �ʿ��� �߿�!*** 
	sort(arr.begin(), arr.end());
	
	for(int i=0; i<m; i++)
	{
		if(binarysearch(arr, targets[i], 0, n-1)>=0)
			cout<<"yes ";
		else
			cout<<"no ";
	}
		
}
