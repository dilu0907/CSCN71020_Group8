#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// Function to check if three sides can form a triangle
bool isValidTriangle(double a, double b, double c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}

// Function to calculate the angles of a triangle given its three sides
void calculateTriangleAngles(double a, double b, double c) {
    const double PI = 3.14159265358979323846;
    double A = acos((b * b + c * c - a * a) / (2 * b * c)) * (180.0 / PI);
    double B = acos((a * a + c * c - b * b) / (2 * a * c)) * (180.0 / PI);
    double C = 180.0 - A - B;

    cout << "Triangle angles: " << A << " degrees, " << B << " degrees, " << C << " degrees." << endl;
}

// Function to calculate distance between two points
double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Function to check if four points form a rectangle
bool isRectangle(vector<pair<double, double>> points, double& perimeter, double& area) {
    vector<double> sides;
    for (int i = 0; i < 4; i++) {
        sides.push_back(distance(points[i].first, points[i].second, points[(i + 1) % 4].first, points[(i + 1) % 4].second));
    }

    double diag1 = distance(points[0].first, points[0].second, points[2].first, points[2].second);
    double diag2 = distance(points[1].first, points[1].second, points[3].first, points[3].second);

    if (sides[0] == sides[2] && sides[1] == sides[3] && fabs(diag1 - diag2) < 1e-6) {
        perimeter = 2 * (sides[0] + sides[1]);
        area = sides[0] * sides[1];
        return true;
    }

    perimeter = sides[0] + sides[1] + sides[2] + sides[3];
    area = 0; // Not a rectangle, so no valid area
    return false;
}

int main() {
    double a, b, c;
    cout << "Enter three side lengths for a triangle: ";
    while (!(cin >> a >> b >> c) || a <= 0 || b <= 0 || c <= 0) {
        cout << "Invalid input. Please enter three positive numbers: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if (isValidTriangle(a, b, c)) {
        cout << "The given sides form a triangle.\n";
        calculateTriangleAngles(a, b, c);
    }
    else {
        cout << "The given sides do not form a triangle.\n";
    }

    vector<pair<double, double>> points(4);
    cout << "Enter four points (x y) one by one:\n";
    for (int i = 0; i < 4; i++) {
        while (!(cin >> points[i].first >> points[i].second)) {
            cout << "Invalid input. Please enter two numeric values: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    double perimeter, area;
    if (isRectangle(points, perimeter, area)) {
        cout << "The given points form a rectangle.\n";
        cout << "Perimeter: " << perimeter << "\n";
        cout << "Area: " << area << "\n";
    }
    else {
        cout << "The given points do not form a rectangle.\n";
        cout << "Perimeter: " << perimeter << "\n";
    }

    return 0;
}
