#include <vector>
using namespace std;
#include <numeric>


vector<int> solution(int N, vector<int> &P, vector<int> &Q) {

    // Find all primes between 2-N/2 using sieve method.

    vector<bool> isprime(1+N/2, 1);
    vector<bool> isSemiPrime(N+1, 0);
    vector<int> primes;
    primes.reserve(N/2);

    isprime[0] = 0;
    for (size_t p = 2; p < isprime.size(); ++p) {
        if (isprime[p]) {
            for (size_t m = 2*p; m < isprime.size(); m+=p) {
                isprime[m] = 0;
            }
            primes.push_back(p);
        }
    }

    for (size_t i = 0; i < primes.size(); ++i) {
        for (size_t j = i; j < primes.size(); ++j) {
            size_t n = primes[i]*primes[j];
            if (n>=isSemiPrime.size()) break;
            isSemiPrime[n] = 1;          
        }
    }

    vector<int> result;
    result.reserve(P.size());
    int max_in_query = *max_element(Q.begin(), Q.end());
    int min_in_query = *min_element(P.begin(), P.end());
    vector<int> prefix_sum(max_in_query+1-min_in_query, 0);

    int acc = 0;
    auto d_first = prefix_sum.begin();
    for (auto iter = std::next(isSemiPrime.cbegin(),min_in_query); iter!= std::next(isSemiPrime.cbegin(),max_in_query+1); iter = std::next(iter)) {
        acc+=(*iter);
        (*d_first) = acc;
        ++d_first;
    }

    for (size_t i = 0; i < P.size(); ++i) {
        int upper = prefix_sum[Q[i]-min_in_query];
        int lower = (P[i]>min_in_query)? prefix_sum[P[i]-1-min_in_query] :0;
        result.push_back(upper - lower);
    }

    return result;
}

