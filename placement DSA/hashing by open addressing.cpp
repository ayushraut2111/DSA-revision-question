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
            arr[i]=NULL;
        }
    }
    void inserthash(int x)
    {
        if(size==cap)
        {
            cout<<"hashtable is full"<<endl;
            return;
        }
        int key=x%cap;
        if(arr[key]==NULL||arr[key]==-1)
        {
            arr[key]=x;
            size++;
            return ;
        }
        while(arr[key]!=NULL&&arr[key]!=-1)
        {
            key=(key+1)%cap;
        }
        arr[key]=x;
        size++;
    }
    void deletehash(int x)
    {
        int key=x%cap;
        if(arr[key]==x)
        {
            arr[key]=-1;
            return ;
        }
        int temp=key;
        key=(key+1)%cap;
        while(arr[key]!=NULL&&temp!=key)
        {
            if(arr[key]==x)
        {
            arr[key]=-1;
            return ;
        }
            key=(key+1)%cap;
        }
        if(arr[key]==NULL||temp==key)
        {
            cout<<"not found"<<endl;
            return ;
        }
    }
    void printhash()
    {
        for(int i=0;i<cap;i++)
        {
            cout<<arr[i]<<endl;
        }
    }
};
int main()
{
    Myhash h(7);
    h.inserthash(1);
    h.inserthash(1);
    h.inserthash(1);
    h.deletehash(1);
    h.deletehash(1);
    h.deletehash(1);
    h.printhash();
}