#include <vector>

using namespace std;

int solution(vector<int> &A, vector<int> &B) {
    
    vector<int> fishes;
    fishes.reserve(A.size());

    fishes.push_back(0);
    for (size_t i = 1; i < A.size(); ++i) {
        // See how the fish at index fish.back interacts with fish i.
        if (fishes.empty()) {
            fishes.push_back(i);
        }
        else if (B[fishes.back()] == B[i] || (B[fishes.back()]==0 && B[i]==1)) fishes.push_back(i);
        else {
            if (A[fishes.back()] < A[i]) {
                auto iter = fishes.rbegin();
                for (; 
                    (iter!=fishes.rend()) 
                    && (A[*iter] < A[i])
                    && (B[*iter] == 1 && B[i]==0); ) 
                {
                    iter=std::next(iter);
                }
                    
                if (iter==fishes.rend()) {
                    *fishes.begin() = i;
                    fishes.erase(iter.base()+1, fishes.end());
                } else if (!(B[*iter] == 1 && B[i]==0)) {
                    fishes.erase(iter.base(), fishes.end());
                    fishes.push_back(i);
                } else if (A[*iter] > A[i]) {
                    fishes.erase(iter.base(), fishes.end());
                }
            }
        }
    }
    return fishes.size();
}
