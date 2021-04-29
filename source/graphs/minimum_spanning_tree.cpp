/// SOURCE - MINIMUM SPANNING TREE
/** Source file for Minimum Spanning Tree. */
#ifndef __MINIMUM_SPANNING_TREE__
#define __MINIMUM_SPANNING_TREE__

//_____________________________________________________________________________

// ------ IMPLEMENTATION ------ //

/** Finds the MST starting from o using Prim. O(m*log2(n)),O(n+m)} */
Graph Graph::prim(int o){
  bool(*comp)(const Graph::Edge&e1,const Graph::Edge&e2);
  comp=[](const Graph::Edge&e1,const Graph::Edge&e2){return e1.w>e2.w;};
  pqueue<Graph::Edge,vector<Graph::Edge>,decltype(comp)> pq(comp);
  Graph mst(n); vector<bool>taken(n,false); taken[o]=true;
  fore(e,graph[o]) if(!taken[e.fst])pq.push({o,e.fst,e.snd});
  while (!pq.empty()) {
    Graph::Edge p=pq.top(); pq.pop();
    if (!taken[p.v]) {
      mst.add_edge(p),taken[p.v]=true;
      fore(e,graph[p.v])if(!taken[e.fst])pq.push({p.v,e.fst,e.snd});
    }
  }
  return mst;
}

/** Finds the MSF using Kruskal. {O(n+m*log2(m)),O(n)} */
Graph Graph::kruskal(){
  DSUnion comps(n); Graph mst(n);
  vector<Graph::Edge>sorted(edges); sort(all(sorted));
  fore(e,sorted)
    if (comps.find(e.u)!=comps.find(e.v)) mst.add_edge(e),comps.join(e.u,e.v);
  return mst;
}

//_____________________________________________________________________________

#endif // __MINIMUM_SPANNING_TREE__
