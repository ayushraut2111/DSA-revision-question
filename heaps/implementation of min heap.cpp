#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct minheap{
    int *arr;
    int size,cap;
    minheap(int c)
    {
        cap=c;
        size=0;
        arr=new int[cap];
    }
    int lchild(int i)
    {
        return 2*i+1;
    }
    int rchild(int i)
    {
        return 2*i+2;
    }
    int parent(int i)
    {
        return (i-1)/2;
    }
    void insertheap(int x)
    {
        if(size==cap)
        {
            cout<<"heap is full"<<endl;
            return;
        }
        arr[size]=x;
        size++;
        int i=size-1;
        while(arr[i]<arr[parent(i)]&&i!=0)
        {
            swap(arr[i],arr[parent(i)]);
            i=parent(i);
        }
    }
    void minheapify(int i)
    {
        int lt=lchild(i);
        int rt=rchild(i);
        int smallest=i;
        if(lt<size&&arr[i]>arr[lt])
        {
            smallest=lt;
        }
        if(rt<size&&arr[smallest]>arr[rt])
        {
            smallest=rt;
        }
        if(smallest!=i)
        {
            swap(arr[i],arr[smallest]);
            minheapify(smallest);
        }
    }
};
int main()
{
    
}