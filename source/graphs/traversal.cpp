/// SOURCE - TRAVERSAL
/** Source file for Traversal. */
#ifndef __TRAVERSAL__
#define __TRAVERSAL__

//_____________________________________________________________________________

// ------ IMPLEMENTATION ------ //

/** Returns the visited nodes doing dfs from vertex o. {O(n+m),O(n)} */
uset<int>Graph::dfs(int o){
  uset<int>us;us.insert(o);vector<bool>used(n);used[o]=true;
  stack<int>s;s.push(o);
  while(!s.empty()){
    int x=s.top(); s.pop();
    fore(e,graph[x]) {
      int y=e.fst;
      if(!used[y])s.push(y),us.insert(y),used[y]=true;
    }
  }
  return us;
}

/** Returns the shortest path from o to each node doing bfs. {O(n+m),O(n)} */
vector<pair<int,int>>Graph::bfs(int o){
  vector<pair<int,int>>d(n,{-1,INT_MAX}); d[o].snd=0; queue<int>q; q.push(o);
  while(!q.empty()){
    int x=q.front(); q.pop();
    fore(e,graph[x]){
      int y=e.fst;
      if(d[y].snd==INT_MAX)d[y].fst=x,d[y].snd=d[x].snd+1,q.push(y);
    }
  }
  return d;
}

//_____________________________________________________________________________

#endif // __TRAVERSAL__
