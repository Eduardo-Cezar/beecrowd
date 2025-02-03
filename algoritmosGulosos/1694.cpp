#include <iostream>

//#define FOR_UPTO(start, end) for (int it = start; it < end; it++)

using namespace std;

int main(){
    unsigned n, m, r, c;
    int ** mat = nullptr;
    n = m = r = c = 0;

    cin >> n >> m >> r >> c;

    mat = new int*[n];
    for (int i = 0; i < n; i++){
        mat[i] = new int[m];
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }


    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << mat[i][j] << ' ';
        }
        cout << endl;
    }


    delete [] mat;
    return 0;
}