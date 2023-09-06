#include <vector>
using namespace std;

int solution(vector<int> &A) {
    
    if (A.size()<2) return 0;
    int minn = A[0];
    int maxd = A[1]-A[0];
    for (size_t i = 1; i < A.size()-1; ++i) {
        minn = min(minn, A[i]);
        maxd= max(maxd, A[i+1]-minn);
    } 
    return max(0, maxd);
}
