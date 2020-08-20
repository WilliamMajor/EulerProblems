// EvenFibSum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int evenFibSum(int targetNumber);
int FibNumber(int n);

int main()
{
    cout << evenFibSum(4000000);
}

int evenFibSum(int targetNumber)
{
    int returnSum = 0;
    int fib = 0;
    
    for (int idx = 0; fib < targetNumber; idx++)
    {
        fib = FibNumber(idx);
        if (fib % 2 == 0)
        {
            returnSum += fib;
        }
    }

    return returnSum;
}

int FibNumber(int n)
{

    vector<int> f(n + 2, 0);
    int i = 0;

    f[0] = 0;
    f[1] = 1;

    for (i = 2; i <= n; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}