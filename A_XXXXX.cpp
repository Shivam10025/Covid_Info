////////////////////////////////////////////////////
//                                                //
//        Coded by Shivam Bindal                  //
//                                                //
////////////////////////////////////////////////////
#include <bits/stdc++.h>
#include <algorithm>
#include <set>
#include <math.h>
#include <vector>
#define ll long long
#define cn cout<<"NO\n"
#define cy cout<<"YES\n"
#define cm cout<<"-1\n"
#define vl vector<ll>v
#define sl set<ll>v
#define ff first
#define ss second
#define sc set<char>v
#define elif else if
#define nl endl
#define MOD 1000000007
#define key             pair<ll,ll>
#define mode 1000000009
#define mo 10000005
using namespace std;
void SieveOfEratosthenes(ll n, bool prime[],bool primesquare[], ll a[]){
    for (ll i = 2; i <= n; i++)
        prime[i] = true;
    for (ll i = 0; i <= (n * n + 1); i++)
        primesquare[i] = false;
    prime[1] = false;
    for (ll p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (ll i = p * 2; i <= n; i += p)
                prime[i] = false;
        }
    }
    ll j = 0;
    for (ll p = 2; p <= n; p++) {
        if (prime[p]){
            a[j] = p;
            primesquare[p * p] = true;
            j++;
        }
    }
}
ll countDivisors(ll n)
{
    if (n == 1)
        return 1;
    bool prime[n + 1], primesquare[n * n + 1];
    ll a[n];
    SieveOfEratosthenes(n, prime, primesquare, a);
    ll ans = 1;
    for (ll i = 0;; i++) {
        if (a[i] * a[i] * a[i] > n)break;
        ll cnt = 1;
        while (n % a[i] == 0){
            n = n / a[i];
            cnt = cnt + 1;
        }
        ans = ans * cnt;
    }
    if (prime[n])
        ans = ans * 2;
    else if (primesquare[n])
        ans = ans * 3;
    else if (n != 1)
        ans = ans * 4;
    return ans;
}
ll powerLL(ll x, ll n){
    ll result = 1;
    while (n) {
        if (n & 1)
            result = result * x % MOD;
        n = n / 2;
        x = x * x % MOD;
    }
    return result;
}
void reduceFraction(ll x, ll y){
    ll d;
    d = __gcd(x, y);
    x = x / d;
    y = y / d;
    cout<<x+y<<endl;
}
ll getSum(ll BITree[], ll index) {
    ll sum = 0; 
    index = index + 1; 
    while (index>0) { 
        sum += BITree[index]; 
        index -= index & (-index); 
    } 
    return sum; 
} 
void updateBIT(ll BITree[], ll n, ll index, ll val) { 
    index = index + 1; 
    while (index <= n) { 
        BITree[index] += val; 
        index += index & (-index); 
    } 
}
ll *constructBITree(ll arr[], ll n) { 
    ll *BITree = new ll[n+1]; 
    for (ll i=1; i<=n; i++) BITree[i] = 0; 
    for (ll i=0; i<n; i++) updateBIT(BITree, n, i, arr[i]); 
    return BITree; 
} 
bool isPalindrome(string s){
    ll length = s.size();
    stack<char> st;
    ll i, mid = length / 2;
 
    for (i = 0; i < mid; i++) {
        st.push(s[i]);
    }
    if (length % 2 != 0) {
        i++;
    }
    char ele;
    while (s[i] != '\0'){
         ele = st.top();
         st.pop();
     if (ele != s[i])
        return false;
        i++;
    }
 return true;
}
bool isPrime(ll n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
  
    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;
  
    for (ll i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
  
    return true;
}
ll getSubarraySum(ll sum[], ll i, ll j)
{
    if (i == 0)
        return sum[j];
    else
        return (sum[j] - sum[i - 1]);
}

ll find(ll n){
    ll ans=0;
    while(n%2==0){
        n=n/2;
        ans++;
    }
    for(ll i=3;i*i<=n;i+=2){
        while(n%i==0)
        {
            n=n/i;
            ans++;
        }
    }
    if(n>1)
    ans++;
    return ans;
}
struct co{
    ll x,y;
};
ll f(ll x1,ll y1,ll x2,ll y2,ll i,ll j){
    ll ans=abs(x1-i)+abs(y1-j)+abs(x2-x1)+abs(y2-y1)+abs(x2-i)+abs(y2-j);
    return ans;
}
void solvee(){
    ll e;
    cin>>e;
    while(e--){
        ll n , x;
        cin>>n>>x;
        ll a[n];
        ll sum=0;
        for(ll i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        if(sum%x!=0){
            cout<<n<<endl;
        }
        else{
            ll p=-1 , q=-1;
            ll flag=0;
            for(ll i=0;i<n;i++){
                if(a[i]%x!=0){
                    flag=1;
                    break;
                }
            }
            for(ll i=0;i<n;i++){
                if(a[i]%x!=0){
                    p = i+1;
                    break;
                }
            }
            for(ll i=n-1;i>=0;i--){
                if(a[i]%x!=0){
                    q = n-i;
                    break;
                }
            }
            if(flag==0){
                cout<<-1<<endl;
            }
            else{
                cout<<n - min(p , q)<<endl;
            }
        }
    }
}
void solve(){
    ll n , m , a , b;
    cin>>n>>m>>a>>b;
    ll c = n*a;
    c = min(c , ((n%m)*a) + ((n/m)*b));
    c = min(c , ((n+m-1)/(m))*b);
    cout<<c<<endl;
}
int main(){
    solvee();
    //solve();
    return 0;
}
