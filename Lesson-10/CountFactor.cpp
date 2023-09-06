#include <vector>
using namespace std;

int solution(int N) {
    if (N==1) return 1;
    if (N==std::numeric_limits<int>::max()) return 2;
    int i = 1;
    int count  = 0;
    int delta = (N&1)?2:1;

    while (i*i < N){        
        const bool is_divisor = (N%i==0);
        count += (2*is_divisor);
        i+=delta;
    }
    count += ((i*i)==N);
    return count;
}