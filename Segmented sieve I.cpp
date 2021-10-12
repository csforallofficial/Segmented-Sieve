#include<bits/stdc++.h>
#include<vector>
using namespace std;
int sieve[100005];
void createSieve(){
    for(long long i = 2; i < 100000; i++)
        sieve[i] = 1;
    for(long long i = 2; i < 100000; i++){
        if(sieve[i] == 1){
            for(long long j = i*i; j < 100000; j+=i){
                if(sieve[j] == 1)
                    sieve[j] = 0;
            }
        }
    }
}
void segmentedSieve(){
    createSieve();
    int l,r;
    cin >> l >> r;
    //Step 1: Collect all primes till sqrt(N)
    vector<int> primes;
    for(int i = 2; i*i <=r; i++){
        if(sieve[i] == 1)
            primes.push_back(i);
    }
    //Step 2: Create dummy array of different size and everyone marked as true
    int dummy[r-l+1];
    for(int i = 0; i < r-l+1; i++)
        dummy[i] = 1;
    //step 3: mark all multiples of primes
    for(auto pr:primes){
        int firstmultiple = (l % pr) + pr;
        for(int j = max(firstmultiple,pr*pr); j <= r; j+=pr ){
            dummy[j-l] = 0;
        }
    }
    //step 4: Iterate and count primes
    int count = 0;
    for(int i = l; i <=r; i++){
        if(dummy[i-l]==1)
            count++;
    }
    cout << count << endl;
}
int main() {
	segmentedSieve();
	return 0;
}
