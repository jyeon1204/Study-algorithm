#include <bits/stdc++.h>
using namespace std;

int d[1000] = {0, };

int main(void){
	int x;
	cin >> x; //n�� �Է¹��� 
	
	d[1] = 1; 
	d[2] = 3; //i-1, i-2�� �̸� �����س��� 
	
	for(int i=3; i<=x; i++)
		d[i] = (d[i-1]+d[i-2]*2) % 796796; //��ȭ���� �״�� �Űܳ���, �������� ������ 796796�� �ִ´� 
	
	cout<<d[x];	
		
	
} 
