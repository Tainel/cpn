/// SOURCE - TOPOLOGICAL SORT
/** Source file for Topological Sort. */
#ifndef __TOPOLOGICAL_SORT__
#define __TOPOLOGICAL_SORT__

//_____________________________________________________________________________

// ------ IMPLEMENTATION ------ //

/** Returns true iff the graph is a DAG, in which case stores a topological
 * order of the graph. {O(n+m),O(n)} */
bool Graph::topological_sort(vector<int>&order){
  order.clear(); queue<int>q;
  forn(i,n) if(degs[i].fst==0)q.push(i);
  while (!q.empty()) {
    int v = q.front(); q.pop(),order.pb(v);
    fore(e,graph[v]){int y=e.fst;if(!--degs[y].fst)q.push(y);}
  }
  if (sz(order)<n) order.clear();
  return sz(order)==n;
}

//_____________________________________________________________________________

#endif // __TOPOLOGICAL_SORT__
