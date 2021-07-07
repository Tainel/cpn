/// SOURCE - LOWEST COMMON ANCESTOR
/** Source file for Lowest Common Ancestor. */
#ifndef __LOWEST_COMMON_ANCESTOR__
#define __LOWEST_COMMON_ANCESTOR__

//_____________________________________________________________________________

// ------ IMPLEMENTATION ------ //

/** Gets the bfs order of the nodes. {O(n),=} */
vector<pair<int,int>>Graph::bfs_tags(int root) {
  vector<pair<int,int>>tags(n,mp(-1,-1));
  queue<int>q; q.push(root);
  for(int i=0;!q.empty();){
    int x=q.front(); q.pop();
    tags[x].fst=i,tags[i++].snd=x;
    fore(e,graph[x])if(tags[e.fst].fst==-1)q.push(e.fst);
  }
  return tags;
}

/** Gets the Euler tour of the tree. {O(n),=} */
vector<int>Graph::euler_tour(int root) {
  vector<int>tour(2*n-1);vector<bool>used(n);int idx=0;
  complete_tour(root,idx,used,tour);
  return tour;
}

/** Auxiliary function to get the Euler tour of a tree recursively. {O(n),=} */
void Graph::complete_tour(int v,int&idx,vector<bool>&used,vector<int>&tour){
  used[v]=true,tour[idx++]=v;
  fore(e,graph[v]){
    if(!used[e.fst]){
      complete_tour(e.fst,idx,used,tour);
      tour[idx++]=v;
    }
  }
}

/** Necessary data for LCA related problems. */
class TreeLCA {
  public:
    vector<int>occ; // tags with the first occurrence of each node in the tour
    vector<pair<int,int>>tags,depths; // order and depth of each node
    RMQst<int>*data; // sparse table of the Euler tour
    TreeLCA(Graph&g,int root=0);
    int lca(int u,int v);
    int dist(int u,int v);
};

/** Initializes the necessary data for LCA related problems. {O(n),=} */
TreeLCA::TreeLCA(Graph&g,int root){
  depths = g.bfs(root);
  tags = g.bfs_tags(root);
  vector<int>tour = g.euler_tour(root);
  int s=sz(tour); occ.resize(g.n,-1);
  forn(i,s){
    tour[i]=tags[tour[i]].fst;
    if(occ[tour[i]]==-1)occ[tour[i]]=i;
  }
  data = new RMQst<int>(tour);
}

/** Finds the lowest common ancestor between two nodes in a tree. {O(1),=} */
int TreeLCA::lca(int u,int v){
  int fu=occ[tags[u].fst],fv=occ[tags[v].fst];
  return tags[data->get(min(fu,fv),max(fu,fv)+1)].snd;
}

/** Finds the distance between two nodes in a tree. {O(1),=} */
int TreeLCA::dist(int u,int v){
  return depths[u].snd+depths[v].snd-2*depths[lca(u,v)].snd;
}

//_____________________________________________________________________________

#endif // __LOWEST_COMMON_ANCESTOR__
