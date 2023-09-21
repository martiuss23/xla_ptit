#include<iostream>
using namespace std;

const int R = 255;

int main(){
    float a;
    int b, n;
    cin >> a >> b >> n;
    int matrix[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
            matrix[i][j] = min((int)(matrix[i][j] * a) + b, R);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
