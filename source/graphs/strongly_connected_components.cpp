/// SOURCE - STRONGLY CONNECTED COMPONENTS
/** Source file for Strongly Connected Components. */
#ifndef __STRONGLY_CONNECTED_COMPONENTS__
#define __STRONGLY_CONNECTED_COMPONENTS__

//_____________________________________________________________________________

// ------ IMPLEMENTATION ------ //

/** Auxiliary recursive function for Tarjan's algorithm. {O(n+m),=} */
void Graph::fscc(int u,pair<int,vector<vector<vector<int>>>>&a,stack<int>&s){
  a.snd[0][0][u]=a.snd[0][1][u]=++a.fst,a.snd[0][2][u]=1;s.push(u);
  fore(e,graph[u]){
    int v=e.fst;
    if (a.snd[0][0][v]==-1)
      fscc(v,a,s),a.snd[0][1][u]=min(a.snd[0][1][u],a.snd[0][1][v]);
    else if(a.snd[0][2][v])a.snd[0][1][u]=min(a.snd[0][1][u],a.snd[0][0][v]);
  }
  if (a.snd[0][0][u] == a.snd[0][1][u]){
    vector<int>scctem;
    for(int v=-1;u!=v;)v=s.top(),s.pop(),a.snd[0][2][v]=0,scctem.pb(v);
    a.snd[1].pb(scctem);
  }
}

/** Returns a vector with the scc using Tarjan. {O(n+m),=} */
vector<vector<int>>Graph::tarjan() {
  stack<int>s;
  pair<int,vector<vector<vector<int>>>>args; args.fst=0;
  args.snd.resize(2); args.snd[0].resize(3);
  forn(i,3)args.snd[0][i].resize(n,i==0?-1:0);
  forn(i,n) if(args.snd[0][0][i]==-1)fscc(i,args,s);
  return args.snd[1];
}

//_____________________________________________________________________________

#endif // __STRONGLY_CONNECTED_COMPONENTS__
