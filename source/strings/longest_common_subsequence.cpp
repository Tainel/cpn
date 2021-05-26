/// SOURCE - LONGEST COMMON SUBSEQUENCE
/** Source file for Longest Common Subsequence. */
#ifndef __LONGEST_COMMON_SUBSEQUENCE__
#define __LONGEST_COMMON_SUBSEQUENCE__

//_____________________________________________________________________________

// ------ IMPLEMENTATION ------ //

/** Returns the maximum common subsequence between two strings. {O(n*m),=} */
template<class T>T lcs(T& str1,T& str2){
  int n=sz(str1),m=sz(str2); T s;
  vector<vector<int>>dp(n+1,vector<int>(m+1));
  forr(i,1,n+1)
    forr(j,1,m+1)
      if(str1[i-1]==str2[j-1])dp[i][j]=dp[i-1][j-1]+1;
      else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
  for(int i=n,j=m;i>0&&j>0;) {
    if(str1[i-1]==str2[j-1])s.pb(str1[i-1]),--i,--j;
    else if(dp[i-1][j]>dp[i][j-1])--i;
    else --j;
  }
  reverse(all(s));
  return s;
}

//_____________________________________________________________________________

#endif // __LONGEST_COMMON_SUBSEQUENCE__
