#include<bits/stdc++.h>
using namespace std;
struct myhash
{
    int bucket;
    int *arr;
    myhash(int x)
    {
        bucket=x;
        arr=new int[bucket];
        for(int i=0;i<bucket;i++)
        {
            arr[i]=NULL;
        }
    }
    int hashf(int x)
    {
        return x%bucket;
    }
    void inserthash(int x)
    {
        int key=hashf(x);
        int temp=key;
        if(arr[key]==NULL||arr[key]==-1)
        {
            arr[key]=x;
            return;
        }
        key=hashf(key+1);  // key=(key+1)%bucket;
        while(arr[key]!=NULL&&arr[key]!=-1&&key!=temp)
        {
            key=(key+1)%bucket;
        }
        if(key==temp)
        {
            cout<<"overflow"<<endl;
            return ;
        }
        arr[key]=x;
        return ;
    }
    void deletehash(int x)
    {
        int key=x%bucket;
         if(arr[key]==x)
         {
             arr[key]=-1;
             return;
         }
         int temp=key;
         key=(key+1)%temp;
         while(arr[key]!=NULL&&key!=temp&&arr[key]!=x)
         {
             key=(key+1)%temp;
         }
         if(key==temp||arr[key]==NULL)
         {
             cout<<"data to be deleted not found"<<endl;
             return;
         }
         arr[key]=-1;
         return;
    }
    void search(int x)
    {
        int key=x%bucket;
        int temp=key;
        if(arr[key]==x)
        {
            cout<<"data found"<<endl;
            return ;
        }
        key=(key+1)%bucket;
        while(arr[key]!=NULL&&key!=temp&&arr[key]!=x)
        {
            key=(key+1)%bucket;
        }
        if(arr[key]==NULL||key==temp)
        {
            cout<<"data not found"<<endl;
            return ;
        }
        if(arr[key]==x)
        {
            cout<<"data found"<<endl;
            return ;
        }
    }
    void printash()
    {
        for(int i=0;i<bucket;i++)
        {
            cout<<arr[i]<<endl;
        }
    }
};
int main()
{
    myhash h1(3);
    h1.inserthash(3);
    h1.inserthash(1);
    h1.inserthash(2);
    h1.inserthash(5);
    h1.printash();
    h1.deletehash(2);
    h1.inserthash(5);
    h1.printash();
    h1.search(1);

}