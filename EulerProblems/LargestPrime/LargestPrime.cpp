// LargestPrime.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

uint64_t LargestPrime(uint64_t targetNumber);
bool isPrime(uint64_t n);

int main()
{
    cout << (uint64_t)LargestPrime(600851475143);
}

uint64_t LargestPrime(uint64_t targetNumber)
{
    uint64_t maxPrime = -1;

    while (targetNumber % 2 == 0) {
        maxPrime = 2;
        targetNumber >>= 1; // equivalent to n /= 2 
    }

    for (int i = 3; i <= sqrt(targetNumber); i += 2) {
        while (targetNumber % i == 0) {
            maxPrime = i;
            targetNumber = targetNumber / i;
        }
    }
    if (targetNumber > 2)
        maxPrime = targetNumber;

    return maxPrime;
}

