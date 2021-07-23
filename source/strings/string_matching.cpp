/// SOURCE - STRING MATCHING
/** Source file for String Matching. */
#ifndef __STRING_MATCHING__
#define __STRING_MATCHING__

//_____________________________________________________________________________

// ------ IMPLEMENTATION ------ //

/** Given str returns l such that l[i] is the size of the longest proper prefix
 * that is also a suffix of the first i elements of str. {O(m),=} */
template<class T>vector<int>lpps(T& str){
  int m=sz(str);
  vector<int>l(m);
  for(int i=1,len=0;i<m;)
    if(str[i]==str[len])l[i++]=++len;
    else if(len)len=l[len-1];
    else l[i++]=0;
  return l;
}

/** Returns the start of the ocurrences of str in txt using Knuth-Morris-Pratt.
 * {O(n+m),=} */
template<class T>vector<int>kmp(T& txt,T& str){
  int n=sz(txt),m=sz(str);
  vector<int>pos,l=lpps(str);
  for(int i=0,j=0;i<n;) {
    if(str[j]==txt[i])++j,++i;
    if(j==m)pos.pb(i-j),j=l[j-1];
    else if(i<n&&str[j]!=txt[i]) j=(j)?l[j-1]:(++i,j);
  }
  return pos;
}

/** Given s returns z such that z[i] is the length of the longest substring of
 * s that starts in i and is a proper prefix of s. {O(r),=} */
vector<int>z_array(string& s){
  int r=sz(s),x=0,y=0;
  vector<int>z(r);
  forr(i,1,r){
    z[i]=max(0,min(z[i-x],y-i+1));
    while(i+z[i]<r&&s[z[i]]==s[i+z[i]])x=i,y=i+z[i]++;
  }
  return z;
}

/** Returns the start of the ocurrences of str in txt using Z-Search.
 * {O(n+m),=} */
vector<int>z_search(string& txt,string& str){
  string s=str+"@"+txt;
  vector<int>pos,z=z_array(s);
  int m=sz(str),len=sz(s);
  forr(i,m+1,len)if(z[i]==m)pos.pb(i-m-1);
  return pos;
}

/** Returns the start of the ocurrences of str in txt using Rabin-Karp.
 * {O(n+m),=} */
vector<int>rabin_karp(string& txt,string& str){
  vector<int> pos; int p=32887,d=256,n=sz(txt),m=sz(str);
  int j=0,t=0,s=0,h=(int)expmod((ull)d,(ull)m-1,(ull)p),l=n-m+1;
  forn(i,m) t=(d*t+txt[i])%p,s=(d*s+str[i])%p;
  forn(i,l) {
    if (s==t) {for(;j<m;++j)if(txt[i+j]!=str[j])break; if (j==m)pos.pb(i);}
    if(i<n-m) t=(d*(t-txt[i]*h)+txt[i+m])%p,t+=((t<0)?p:0);
  }
  return pos;
}

//_____________________________________________________________________________

#endif // __STRING_MATCHING__
