// Given a string s, return the number of palindromic substrings in it.

// A string is a palindrome when it reads the same backward as forward.

// A substring is a contiguous sequence of characters within the string.

 

// Example 1:

// Input: s = "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".
// Example 2:

// Input: s = "aaa"
// Output: 6
// Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 

// Constraints:

// 1 <= s.length <= 1000
// s consists of lowercase English letters.

#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#include<map>
using namespace std;


class Solution {
public:

    int f(string s,int ind1,int ind2){
        int counts=0;
        if(ind1>=s.length() || ind2>= s.length() || ind1<0 || ind2<0) return counts;
        while(ind1>=0 && ind2<s.length()){
            if(s[ind1]==s[ind2]){
                counts++;
                ind1--,ind2++;
            }
            else break;
        }
        return counts;
    }

    int countSubstrings(string s) {
        int count=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            count += f(s,i,i);
            count += f(s,i,i+1);
        }
        return count;
    }
};

int main(){
    Solution s;
    string s1="hewui";
    int ans = s.countSubstrings(s1);
    cout<<ans<<" ";
}