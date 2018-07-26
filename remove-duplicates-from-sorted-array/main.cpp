#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        for (auto it = nums.begin(); it != nums.end(); it++)
        {
            for (auto itDup = it+1; itDup != nums.end(); itDup++)
            {
                if (*it == *itDup)
                {
                    nums.erase(itDup);
                }
            }
        }
        return nums.size();
    }
};

int main ()
{
    std::vector<int> testcase {1,1,2};
    int soln = 2;

    Solution s;
    int solution = s.removeDuplicates(testcase);
    
    assert(solution == soln);

    return 0;
}
