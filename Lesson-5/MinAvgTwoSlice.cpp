// you can use includes, for example:
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

int solution(vector<int> &A) {
    // Implement your solution here

    vector<int> rA;
    rA.reserve(A.size());

    std::partial_sum(A.begin(), A.end(), A.begin());

    double min_avg = (A[0]+A[1]/2);
    int min_idx = 0;
    for (int i = -1; i < static_cast<int>(A.size()-2); ++i) { 
        for (int j = A.size()-1; j > i+1; --j) { 

            const double lower_A = (i<0)?0:A[i];
            double avg = static_cast<double>(A[j]-lower_A)/(j-i);

            if (avg<min_avg){
                min_avg = avg;
                min_idx = i+1;
            }
        }       
    }
    return min_idx;
}
