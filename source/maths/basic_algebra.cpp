/// SOURCE - BASIC ALGEBRA
/** Source file for Basic Algebra. */
#ifndef __BASIC_ALGEBRA__
#define __BASIC_ALGEBRA__

//_____________________________________________________________________________

// ------ IMPLEMENTATION ------ //

/** Returns the floor of the square root of x. {O(log2(x)),O(1)} */
ull sqrtbs(ull x) {
  if(x<2)return x;
  ull s=0;
  for(ull l=1,r=x;l<=r;){
    ull m=l+((r-l)>>1),t;
    if (m>=(1ULL<<32)) r=m-1;
    else if((t=m*m)==x) return m;
    else if(t<x)l=m+1,s=m;
    else r=m-1;
  }
  return s;
}

/** Returns {x,y} where a*x+b*y = gcd(a,b). {O(log2(a+b)),=} */
pair<ull,ull>extended_euclidean(ull a,ull b){
  if(!b)return{1,0};
  pair<ull,ull> c = extended_euclidean(b,a%b);
  return{c.snd,c.fst-(a/b)*c.snd};
}

/** Returns the GCD of a and b. {O(log2(a+b)),=} */
ull gcd(ull a,ull b){return (b)?gcd(b,a%b):a;}

/** Returns the LCM of a and b. {O(log2(a+b)),=} */
ull lcm(ull a,ull b){return (a/gcd(a,b))*b;}

//_____________________________________________________________________________

#endif // __BASIC_ALGEBRA__
