/// SOURCE - MODULAR ARITHMETIC
/** Source file for Modular Arithmetic. */
#ifndef __MODULAR_ARITHMETIC__
#define __MODULAR_ARITHMETIC__

//_____________________________________________________________________________

// ------ IMPLEMENTATION ------ //

/** Returns (a*b)%m. {O(log2(b)),O(1)} */
ull mulmod(ull a,ull b,ull m=(ull)MOD){
  if(a<(1ULL<<32)&&b<(1ULL<<32)) return a*b%m;
  ull r=0;
  for(a%=m,b%=m;b;b>>=1,a<<=1,a=(a>=m)?a-m:a){if(b&1){r+=a;if(r>=m)r-=m;}}
  return r;
}

/** Returns (b^e)%m. {O(log2(e)*log2(b)),O(1)} */
ull expmod(ull b,ull e,ull m=(ull)MOD){
  ull ans=1; b%=m; while(e){if(e&1)ans=mulmod(ans,b,m);b=mulmod(b,b,m),e>>=1;}
  return ans;
}

/** Returns c such that (c*a)%m = 1. {O(log2(m)),O(1)} */
ull invmod(ull a,ull m=MOD){return expmod(a,m-2,m);}

//_____________________________________________________________________________

#endif // __MODULAR_ARITHMETIC__
