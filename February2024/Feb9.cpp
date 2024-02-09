// Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

// answer[i] % answer[j] == 0, or
// answer[j] % answer[i] == 0
// If there are multiple solutions, return any of them.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [1,2]
// Explanation: [1,3] is also accepted.
// Example 2:

// Input: nums = [1,2,4,8]
// Output: [1,2,4,8]
 

// Constraints:

// 1 <= nums.length <= 1000
// 1 <= nums[i] <= 2 * 109
// All the integers in nums are unique.
#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#include<map>
using namespace std;


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums),end(nums));
        int maxi = 1, idx = 0;
        vector<int> dp(n,1);
        vector<int> hash(n,-1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j] == 0 && dp[i] < dp[j] + 1){
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                idx = i;
            }
        }
        vector<int> ans;
        int k = idx; 
        while (k >= 0) 
        { 
           ans.push_back(nums[k]);
            k = hash[k]; 
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};
int main(){
    Solution s;
    vector<int> n = {1,2,4,8,10,16};
    vector<int> ans = s.largestDivisibleSubset(n);
    for(auto i:ans) cout<<i<<" ";
}