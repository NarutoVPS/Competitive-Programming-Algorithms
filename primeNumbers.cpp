#include <bits/stdc++.h>

using namespace std;

/*
NAIVE APPROACH :- iterate through 2 to n and check it n has any divisors
for (int i=2; i<n; i++)
    if (n%i==0) return false;
return true;

BETTER SOLUTION :- It is sufficient to check if n has any divisors from 2 to sqrt(n)

bool isPrime (int n)
{
    if (n<=1) return false;
    if (n==2) return true;
    if (n%2==0) return false;

    int m=Math.sqrt(n);

    for (int i=3; i<=m; i+=2)
        if (n%i==0)
            return false;

    return true;
}

ENTER SIEVE METHOD😎:-
    The Sieve of Eratosthenes will generate all the primes from 2 to a given number n. It begins by assuming that all numbers are prime. 
    It then takes the first prime number and removes all of its multiples. 
    It then applies the same method to the next prime number. 
    This is continued until all numbers have been processed.

*/

vector<bool> sieve(int n){
    vector<bool> prime(n, true);
    prime[0]=false;
    prime[1]=false;
    int m = sqrt(n);

    for (int i=2; i<=m; i++){
        if (prime[i]){
            for (int k=i*i; k<=n; k+=i)
                prime[k]=false;
        }
    }
    return prime;
}


int main(){
    int n{};
    cin>>n;

    auto result = sieve(n);
    cout<<boolalpha;
    cout<<result[n]<<endl;

    return 0;
}