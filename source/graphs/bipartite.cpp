/// SOURCE - BIPARTITE
/** Source file for Bipartite. */
#ifndef __BIPARTITE__
#define __BIPARTITE__

//_____________________________________________________________________________

// ------ IMPLEMENTATION ------ //

/** Determines if the graph is bipartite. If true, stores the color of each
 * node. {O(n+m),=} */
bool Graph::bipartite(vector<int>&color){
  color.resize(n,-1); bool bip=true; queue<int>q;
  forn(i,n){
    if(color[i]==-1){
      q.push(i),color[i]=0;
      while(!q.empty()){
        int v=q.front(); q.pop();
        fore(e,graph[v])
          if(color[e.fst]==-1)color[e.fst]=color[v]^1,q.push(e.fst);
          else bip&=color[e.fst]!=color[v];
      }
    }
  }
  return bip;
}

//_____________________________________________________________________________

#endif // __BIPARTITE__
