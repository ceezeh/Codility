#include <vector>
using namespace std;

int solution(vector<int> &A) {
   
    struct P{
        int val;
        size_t idx;
    };

    vector<P> s;
    s.reserve(A.size());
    for (size_t i = 0; i < A.size();++i ) {
        if (s.empty()) {
            s.push_back({A[i], i});
            continue;
        }
        if (s.back().val != A[i] ) {
            s.pop_back();
        } else {
            s.push_back({A[i], i});
        }
    }
    if (s.empty()) return -1;

    int c = 0;
    for (size_t i = 0; i < A.size();++i ) {
        c+= (A[i]==s[0].val);
    }
    return (c > static_cast<int>(A.size()/2))?s[0].idx:-1;
}