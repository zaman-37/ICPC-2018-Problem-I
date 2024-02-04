/// ICPC 2018, Problem: I


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<int>::iterator vit;
typedef set<int>::iterator sit; 

#define PB push_back
#define F first
#define S second
#define MP make_pair
#define endl '\n'
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define sz(x) (int)x.size()
#define tt int t; cin >> t; for (int tc=1; tc<=t; tc++)

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infll = 9000000000000000000;
#define MOD 1000000007

#define mem(a,b) memset(a, b, sizeof(a) )
#define sqr(a) ((a) * (a))
ll gcd ( ll a, ll b ) { return __gcd ( a, b ); }
ll lcm ( ll a, ll b ) { return a * ( b / gcd ( a, b ) ); }

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield);cout.precision(10);cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

int dx[] = {0, 0, +1, -1};
int dy[] = {+1, -1, 0, 0};
//int dx[] = {+1, 0, -1, 0, +1, +1, -1, -1};
//int dy[] = {0, +1, 0, -1, +1, -1, +1, -1};

ll n, m, k;
const int mx = 1e4 + 123;
int arr[mx];

bool cal (int mid) {
    int val = arr[1] + mid*2;
    int l = 1;
    bool fl = false;
    int a = k;
    while (a--) {
        int r = m;
        while (l<=r) {
            int m = (l+r)/2;
            if (val >= arr[m]) {
                l = m+1;
            } else {
                r = m-1;
            }
        }

        if (l>m) {
            fl = true;
            break;
        }

        int dis = (arr[l]-arr[1])/2;
        if (dis <= mid) l++;
        
        val = arr[l] + mid*2;
    }

    return fl;
}

int main() {
    optimize()
    tt {
        cin >> n >> m >> k;
        mem (arr, 0);
        for (int i=1; i<=m; i++) cin >> arr[i];
        sort(arr, arr+m+1);

        int l = 1, r = 1e9 + 123;
        while (l<=r) {
            int mid = (l+r)/2;
            if (cal(mid)) {
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        cout << "Case " << tc << ": " << l << endl;
    }

    return 0;
}

/*
Test Case: 
3
5 2 1
1 5
5 2 1
1 4
100 6 3
*/

/*
Output: 
3
5 2 1
1 5
5 2 1
1 4
100 6 3
*/