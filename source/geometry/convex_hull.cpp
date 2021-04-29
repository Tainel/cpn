/// SOURCE - CONVEX HULL
/** Source file for Convex Hull. */
#ifndef __CONVEX_HULL__
#define __CONVEX_HULL__

//_____________________________________________________________________________

// ------ IMPLEMENTATION ------ //

/** Returns the convex hull of pol in ccw order. {O(n*log2(n)),O(n)} */
vector<Pnt>convex_hull(vector<Pnt>&pol){
  if (pol.empty()) return {};
  vector<Pnt> h; int n=sz(pol); sort(all(pol));
  forn(i,n){
    while(sz(h)>=2&&!h.back().right(h[sz(h)-2],pol[i]))h.pp();
    h.pb(pol[i]);
  }
  h.pp(); int k=sz(h);
  dforn(i,n) {
    while(sz(h)>=k+2&&!h.back().right(h[sz(h)-2],pol[i]))h.pp();
    h.pb(pol[i]);
  }
  h.pp();
  return h;
}

/** Determines if p is inside chull. If b is true, points in the sides of chull
 * are considered inside the convex poligon. {O(log2(n)),O(1)} */
bool inchull(Pnt&p,vector<Pnt>&chull,bool b=false){
  auto f=[](Pnt&x,Pnt&q,Pnt&r,bool d){return d?x.right(q,r):!x.left(q,r);};
  if(f(p,chull[0],chull[1],b)||f(p,chull.back(),chull[0],b))
    return false;
  int l=1,r=sz(chull)-1;
  while(r-l>1){
    int m=l+(unsigned(r-l)>>1);
    if(!f(p,chull[0],chull[m],b))l=m;
    else r=m;
  }
  return !f(p,chull[l],chull[l+1],b);
}

//_____________________________________________________________________________

#endif // __CONVEX_HULL__
