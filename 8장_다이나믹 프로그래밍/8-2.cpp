#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr; // â���� ���� 
int d[1000] = {0, }; //���̳��� ���α׷����� ���� �迭 

int main(void){
	
	cin >> n;
	for(int i=0; i<n; i++)
	{
		int x;
		cin >> x;
		arr.push_back(x); //â���� ���� �Է¹��� 
	}
	
	d[0] = arr[0];
	d[1] = max(arr[0], arr[1]); //a-1, a-2�� ���ϱ� ���� ù��° �ι�° �׸��� ������ 
	for(int i=2; i<n; i++) //���Ҿ� ��� 
		d[i] = max(arr[i-1], arr[i-2]+arr[i]); //��ȭ�� �״�� �Űܿ�. 
	
	
	cout<<d[n-1];
	
}
