/// SOURCE - CARTESIAN POINTS
/** Source file for Cartesian Points. */
#ifndef __CARTESIAN_POINTS__
#define __CARTESIAN_POINTS__

//_____________________________________________________________________________

// ------ IMPLEMENTATION ------ //

/** Point in the plane. */
struct Pnt {
  double x,y; // coordinates
  Pnt(double _x=0,double _y=0);
  double norm();
  double normsq();
  bool aligned(const Pnt&q,const Pnt&r);
  bool left(const Pnt&q,const Pnt&r);
  bool right(const Pnt&q,const Pnt&r);
  /** Sum between two points. {O(1),=} */
  Pnt operator+(const Pnt&q)const&{return Pnt(x+q.x,y+q.y);}
  /** Difference between two points. {O(1),=} */
  Pnt operator-(const Pnt&q)const&{return Pnt(x-q.x,y-q.y);}
  /** Dot product between two points. {O(1),=} */
  double operator*(const Pnt&q)const&{return x*q.x+y*q.y;}
  /** Cross product between two points. {O(1),=} */
  double operator^(const Pnt&q)const&{return x*q.y-y*q.x;}
  /** Product between a point and a number. {O(1),=} */
  Pnt operator*(double k)const&{return Pnt(x*k,y*k);}
  /** Division of a point by a number. {O(1),=} */
  Pnt operator/(double k)const&{return Pnt(x/k,y/k);}
  /** Sum between a point and a number. {O(1),=} */
  Pnt operator+(double k)const&{return Pnt(x+k,y+k);}
  /** Difference between a point and a number. {O(1),=} */
  Pnt operator-(double k)const&{return Pnt(x-k,y-k);}
  /** Equality between two points. {O(1),=} */
  bool operator==(const Pnt&q)const&{return eql(x,q.x)&&eql(y,q.y);}
  /** Order between points, from left to right and ascending. {O(1),=} */
  bool operator<(const Pnt&q)const&{
    return lss(x,q.x)||(eql(x,q.x)&&lss(y,q.y));
  }
};

/** Initializes a point in the plane. {O(1),=} */
Pnt::Pnt(double _x,double _y):x(_x),y(_y){}

/** Returns the norm. {O(1),=} */
double Pnt::norm(){return sqrt(x*x+y*y);}

/** Returns the square of the norm. {O(1),=} */
double Pnt::normsq(){return x*x+y*y;}

/** Checks if a point is in qr. {O(1),=} */
bool Pnt::aligned(const Pnt&q,const Pnt&r){return eql((q-*this)^(r-*this),0);}

/** Checks if a point is to the left of qr. {O(1),=} */
bool Pnt::left(const Pnt&q,const Pnt&r){return lss(0,((q-*this)^(r-*this)));}

/** Checks if a point is to the right of qr. {O(1),=} */
bool Pnt::right(const Pnt&q,const Pnt&r){return lss(((q-*this)^(r-*this)),0);}

/** Returns the distance between two points. {O(1),=} */
double dist(const Pnt&p,const Pnt&q){return(q-p).norm();}

/** Returns the square distance between two points. {O(1),=} */
double distsq(const Pnt&p,const Pnt&q){return(q-p).normsq();}

/** Returns the point rotated t radians ccw around the origin. {O(1),=} */
Pnt rotate(const Pnt&p,double t){
  return Pnt(p.x*cos(t)-p.y*sin(t),p.x*sin(t)+p.y*cos(t));
}

/** Returns angle poq in radians. {O(1),=} */
double angle(const Pnt&p,const Pnt&o,const Pnt&q){
  Pnt op=p-o,oq=q-o;return atan2(op^oq,op*oq);
}

//_____________________________________________________________________________

#endif // __CARTESIAN_POINTS__
