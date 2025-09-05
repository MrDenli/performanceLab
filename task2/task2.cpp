#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

const double EPSILON = 1e-6;

using namespace std;

void pointCalc(double x0, double y0, double xr, double yr, double x, double y) {
    double value = ((x - x0) * (x - x0)) / (xr * xr) + ((y - y0) * (y - y0)) / (yr * yr);

    if (abs(value - 1.0) < EPSILON) {
        cout << 0 << endl;
    }
    else if (value < 1.0) {
        cout << 1 << endl;
    }
    else {
        cout << 2 << endl;
    }
}

int main() {
    ifstream ellipse_file("ellipse_file.txt");
    double x0, y0, xr, yr;
    ellipse_file >> x0 >> y0 >> xr >> yr;
    ellipse_file.close();

    ifstream points_file("points_file.txt");
    double x, y;
    while (points_file >> x >> y) {
        pointCalc(x0, y0, xr, yr, x, y);
    }
    points_file.close();

    return 0;
}