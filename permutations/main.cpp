#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <cmath>
/* Problem description */

class Solution
{
private:
    std::vector<int> separate_digits(int n)
    { // n is nonnegative at this point.

        /* while loop code to get number of digits {
        int digits = 0;
        while (n)
        {
            n /= 10;
            digits++;
        }
        */

        /* count digits with log10 then loop to separate
        and also the code to separate digits into a vector
        int digits = log10(n) + 1;
        std::vector<int> v;
        int digit, divisor;
        // Need to go in reverse to put in vector in the right order.
        for (int i = digits-1; i >= 0; i--)
        {
            divisor = pow(10, i);
            digit = n / divisor;
            n -= digit * divisor; // 1234-1000, 234-200, 34-30, 4-?
            v.push_back(digit);
        }
        */

        // Best way IMO, does not (but can) count digits if needed.
        std::vector<int> v;
        while (n)
        {
            v.push_back(n % 10);
            n /= 10;    // you can also not modify n
                        // and increase the modulator (10 100 1000 ...)
        }
        std::reverse(v.begin(), v.end()); // favorite part
        return v;
    }

public:
    int random_permutation(int n)
    {
        if (n<0) return -1;
        std::vector<int> digits = separate_digits(n);
    }
};

int main()
{
    /* Test case and answer generation */

    /* Invoke the solution */
    Solution s;
    s.random_permutation(1234);

    /* Check solution */



    return 0;
}
