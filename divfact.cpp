
/*
Concepts used:
(1) Number of divisors of a number using prime factorization.
(2) All prime numbers less 'n' are prime factors of 'n!'.
(3) The highest exponent of prime 'p' in 'n!' is sum of floor(n/p^j).It can be also expressed as (n-g(n,p))/(p-1) where g(n,p) is sum of digits of number which is formed when we represent in 'n' in base 'p'.
*/
#include<bits/stdc++.h>
#define c 1000000007
unsigned long long p[5137];
inline void ri(unsigned long long *n){
    *n=0;
    register  int ch=getchar_unlocked();
    while(ch >= '0' && ch <= '9'){
        *n = ((*n)<<3) + ((*n)<<1) + ch - '0';
        ch = getchar();
    }
}
 inline void wi(unsigned long long  int a){
     
     char snum[20];
      register int i=0;
     do {
          snum[i++]=a%10+48;
          a=a/10;
     } while(a!=0);
     i=i-1;
      while(i>=0)
     putchar_unlocked(snum[i--]);
     putchar_unlocked('\n');
}
inline void f(){
  register unsigned int  i,cp=0;
  register  unsigned long long j;
 static  bool flag[50055];
 p[cp]=2;
  cp=1;
  for(i=3;i<=50050;i=i+2){
    if(flag[i]==0){
       p[cp]=i;
      cp++;
      for(j=1ll*i*i;j<=50050;j+=2*i) flag[j]=1;
    }
  }

}
int main(){
  f();
  register unsigned long long  t,n,i;
  register unsigned long long j,ans,temp;
  ri(&t);
  while(t--){
    
    temp=1;
    ri(&n);
	for(i=0;p[i]<=n;i++){
		ans=0;
		j=n;
		while(j>=p[i]){
			ans=ans+( long long)(j%p[i]);
			j=( long long)(j/p[i]);
		}
		ans=ans+j;
		ans=(n-ans)/(p[i]-1);
		temp=(temp*(ans+1))%c;
	}
   wi(temp);
  }
  return 0;
}

