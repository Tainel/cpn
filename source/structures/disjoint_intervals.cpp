/// SOURCE - DISJOINT INTERVALS
/** Source file for Disjoint Intervals. */
#ifndef __DISJOINT_INTERVALS__
#define __DISJOINT_INTERVALS__

//_____________________________________________________________________________

// ------ IMPLEMENTATION ------ //

/** Set of disjoint integer intervals. */
class Intervals {
  public:
    set<pair<ll,ll>>s; // intervals
    void insert(pair<ll,ll>v);
    void insert(ll v);
    void erase(pair<ll,ll>v);
    void erase(ll v);
    bool contains(pair<ll,ll>v);
    bool contains(ll v);
};

/** Inserts an interval. {O(log2(n)),O(1)} */
void Intervals::insert(pair<ll,ll>v) {
  if (v.fst>=v.snd) return;
  auto at=s.lb(v),it=at;
  if (at!=s.begin()&&(--at)->snd>=v.fst) v.fst=at->fst,--it;
  for (;it!=s.end()&&it->fst<=v.snd;s.erase(it++))v.snd=max(v.snd,it->snd);
  s.insert(v);
}

/** Inserts a number. {O(log2(n)),O(1)} */
void Intervals::insert(ll v){insert({v,v+1});}

/** Removes an interval. {O(log2(n)),O(1)} */
void Intervals::erase(pair<ll,ll>v){
  if (v.fst>=v.snd) return;
  auto it=s.lb({v.fst+1,v.fst+1});
  if (it!=s.begin())--it;
  pair<ll,ll>i1=*it,i2; i1.snd=min(i1.snd,v.fst);
  while (it!=s.end()&&it->snd<v.snd) s.erase(it++);
  if (it!=s.end()) i2=*it,s.erase(it);
  i2.fst=max(i2.fst,v.snd);
  if (i1.fst<i1.snd) s.insert(i1);
  if (i2.fst<i2.snd) s.insert(i2);
}

/** Removes a number. {O(log2(n)),O(1)} */
void Intervals::erase(ll v){erase({v,v+1});}

/** Checks if an interval exists. {O(log2(n)),O(1)} */
bool Intervals::contains(pair<ll,ll>v){
  if (v.fst>=v.snd) return false;
  auto it=s.lb({v.fst+1,v.fst+1});
  return it!=s.begin()&&v.snd<=(--it)->snd;
}

/** Checks if a number exists. {O(log2(n)),O(1)} */
bool Intervals::contains(ll v){
  auto it=s.lb({v+1,v+1});
  return it!=s.begin()&&v<(--it)->snd;
}

//_____________________________________________________________________________

#endif // __DISJOINT_INTERVALS__
