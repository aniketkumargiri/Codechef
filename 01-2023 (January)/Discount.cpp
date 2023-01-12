/* Author: Aniket Giri */
#include <bits/stdc++.h>
using namespace std;
/*********************templete********************/
#define ll long long int
#define ld long double
#define fl(i, a, n) for (ll i = a; i < n; i++)
#define vl vector<ll>
#define pl pair<ll, ll>
#define um unordered_map<ll, ll>
#define all(v) (v).begin(), (v).end()
#define pu push_back
#define sp " "
#define nl "\n"
#define mns cout << "-1" << endl
#define zero cout << "0" << endl
#define one cout << "1" << endl
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define debug(x) cout << x << endl
#define rt return
const ll mod = (ll)(1e9 + 7);
const ll N = (ll)(1e5 + 5);
#define maxi LLONG_MAX
#define mini LLONG_MIN

template <typename T>
istream &operator>>(istream &input, vector<T> &v) {
    for (auto &i : v) {
        cin >> i;
    }
    return input;
}
template <typename T>
ostream &operator<<(ostream &output, vector<T> &v) {
    for (auto &i : v) {
        cout << i << sp;
    }
    return output;
}

/*********************Utility********************/
bool comp(const pl &a, const pl &b) { return (a.second < b.second); }
ll ceil_div(ll a, ll b) { return a % b == 0 ? a / b : (a / b) + 1; }
ll div_div(ll a, ll b) { return (a * b - 1) / (b - 1); }
ll no_of_digits(ll n) { return floor(log10(n) + 1); }
ll lcm(ll a, ll b) { return (a * 1LL * b) / __gcd(a, b); }
bool isVowel(char ch) { return (0x208222 >> (ch & 0x1f)) & 1; }
bool isSubstring(string s1, string s2) { return (s2.find(s1) != string::npos); }
bool isPerfectSquare(ll n) { return (ceil((ld)sqrt(n)) == floor((ld)sqrt(n))); }
ll mod_add(ll a, ll b) {
    a = a % mod;
    b = b % mod;
    return (((a + b) % mod) + mod) % mod;
}
ll mod_mul(ll a, ll b) {
    a = a % mod;
    b = b % mod;
    return (((a * b) % mod) + mod) % mod;
}
ll inv(ll i) {
    return (i == 1) ? 1 : (mod - ((mod / i) * inv(mod % i)) % mod) % mod;
}
ll binaryToDecimal(string s);
string decimalToBinary(ll n);
ll sumOfDigits(ll n);
ll power(ll a, ll b);
ll nearestPowerOfKtoN(ll n, ll k);
ll reverse(ll n);
bool isPalindrome(string s, ll start, ll end);
bool isSubSequence(string s1, string s2, ll m, ll n);
bool isPrime(ll n);
vl primeFactors(ll n);
vl sieveOfEratosthenes(ll m, ll n);
ll fibonacci(ll n);
bool isSubsetSum(vl arr, int sum);
ll maximumSubArraySum(vl &a, ll size);
ll longestIncreasingSubsequence(vl &nums);
ll longestCommonSubsequence(string s1, string s2, ll m, ll n);
ll binarySearch(vl &a, ll low, ll high, ll target);
vl nextGreaterElement(vl a, ll n);

/*********************Helper********************/

/*********************Solve Code********************/
void solve() {
    // Add your code here
    ll n;
    cin >> n;
    cout << 100 - n << nl;
}

/*********************Input-Output********************/
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

void open() {
#ifdef ANIKET
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
}

/*********************main******************/
int main() {
    fast;
    open();
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
    rt 0;
}

/**************Binary To Decimal*************/
ll binaryToDecimal(string s) {
    ll n = 0, k = 0;
    ll len = s.length();
    for (ll i = len - 1; i >= 0; i--) {
        if (s[i] == '1') {
            n += pow(2, k);
        }
        k++;
    }
    return n;
}

/**************Decimal To Binary*************/
string decimalToBinary(ll n) {
    string s = "";
    while (n) {
        s = to_string(n % 2) + s;
        n >>= 1;
    }
    return s;
}

/****************Sum of Digits***************/
ll sumOfDigits(ll n) {
    ll sum = 0;
    while (n != 0) {
        sum = sum + n % 10;
        n = n / 10;
    }
    return sum;
}

/****************Power***************/
ll power(ll a, ll b) {
    a %= mod;
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res = res * a % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

/**********Power of K Nearest to N*********/
ll nearestPowerOfKtoN(ll n, ll k) {
    ll lg = log(n) / log(k);
    ll a = pow(k, lg);
    ll b = pow(k, lg + 1);
    if ((n - a) < (b - n)) {
        return a;
    }
    return b;
}

/***************Reverse the digits**************/
ll reverse(ll n) {
    ll rev = 0;
    while (n != 0) {
        ll rem = n % 10;
        rev = rev * 10 + rem;
        n /= 10;
    }
    return rev;
}

/****************Is Palindrome***************/
bool isPalindrome(string s, ll start, ll end) {
    while (start < end) {
        if (s[start] != s[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

/****************Is Subsequence***************/
bool isSubSequence(string s1, string s2, ll m, ll n) {
    long long int j = 0;
    for (ll i = 0; i < n && j < m; i++) {
        if (s1[j] == s2[i]) {
            j++;
        }
    }
    return (j == m);
}

/******************Is Prime*****************/
bool isPrime(ll n) {
    if (n <= 1) {
        return false;
    }
    for (ll i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

/*******************Prime Divisors******************/
vl primeFactors(ll n) {
    vl ans;
    ll i = 2;
    while (n > 1) {
        if (n % i == 0) {
            ans.push_back(i);
            n /= i;
        } else {
            i++;
        }
    }
    return ans;
}

/*************Sieve of Eratosthenes************/
vl sieveOfEratosthenes(ll m, ll n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for (ll i = 2; i * i < n + 1; i++) {
        if (isPrime[i] == true && (ll)i * i <= n) {
            for (ll j = i * i; j < n + 1; j += i) {
                isPrime[j] = false;
            }
        }
    }
    vl primes;
    for (ll i = m; i < n + 1; i++) {
        if (isPrime[i] == true) {
            primes.push_back(i);
        }
    }
    return primes;
}

/*****************Fibonacci****************/
ll fibonacci(ll n) {
    ll prev2 = 0, prev1 = 1;
    if (n == 0) {
        return prev2;
    }
    if (n == 1) {
        return prev1;
    }
    for (ll i = 1; i < n; i++) {
        ll curr = prev2 + prev1;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

/*****************Subset Sum****************/
bool isSubsetSum(vl arr, int sum) {
    ll n = arr.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1));
    for (ll j = 0; j < sum + 1; j++) {
        dp[0][j] = false;
    }
    for (ll i = 0; i < n + 1; i++) {
        dp[i][0] = true;
    }
    for (ll i = 1; i < n + 1; i++) {
        for (ll j = 1; j < sum + 1; j++) {
            if (arr[i - 1] <= j) {
                dp[i][j] = (dp[i - 1][j - arr[i - 1]]) || (dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];
}

/*************Kadane's Algorithm************/
ll maximumSubArraySum(vector<ll> &a, ll size) {
    ll max_so_far = LLONG_MIN;
    ll max_ending_here = 0;
    for (ll i = 0; i < size; i++) {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
        }
        if (max_ending_here < 0) {
            max_ending_here = 0;
        }
    }
    return max_so_far;
}

/**********Longest Increasing Subsequence*********/
ll longestIncreasingSubsequence(vl &nums) {
    ll n = nums.size();
    vl ans;
    ans.push_back(nums[0]);
    for (ll i = 1; i < n; i++) {
        if (ans.back() < nums[i]) {
            ans.push_back(nums[i]);
        } else {
            ll idx = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
            ans[idx] = nums[i];
        }
    }
    return ans.size();
}

/**********Longest Common Subsequence*********/
ll longestCommonSubsequence(string s1, string s2, ll m, ll n) {
    ll dp[m + 1][n + 1];
    for (ll i = 0; i < m + 1; i++) {
        for (ll j = 0; j < n + 1; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

/*************Binary Search************/
ll binarySearch(vl &a, ll low, ll high, ll target) {
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        if (a[mid] == target) {
            return mid;
        } else if (a[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

/***********Next Greater Element**********/
vl nextGreaterElement(vl a, ll n) {
    vl ans;
    stack<ll> st;
    for (ll i = n - 1; i >= 0; i--) {
        if (st.size() > 0) {
            while (!st.empty() && st.top() <= a[i]) {
                st.pop();
            }
        }
        if (st.empty()) {
            ans.push_back(-1);
        } else {
            ans.push_back(st.top());
        }
        st.push(a[i]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
