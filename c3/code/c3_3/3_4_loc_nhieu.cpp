#include<iostream>
#include<cmath>
using namespace std;
int n, K = 9; 
int P[6][6] = {{2, 2, 7, 3, 0, 0},
			{2, 2, 7, 3, 0, 0},
			{3, 3, 1, 6, 3, 3},
			{0, 0, 1, 3, 5, 5},
			{3, 3, 6, 7, 1, 1},
			{3, 3, 6, 7, 1, 1}};
double W[3][3];

void edgeProcessing(int K[6][6]){
	//lap lai pixel o ria
	K[0][0] = K[1][1];
	K[5][5] = K[4][4];
	K[0][5] = K[1][4];
	K[5][0] = K[4][1];
	for(int i = 1; i < 5; i++){
		K[0][i] = K[1][i];
		K[i][0] = K[i][1];
		K[i][5] = K[i][4];
		K[5][i] = K[4][i];
	}
}


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

int medianFilter(int matrix[6][6], int x, int y){
    int a[10];
    a[0] = -1;
    int current = 1;
    for(int i = x-1; i <= x+ 1; i++ ){
        for(int j = y - 1; j <= y + 1; j++){
        	if(current == 1) a[current++] = matrix[i][j];
			else{
				insertionSort(a, current, matrix[i][j]);
            	current++;
			}        
        }
    }
    return (K%2==0)?a[K/2]:a[(K+1)/2];
}


int spatialAverageFilter(int matrix[6][6], int x, int y){
    double result = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            result += W[i][j] * matrix[i + x - 1][j + y - 1];
        }
    }
    
    return round(result);
}



int main(){
    fill(&W[0][0], &W[0][0] + 9, (double)1/9);
    int spatialAverageMatrix[6][6];
    int medianMatrix[6][6];
    int bothFilter[6][6];
    //Ma tran ban dau sau khi xu ly bien 
    cout << "Ma tran ban dau sau khi xu ly bien" << endl;
    for(int i = 0; i <= 5; i++){
    	for(int j =0; j <= 5; j++){
    		cout << P[i][j] << " ";
		}
		cout << endl;
	}
    //Bo loc trung vi
    cout << "Bo loc trung binh -> spatialAverageMatrix" << endl;
    for(int i = 1; i < 5 ; i++){
        for(int j = 1; j < 5; j++){
        	spatialAverageMatrix[i][j] =  spatialAverageFilter(P, i, j);
            cout << spatialAverageMatrix[i][j] << " ";
        }
        cout << endl;
    }
    //Bo loc trung binh
    cout << "Bo loc trung vi -> medianMatrix" << endl;
    for(int i = 1; i < 5 ; i++){
        for(int j = 1; j < 5; j++){
        	medianMatrix[i][j] = medianFilter(P, i, j);
            cout << medianMatrix[i][j] << " ";
        }
        cout << endl;
    }
    
    // Xu ly bien cua ma spatialAverageMatrix
    edgeProcessing(spatialAverageMatrix);
    cout << "Xu ly bien cua ma tran spatialAverageMatrix -> spatialAverageMatrix[6][6]" << endl;
	for(int i = 0; i <= 5; i++){
    	for(int j =0; j <= 5; j++){
    		cout << spatialAverageMatrix[i][j] << " ";
		}
		cout << endl;
	}
	
	//Loc trung binh roi loc tiep trung vi
    cout << "Loc trung vi ma tran spatialAverageMatrix[6][6] -> ma tran bothFilter" << endl;
    for(int i = 1; i < 5; i++){
    	for(int j =1; j < 5; j++){
    		bothFilter[i][j] = medianFilter(spatialAverageMatrix, i, j);
    		cout << bothFilter[i][j] << " ";
		}
		cout << endl;
	}
   
    return 0;
}


