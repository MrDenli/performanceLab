#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

int calc(vector<int> vec) {
    sort(vec.begin(), vec.end());
    int mid = vec.size() / 2;
    int sm = 0;
    for (int i = 0; i < mid; i++) {
        sm += abs(vec[i] - vec[mid]);
        if (sm > 20) {
            return -1;
        }
    }
    for (int i = mid + 1; i < vec.size(); i++) {
        sm += abs(vec[i] - vec[mid]);
        if (sm > 20) {
            return -1;
        }
    }
    return sm;
}

int main() {
    string s;
    cin >> s;
    ifstream inputFile(s);
    vector<int> vec;
    int x;
    while (inputFile >> x) {
        vec.push_back(x);
    }
    inputFile.close();
    int rez = calc(vec);
    if (rez == -1) {
        cout << "20 ходов недостаточно для приведения всех элементов массива к одному числу" << endl;
    }
    else {
        cout << rez << endl;
    }

    return 0;
}