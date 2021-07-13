#include <iostream>
using namespace std;

string inputData;
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int count = 0;

int main() {
    cin >> inputData;
    int row = inputData[1] - '0';
    int column = inputData[0] - 'a' + 1;
    
	for(int i=0; i<8; i++){
		int nx = row+dx[i];
		int ny = column + dy[i];
		
		if(nx<1 || ny<1 || nx>8 || ny>8)
			continue;	
		count++;
	}
	
	cout<<count;
	
}
