#include <vector>
#include <algorithm>
#include <iostream>
#include <random> // random_device, mt19937
//#include <cmath> // log10, pow

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

    template <typename T>
    void print(std::vector<T> v)
    {
        for (auto it = v.begin(); it != v.end(); it++)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }


public:
    int random_permutation(int n)
    {
        if (n<0) return -1;
        /// Put digits into a vector to manipulate
        std::vector<int> digits = separate_digits(n);

        print(digits);

        /// Generate a random permutation

        // Stop using srand(time(NULL)) and rand(). Defined in <random>
        // Dr. Sutton talked about these towards the end of the sem.
        std::random_device random_dev;
        std::mt19937 generator(random_dev()); // mt19937 is a URBG
        std::shuffle(digits.begin(), digits.end(), generator);

        print(digits);

        /// Recombine into an int and return

        // Use reverse iterators.
        int value = 0;
        for (auto rit = digits.rbegin(); rit != digits.rend(); rit++)
        {
            value += *rit * pow(10, rit - digits.rbegin());
        }
        return value;
        // Using indeces, note it is more complicated because
        // you have to account for the 0-start-indexing array
        // problem.
        // int value = 0;
        // for (int i = digits.size()-1; i >= 0; i--)
        // {
        //     value += digits.at(i) * pow(10, digits.size()-(i+1));
        // }
    }
};

int main()
{
    /* Test case and answer generation */
    int num = 12345;
    std::cout << num << std::endl;

    /* Invoke the solution */
    Solution s;
    std::cout << s.random_permutation(num) << std::endl;

    /* Check solution */

    return 0;
}
