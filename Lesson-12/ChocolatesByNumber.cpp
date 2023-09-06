#include <bitset>
int solution(int N, int M) {
    // Implement your solution here
    
    if (N==1) return 1;
    bitset<1000000001>b{};

    int count  = 0;
    for (int i = 0; b[i]!=1;  ) {
        count += (1+(N-i-1)/M);
        b[i] = 1;
        const int inter = (N-i)%M;
        i = ( (inter!=0) * (M - inter) )%N;
    }
    return count;
}