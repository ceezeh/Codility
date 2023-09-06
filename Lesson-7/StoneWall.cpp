#include <vector>
using namespace std;

int solution(vector<int> &H) {
    int s = 1;
    vector<int> q{H[0]};
    q.reserve(H.size());


    for (size_t i = 1; i < H.size(); ++i) {
        bool incr1 = (H[i]>H[i-1]);

        
        // Search the visited for exact height.

        auto iter = upper_bound( q.begin(), q.end(), H[i] );
        q.erase(iter, q.end());
        bool incr2 = q.back() != H[i];
        if (incr2) {
            q.push_back(H[i]); 
        } 

        s+=(incr2||incr1);

    }
    return s;
}