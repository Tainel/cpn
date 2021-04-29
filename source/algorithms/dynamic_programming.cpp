/// SOURCE - DYNAMIC PROGRAMMING
/** Source file for Dynamic Programming. */
#ifndef __DYNAMIC_PROGRAMMING__
#define __DYNAMIC_PROGRAMMING__

//_____________________________________________________________________________

// ------ IMPLEMENTATION ------ //

/** Returns dp of size k+1 such that dp[i] is the maximum possible value after
 * evaluating [0,n) with capacity i. {O(n*k),O(k)} */
template<class T>vector<T>knapsack(vector<T>&val,vector<int>&w,int k){
  int n=sz(val); vector<T>dp(k+1);
  forn(i,n)
    for(int j=k;j>=w[i];--j)
      dp[j]=max(dp[j],dp[j-w[i]]+val[i]);
  return dp;
}

//_____________________________________________________________________________

#endif // __DYNAMIC_PROGRAMMING__
