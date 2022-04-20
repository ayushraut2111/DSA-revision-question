#include<bits/stdc++.h>
using namespace std;
void pass(int *a[])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<a[i][j]<<endl;
        }
    }   
}
int main()
{
    // int **a;
    //     a=new int*[3];
    int *a[3];
    for(int i=0;i<3;i++)
    {
        a[i]=new int[3];
        for(int j=0;j<3;j++)
        {
            cin>>a[i][j];
        }
    }
    pass(a);
    
}