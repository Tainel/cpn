/// SOURCE - RANGE MINIMUM QUERY
/** Source file for Range Minimum Query. */
#ifndef __RANGE_MINIMUM_QUERY__
#define __RANGE_MINIMUM_QUERY__

//_____________________________________________________________________________

// ------ IMPLEMENTATION ------ //

/** Sparse Table for idempotent operations over static ranges. */
template<class T=ll>class RMQst {
  public:
    typedef const T&(*F)(const T&,const T&); // type of idempotence
    int n,k; // size and depth
    vector<int>logs; // logarithms
    vector<vector<T>>st; // table
    F op; // idempotence
    RMQst(vector<T>&a,F _op=min);
    T get(int l,int r);
};

/** Initializes the sparse table. {O(n*log2(n)),=} */
template<class T>RMQst<T>::RMQst(vector<T>&a,F _op){
  n=sz(a),logs.resize(n+1),logs[0]=-1,op=_op;
  forr(i,2,n+1)logs[i]=logs[unsigned(i)>>1]+1;
  k=logs[n]+1,st.resize(n,vector<T>(k));
  forn(i,n)st[i][0]=a[i];
  forr(j,1,k)
    for(int i=0;i+(1<<j)<=n;++i)
      st[i][j]=op(st[i][j-1],st[i+(1<<(j-1))][j-1]);
}

/** Returns op in [l,r). {O(1),=} */
template<class T>T RMQst<T>::get(int l,int r){
  int j=logs[r-l];
  return op(st[l][j],st[r-(1<<j)][j]);
}

//_____________________________________________________________________________

#endif // __RANGE_MINIMUM_QUERY__
