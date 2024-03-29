// Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

// Example 1:

// Input: temperatures = [73,74,75,71,69,72,76,73]
// Output: [1,1,4,2,1,1,0,0]
// Example 2:

// Input: temperatures = [30,40,50,60]
// Output: [1,1,1,0]
// Example 3:

// Input: temperatures = [30,60,90]
// Output: [1,1,0]
#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> ans(n, 0);
        vector<int> st;
        st.push_back(n-1);
        for(int i=n-2; i>=0; i--){
            while(!st.empty() && temperatures[i] >= temperatures[st.back()])
                st.pop_back();

            if (!st.empty())
                ans[i] = st.back() - i;

            st.push_back(i);
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> temps = {1,2,3,4};
    vector<int> ans = s.dailyTemperatures(temps);
    for(auto i:ans){
        cout<<i<<" ";
    }
}