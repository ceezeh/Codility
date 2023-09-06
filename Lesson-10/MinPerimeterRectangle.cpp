#include <cmath>

int solution(int N) {
    // Implement your solution here
    int l = sqrt(N);

    if (l*l == N) return 4*l;

    for (;N%l != 0; --l) ;

    return 2* (l + N/l);
}
