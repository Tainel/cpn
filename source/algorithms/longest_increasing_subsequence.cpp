/// SOURCE - LONGEST INCREASING SUBSEQUENCE
/** Source file for Longest Increasing Subsequence. */
#ifndef __LONGEST_INCREASING_SUBSEQUENCE__
#define __LONGEST_INCREASING_SUBSEQUENCE__

//_____________________________________________________________________________

// ------ IMPLEMENTATION ------ //

/** Returns the lis in v. {O(n*log2(n)),O(n)} */
template<class T=ll>vector<T>lis(vector<T>&v,T ninf=-INF,T inf=INF){
  int n=sz(v); vector<int>p(n); vector<T>ans;
  vector<pair<T,int>>d(n+1); d[0]={ninf,-1}; forn(i,n)d[i+1]={inf,-1};
  forn(i,n) {
    int j=int(ub(all(d),mp(v[i],INT_MAX))-d.begin());
    if (d[j-1].fst<v[i]&&v[i]<d[j].fst) p[i]=d[j-1].snd,d[j]={v[i],i};
  }
  dforn(i,n+1)
    if (!(d[i].fst==inf)) {
      for (int k=d[i].snd;k!=-1;k=p[k]) ans.pb(v[k]);
      reverse(all(ans)); break;
    }
  return ans;
}

//_____________________________________________________________________________

#endif // __LONGEST_INCREASING_SUBSEQUENCE__
