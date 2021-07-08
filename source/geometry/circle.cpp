/// SOURCE - CIRCLE
/** Source file for Circle. */
#ifndef __CIRCLE__
#define __CIRCLE__

//_____________________________________________________________________________

// ------ IMPLEMENTATION ------ //

/** Circle in the plane. */
struct Circle {
  Pnt o; // center of the circle
  double r; // radius of the circle
  Circle(Pnt _o=Pnt(),double _r=1);
  double perimeter();
  double area();
  bool inside(const Pnt&p);
  bool outside(const Pnt&p);
  bool belongs(const Pnt&p);
  /** Equality between two circles. {O(1),=} */
  bool operator==(const Circle&c)const&{return o==c.o&&eql(r,c.r);}
};

/** Initializes a circle in the plane. {O(1),=} */
Circle::Circle(Pnt _o,double _r):o(_o),r(_r){}

/** Returns the perimeter of the circle. {O(1),=} */
double Circle::perimeter(){return 2*M_PI*r;}

/** Returns the area of the circle. {O(1),=} */
double Circle::area(){return M_PI*r*r;}

/** Determines if p is strictly inside the area of the circle. {O(1),=} */
bool Circle::inside(const Pnt&p){return lss(distsq(o,p),r*r);}

/** Determines if p is strictly outside the area of the circle. {O(1),=} */
bool Circle::outside(const Pnt&p){return lss(r*r,distsq(o,p));}

/** Determines if p belongs to the circle. {O(1),=} */
bool Circle::belongs(const Pnt&p){return eql(distsq(o,p),r*r);}

/** Returns the intersection points of two different circles. {O(1),=} */
vector<Pnt>intersection(const Circle&c0,const Circle&c1){
  vector<Pnt>p; double d=dist(c0.o,c1.o),sr=c0.r+c1.r;
  if(lss(d,fabs(c0.r-c1.r))||lss(sr,d)||c0==c1)return p;
  double rr=c0.r*c0.r, a=(rr-c1.r*c1.r+d*d)/(2*d), h=sqrt(rr-a*a);
  double x=c0.o.x+a*(c1.o.x-c0.o.x)/d, y=c0.o.y+a*(c1.o.y-c0.o.y)/d;
  double hx=h*(c1.o.y-c0.o.y)/d, hy=h*(c1.o.x-c0.o.x)/d;
  p.pb(Pnt(x+hx,y-hy));
  if(eql(d,sr))return p;
  p.pb(Pnt(x-hx,y+hy));
  return p;
}

//_____________________________________________________________________________

#endif // __CIRCLE__
