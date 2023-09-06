#include <vector>
using namespace std;

int solution(vector<int> &A) {
    
    if (A.size()<4) return 0;

    vector<int>maxright(A.size(), 0);  
    {
        for (size_t i=A.size()-2; i > 1 ; --i) {
            maxright[i] = max(maxright[i+1]+A[i], A[i]);
        }
    }

    vector<int>maxleft(A.size(), 0);  
    {
        for (size_t i=1; i < A.size()-2 ; ++i) {
            maxleft[i] = max(maxleft[i-1]+A[i], A[i]);
        }
    }

    int maxsum = 0;
    for (size_t i=1; i < A.size()-1; ++i) {

        const bool left_exist = i>1;
        const bool right_exist = i<(A.size()-2);

        const int rightsum = maxright[i+1];
        const int leftsum  = maxleft[i-1];

        if (left_exist&right_exist) maxsum = max(maxsum, leftsum+rightsum);

        if (left_exist) maxsum = max(maxsum, leftsum);
        if (right_exist) maxsum = max(maxsum, rightsum);
    }

    return maxsum;
}
