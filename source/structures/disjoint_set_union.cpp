/// SOURCE - DISJOINT SET UNION
/** Source file for Disjoint Set Union. */
#ifndef __DISJOINT_SET_UNION__
#define __DISJOINT_SET_UNION__

//_____________________________________________________________________________

// ------ IMPLEMENTATION ------ //

/** Storage of disjoint sets according to their size. */
class DSUnion {
  public:
    int n,m; // number of elements and sets
    vector<pair<int,int>>s; // sets
    DSUnion(int _n=MAXN);
    int find(int v);
    void join(int u,int v);
};

/** Initializes a DSUnion with unitary sets. {O(n),=} */
DSUnion::DSUnion(int _n):n(_n),m(_n),s(_n){forn(i,n)s[i]={i,1};}

/** Finds the set of v. {O(1),=} */
int DSUnion::find(int v){return (v==s[v].fst)?v:s[v].fst=find(s[v].fst);}

/** Joins the sets of u and v quickly. {O(1),=} */
void DSUnion::join(int u,int v){
  int oldc=find(u),newc= find(v);
  if (oldc!=newc) {
    if (s[oldc].snd>s[newc].snd) swap(oldc,newc);
    s[oldc].fst=newc,s[newc].snd+=s[oldc].snd,--m;
  }
}

/** Storage of disjoint sets with their components. */
class UnionFind {
  public:
    int n,m; // number of elements and sets
    vector<pair<int,vector<int>>>s; // sets
    UnionFind(int _n=MAXN);
    int find(int v);
    void join(int u,int v);
    vector<int>&get_comps(int v);
};

/** Initializes a UnionFind with unitary sets. {O(n),=} */
UnionFind::UnionFind(int _n):n(_n),m(_n),s(_n){forn(i,n)s[i]={i,{i}};}

/** Finds the set of v quickly. {O(1),=} */
int UnionFind::find(int v){return s[v].fst;}

/** Joins the sets of u and v. {O(log2(n)),O(1)} */
void UnionFind::join(int u,int v){
  int oldc=find(u),newc=find(v);
  if (oldc!=newc) {
    if (sz(s[oldc].snd)>sz(s[newc].snd)) swap(oldc,newc);
    fore(w,s[oldc].snd)s[newc].snd.pb(w),s[w].fst=newc;
    s[oldc].snd.clear(),--m;
  }
}

/** Returns the components of the set of v. {O(1),=} */
vector<int>&UnionFind::get_comps(int v){return s[find(v)].snd;}

//_____________________________________________________________________________

#endif // __DISJOINT_SET_UNION__
