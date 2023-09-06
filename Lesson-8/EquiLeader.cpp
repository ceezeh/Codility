#include <vector>
using namespace std;

   struct LeaderInfo{
        int leader;
        int num;
    };

LeaderInfo ComputeLeader (vector<int> &A, size_t start, size_t end, vector<int> &s ) {

    for (size_t i = start; i < end;++i) {
        if (s.empty()) {
            s.push_back(A[i]);
            continue;
        }
        if (A[i]!= s.back()) s.pop_back();
        else s.push_back(A[i]);
    }
    if (s.empty()) {
        s.clear();
        return {0,-1};
    }
    int c= 0;
    for (size_t i = start; i < end;++i) {
        c+= (A[i]==s[0]);
    }
    if (c>(static_cast<int>((end-start)/2))){
        s.clear();
        return {s[0], c};
    }
    s.clear();
    return {0, -1};
}


int solution(vector<int> &A) {

    vector<int> s;
    s.reserve(A.size());


    LeaderInfo right = ComputeLeader (A, 1, A.size(), s);
    if (right.num < 0) return 0;


    int num =  (A[0]==right.leader);

    LeaderInfo left {right.leader, num};
    
    for (size_t i = 1; i < A.size()-1;++i) {
        // Keep track of whether we are reducing the leader in R.
        if (A[i] == right.leader) {
            ++left.num;
            --right.num;
        }
        // If still majority in both, then add.
        bool mr = right.num > static_cast<int>((A.size()-i-1)/2);
        bool ml = left.num > static_cast<int>((i+1)/2);
        if (mr&ml) {
            ++num;
        }

    }
    return num;
    
}
