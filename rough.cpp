#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {   
        int longest=0;
        int count=1;
        set<int> st;
        for (int i = 0; i < nums.size(); i++)
        {
            st.insert(nums[i]);
        }

        for (auto it = st.begin(); it != st.end();)
        {
            longest=max(longest,count);
            auto nextIt = std::next(it); // Get next iterator without modifying `it`

            if (nextIt != st.end() && *it + 1 == *nextIt)
            {
                count++;
            }
            else{
                count=1;
            }

            it = nextIt; // Move iterator forward after processing
        }
        return longest;
    }
};
int main()
{
    Solution s;
    vector<int> v = {100, 4, 200, 1, 3, 2};
   cout<< s.longestConsecutive(v);
    return 0;
}