#include<iostream>
#include<string>
using namespace std;

int main(){
    int n;
    cin>>n;
    string num = to_string(n);
    string s="";
    int l = num.length();
    for(int i=0;i<l;i++){
        char ch=num[i];
        if(i==0 && ch!='9' && ch>='5') s+='9'-ch;
        else{
            if(ch>='5') s+='9'-ch;
        }
        cout<<s;
    }
    int ans=0;
    for(auto i:s){
        ans=ans*10+(i-'0');
    }
    cout<<ans;
}