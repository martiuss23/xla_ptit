#include<iostream>
#include<math.h>
using namespace std;
int n, m;
int R;

void hitorgramEqualizing(int r[], int matrix[100][100]){
	int total = n * m;
	int P[R]{0};
	for(int i = 0; i < R; i++){
		if(i > 0)
			r[i] += r[i-1];
		P[i] = round((double)r[i]*(R-1)/total);
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << P[matrix[i][j]] << " ";
		}
		cout << endl;
	}	
	
}

int main(){
	cin >> n >> m >> R;
	int matrix[100][100];
	int r[R]{0};
	for(int i = 0; i <n; i++){
		for(int j = 0; j < m; j++){
			cin >> matrix[i][j];
			r[matrix[i][j]]++;
		}
	}
	hitorgramEqualizing(r, matrix);
	
	
	return 0;
}
