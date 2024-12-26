#include <bits/stdc++.h>
using namespace std;
vector<int> *a,*rev;
bool *visited;
int *truoc,v,e;
vector<pair<int,int>> tmp;
void graph(void)
{
    cin>>v>>e;
    a=new vector<int>[v+1];
    rev=new vector<int>[v+1];
    for(int i=1;i<=e;i++)
    {
        int u,v1;
        cin>>u>>v1;
        if(u<=v && v1<=v) tmp.push_back({u,v1});
        a[u].push_back(v1);
        rev[v1].push_back(u);
    }
}
void visited1(void)
{
    visited=new bool[v+1];
    truoc=new int[v+1];
    for(int i=1;i<=v;i++) {visited[i]=false;truoc[i]=0;}
}
void dfs1(int u)
{
    visited[u]=true;
    for(int i=0;i<a[u].size();i++) if(!visited[a[u][i]])
    {
        truoc[a[u][i]]=u;
        dfs1(a[u][i]);
    }
}
void dfs2(int u)
{
    visited[u]=true;
    for(int i=0;i<rev[u].size();i++) if(!visited[rev[u][i]])
    {
        truoc[rev[u][i]]=u;
        dfs2(rev[u][i]);
    }
}
string ham(void)
{
    graph();
    visited1();
    dfs1(1);
    for(int i=1;i<=v;i++) if(!visited[i]) return "NO";
    visited1();
    dfs2(1);
    for(int i=1;i<=v;i++) if(!visited[i]) return "NO";
    return "YES";
}
int main()
{
    int w;
    cin>>w;
    while(w--)
    {
        string kq=ham();
        cout<<kq<<endl;
    }
    return 0;
}
