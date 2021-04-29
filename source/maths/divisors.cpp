/// SOURCE - DIVISORS
/** Source file for Divisors. */
#ifndef __DIVISORS__
#define __DIVISORS__

//_____________________________________________________________________________

// ------ IMPLEMENTATION ------ //

/** Stores in d the divisors of x already factored, starting from the first
 * factor. {O(d(x)),=} */
void get_divs(vector<ull>&d,map<ull,int>&f,map<ull,int>::iterator i,ull r=1){
  if(i==f.begin())d.clear();
  if(i==f.end()){d.pb(r);return;}
  ull p=i->fst,k=i->snd+1;++i; while(k--)get_divs(d,f,i,r),r*=p;
}

/** Returns the number of divisors of x already factored. {O(q(x)),O(1)} */
ull num_divs(map<ull,int>&facts){ull n=1;fore(e,facts)n*=(e.snd+1);return n;}

/** Returns the sum of divisors of x already factored. {O(q(x)*k(x)),O(1)} */
ull sum_divs(map<ull,int>&facts){
  ull sum=1;
  fore(e,facts){ull pot=1,aux=0;forn(i,e.snd+1)aux+=pot,pot*=e.fst;sum*=aux;}
  return sum;
}

//_____________________________________________________________________________

#endif // __DIVISORS__
