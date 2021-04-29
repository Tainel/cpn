/// SOURCE - BINARY SEARCH
/** Source file for Binary Search. */
#ifndef __BINARY_SEARCH__
#define __BINARY_SEARCH__

//_____________________________________________________________________________

// ------ IMPLEMENTATION ------ //

/** Returns the index of x in sorted v in range [l,r), or -1 if not in range.
 * {O(log2(r-l)),O(1)} */
template<class T>int bs(vector<T>&v,T x,int l=-1,int r=-1){
  if(l<0)l=0;
  if(r<0)r=sz(v);
  while (l<r) {
    int m=l+(unsigned(r-l-1)>>1);
    if(v[m]==x) return m;
    l=(v[m]<x)?m+1:(r=m,l);
  }
  return -1;
}

//_____________________________________________________________________________

#endif // __BINARY_SEARCH__
