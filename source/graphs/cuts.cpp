/// SOURCE - CUTS
/** Source file for Cuts. */
#ifndef __CUTS__
#define __CUTS__

//_____________________________________________________________________________

// ------ IMPLEMENTATION ------ //

/** Returns the bridges and articulation points of the graph. {O(n+m),O(n)} */
pair<vector<pair<int,int>>,vector<int>>Graph::get_cuts(){
  vector<bool>visited(n),ap(n); vector<int>tin(n,-1),low(n,-1),cutpoints;
  vector<pair<int,int>>bridges; int timer=0;
  function<void(int,int)>dfs_cuts = [&](int u,int p){
    visited[u]=true, tin[u] = low[u] = timer++;
    int children=0;
    fore(e,graph[u]){
      int v=e.fst;
      if(v==p)continue;
      if(visited[v])low[u]=min(low[u],tin[v]);
      else{
        dfs_cuts(v,u),low[u]=min(low[u],low[v]);
        if(low[v]>tin[u])bridges.pb({u,v});
        if(low[v]>=tin[u]&&p!=-1&&!ap[u])cutpoints.pb(u),ap[u]=true;
        ++children;
      }
    }
    if(p==-1&&children>1&&!ap[u])cutpoints.pb(u),ap[u]=true;
  };
  forn(i,n)if(!visited[i])dfs_cuts(i,-1);
  return {bridges,cutpoints};
}

//_____________________________________________________________________________

#endif // __CUTS__
