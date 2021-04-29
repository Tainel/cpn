/// SOURCE - SHORTEST PATH
/** Source file for Shortest Path. */
#ifndef __SHORTEST_PATH__
#define __SHORTEST_PATH__

//_____________________________________________________________________________

// ------ IMPLEMENTATION ------ //

/** Finds the shortest path from vertex o to each node using Dijkstra.
 * {O(m*log2(n)),O(n)} */
vector<pair<int,ll>>Graph::dijkstra(int o){
  vector<pair<int,ll>>d(n,{-1,(ll)INF}); d[o].snd=0;
  pqueue<pair<ll,int>>pq; pq.push({0,o});
  while (!pq.empty()) {
    ll p=-pq.top().fst; int x=pq.top().snd; pq.pop();
    if (d[x].snd!=p) continue;
    int r=sz(graph[x]);
    forn(i,r) {
      int y=graph[x][i].fst; ll w=graph[x][i].snd;
      if (d[y].snd==(ll)INF||p+w<d[y].snd) d[y]={x,p+w},pq.push({-d[y].snd,y});
    }
  }
  return d;
}

 /** Finds the shortest path from vertex o to each node using Bellman-Ford.
 * {O(n*m),O(n)} */
vector<pair<int,ll>>Graph::bellman_ford(int o,bool neg){
  vector<pair<int,ll>>d(n,{-1,(ll)INF}); d[o].snd=0;
  forn(i,n-1)
    fore(e,edges) {
      if(d[e.u].snd<(ll)INF&&d[e.u].snd+e.w<d[e.v].snd)
        d[e.v]={e.u,d[e.u].snd+e.w};
      if(und&&d[e.v].snd<(ll)INF&&d[e.v].snd+e.w<d[e.u].snd)
        d[e.u]={e.v,d[e.v].snd+e.w};
    }
  if (!neg) return d;
  forn(i,n-1)
    fore(e,edges) {
      if (d[e.u].snd<(ll)INF&&d[e.u].snd+e.w<d[e.v].snd)
        d[e.v]={-1,-(ll)INF};
      if (und&&d[e.v].snd<(ll)INF&&d[e.v].snd+e.w<d[e.u].snd)
        d[e.u]={-1,-(ll)INF};
    }
  return d;
}

/** Returns a matrix d, where d[i][j] is the minimum cost from i to j, using
 * Floyd-Warshall. {O(n^3),O(n^2)} */
vector<vector<ll>>Graph::floyd_warshall(bool neg){
  vector<vector<ll>>d(n,vector<ll>(n,(ll)INF));
  fore(e,edges) {
    d[e.u][e.v]=min(d[e.u][e.v],e.w);
    if (und) d[e.v][e.u]=min(d[e.v][e.u],e.w);
  }
  forn(k,n)
    forn(i,n)
      if (d[i][k]<(ll)INF)
        forn(j,n)if(d[k][j]<(ll)INF)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
  if (!neg) return d;
  forn(v,n)
    forn(u,n)
      if (d[v][u]>-(ll)INF)
        forn(i,n)
          if(d[v][i]<(ll)INF&&d[i][i]<0&&d[i][u]<(ll)INF)d[v][u]=-(ll)INF;
  return d;
}

//_____________________________________________________________________________

#endif // __SHORTEST_PATH__
