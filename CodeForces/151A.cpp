#include<iostream>
using namespace std;

int main(){
    int n,k,l,c,d,p,nl,np;
    cin>>n>>k>>l>>c>>d>>p>>nl>>np;
    int tl=k*l/nl;
    int ls=c*d;
    int sg=p/np;
    int ans = min(min(tl,ls),sg)/n;
    cout<<ans;  
}