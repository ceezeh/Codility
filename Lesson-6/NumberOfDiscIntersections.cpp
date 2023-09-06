#include <vector>
using namespace std;


template <typename T1>
auto sc = [] <typename T2>(T2 v) {return static_cast<T1>(v);};

int solution(vector<int> &A) {
    
    int intersections = 0;
   
    struct disc {
        long lower;
        long upper;
    };

    vector<disc> discs(A.size(), disc{});

     for (long i = 0; i< sc<long>(A.size()); ++i) {
         discs[i].upper = i+A[i];
         discs[i].lower = i-A[i];
    }

    std::sort(discs.begin(), discs.end(),[](disc& a, disc& b) {
        return a.lower < b.lower;
    });


    for (int i = 0; i< sc<int>(A.size()-1); ++i) {
        for (size_t j=i+1; discs[i].upper>=discs[j].lower && j<A.size(); ++j) {
            ++intersections;
            if (intersections>10000000) return -1;
        }
        
    }
    return intersections;
}
