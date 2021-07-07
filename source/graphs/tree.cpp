/// SOURCE - TREE
/** Source file for Tree. */
#ifndef __TREE__
#define __TREE__

//_____________________________________________________________________________

// ------ IMPLEMENTATION ------ //

/** Determines if the graph is a tree. {O(n+m),O(n)} */
bool Graph::is_tree(){return und&&m==n-1&&sz(dfs())==n;}

/** Returns the diameter of the tree. {O(n+m),O(n)} */
int Graph::tree_diameter(){
  vector<int>d(n,-1);d[0]=0; stack<int>s;s.push(0);
  int node=0;
  while(!s.empty()){
    int x=s.top(); s.pop();
    fore(e,graph[x]) {
      int y=e.fst;
      if(d[y]==-1){d[y]=d[x]+1,s.push(y);if(d[y]>d[node])node=y;}
    }
  }
  forn(i,n)d[i]=-1;
  s.push(node),d[node]=0;
  while(!s.empty()){
    int x=s.top(); s.pop();
    fore(e,graph[x]){
      int y=e.fst;
      if(d[y]==-1){d[y]=d[x]+1,s.push(y);if(d[y]>d[node])node=y;}
    }
  }
  return d[node];
}

//_____________________________________________________________________________

#endif // __TREE__
