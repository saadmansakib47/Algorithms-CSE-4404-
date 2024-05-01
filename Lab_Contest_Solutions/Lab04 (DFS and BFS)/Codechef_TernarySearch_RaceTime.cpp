#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 10;
int n;
double k;
vector<double> speed(N), dis(N);

double p(double ind, double time) {
    return (speed[ind] * time) + dis[ind];
}

double f(double time) {
    double minValue = p(0, time);
    double maxValue = p(0, time);
    for (int i = 1; i < n; i++) {
        minValue = min(minValue, p(i, time));
        maxValue = max(maxValue, p(i, time));
    }
    return maxValue - minValue;
}

double ternarySearch() {
    double l = 0, r = k, errorLimit = 1e-9;
    while (r - l > errorLimit) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        if (f(m1) > f(m2))
            l = m1;
        else
            r = m2;
    }
    return f(l);
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> speed[i] >> dis[i];
    double result = ternarySearch();
    printf("%0.6lf\n", result);
}

int main() {
    solve();
    return 0;
}

