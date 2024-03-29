#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3F3F3F3F3FLL
#define DINF (double)1e+30
#define EPS (double)1e-9
#define PI (double)acos(-1.0)
#define RAD(x) (double)(x*PI)/180.0
#define PCT(x,y) (double)x*100.0/y
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define F first
#define S second
#define D(x) x&(-x)
#define ALL(x) x.begin(),x.end()
#define RESET(a,b) memset(a, b, sizeof(a))
#define DEBUG(x,y) cout << x << y << endl
#define gcd(x,y) __gcd(x, y)
#define lcm(x,y) (x/gcd(x,y))*y
#define bitcnt(x) __builtin_popcountll(x)
#define lbit(x) 63-__builtin_clzll(x)
#define zerosbitll(x) __builtin_ctzll(x)
#define zerosbit(x) __builtin_ctz(x)

enum {North, East, South, West};
//{0, 1, 2, 3}
//{Up, Right, Down, Left}

int mi[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int mj[] = {0, 1, 0, -1, 1, 1, -1, -1};

const int MN=105;
int n, m, k;
int cnt=1;

struct node
{
public:
	int id, x, lap, t;
	node(){};
	node(int _id, int _x, int _lap, int _t)
	{
		id=_id, x=_x, lap=_lap, t=_t;
	}
	void update()
	{
		if(x==k)
		{
			x=1;
			lap++;
		}
		else
			x++;
		t=cnt++;
	}
	bool operator <(const node &foo) const
	{
		if(lap!=foo.lap)
			return lap>foo.lap;
		if(x!=foo.x)
			return x>foo.x;
		return t<foo.t;
	}
};

void init()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cout << "[FREOPEN]" << endl;
	return;
}

int main()
{
	//init();
	scanf("%d %d %d", &k, &n, &m);

	vector<node>data;
	for(int i=1; i<=n; i++)
		data.pb(node(i, 1, 0, 0));
	for(int i=0; i<m; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		x--;
		if(data[x].x==y)
			data[x].update();
	}
	sort(ALL(data));
	for(int i=0; i<n; i++)
	{
		i>0?printf(" "):NULL;
		printf("%d", data[i].id);
	}
	printf("\n");
	return 0;
}