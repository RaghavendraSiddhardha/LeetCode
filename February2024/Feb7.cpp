// Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

// Return the sorted string. If there are multiple answers, return any of them.

 

// Example 1:

// Input: s = "tree"
// Output: "eert"
// Explanation: 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
// Example 2:

// Input: s = "cccaaa"
// Output: "aaaccc"
// Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
// Note that "cacaca" is incorrect, as the same characters must be together.
// Example 3:

// Input: s = "Aabb"
// Output: "bbAa"
// Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
// Note that 'A' and 'a' are treated as two different characters.
 

// Constraints:

// 1 <= s.length <= 5 * 105
// s consists of uppercase and lowercase English letters and digits.

#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#include<map>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        map<char,int> M;
        for(int i=0;i<s.length();i++){
            M[s[i]]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto i:M){
            pq.push({i.second,i.first});
        }
        string ans;
        while(!pq.empty()){
            int n=pq.top().first;
            char c=pq.top().second;
            pq.pop();
            for(int j=0;j<n;j++) ans+=c;
        }
        return ans;
    }
};

int main(){
    Solution s;
    string s1="abccbbadft";
    string ans = s.frequencySort(s1);
    cout<<ans;
}