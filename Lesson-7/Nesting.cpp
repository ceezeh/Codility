#include <vector>
#include <map>
#include <string>

using namespace std;


int solution(string &S) {

    vector<int> queue;
    queue.reserve(S.size());

    map<char, int> enc {{'(', 1}, {')', -1}};

  
    for (size_t i = 0; i < S.size();++i) {
        if (enc[S[i]]>0) {queue.push_back(enc[S[i]]); continue;}
        
        if (queue.empty()) return 0;
        queue.pop_back();
    }

    return queue.size()==0;
}