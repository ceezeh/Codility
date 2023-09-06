#include <cmath>
#include <vector>
using namespace std;

int solution(std::vector<int> &A) {

    if (A.size()<3) return 0;
    
    std::vector<size_t> peaks;
    peaks.reserve(A.size());
    for (size_t i = 1; i < A.size()-1; ++i) {
        if (A[i]>A[i-1] && A[i]> A[i+1]) peaks.push_back(i);
    }

    if (peaks.empty()) return 0;

    // Get the first potential max spacing/peaks.  
    size_t min_gap = sqrt(A.size() - peaks[0]-1)+1;
    
    // Max num is always max_gap + 1
    // Check if max possible gap is valid. If so return, else search for the next highest possible gap.
    size_t gap = min_gap;
    size_t recorded_max_flags = 0;
    size_t min_appropriate_gap = std::min(gap, 1+((A.size() - peaks[0]-1)/gap)); 

    while (gap && min_appropriate_gap > recorded_max_flags) 
    {
        size_t last_valid_peak_idx = 0;
        size_t no_of_peaks = 1;
        // For a given gap and size, there is a max number of flags possible. The minimum of both will be called the min_appropriate_gap.
        // Loop through sectors and determine if there is at least one peak in range.
        
        for (size_t blk_start = peaks[0]+gap; blk_start < A.size(); ) 
        {
            // Search for a peak at i+max_p_gap range.
            bool found_in_range = false;

            for (size_t j = last_valid_peak_idx+1; j < peaks.size();++j)
            {

                if ((peaks[j]- peaks[last_valid_peak_idx]) >= gap) 
                {
                    // If we find a peak in range, record its idx to be used 
                    // for minimum distance checks.              
                    last_valid_peak_idx = j;
                    found_in_range = true;
                    break;
                } 
            }

            if(found_in_range)  {
                ++no_of_peaks; 
                blk_start = peaks[last_valid_peak_idx]+gap;
                if (no_of_peaks>=min_appropriate_gap) break;}
            else {
                            
                break;
            }
        }
        --gap; // Try a smaller gap and recompute the minimum suitable distance.
        min_appropriate_gap = std::min(gap, 1+((A.size() - peaks[0]-1)/gap));  

        recorded_max_flags = max(recorded_max_flags, no_of_peaks);

        no_of_peaks = 0; 
    }
    return recorded_max_flags;
}