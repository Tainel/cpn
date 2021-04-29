/// SOURCE - COMBINATORICS
/** Source file for Combinatorics. */
#ifndef __COMBINATORICS__
#define __COMBINATORICS__

//_____________________________________________________________________________

// ------ IMPLEMENTATION ------ //

/** Factorial tables for combinatorics using modular arithmetic. */
class ModTable {
  public:
    int n,m; // size and modulo
    vector<int>inv,fct,ift; // tables
    ModTable(int _n=MAXN,int _m=MOD);
    int kperm(int r,int k);
    int combs(int r,int k);
    int dists(int r,int k);
    int catalan(int r);
    pair<int,ll>wilson(ll r);
};

/** Initializes the factorial tables using dp. {O(n),=} */
ModTable::ModTable(int _n,int _m):n(_n),m(_m),inv(_n+1),fct(_n+1),ift(_n+1){
  inv[1]=1; forr(i,2,n+1) inv[i]=m-int((ll)(m/i)*inv[m%i]%m);
  fct[0]=1; forr(i,1,n+1) fct[i]=int((ll)fct[i-1]*i%m);
  ift[0]=1; forr(i,1,n+1) ift[i]=int((ll)ift[i-1]*inv[i]%m);
}

/** Returns (rPk)%m. {O(1),=} */
int ModTable::kperm(int r,int k){return (r<k)?0:int((ll)fct[r]*ift[r-k]%m);}

/** Returns (rCk)%m. {O(1),=} */
int ModTable::combs(int r,int k){
  return (r<k)?0:int((ll)fct[r]*ift[k]%m*ift[r-k]%m);
}

/** Returns ((r+k-1)Cr)%m. {O(1),=} */
int ModTable::dists(int r,int k){return combs(r+k-1,r);}

/** Returns the r-th Catalan number mod m. {O(1),=} */
int ModTable::catalan(int r){return int((ll)fct[2*r]*ift[r+1]%m*ift[r]%m);}

/** Returns {a%m,k} such that r! = a*(m^k). {O(log(r,m)),=} */
pair<int,ll>ModTable::wilson(ll r){
  if(r<m)return{fct[r],0};
  ll d=r/m; pair<int,ll>p=wilson(d);
  return{int((ll)p.fst*fct[r%m]%m*(d&1?m-1:1)%m),p.snd+d};
}

/** Table of binomial coefficients. */
class Pascal {
  public:
    int n,m; // size and modulo
    vector<vector<int>>t; // binomial coefficients
    Pascal(int _n=3000,int _m=2999);
    int lucas(ll r,ll k);
};

/** Initializes t such that t[i][j] = (iCj)%m. {O(n^2),=} */
Pascal::Pascal(int _n,int _m):n(_n),m(_m),t(_n+1,vector<int>(_n+1)){
  forn(i,n+1){t[i][0]=t[i][i]=1;forr(j,1,i)t[i][j]=(t[i-1][j-1]+t[i-1][j])%m;}
}

/** Returns (rCk)%m. {O(log(r,m)),O(1)} */
int Pascal::lucas(ll r,ll k){
  if(r<k)return 0;
  int c=1; while(r+k)c=int((ll)c*t[r%m][k%m]%m),r/=m,k/=m; return c;
}

/** Table of set partitions. */
class SBell {
  public:
    int n,m; // size and modulo
    vector<vector<int>>s; // Stirling numbers
    vector<int>bell; // Bell numbers
    SBell(int _n=3000,int _m=MOD);
};

/** Initializes the table of Stirling and Bell numbers mod m. {O(n^2),=} */
SBell::SBell(int _n,int _m):n(_n),m(_m),s(_n+1,vector<int>(_n+1)),bell(_n+1){
  forr(i,1,n+1) s[i][1]=1; forr(i,2,n+1) s[1][i]=0;
  forr(i,2,n+1)forr(j,2,n+1)s[i][j]=int((s[i-1][j-1]+(ll)j*s[i-1][j]%m)%m);
  forn(i,n+1) forn(j,n+1) bell[i]=(bell[i]+s[i][j])%m;
}

//_____________________________________________________________________________

#endif // __COMBINATORICS__
