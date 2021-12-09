#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.


*/

class solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        //Keys are the array values and values are the associated array indices
        map<int,int> hash; // Use as a hash table ,instead of creating one
        vector<int> result;

        for(int i = 0; i < nums.size(); i++)
        {
            if(hash.count(target - nums[i])) // If the partner of ths value to reach the target sum has been saved already
            {
                result.push_back(hash[target - nums[i]]);
                result.push_back(i);
                return result;
            }
            else
            {
                hash[nums[i]] = i;
            }
        }
        return result;
    }
};





int main()
{
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);

    int target = 9;
    solution s;

    vector<int> two_sum = s.twoSum(nums, target);

    for(int i = 0; i < two_sum.size(); i++)
    {
        printf("%d ,", two_sum[i]);
    }

    return 0;
}