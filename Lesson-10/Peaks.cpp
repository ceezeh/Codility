#include <vector>
using namespace std;

int solution(vector<int> &A) {

    // Find all primes in range.
    // Check all primes starting from the lowest to see if it is a valid slicer.

    vector<size_t> peaks;
    peaks.reserve(A.size());
    if (A.size() < 3) return 0;
    for (size_t i = 1; i < A.size()-1; ++i ) {
        if (A[i]>A[i-1] && A[i]>A[i+1])   peaks.push_back(i);
    }
    //Get an initial minimum possible gap.
    if (peaks.empty()) return 0;

    size_t gap = *peaks.begin()+1;

    while (gap<= A.size()) {  
        if (A.size()%gap) {++gap; continue;}
          
        // Check if valid.
        size_t last_peak_idx = 0;
        bool valid = true;
        for (size_t blckstart = gap; blckstart < A.size(); blckstart+=gap) 
        {
            bool nfound = true;
            for (size_t i = last_peak_idx+1; i < peaks.size(); ++i) 
            {
                if (peaks[i]>=(blckstart) && peaks[i]<blckstart+gap) 
                {
                    last_peak_idx = i;
                    nfound = false;
                    break;
                }
            }
            if (nfound) { valid = false; break; }
        }        
        if (valid) return A.size()/gap; 
        
        
        ++gap;
    }
    return 0;
}   

