#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <float.h>
#include <iomanip>

using namespace std;
struct Point {
    double x, y, z;
};

double distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) + pow(p1.z - p2.z, 2));
}

bool compareX(const Point &p1, const Point &p2) {
    return p1.x < p2.x;
}

bool compareY(const Point &p1, const Point &p2) {
    return p1.y < p2.y;
}

double bruteForce(vector<Point> &points, int l, int r) {
    double min_dist = DBL_MAX;
    for (int i = l; i <= r; i++) {
        for (int j = i + 1; j <= r; j++) {
            double dist = distance(points[i], points[j]);
            if (dist < min_dist) {
                min_dist = dist;
            }
        }
    }
    return min_dist;
}

double stripClosest(vector<Point> &strip, double d) {
    double min_dist = d;
    sort(strip.begin(), strip.end(), compareY);

    for (int i = 0; i < strip.size(); i++) {
        for (int j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < min_dist; j++) {
            if (fabs(strip[j].z - strip[i].z) < min_dist) {
                double dist = distance(strip[i], strip[j]);
                if (dist < min_dist) {
                    min_dist = dist;
                }
            }
        }
    }

    return min_dist;
}

double closestPairRec(vector<Point> &points, int l, int r) {
    if (r - l <= 3) {
        return bruteForce(points, l, r);
    }

    int mid = (l + r) / 2;
    double mid_x = points[mid].x;
    double dl = closestPairRec(points, l, mid);
    double dr = closestPairRec(points, mid + 1, r);

    double d = min(dl, dr);
    vector<Point> strip;
    for (int i = l; i <= r; i++) {
        if (fabs(points[i].x - mid_x) < d) {
            strip.push_back(points[i]);
        }
    }

    return min(d, stripClosest(strip, d));
}

double closestPair(vector<Point> &points) {
    sort(points.begin(), points.end(), compareX);
    return closestPairRec(points, 0, points.size() - 1);
}

int main() {
    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y >> points[i].z;
    }

    cout << fixed << setprecision(6) << closestPair(points) << endl;
    return 0;
}