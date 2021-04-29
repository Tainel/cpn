/// SOURCE - GRAPH
/** Source file for Graph. */
#ifndef __GRAPH__
#define __GRAPH__

//_____________________________________________________________________________

// ------ IMPLEMENTATION ------ //

/** General graph. */
class Graph {
  public:
    /** General edge of a graph. */
    struct Edge {
      int u,v;ll w;
      Edge(int _u,int _v,ll _w=1):u(_u),v(_v),w(_w){}
      bool operator<(const Edge&e)const{return w<e.w;}
    };
    int n,m=0; // number of nodes and edges
    ll weight=0; // total weight
    vector<Edge>edges; // edges
    vector<vector<pair<int,ll>>>graph; // adjacency list
    vector<pair<int,int>>degs; // degrees
    bool und; // undirected
    Graph(int _n,bool u=true);
    void add_edge(Edge e);
    void add_edge(int u,int v,ll w=1);
    uset<int>dfs(int o=0);
    vector<pair<int,int>>bfs(int o=0);
    vector<pair<int,ll>>dijkstra(int o=0);
    vector<pair<int,ll>>bellman_ford(int o=0,bool neg=false);
    vector<vector<ll>>floyd_warshall(bool neg=false);
    Graph prim(int o=0);
    Graph kruskal();
    bool topological_sort(vector<int>&order);
    bool euler_path(vector<int>&path);
    void fscc(int u,pair<int,vector<vector<vector<int>>>>&a,stack<int>&s);
    vector<vector<int>>tarjan();
    bool bipartite(vector<int>&color);
};

/** Initializes an empty graph. {O(n),=} */
Graph::Graph(int _n,bool u):n(_n),graph(_n),degs(_n),und(u){}

/** Adds an edge to the graph. {O(1),=} */
void Graph::add_edge(Graph::Edge e){
  ++m,weight+=e.w,edges.pb(e);
  graph[e.u].pb({e.v,e.w}),++degs[e.v].fst,++degs[e.u].snd;
  if(und)graph[e.v].pb({e.u,e.w}),++degs[e.u].fst,++degs[e.v].snd;
}

/** Adds an edge with given values to the graph. {O(1),=} */
void Graph::add_edge(int u,int v,ll w){add_edge(Graph::Edge(u,v,w));}

//_____________________________________________________________________________

#endif // __GRAPH__
