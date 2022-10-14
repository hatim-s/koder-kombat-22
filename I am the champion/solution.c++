// Created by: G Gautham Krishna
#include <bits/stdc++.h>

using namespace std;

// shortforms

#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define all(x) (x).begin(), (x).end()
#define srt(v) sort(v.begin(), v.end())
#define rev(v) reverse(v.begin(), v.end())
#define lb(v, x) lower_bound(v.begin(), v.end(), x)
#define ub(v, x) upper_bound(v.begin(), v.end(), x)
#define cpy(v2, v1) v2.assign(v1.begin(), v1.end())
#define maxv(a) *max_element(a.begin(), a.end())
#define minv(a) *min_element(a.begin(), a.end())
#define ff first
#define ss second
#define endl "\n"

// type definitions

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

// constants

const long long int inf = 1e18;
const int mod = 1000000007;
#define pi 3.141592653589793238462

struct custom_hash
{
	static uint64_t splitmix64(uint64_t x)
	{
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const
	{
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

// graphs

// const int N=1e5+2;
// std::vector<int> vis(N,0);
// std::vector<int> adj[N];

// debugger

#ifndef ONLINE_JUDGE
#define debug(x)       \
	cerr << #x << " "; \
	_print(x);         \
	cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t)
{
	cerr << t;
}
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
	cerr << "{";
	_print(p.ff);
	cerr << ",";
	_print(p.ss);
	cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
	cerr << "[ ";
	for (T i : v)
	{
		_print(i);
		cerr << " ";
	}
	cerr << "]";
}
template <class T>
void _print(set<T> v)
{
	cerr << "[ ";
	for (T i : v)
	{
		_print(i);
		cerr << " ";
	}
	cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
	cerr << "[ ";
	for (T i : v)
	{
		_print(i);
		cerr << " ";
	}
	cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
	cerr << "[ ";
	for (auto i : v)
	{
		_print(i);
		cerr << " ";
	}
	cerr << "]";
}
template <class T, class V>
void _print(multimap<T, V> v)
{
	cerr << "[ ";
	for (auto i : v)
	{
		_print(i);
		cerr << " ";
	}
	cerr << "]";
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll gcd(ll a, ll b)
{
	if (b > a)
	{
		return gcd(b, a);
	}
	if (b == 0)
	{
		return a;
	}
	return gcd(b, a % b);
}
ll binexp(ll a, ll b, ll mod)
{
	ll res = 1;
	while (b > 0)
	{
		if (b & 1)
			res = (res * a) % mod;
		a = (a * a) % mod;
		b = b >> 1;
	}
	return res;
}
void extendgcd(ll a, ll b, ll *v)
{
	if (b == 0)
	{
		v[0] = 1;
		v[1] = 0;
		v[2] = a;
		return;
	}
	extendgcd(b, a % b, v);
	ll x = v[1];
	v[1] = v[0] - v[1] * (a / b);
	v[0] = x;
	return;
} // pass an arry of size1 3
ll mminv(ll a, ll b)
{
	ll arr[3];
	extendgcd(a, b, arr);
	return arr[0];
} // for non prime b
ll mminvprime(ll a, ll b) { return binexp(a, b - 2, b); }
bool revsort(ll a, ll b) { return a > b; }
ll combination(ll n, ll r, ll m, vector<ll> &fact, vector<ll> &ifact)
{
	ll val1 = fact[n];
	ll val2 = ifact[n - r];
	ll val3 = ifact[r];
	return (((val1 * val2) % m) * val3) % m;
}
void google(int t) { cout << "Case #" << t << ": "; }
vector<ll> sievefn(int n)
{
	int *arr = new int[n + 1]();
	vector<ll> vect;
	for (int i = 2; i <= n; i++)
		if (arr[i] == 0)
		{
			vect.push_back(i);
			for (int j = 2 * i; j <= n; j += i)
				arr[j] = 1;
		}
	return vect;
}
ll mod_add(ll a, ll b, ll m)
{
	a = a % m;
	b = b % m;
	return (((a + b) % m) + m) % m;
}
ll mod_mul(ll a, ll b, ll m)
{
	a = a % m;
	b = b % m;
	return (((a * b) % m) + m) % m;
}
ll mod_sub(ll a, ll b, ll m)
{
	a = a % m;
	b = b % m;
	return (((a - b) % m) + m) % m;
}
ll mod_div(ll a, ll b, ll m)
{
	a = a % m;
	b = b % m;
	return (mod_mul(a, mminvprime(b, m), m) + m) % m;
} // only for prime m
ll phin(ll n)
{
	ll number = n;
	if (n % 2 == 0)
	{
		number /= 2;
		while (n % 2 == 0)
			n /= 2;
	}
	for (ll i = 3; i <= sqrt(n); i += 2)
	{
		if (n % i == 0)
		{
			while (n % i == 0)
				n /= i;
			number = (number / i * (i - 1));
		}
	}
	if (n > 1)
		number = (number / n * (n - 1));
	return number;
} // O(sqrt(N))
ll getRandomNumber(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rng); }

// Credits to HealthyUG for the inspiration.
// Segment Tree with Point Updates and Range Queries
// Supports multiple Segment Trees with just a change in the Node and Update
// Very few changes required everytime

template <typename Node, typename Update>
struct SegTree
{
	vector<Node> tree;
	vector<ll> arr; // type may change
	int n;
	int s;
	SegTree(int a_len, vector<ll> &a)
	{ // change if type updated
		arr = a;
		n = a_len;
		s = 1;
		while (s < 2 * n)
		{
			s = s << 1;
		}
		tree.resize(s);
		fill(all(tree), Node());
		build(0, n - 1, 1);
	}
	void build(int start, int end, int index) // Never change this
	{
		if (start == end)
		{
			tree[index] = Node(arr[start]);
			return;
		}
		int mid = (start + end) / 2;
		build(start, mid, 2 * index);
		build(mid + 1, end, 2 * index + 1);
		tree[index].merge(tree[2 * index], tree[2 * index + 1]);
	}
	void update(int start, int end, int index, int query_index, Update &u) // Never Change this
	{
		if (start == end)
		{
			u.apply(tree[index]);
			return;
		}
		int mid = (start + end) / 2;
		if (mid >= query_index)
			update(start, mid, 2 * index, query_index, u);
		else
			update(mid + 1, end, 2 * index + 1, query_index, u);
		tree[index].merge(tree[2 * index], tree[2 * index + 1]);
	}
	Node query(int start, int end, int index, int left, int right)
	{ // Never change this
		if (start > right || end < left)
			return Node();
		if (start >= left && end <= right)
			return tree[index];
		int mid = (start + end) / 2;
		Node l, r, ans;
		l = query(start, mid, 2 * index, left, right);
		r = query(mid + 1, end, 2 * index + 1, left, right);
		ans.merge(l, r);
		return ans;
	}
	void make_update(int index, ll val)
	{									 // pass in as many parameters as required
		Update new_update = Update(val); // may change
		update(0, n - 1, 1, index, new_update);
	}
	Node make_query(int left, int right)
	{
		return query(0, n - 1, 1, left, right);
	}
};

struct Node1
{
	ll val; // may change
	Node1()
	{			 // Identity element
		val = 0; // may change
	}
	Node1(ll p1)
	{			  // Actual Node
		val = p1; // may change
	}
	void merge(Node1 &l, Node1 &r)
	{						 // Merge two child nodes
		val = (l.val + r.val)%mod; // may change
	}
};

struct Update1
{
	ll val; // may change
	Update1(ll p1)
	{			  // Actual Update
		val = p1; // may change
	}
	void apply(Node1 &a)
	{				 // apply update to given node
		a.val = val; // may change
	}
};

int main()
{
	// #ifndef ONLINE_JUDGE
	// freopen("inputf.in", "r", stdin);
	// freopen("outputf.in", "w", stdout);
	// freopen("Error.txt", "w", stderr);
	// #endif

	// fast io
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// main code starts here

	ll n;
	cin >> n;

	vector<ll> a(n);
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	// debug(a)

	vector<SegTree<Node1, Update1>> segs;

	vector<ll> v;
	for (int i = 0; i <= n; i++)
	{
		v.push_back(0);
	}

	for (ll i = 0; i < 12; i++)
	{
		segs.push_back(SegTree<Node1, Update1>(n + 1, v));
	}

	ll dp[n + 5][12];

	for (int i = 0; i < n; i++)
	{
		dp[i][1] = 1;
		segs[1].make_update(a[i], 1);
		for (int j = 2; j <= 11; j++)
		{
			dp[i][j] = segs[j - 1].make_query(0, a[i] - 1).val;
			// debug(dp[i][j])
			segs[j].make_update(a[i], dp[i][j]);
		}
	}

	int q;
	cin >> q;

	for (int i = 0; i < q; i++)
	{
		ll pow, no;
		cin >> pow >> no;
		if (pow > n)
		{
			pow = n + 1;
		}
		// debug(pow)
		cout << segs[no].make_query(0, pow - 1).val << endl;
	}

	// cout<<segs[k+1].make_query(0,n).val<<endl;

	return 0;
}
