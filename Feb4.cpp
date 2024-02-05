// Given two strings s and t of lengths m and n respectively, return the minimum window 
// substring
//  of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

// The testcases will be generated such that the answer is unique.

 

// Example 1:

// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
// Example 2:

// Input: s = "a", t = "a"
// Output: "a"
// Explanation: The entire string s is the minimum window.
// Example 3:

// Input: s = "a", t = "aa"
// Output: ""
// Explanation: Both 'a's from t must be included in the window.
// Since the largest window of s only has one 'a', return empty string.





#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;


// class Solution {
// public:

//     bool got(string x,string t){
//         sort(x.begin(),x.end());
//         sort(t.begin(),t.end());
//         int n = x.length();
//         int m = t.length();
//         for(int i=0;i<n-m+1;i++){
//             if(x.substr(i,i+m)==t){
//                 return true;
//             }
//         }
//         return false;
//     }
//     string minWindow(string s, string t) {
//         int n=s.length();
//         int m=t.length();
//         string ans="";
//         string finals="";
//         int i=0;
//         while(i<n){
//             ans+=s[i];
//             int j=i+1;
//             while(j<n && got(ans,t)==false){
//                 ans+=s[j];
//                 j++;
//             }
//             i++;
//             if(got(ans,t)){
//                 if(finals==""){
//                     finals=ans;
//                 }
//                 else{
//                     if(finals.length()>ans.length()){
//                         finals=ans;
//                     }
//                 }
//             }
//             ans="";
//         }
//         return finals;
//     }
// };

// class Solution {
// public:

//     bool got(map<char,int> mp1,map<char,int> mp2){
//         for(auto i:mp2){
//             if(mp1.find(i.first)==mp1.end() || mp1[i.first]<i.second){
//                 return false;
//             }
//         }
//         return true;
//     }
//     string minWindow(string s, string t) {
//         int n=s.length();
//         int m=t.length();
//         map<char,int> mp1,mp2;
//         for(auto i:t) mp2[i]++;
//         int start=0;
//         int length=INT_MAX;
//         int j=0;
//         for(int i=0;i<n;i++){
//             mp1[s[i]]++;
//             while(j<=i && got(mp1,mp2)){
//                 if(i-j+1<length){
//                     length=i-j+1;
//                     start=j;
//                 }
//                 mp1[s[j]]--;
//                 j++;
//             }
//         }
//         return length==INT_MAX?"":s.substr(start,length);
//     }
// };

class Solution {
public:
   string minWindow(string s, string t) {
        unordered_map<char, int>mp;
        for(int i=0; i<t.length(); i++){
            mp[t[i]]++;
        }
        int count=0;
        int low=0;
        int minlength=1e9;
        int minstart=0;
        
        for(int i=0; i<s.length(); i++){
            if(mp[s[i]]>0){
                count++;
            }
            mp[s[i]]--;
            
            if(count==t.length()){
                while(low<=i && mp[s[low]]<0){
                    mp[s[low]]++;
                    low++;
                }
                if(minlength>i-low+1){
                    minlength=i-low+1;
                    minstart=low;
                }
                mp[s[low++]]++;
                count--;
            }
        }
        return minlength==1e9 ? "" :s.substr(minstart, minlength);
    }
};

int main(){
    Solution s;
    string s1="abc";
    string t="ac";
    string ans = s.minWindow(s1,t);
    cout<<ans;
}