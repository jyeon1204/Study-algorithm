#include <bits/stdc++.h>
using namespace std;

int d[1000] = {0, };

int main(void){
	int x;
	cin >> x; //n을 입력받음 
	
	d[1] = 1; 
	d[2] = 3; //i-1, i-2를 미리 정의해놓음 
	
	for(int i=3; i<=x; i++)
		d[i] = (d[i-1]+d[i-2]*2) % 796796; //점화식을 그대로 옮겨놓고, 문제에서 정의한 796796도 넣는다 
	
	cout<<d[x];	
		
	
} 
