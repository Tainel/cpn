/// SOURCE - EULER PHI
/** Source file for Euler Phi. */
#ifndef __EULER_PHI__
#define __EULER_PHI__

//_____________________________________________________________________________

// ------ IMPLEMENTATION ------ //

/** Returns the number of coprimes smaller than x already factored.
 * {O(q(x)),O(1)} */
ull euler_phi(ull x,map<ull,int>&f){fore(e,f)x-=(x/e.fst);return x;}

/** Returns the number of coprimes smaller than x. {O(sqrt(x)),O(1)} */
ull euler_phi(ull x){
  ull ans=x;
  for(ull i=2;i<x+1&&i*i<=x;++i)if(!(x%i)){while(!(x%i))x/=i;ans-=ans/i;}
  return (x!=1)?ans-ans/x:ans;
}

/** Returns the values of euler_phi up to n. {O(n*log2(log2(n))),O(n)} */
vector<int>phi_table(int n=MAXN){
  vector<int>phi(++n);
  forn(i,n)phi[i]=i;
  forr(i,2,n)if(phi[i]==i)for(int j=i;j<n;j+=i)phi[j]-=phi[j]/i;
  return phi;
}

//_____________________________________________________________________________

#endif // __EULER_PHI__
