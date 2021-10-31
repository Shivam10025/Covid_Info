#include<bits/stdc++.h>
#include<string>
#include <algorithm>
#include <set>
#include <math.h>
#include <vector>
#define ll long long
#define repi(i,a,b) for(ll i=a;i<=b;i++)
#define repd(i,a,b) for(ll i=a;i>=b;i--)
#define cy cout<<"YES\n"
#define cn cout<<"NO\n"
#define MOD 1000000009
#define vi vector<int>
#define vl vector<ll>
#define ql queue<ll>
#define pb push_back
#define nl cout<<"\n"
#define cm cout<<"-1\n"
using namespace std;

void addEdge(vl adj[], ll u, ll v){
     adj[u].pb(v);
     adj[v].pb(u);
}

void BFS(vi adj[], ll v, ll s){
    bool visited[v+1];
    repi(i,0,v-1){
        visited[i]=false;
    }
    ql q;
    visited[s]=true;
    q.push(s);
    while(q.empty()==false){
        ll u=q.front();
        q.pop();
        cout<<u<<" ";
        for(int v:adj[u]){
            if(visited[v]==false){
                visited[v]=true;
                q.push(v);
            }
        }
    }
}

int main(){
    ll v=4;
    vl adj[v];
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,2,3);
    addEdge(adj,2,4);
    addEdge(adj,3,4);

}