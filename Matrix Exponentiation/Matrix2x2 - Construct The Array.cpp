#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

long long n, k,x;

const int SZ = 2;
struct Matrix {
  int a[SZ][SZ];

  Matrix(int val = 0) {
    for (int i=0; i<SZ; i++) {
      for (int j=0; j<SZ; j++) a[i][j] = 0;
      a[i][i] = val;
    }
  }

  Matrix operator * (const Matrix &other) {
    Matrix ret;
    for (int i=0; i<SZ; i++) {
      for (int j=0; j<SZ; j++) {
        for (int k=0; k<SZ; k++) {
          ret.a[i][j] = (1LL * a[i][k] * other.a[k][j] + ret.a[i][j]) % MOD;
        }
      }
    }

    return ret;
  }
};

Matrix power(Matrix A, long long y) {
  Matrix ret(1);

  for (; y; y >>= 1) {
    if (y & 1) ret = ret * A;
    A = A * A;
  }

  return ret;
}


int main() {

  scanf("%lld %lld %lld", &n, &k, &x);

  n=n-2;


  if (n == 1) {
    if(x==1) cout<<(k-1)<<endl;
    else cout<<(k-1)*(k-2)<<endl;
  }
  else if(n==2){
    if(x==1) cout<<(k-2)<<endl;
    else cout<<(k-2)*(k-2)+(k-1)<<endl;
  }
  else{

    Matrix A;

    A.a[0][0] = (k-2) % MOD;     A.a[0][1] = (k-1) % MOD;
    A.a[1][0] = 1 % MOD;         A.a[1][1] = 0;

    A = power(A, n-2);
    if(x==1) printf("%lld\n",(((A.a[0][0]*(((k-1)*(k-2))%MOD))%MOD) + (A.a[0][1]*(k-1)) % MOD)% MOD);
    else printf("%lld\n", (((A.a[0][0]*(((k-2)*(k-2)+(k-1))%MOD))%MOD) + (A.a[0][1]*(k-2)) % MOD)% MOD);

  }




  return 0;
}
