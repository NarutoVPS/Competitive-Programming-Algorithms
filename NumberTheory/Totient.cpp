#include <bits/stdc++.h>
using namespace std;

vector<int> makePhiSeive(int n)
{
    // vector to store all the phi values form 1 to n
    vector<int> phi(n + 1);

    // initialize vector form 0 to n
    for (int i{}; i < n + 1; i++)
        phi[i] = i;

    // iterate from 2 to n
    for (int i{2}; i <= n; i++)
    {
        // if current element is prime
        if (phi[i] == i)
        {
            phi[i] = i - 1; // decrement the prime number by 1
            // multiply all it's multiples with n*(1-1/p) ; p is current prime number
            for (int j{2 * i}; j <= n; j += i)
                phi[j] = (phi[j] * (i - 1)) / i; // we 1st perform multiplication as 1/p will become 0
        }
    }

    return phi;
}

int main()
{
    int t;
    cin >> t;

    // calculate phi upto 10^5 once
    vector<int> phiSeive = makePhiSeive(100000);
    while (t--)
    {
        int n;
        cin >> n;

        // print the phi(n) from calculated vector
        cout << phiSeive[n] << endl;
    }

    return 0;
}
