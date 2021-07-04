/// SOURCE - NIM
/** Source file for Nim. */
#ifndef __NIM__
#define __NIM__

//_____________________________________________________________________________

// ------ IMPLEMENTATION ------ //

/** Determines if the current player has a winning nim strategy. {O(n),O(1)} */
template<class T>bool nim(vector<T>&heaps){
  T x=(T)0,n=sz(heaps);
  forn(i,n)x^=heaps[i];
  return x!=((T)0);
}

//_____________________________________________________________________________

#endif // __NIM__
