// you can use includes, for example:
#include <algorithm>
#include <numeric>
#include <map>
#include <vector>
#include <array>
#include <string>

using namespace std;

enum class RangeType {ASC, DESC};

struct Range{
    int s;
    int e{-1};
    int min;
    RangeType type;
    vector<Range*>sub_range;
};

//-----------------------------------------------------------
vector<Range> GetRange(string &S, bool& flip) {
    flip = false;
    vector<Range> ranges;
    std::map<char, int> factors{{'A', 1}, {'C', 2},{'G', 3},{'T', 4}};

    RangeType t = (factors[S[0]]<= factors[S[1]])?RangeType::ASC:RangeType::DESC;
    Range r;
    r.s = 0;
    r.type = t;
    for (size_t i = 1; i < S.size(); ++i) {
        RangeType t2 = (factors[S[i-1]]<= factors[S[i]])?RangeType::ASC:RangeType::DESC;
        if (t!= t2) {
            flip = true;
            r.e = i-1;
            r.min = (r.type==RangeType::ASC)?r.s:r.e;
            ranges.push_back(r);

            // Reuse old variables.
            r.type = t2;
            r.s = i;
            r.e = -1;
            t = t2;
        }
    }
    if (r.e == -1) { // Take care of when the last range is incompletely created.
        r.e = S.size()-1;
        r.min = (r.type==RangeType::ASC)?r.s:r.e;
        ranges.push_back(r);
    }
    return ranges;
}

//-----------------------------------------------------------
vector<Range> GetRange(vector<Range> &lower_range, bool& flip) {
    vector<Range> ranges;
    flip = false;

    RangeType t = (lower_range[0].min<= lower_range[1].min)?RangeType::ASC:RangeType::DESC;
    Range r;
    r.s = 0;
    r.type = t;
    r.sub_range.push_back(&lower_range[0]);

    for (size_t i = 1; i < lower_range.size();++i) {
        RangeType t2 = (lower_range[i-1].min<= lower_range[i].min)?RangeType::ASC:RangeType::DESC;
        if (t!= t2) {
            flip = true;
            r.e = lower_range[i-1].e;
            r.min = (r.type==RangeType::ASC)?r.s:r.e;
            ranges.push_back(r);

            // Reuse old variables.
            r.sub_range.clear();
            r.type = t2;
            r.s = lower_range[i].s;
            r.e = -1;
            t = t2;
        }
        r.sub_range.push_back(&lower_range[i]);
    }
    if (r.e == -1) { // Take care of when the last range is incompletely created.
        r.e = lower_range.back().e;
        r.min = (r.type==RangeType::ASC)?r.s:r.e;
        ranges.push_back(r);
    }
    return ranges;

}
//-----------------------------------------------------------
int GetMin(const vector<Range>& cache, int s, int e) {
    int min = cache[0].min;
    for (auto iter = cache.begin(); iter!=cache.end();iter=std::next(iter) ) {
        // if (iter->s < s && iter->e>e ) {
        //     // Go a level deeper
        // }

        bool SInIter = s>=iter->s && s<= iter->e;
        bool EInIter = e>=iter->s && e<= iter->e;
        if ( SInIter ) { // No need to go a level deeper
            if (iter->type == RangeType::ASC) {
                min = s;
            } else {
                min = iter->min;
            }
        }
        if (EInIter ) { 
            int min_cand;
            if (iter->type == RangeType::ASC) {
                min_cand = iter->min;
            } else {
                min_cand = e;
            }
            min = (min_cand < min)? min_cand:min;
        }
        if (!SInIter & !EInIter & (s<iter->s) & (e>iter->e)) {
            min = (iter->min<min)?iter->min: min;
        }
    }
    return min;
}

//-----------------------------------------------------------
vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    // Implement your solution here
    
    vector<vector<Range>> range_levels;
    bool flip = false;
    {
        vector<Range> ranges = GetRange(S, flip);
        range_levels.push_back(ranges);
    }

    vector<int> ans;
    ans.reserve(Q.size());

    for (size_t i = 0; i < Q.size();++i) {
        int min = GetMin(range_levels.back(), P[i], Q[i]);
        ans.push_back(min);
    }

    return ans;
}
