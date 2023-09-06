#include <vector>
using namespace std;

int solution(vector<int> &A) {

    bool all_neg = true;
    int maxn = A[0];
    int maxsum = 0;
    int maxallsum = 0;
    for (size_t i = 0; i < A.size();++i) {
        if (A[i]>0) all_neg = false;
        maxn = max(maxn,A[i]);

        maxsum = max(0, maxsum+A[i]);
        maxallsum = max(maxsum, maxallsum);
    }

    if (all_neg) return maxn;
    return maxallsum;
}