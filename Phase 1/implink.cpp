// https://cp-algorithms.com/algebra/extended-euclid-algorithm.html
int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}// above code will give soln of ax+by=gcd(a,b) 

// to find modulo of a^b%m in o(logb)
long long bin_pow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
// cashing for factorinal 
// Factorial precomputation
using ll =long long;
const int MAX = 100000;
const int MOD = 10000007;
vector<ll> fact(MAX + 1, 0), inv_fact(MAX + 1, 0);

void factorials() {
    fact[0] = 1;

    for (ll i = 1; i <= MAX; i++)
        fact[i] = (fact[i - 1] * i) % MOD;

    inv_fact[MAX] = bin_pow(fact[MAX], MOD - 2, MOD);

    for (ll i = MAX - 1; i >= 0; i--)
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
}

// nCr calculation using factorials
ll ncr(int n, int k) {
    return (fact[n] * ((inv_fact[k] * inv_fact[n - k]) % MOD)) % MOD;
}
// Multiplication technique
ll multiplication(int n, int r) {
    ll result = 1;

    for (int i = 0; i < r; i++)
        result = (result * (n - i) / (i + 1)) % MOD;

    return result;
}
