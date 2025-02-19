/*
 https://judge.beecrowd.com/pt/problems/view/1649
*/

#include <iostream>

using namespace std;

int main() {
    unsigned n, m, r, c;
    int** mat = nullptr;
    char pixel = ' ';
    int operacoes = 0;
    bool ehPosivel = true;

    n = m = r = c = 0;

    while (cin >> n >> m >> r >> c, n || m || r || c) {
        operacoes = 0;
        bool ehPosivel = true;

        mat = new int*[n];
        for (int i = 0; i < n; i++)
            mat[i] = new int[m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> pixel;
                mat[i][j] = pixel - '0'; // converte char para int
            }
        }

        // escolha gulosa
        for (int i = 0; i <= n - r; i++) {
            for (int j = 0; j <= m - c; j++) {
                if (mat[i][j] == 1) {
                    for (int x = i; x < i + r; x++) {
                        for (int y = j; y < j + c; y++) {
                            mat[x][y] = 1 - mat[x][y];
                        }
                    }
                    operacoes++;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) {
                    ehPosivel = false;
                    break;
                }
            }
            if (!ehPosivel) break;
        }

        cout << (ehPosivel ? operacoes : -1) << endl;

        for (int i = 0; i < n; i++)
            delete[] mat[i];

        delete[] mat;
    }

    return 0;
}