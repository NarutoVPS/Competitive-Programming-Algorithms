#include <bits/stdc++.h>
using namespace std;

void extendedEuclid(int a, int b, int &x, int &y)
{
    // if b = 0, we reached the base case & thus we set the values of x & y as derived above and return
    if (b == 0)
    {
        x = 1;
        y = 0;
        return;
    }

    int x1, y1;
    extendedEuclid(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
}

int findModuloInverse(int a, int m)
{
    int x, y;

    extendedEuclid(a, m, x, y); // get values of x & y, x will be our answer
    return (x + m) % m;
}

int findX(const vector<int> &num, const vector<int> &rem)
{
    int prod = 1, result{};

    for (int e : num)
        prod *= e;

    for (int i{}; i < num.size(); i++)
    {
        int pp = prod / num[i];
        result += rem[i] * pp * findModuloInverse(pp, num[i]);
    }

    return result % prod;
}

int main()
{
    vector<int> num, rem;
    // get num & rem

    cout << findX(num, rem) << endl;
}
