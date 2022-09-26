#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct Myhash{
    int *arr;
    int size,cap;
    Myhash(int c)
    {
        size=0;cap=c;
        arr=new int[c];
        for(int i=0;i<c;i++)
        {
            arr[i]=-1;
        }
    }
};
int main()
{
    
}