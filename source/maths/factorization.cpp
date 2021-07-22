/// SOURCE - FACTORIZATION
/** Source file for Factorization. */
#ifndef __FACTORIZATION__
#define __FACTORIZATION__

//_____________________________________________________________________________

// ------ IMPLEMENTATION ------ //

/** Factorizes x <= sz(sieve). {O(log2(x)),O(q(x))} */
map<ull,int>sieve_fact(int x,vector<int>&sieve){
  map<ull,int>facts;
  while(sieve[x])++facts[sieve[x]],x/=sieve[x];
  if(x>1)++facts[x];
  return facts;
}

/** Factorizes x <= sz(primes)^2. {O(pi(x)),O(q(x))} */
map<ull,int>prime_fact(ull x,vector<int>&primes){
  map<ull,int> facts;
  fore(p,primes){while(!(x%p))++facts[p],x/=p;if(x==1)break;}
  if (x>1)++facts[x];
  return facts;
}

/** Returns a non trivial factor of x. {O(sqrt(sqrt(x))*log2(x)),O(1)} */
ull pollard_rho(ull x){
  if((x&1)==0)return 2;
  ull r=2,y=2,d=1,b=irnd64(1,x),c=irnd64(1,x);
  while(d==1){
    r=(mulmod(r,r+b,x)+c)%x,y=(mulmod(y,y+b,x)+c)%x;
    y=(mulmod(y,y+b,x)+c)%x,d=gcd((r<y)?y-r:r-y,x);
  }
  return (d==x)?pollard_rho(x):d;
}

/** Stores in facts the factorization of x. {O(log2(x)^3),=} */
void rho_fact(ull x,map<ull,int>&facts){
  if(x==1)return;
  if(miller_rabin(x)){++facts[x];return;}
  ull f=pollard_rho(x); rho_fact(f,facts),rho_fact(x/f,facts);
}

//_____________________________________________________________________________

#endif // __FACTORIZATION__
