/// SOURCE - PALINDROMES
/** Source file for Palindromes. */
#ifndef __PALINDROMES__
#define __PALINDROMES__

//_____________________________________________________________________________

// ------ IMPLEMENTATION ------ //

/** Determines if str is a palindrome. {O(n),O(1)} */
template<class T>bool is_palindrome(T& str){
  unsigned n=(unsigned)sz(str),k=n>>1;
  forn(i,k)if(str[i]!=str[n-i-1])return false;
  return true;
}

/** Given str, returns d1 and d2 such that d1[i] is the size of the longest odd
 * palindrome centered in str[i] and d2[i] is the size of the longest even
 * palindrome centered in str[i-1|i]. {O(n),=} */
template<class T>pair<vector<int>,vector<int>>manacher(T& str){
  int n=sz(str); vector<int>d1(n),d2(n);
  for(int i=0,l=0,r=-1;i<n;++i){
    int k=(i>r)?1:min(d1[l+r-i],r-i+1);
    while(0<=i-k&&i+k<n&&str[i-k]==str[i+k])++k;
    d1[i]=k--; if(i+k>r)l=i-k,r=i+k;
  }
  for (int i=0,l=0,r=-1;i<n;++i){
    int k=(i>r)?0:min(d2[l+r-i+1],r-i+1);
    while(0<=i-k-1&&i+k<n&&str[i-k-1]==str[i+k])++k;
    d2[i]=k--; if(i+k>r)l=i-k-1,r=i+k;
  }
  return {d1,d2};
}

//_____________________________________________________________________________

#endif // __PALINDROMES__
