int solution(int A, int B, int K) {
    
    int n1 = A/K;
    int n2 = B/K;
    
    return n2-n1 + (A%K==0);

}