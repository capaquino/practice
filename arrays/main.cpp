#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <iostream>

/* Rotate array */

class Solution
{
public:
    template <typename T>
    void rightRotate(std::vector<T>& v, int steps)
    {
        for (int i = 0; i < steps; i++)
        {
            T save;
            T set = v.back();
            for (auto it = v.begin(); it != v.end(); it++)
            {
                    save = *it;
                    *it = set;
                    set = save;
            }
        }
    }

    template <typename T>
    void print(std::vector<T>& v)
    {
        for (auto it = v.begin(); it != v.end(); it++)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }

};

int main()
{
    /* Test case and answer generation */
    std::vector<int> v {1,2,3,4,5,6,7};

    /* Invoke the solution */
    Solution s;
    s.print(v);
    s.rightRotate(v,1);
    s.print(v);
    s.rightRotate(v,1);
    s.print(v);
    s.rightRotate(v,1);
    s.print(v);
    /* Check solution */

    return 0;
}
