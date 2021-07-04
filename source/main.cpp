/// SOURCE - MAIN
/** Main file. */
#ifndef __MAIN__
#define __MAIN__

//_____________________________________________________________________________

// ------ TEMPLATE ------ //

// Optimizations
#pragma GCC optimize "Ofast,unroll-loops"
#pragma GCC target "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma"
// Headers and Namespace
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
// Input and Output Options
#define INPUT freopen("input.txt","r",stdin)
#define OUTPUT freopen("output.txt","w",stdout)
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
// IO Macros
#define cases int tttttt;cin>>tttttt;while(tttttt--)
#define nn cout<<"\n"
#define debug(n) cout<<#n" = "<<(n)<<"\n"
#define printd(d) cout<<fixed<<setprecision(10)<<(d)
#define printv(v) {fore(eeeeee,(v))cout<<eeeeee<<" ";nn;}
#define printm(m) {fore(ffffff,(m)){printv(ffffff);}}
// Alias Macros
#define ub upper_bound
#define lb lower_bound
#define pb push_back
#define pp pop_back
#define mp make_pair
#define fst first
#define snd second
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
// Iteration Macros
#define fore(e,v) for(const auto&e:(v))
#define forn(i,n) forr(i,0,n)
#define forr(i,a,b) for(int i=(a);i<(b);++i)
#define forit(it,v) for(auto it=(v).begin();it!=(v).end();++it)
#define dforn(i,n) dforr(i,0,n)
#define dforr(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define dforit(it,v) for(auto it=(v).rbegin();it!=(v).rend();++it)
// Function Macros
#define sz(v) ((int)(v).size())
#define eql(a,b) (fabs((a)-(b))<EPS)
#define leq(a,b) ((a)<(b)+EPS)
#define lss(a,b) ((a)+EPS<(b))
#define irnd(a,b) (rnd()%((b)-(a)+1)+(a))
// Expansion Macros
#define all(v) (v).begin(),(v).end()
// Types
typedef long long ll;
typedef unsigned long long ull;
// Constants
const double EPS = 1e-9;
const int MAXN = 10000000;
const int MOD = 1000000007;
const ull INF = 1000000000000000001ULL;
// Other Definitios
mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rnd64((ull)chrono::steady_clock::now().time_since_epoch().count());

//_____________________________________________________________________________

// ------ IMPLEMENTATION ------ //

#ifdef _LOCAL_COMP
#include "structures/range_minimum_query.cpp"
#include "structures/fenwick_tree.cpp"
#include "structures/disjoint_set_union.cpp"
#include "structures/disjoint_intervals.cpp"
#include "maths/combinatorics.cpp"
#include "maths/basic_algebra.cpp"
#include "maths/modular_arithmetic.cpp"
#include "maths/primes.cpp"
#include "maths/factorization.cpp"
#include "maths/divisors.cpp"
#include "maths/euler_phi.cpp"
#include "graphs/graph.cpp"
#include "graphs/traversal.cpp"
#include "graphs/shortest_path.cpp"
#include "graphs/minimum_spanning_tree.cpp"
#include "graphs/euler_path.cpp"
#include "graphs/bipartite.cpp"
#include "graphs/strongly_connected_components.cpp"
#include "graphs/topological_sort.cpp"
#include "strings/palindromes.cpp"
#include "strings/string_matching.cpp"
#include "strings/longest_common_subsequence.cpp"
#include "geometry/cartesian_points.cpp"
#include "geometry/convex_hull.cpp"
#include "algorithms/binary_search.cpp"
#include "algorithms/dynamic_programming.cpp"
#include "algorithms/longest_increasing_subsequence.cpp"
#include "algorithms/nim.cpp"
#endif // _LOCAL_COMP

//_____________________________________________________________________________

// ------ SOLUTION ------ //

static void solve(void){
  return;
}

//_____________________________________________________________________________

// ------ MAIN ------ //

int main(void){
  FASTIO;
  solve();
  return 0;
}

//_____________________________________________________________________________

#endif // __MAIN__
