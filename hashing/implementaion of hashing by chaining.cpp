#include<bits/stdc++.h>
using namespace std;
struct myhash
{
    int bucket;
    list<int>*table;
    myhash(int b)
    {
        bucket=b;
        table=new list<int>[bucket];
    }
    int hashf(int x)
    {
        return x%bucket;
    }
    void inserthash(int x)
    {
        int key=hashf(x);
        table[key].push_back(x);
    }
    void deletehash(int x)
    {
        int key=hashf(x);
        table[key].remove(x);
    }
    void printhash()
    {
        for(int i=0;i<bucket;i++)
        {
            if(table[i].size()==0)
            continue;
            for(auto it=table[i].begin();it!=table[i].end();it++)
            {
                cout<<*it<<" ";
            }
            cout<<endl;
        }
    }
    void search(int x)
    {
        int key=hashf(x);
        for(auto it=table[key].begin();it!=table[key].end();it++)
        {
            if(*it==x)
            {
                cout<<"found"<<endl;
                return ;
            }
        }
        cout<<"not found"<<endl;
        return ;
    }

};
int main()
{
    myhash h1(7);
    h1.inserthash(1);
    h1.inserthash(7);
    h1.inserthash(45);
    h1.inserthash(89);
    h1.inserthash(1000);
    h1.printhash();
    h1.search(1000);

}