#include<bits/stdc++.h>
#define ll long long
using namespace std;
// bool anagram(string s1,string s2)
// {
//     sort(s1.begin(),s1.end());
//     sort(s2.begin(),s2.end());
//     if(s1==s2)
//     return true;
//     return false;
// }
bool anagram(string s1,string s2)
{
    if(s1.length()!=s2.length())
    return false;
    int charac[256];
    memset(charac,0,256*sizeof(charac[0]));
    for(int i=0;i<s1.length();i++)
    {
        charac[s1[i]]++;
        charac[s2[i]]--;
    }
    for(int i=0;i<256;i++)
    {
        if(charac[i]!=0)
        return false;
    }
    return true;
}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    anagram(s1,s2)?cout<<"yes":cout<<"no";
}

// to solve this problem first we create a array of size 256 and initialise every element as 0 we have taken the size 256
// because max to max the ascii value of any char will go upto 256 and then run a loop and increment this array for first string an d
// decrement for the second string and at the end if both have same number and same character then it is going to be all zero
// because they both contain same number of characters and one time we are incrementing and other time we are decrementing 