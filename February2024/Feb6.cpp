// Given an array of strings strs, group the anagrams together. You can return the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

// Example 1:

// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
// Example 2:

// Input: strs = [""]
// Output: [[""]]
// Example 3:

// Input: strs = ["a"]
// Output: [["a"]]
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<int>> mp;
        for(int i=0;i<strs.size();i++){
            string mod = strs[i];
            sort(mod.begin(),mod.end());
            if(mp.find(mod)==mp.end()){
                mp[mod].push_back(i);
            }
            else{
                mp[mod].push_back(i);
            }
        }
        vector<vector<string>> ans;
        for(auto vec:mp){
            vector<string> t;
            for(auto str:vec.second){
                t.push_back(strs[str]);
            }
            ans.push_back(t);
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<string> s1={"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> ans = s.groupAnagrams(s1);
    for(auto vec:ans){
        for(auto str:vec) cout<<str<<" ";
        cout<<"\n";
    }
}