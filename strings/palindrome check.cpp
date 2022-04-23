#include<bits/stdc++.h>
using namespace std;
bool palindrome(string s,int l,int r)
{
    if(l==r)
    return true;
    if(l<r)
    {
        if(s[l]!=s[r])
        {
            return false;
        }
        return palindrome(s,l+1,r-1);
    }
}
int main()
{
    string s;
    cin>>s;
    int n=s.length()-1;
    palindrome(s,0,n)?cout<<"yes":cout<<"no";
}