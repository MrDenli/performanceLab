#include <iostream>
#include <vector>
#include <future>
#include <thread>

using namespace std;

vector<int> calc(int n, int m) {
    vector<int> ans;
    ans.push_back(1);
    int x = m % n;
    while (x != 1) {
        if (x == 0) {
            ans.push_back(n);
        } else {
            ans.push_back(x);
        }
        x = (x + m - 1) % n;
    }
    return ans;
}

void printVec(const vector<int>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
    }
}

int main() {
    int n1, m1, n2, m2;
    cin >> n1 >> m1 >> n2 >> m2;

    auto future1 = async(launch::async, calc, n1, m1);
    auto future2 = async(launch::async, calc, n2, m2);

    vector<int> ans1 = future1.get();
    vector<int> ans2 = future2.get();
    
    printVec(ans1);
    printVec(ans2);
    return 0;
}