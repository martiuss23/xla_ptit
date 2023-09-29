#include<iostream>
#include<cmath>
using namespace std;
int n, P[100][100];
double W[3][3];

int spatialAverageFilter(int x, int y){
    double result = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            result += W[i][j] * P[i + x - 1][j + y - 1];
        }
    }
    
    return round(result);
}



int main(){
    fill(&W[0][0], &W[0][0] + 9, (double)1/9);
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> P[i][j];
        }
    }
    for(int i = 2; i < n; i++){
        for(int j = 2; j < n; j++){
            cout << spatialAverageFilter(i, j) << " ";
        }
        cout << endl;
    }
    return 0;
}


