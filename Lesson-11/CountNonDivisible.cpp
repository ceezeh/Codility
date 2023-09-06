#include <map>
#include <vector>
using namespace std;

vector<int> solution(vector<int> &A) {

    map<int, int> unique_count{};
    for (size_t i = 0; i < A.size(); ++i) {
        if (unique_count.contains(A[i])) ++unique_count[A[i]];
        else unique_count.insert({A[i], 1});
    }

    vector<int> raw_results(unique_count.rbegin()->first+1, 0); 

    for (auto iter=unique_count.begin(); 
        (iter!=(std::prev(unique_count.end()))) && (iter!=unique_count.end()); 
        iter= std::next(iter)) {

        int k  = iter->first *2;
        while (k <= unique_count.rbegin()->first) {
            raw_results[k]+=iter->second;
            k+=iter->first;
        }
    }

    vector<int> results(A.size(), 0);
    for (size_t i = 0; i < A.size(); ++i) {
        results[i] = A.size() - raw_results[A[i]]-unique_count[A[i]];
    }
    return results;
}