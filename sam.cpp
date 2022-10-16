#include <bits/stdc++.h>
#include <cstring>
#define ll long long
#define repa(i,a,b) for(ll i = a; i <= b; i++)
#define repd(i,a,b) for(ll i = a; i >= b; i--)
#define lli unsigned long long
#define pb push_back
#define in insert
#include <bits/stdc++.h>
#define cn cout << "NO\n"
#define cy cout << "YES\n"
#define cm cout << "-1\n"
#define nl cout << "\n"
#define vv vector<ll> v
#define eli else if
#define el else
#define ss set<ll> s
#define MOD 1000000007
#define mode 1000000009
#define SPEED ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

ll powerexp(ll x, ll n)
{
    ll result = 1;
    while (n)
    {
        if (n & 1)
            result = result * x % MOD;
        n = n / 2;
        x = x * x % MOD;
    }
    return result;
}

ll parent[1];
ll ranks[1];

void initialize()
{
    for (ll i = 0; i < 1; i++)
    {
        parent[i] = i;
        ranks[i] = 0;
    }
}

ll find(ll x)
{
    if (parent[x] == x)
        return x;

    parent[x] = find(parent[x]);

    return parent[x];
}

void unions(ll x, ll y)
{
    ll x_rep = find(x);
    ll y_rep = find(y);

    if (x_rep == y_rep)
        return;

    if (ranks[x_rep] < ranks[y_rep])
        parent[x_rep] = y_rep;

    else if (ranks[y_rep] < ranks[x_rep])
        parent[y_rep] = x_rep;
    else
    {
        parent[y_rep] = x_rep;

        ranks[x_rep]++;
    }
}
set <ll> primeFactors(ll n) 
{ 
    // Prll the number of 2s that divide n 
    set <ll> s;
    while (n % 2 == 0) 
    { 
       // cout << 2 << " "; 
       s.insert(2);
        n = n/2; 
    } 

    // n must be odd at txxs poll. So we can skip 
    // one element (Note i = i +2) 
    for (ll i = 3; i <= sqrt(n); i = i + 2) 
    { 
        // while i divides n, prll i and divide n 
        while (n % i == 0) 
        { 
           // cout << i << " "; 
           s.insert(i);
            n = n/i; 
        } 
    } 

    // Txxs condition is to handle the case when n 
    // is a prime number greater than 2 
    if (n > 2) s.insert(n);
      //  cout << n << " "; 
      return s;
} 
ll facto(ll n){
    ll res = 1, i;
    for (i = 2; i <= n; i++)
        res =  (res*i)%998244353;
    return res%998244353;
}
vector<ll>  printDivisors2(ll n)
{
    // Note that txxs loop runs till square root
    vector<ll> v;
    for (ll i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            // If divisors are equal, prll only one
            if (n/i == i){
             //   cout <<" "<< i;
               v.push_back(i);}

            else{ // Otherwise prll both
              //  cout << " "<< i << " " << n/i;
                 v.push_back(i);  
                 v.push_back(n/i);
                }
        }
    }
    return v;
}

bool isPrime(ll n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;
  
    for (ll i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
  
    return true;
}
//  cout << flush;

ll fun(vector<vector<ll>> &a, ll i, ll par,vector<bool> &vis, vector<ll> &visnode)
{
   // if(vis[i]) return false;
   visnode.push_back(i);
   bool f = false;
   ll res =0;
  // cout << i+1<<" " << par+1<<" ";
    for (auto x:a[i])
    {
        if(vis[x]==false){
            vis[x]= true;
         if(fun(a,x,i,vis,visnode)) f= true;
        }else{
            if(x!=par) f= true;
        }
    }
    return f;
    
}
//Solution::
int solve(vector<int> &A ,vector<int> &B ){
    vector<int> x(32,0);
    vector<int> y(32,0);
    for(int i=0;i<A.size();i++){
        int z= A[i];
        int j=0;
        while (z!=0)
        {
            if(z%2==1){
                x[j]++;
            }
            j++;
            z/=2;
        }
        
    }
    for(int i=0;i<B.size();i++)
    {
        int z = B[i];
        int j=0;
        while (z!=0)
        {
            if(z%2==1){
                y[j]++;
            }
            j++;
            z/=2;
        }  
    }
    
    int res =0;
    int c=1;
    for (int i = 0; i < 32; i++)
    {
       
       if(x[i]!=0 || y[i]!=0)
       {
        if(x[i]!=0 && y[i]!=0)
        {
            if(((B.size()*x[i]) + ((A.size()-x[i])*y[i]))%2==1){
                res += c;
            }
        }else{
            if(x[i]==0)
            {
                if((A.size()*y[i])%2==1){
                     res += c;
                }
            }else if(y[i]==0)
            {
                if((B.size()*x[i])%2==1){
                     res += c;
                }
            }
        }
       }
       c*=2;
    }
    return res;
    
}

int main()
{
     SPEED;
    ll t = 1;
   cin >> t;
    while (t--)
    {
       ll n , k;
       cin >> n >> k;
       ll a[n];
       ll b[n];
       ll sum=0;
       for (ll i = 0; i < n; i++)
       {
         cin >> a[i];
         sum += a[i];
       }
       for (ll i = 0; i < n; i++)
       {
         cin >> b[i];
       }
       sort(b,b+n,greater<ll> ());
       sort(a,a+n,greater<ll> ());
       sum =0;
       ll j1=0, j2=0;
       for (ll i = 0; i < n; i++)
       {
        if(a[j1]>b[j2]){
            sum += a[j1];
            j1++;

        }else{
            if(k>0){
                k--;
                sum += b[j2];
                j2++;
            }else{
                 sum += a[j1];
            j1++;
            }
        }

       }
       

       cout << sum << endl;
       
       
        
    }

    return 0;
}


