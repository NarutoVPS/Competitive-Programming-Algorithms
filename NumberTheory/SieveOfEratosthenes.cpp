/*

    The Sieve of Eratosthenes will generate all the primes from 2 to a given number n. It begins by assuming that all numbers are prime. 
    It then takes the first prime number and removes all of its multiples. 
    It then applies the same method to the next prime number. 
    This is continued until all numbers have been processed.

*/

#include <iostream>
#include <vector>

using namespace std;

vector<bool> makeSeive(int n) {
    // create a boolean array of size n and initialize all elements to true
    vector<bool> seive(n, true);
    // make the values at index 0 & 1 as false as they aren't prime
    seive[0] = seive[1] = false;

    // go from 2 to sqrt(n) as the remaining non-prime numbers from sqrt(n) to n will be marked as not prime by the prime numbers between 2 & sqrt(n)
    for (int i {2}; i*i <= n; i++) {
        // if the number at position "i" is prime
        if (seive[i]) {
            // go from i^2 to n and mark all the multiples of i as not prime (false)
            for (int j {i * i}; j <= n; j += i)
                seive[j] = false;
        }
    }

    // return the seive
    return seive;
}

// Now we have all the prime numbers upto "n"