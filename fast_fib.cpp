#include <iostream>
#include <vector>

using namespace std;

bool is2to2Matrix(const vector<vector<int>>& m) {
    if (m.size() != 2 && m[0].size() != 2 && m[1].size() != 2)
        return false;
    else
        return true;
}

void mulMatrix(vector<vector<int>>& v1, const vector<vector<int>>& v2) {
    if (!is2to2Matrix(v1) || !is2to2Matrix(v2))
        return;

    vector<vector<int>> m(2, vector<int>(2, 0));
    m[0][0] = v1[0][0] * v2[0][0] + v1[0][1] * v2[1][0];
    m[0][1] = v1[0][0] * v2[0][1] + v1[0][1] * v2[1][1];
    m[1][0] = v1[1][0] * v2[0][0] + v1[1][1] * v2[1][0];
    m[1][1] = v1[1][0] * v2[0][1] + v1[1][1] * v2[1][1];

    v1 = m;
}

void printMatrix(const vector<vector<int>>& m) {
    if (!is2to2Matrix(m)) return;
    cout << m[0][0] << " " << m[0][1] << endl;
    cout << m[1][0] << " " << m[1][1] << endl;
}

int main() {
    size_t n;
    size_t k;

    cout << "enter number: ";
    cin >> n;
    k = n;

    vector<vector<int>> m(2, vector<int>(2, 1));
    m[0][0] = 0;
    vector<vector<int>> res(2, vector<int>(2, 1));
    res[0][0] = 0;

    while (k > 0) {
        if (k / 2 == 0) {
            mulMatrix(m, m);
            k /= 2;
        }
        else {
            mulMatrix(res, m);
            k -= 1;
        }
    }

    //printMatrix(res);
    cout << "fib N" << n << " is " << res[1][0] << endl;

    return 0;
}

