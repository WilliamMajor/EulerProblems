// MultipleOf.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std; //for ease of use for final production this would not be included 

int getSums(vector<int> targets, int targetNumber);
int getSums1(vector<int> targets, int targetNumber);

int main()
{
    vector<int> targets = { 3,5 };
    cout << getSums(targets, 1000) << endl;
    cout << getSums1(targets, 1000) << endl;
}

int getSums(vector<int> targets, int targetNumber) // O(n^2) worse case approach, but on average would be faster than O(n)
{
    int returnValue = 0;
    for (int idx = 0; idx < (int)targets.size(); idx++)
    {
        
        int n = 1;
        while (n * targets[idx] < targetNumber)
        {
            bool throwaway = false;
            int test = targets[idx] * n;
            if(!(test % (targets[0] * targets[1]) == 0 && idx == 1))
            {
                returnValue += test;
            }
            n++;
        }
    }
    return returnValue;
}

int getSums1(vector<int> targets, int targetNumber)
{
    int returnValue = 0;
    for (int idx = 0; idx < targetNumber; idx++)
    {
        if (idx % targets[0] == 0 || idx % targets[1] == 0)
        {
            returnValue += idx;
        }
    }
    return returnValue;
}