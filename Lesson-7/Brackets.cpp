#include <map>
#include <vector>
#include <string>

using namespace std;

int solution(string &S) {

    map<char, int> enc {{'(', 1}, {')', -1}, {'[', 2}, {']', -2},{'{', 3}, {'}', -3}};

    vector<int> queue;
    queue.reserve(S.size());

    
    for ( size_t i=0; i< S.size();++i){
        if (enc[S[i]]>0) {
            queue.push_back(enc[S[i]]);
        } else {
            if (queue.back() != -enc[S[i]]) return 0;
            queue.pop_back();
        }
    }

    if (!queue.empty()) return 0;
    return 1;
}
