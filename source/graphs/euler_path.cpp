/// SOURCE - EULER PATH
/** Source file for Euler Path. */
#ifndef __EULER_PATH__
#define __EULER_PATH__

//_____________________________________________________________________________

// ------ IMPLEMENTATION ------ //

/** Returns true iff an eulerian path exists, in which case it's stored in the
 * given vector. {O(n+m),=} */
bool Graph::euler_path(vector<int>& path){
  path.clear(); if (m==0) return true;
  vector<int>outs(n);
  forn(i,n) outs[i]=degs[i].snd;
  vector<unordered_multiset<int>>g(n);
  forn(i,n) fore(e,graph[i]) g[i].insert(e.fst);
  pair<int,int>extra={-1,-1};
  int zeros=0;
  if (und) {
    vector<int>odds;
    forn(i,n) {
      if (degs[i].fst&1) {
        if (extra.fst==-1) extra.fst=i;
        else if (extra.snd==-1) extra.snd=i;
        else return false;
      }
      else if (degs[i].fst==0) ++zeros;
    }
    if (n-zeros!=sz(dfs(edges[0].u))) return false;
    if (extra.fst!=-1) {
      g[extra.fst].insert(extra.snd),g[extra.snd].insert(extra.fst);
      ++outs[extra.fst],++outs[extra.snd];
    }
  }
  else {
    forn(i,n) {
      int dif=degs[i].fst-degs[i].snd;
      if (dif==0&&degs[i].fst==0) ++zeros;
      else if (dif== 1&&extra.fst==-1) extra.fst=i;
      else if (dif==-1&&extra.snd==-1) extra.snd=i;
      else if (dif!=0) return false;
    }
    if (extra.fst!=-1) {
      g[extra.fst].insert(extra.snd),++outs[extra.fst];
      add_edge(Graph::Edge(extra.fst,extra.snd));
    }
    if (n-zeros!=sz(dfs(edges[0].u))) return false;
    if (extra.fst!=-1) {
      Graph::Edge e=edges[--m]; weight-=e.w,graph[e.u].pp(),edges.pp();
      --degs[e.v].fst, --degs[e.u].snd;
      if (und) graph[e.v].pp(),--degs[e.u].fst,--degs[e.v].snd;
    }
  }
  int curr=edges[0].u;
  stack<int>s; s.push(curr);
  while (!s.empty()) {
    if (outs[curr]) {
      auto it=g[curr].begin(); int next=*it;
      g[curr].erase(it);
      if (und) --outs[next],it=g[next].find(curr),g[next].erase(it);
      --outs[curr],s.push(curr),curr = next;
    }
    else path.pb(curr),curr=s.top(),s.pop();
  }
  reverse(all(path));
  if (extra.fst!=-1) {
    bool done=false; path.pp();
    forn(i,m)
      if (path[i]==extra.fst&&path[i+1]==extra.snd) {
        rotate(path.begin(),path.begin()+i+1,path.end());
        done=true; break;
      }
    if (!done)
      dforr(i,1,m+1)
        if (path[i]==extra.fst&&path[i-1]==extra.snd) {
          rotate(path.begin(),path.begin()+i,path.end());
          break;
        }
  }
  if(m==1)reverse(all(path));
  return true;
}

//_____________________________________________________________________________

#endif // __EULER_PATH__
