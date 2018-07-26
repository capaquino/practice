#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <iostream>

/* Count the number of primes less than a non-negative number n */

class Solution
{
public:

    template <typename T>
    void print_vector(std::vector<T> &v)
    {
        std::cout << std::endl;
        for (auto it = v.begin(); it != v.end(); it++)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }

    int countPrimes(int n)
    {
        // Approach 1: Count all numbers up till n and see if they are
        // prime, keep a tally... Seems bad.

        // Approach 2: STL Algorithms ... didn't see anything.

        // Approach 3: After looking online, method called Sieve
        // of Eratosthenes

        // Actually dont need a vector from 1 to n.
        std::vector<bool> v(n, false);

        for (int i=0; i<n; i++) std::cout << i << " ";
        //print_vector(v);

        // Use Sieve of Eratosthenes method
        for (int p = 2; p < n; p++)
        {
            for (int m = 2; p*m<n; m++)
            {
                v.at(p*m) = true;
            }
        }

        print_vector(v);
        // Count the primes (unmarked/false from Sieve method, minus 0 and 1)
        int numPrimes = 0;
        for (int e = 2; e < n; e++)
        {
            if (v.at(e))
            {
                numPrimes++;
            }
        }
        return numPrimes;
    }
};

int main()
{
    /* Test case and answer generation */
    int until = 14;

    /* Invoke the solution */
    Solution s;
    std::cout << "\n" << s.countPrimes(until) << "\n";

    /* Check solution */



    return 0;
}
