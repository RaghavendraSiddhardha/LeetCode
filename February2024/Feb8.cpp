// Given an integer n, return the least number of perfect square numbers that sum to n.

// A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

 

// Example 1:

// Input: n = 12
// Output: 3
// Explanation: 12 = 4 + 4 + 4.
// Example 2:

// Input: n = 13
// Output: 2
// Explanation: 13 = 4 + 9.
 

// Constraints:

// 1 <= n <= 104

#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#include<map>
using namespace std;

vector<int> dp(10001,-1);

class Solution {
public:
    int recur(int n){
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];
        int answer=1e9;
        for(int j=1;j*j<=n;j++){
            int c=1+recur(n-j*j);
            answer=min(answer,c);
        }
        return dp[n]=answer;
    }
    int numSquares(int n) {
        return recur(n);
    }
};

int main(){
    Solution s;
    int n = 101;;
    int ans = s.numSquares(n);
    cout<<ans;
}