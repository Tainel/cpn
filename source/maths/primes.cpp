/// SOURCE - PRIMES
/** Source file for Primes. */
#ifndef __PRIMES__
#define __PRIMES__

//_____________________________________________________________________________

// ------ IMPLEMENTATION ------ //

/** Tries to determine if n is prime. {O(log2(n)^2),O(1)} */
bool maybe_prime(ull n,ull a,ull d,int s){
  if (n==a) return true;
  ull x=expmod(a,d,n);
  if ((x==1)||(x+1==n)) return true;
  forr(_,1,s){
    x=mulmod(x,x,n);
    if(x==1)return false;
    if(x+1==n)return true;
  }
  return false;
}

/** Determines if n is prime. {O(log2(n)^2),O(1)} */
bool miller_rabin(ull n){
  if(n<2)return false;
  int s=0; ull d=n-1; while(!(d&1))d>>=1,++s;
  static const int bases[]={2,3,5,7,11,13,17,19,23,29,31,37};
  fore(a,bases)if(!maybe_prime(n,a,d,s))return false;
  return true;
}

/** Returns a prime sieve of size n+1. {O(n*log2(log2(n))),O(n)} */
vector<int>get_sieve(int n=MAXN){
  vector<int>sieve(++n);
  static const int w[]={4,2,4,2,4,6,2,6};
  for (int p=25; p<n; p+=10)sieve[p]=5;
  for (int p=9; p<n; p+=6)sieve[p]=3;
  for (int p=4; p<n; p+=2)sieve[p]=2;
  for (int p=7,cur=0;p*p<n;p+=w[cur++&7])
    if (!sieve[p])
      for (int j = p*p; j < n; j+=(unsigned(p)<<1))
        if (!sieve[j]) sieve[j] = p;
  return sieve;
}

/** Returns all primes smaller than or equal to n. {O(n),O(pi(n))} */
vector<int>get_primes(int n=MAXN){
  vector<int>sieve=get_sieve(n);
  vector<int>primes;forr(i,2,n)if(!sieve[i])primes.pb(i);
  return primes;
}

//_____________________________________________________________________________

#endif // __PRIMES__
