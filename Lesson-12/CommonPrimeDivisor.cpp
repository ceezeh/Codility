// you can use includes, for example:
// #include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int GCD(int a, int b, int res = 1) {
    while (a!= b) {
        if((!(a&1))&&(!(b&1))) {
            a = a>>1;
            b = b>>1;
            res = res<<1;
        } 
        else if(!(a&1)) {
            a = a>>1;
        }
        else if(!(b&1)) {
            b = b>>1;
        }
        else if (a>b) {
            a-=b;
        } else {
            b-=a;
        }
    }

    return res * a;

}

// This function checks that the num can be reduced 
// to prime factors of gcd and if not, returns false.
bool Reduce (const int gcd, int num) {
    int rem = num/gcd;
    int gn = gcd;
    while (gn != 1) {
            gn = GCD(rem, gn);
            rem/=gn;                
        }
    return (gcd%rem) ==0;
}

int solution(vector<int> &A, vector<int> &B) {
    int count  = 0;
    for (size_t i = 0; i < B.size(); ++i) 
    {

        int gcd = GCD(A[i], B[i]);
        if (A[i]==1 && B[i]==1){++count; continue;}
        else if (gcd==1) continue; 


        if (!Reduce(gcd, A[i])) continue;
        if (!Reduce(gcd, B[i])) continue;

        ++count;
    }

    return count;
}
