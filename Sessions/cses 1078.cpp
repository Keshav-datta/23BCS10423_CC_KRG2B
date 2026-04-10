#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int MAX = 2000005;

long long fact[MAX], invFact[MAX];

long long modpow(long long a,long long b){
    long long res=1;
    while(b){
        if(b&1) res=res*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return res;
}

long long nCr(long long n,long long r){
    if(r<0 || r>n) return 0;
    return fact[n]*invFact[r]%MOD*invFact[n-r]%MOD;
}

int main(){

    int n,m;
    cin>>n>>m;

    vector<pair<int,int>> trap(m);

    for(int i=0;i<m;i++)
        cin>>trap[i].first>>trap[i].second;

    trap.push_back({n,n});
    sort(trap.begin(),trap.end());

    int limit=2*n;

    fact[0]=1;
    for(int i=1;i<=limit;i++)
        fact[i]=fact[i-1]*i%MOD;

    invFact[limit]=modpow(fact[limit],MOD-2);
    for(int i=limit;i>=1;i--)
        invFact[i-1]=invFact[i]*i%MOD;

    int k=trap.size();

    vector<long long> dp(k);

    for(int i=0;i<k;i++){

        int r=trap[i].first;
        int c=trap[i].second;

        dp[i]=nCr(r+c-2,r-1);

        for(int j=0;j<i;j++){

            int r2=trap[j].first;
            int c2=trap[j].second;

            if(c2<=c){

                long long ways=nCr((r-r2)+(c-c2),(r-r2));

                dp[i]=(dp[i]-dp[j]*ways%MOD+MOD)%MOD;
            }
        }
    }

    cout<<dp[k-1];

}
