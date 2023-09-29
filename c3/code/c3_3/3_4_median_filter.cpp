#include<iostream>

using namespace std;
int n, P[100][100], K = 9;

void insertionSort(int a[], int position, int value){
    for(int k = position -1; k >= 1; k--){
        if(a[k] > value){
            a[k+1] = a[k];
            if(k == 1) a[k] = value;
        }
        else{
            a[k+1] = value;
            break;
        }
    }
}

int medianFilter(int x, int y){
    int a[10];
    a[0] = -1;
    int current = 1;
    for(int i = x-1; i <= x+ 1; i++ ){
        for(int j = y - 1; j <= y + 1; j++){
        	if(current == 1) a[current++] = P[i][j];
			else{
				insertionSort(a, current, P[i][j]);
            	current++;
			}        
        }
    }
    return (K%2==0)?a[K/2]:a[(K+1)/2];
}





int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> P[i][j];
        }
    }
    for(int i = 2; i < n; i++){
    	for(int j = 2; j < n; j++){
    		cout << medianFilter(i, j) << " ";
		}
		cout << endl;
	}
    
    return 0;
}
