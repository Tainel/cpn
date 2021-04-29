/// SOURCE - FENWICK TREE
/** Source file for Fenwick Tree. */
#ifndef __FENWICK_TREE__
#define __FENWICK_TREE__

//_____________________________________________________________________________

// ------ IMPLEMENTATION ------ //

/** Fenwick Tree for associative, invertible and neutral-element operations
 * on ranges. */
template<class T=ll>class Fenwick {
  public:
    typedef T(*F)(const T&,const T&); // type of operation and inverse
    typedef T(*G)(const T&,int); // type of product
    int n; // number of nodes
    T z; // neutral element
    vector<T>t,w; // trees
    F op,inv; // operation and inverse
    G mul; // product
    Fenwick(int _n=MAXN,T _z=0,F _op=nullptr,F _inv=nullptr,G _mul=nullptr);
    void update(int l,int r,T v);
    void update(int i,T v);
    T query(int l,int r);
    T query(int i);
};

/** Initializes an empty Fenwick Tree. {O(n),=} */
template<class T>Fenwick<T>::Fenwick(int _n,T _z,F _op,F _inv,G _mul){
  n=_n,z=_z; t.resize(n,z),w.resize(n,z);
  op=_op?_op:[](const T&s,const T&v){return s+v;};
  inv=_inv?_inv:[](const T&s,const T&v){return s-v;};
  mul=_mul?_mul:[](const T&v,int i){return v*i;};
}

/** Applies op in [l,r) with v. {O(log2(n)),O(1)} */
template<class T>void Fenwick<T>::update(int l,int r,T v) {
  T mv=mul(v,l);
  for(int i=l+1;i<=n;i+=(i&-i))t[i-1]=op(t[i-1],v),w[i-1]=op(w[i-1],mv);
  mv=mul(inv(z,v),r),v=inv(z,v);
  for(int i=r+1;i<=n;i+=(i&-i))t[i-1]=op(t[i-1],v),w[i-1]=op(w[i-1],mv);
}

/** Applies op in [i] with v. {O(log2(n)),O(1)} */
template<class T>void Fenwick<T>::update(int i,T v){update(i,i+1,v);}

/** Returns op in [l,r). {O(log2(n)),O(1)} */
template<class T>T Fenwick<T>::query(int l,int r){
  T s=z,d=z; for(int j=r;j>0;j-=(j&-j))s=op(s,t[j-1]),d=op(d,w[j-1]);
  T f=z,g=z; for(int j=l;j>0;j-=(j&-j))f=op(f,t[j-1]),g=op(g,w[j-1]);
  return inv(inv(mul(s,r),d),inv(mul(f,l),g));
}

/** Returns op in [i]. {O(log2(n)),O(1)} */
template<class T>T Fenwick<T>::query(int i){return query(i,i+1);}

//_____________________________________________________________________________

#endif // __FENWICK_TREE__
