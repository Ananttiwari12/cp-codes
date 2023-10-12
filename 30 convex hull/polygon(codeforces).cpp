#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long

#define mod 1000000007

struct Point {
	int x, y;
	bool operator < (Point P) const {
		if (x == P.x) return y < P.y;
		else return x < P.x;
	}
	bool operator == (Point P) const {
		return (x == P.x && y == P.y);
	}
};

bool cw(Point a, Point b, Point c) {
	return a.x * (c.y - b.y) + b.x * (a.y - c.y) + c.x * (b.y - a.y) > 0;
}

bool ccw(Point a, Point b, Point c) {
	return a.x * (c.y - b.y) + b.x * (a.y - c.y) + c.x * (b.y - a.y) < 0;
}

bool cll(Point a, Point b, Point c) {
	return a.x * (c.y - b.y) + b.x * (a.y - c.y) + c.x * (b.y - a.y) == 0;
}

vector<Point> convex_hull(vector<Point> points) {
	if (points.size() <= 2) return points;

	sort(points.begin(), points.end());

	vector<Point> up, down;
	Point first = points[0], last = points.back();

	up.push_back(first); down.push_back(first);

	for (int i = 1; i < points.size(); i++) {
		if (i == points.size() - 1 || cw(first, points[i], last)) {
			// up set
			while (up.size() >= 2 && ccw(up[up.size() - 2], up[up.size() - 1], points[i])) {
				up.pop_back();
			}
			up.push_back(points[i]);
		}
		if(i == points.size() - 1 || ccw(first, points[i], last)) {
			// down set
			while (down.size() >= 2 && cw(down[down.size() - 2], down[down.size() - 1], points[i])) {
				down.pop_back();
			}
			down.push_back(points[i]);
		}
	}
	points.clear();
	for (int i = 0; i < up.size(); i++) {
		points.push_back(up[i]);
	}
	for (int i = 0; i < down.size(); i++) {
		points.push_back(down[i]);
	}

	sort(points.begin(), points.end());
	points.resize(unique(points.begin(), points.end()) - points.begin());

	return points;
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

	int na; cin >> na;

	vector<Point> points_a(na);
	for (int i = 0; i < na; i++) {
		cin >> points_a[i].x >> points_a[i].y;
	}
    int nb; cin>>nb;
    set<Point>st;
    vector<Point>points_b(nb);
	for (int i = 0; i < nb; i++) {
		cin >> points_b[i].x >> points_b[i].y;
        st.insert(points_b[i]);
	}
    vector<Point>points;
    for(int i=0;i<na;i++){
        points.push_back(points_a[i]);
    }
    for(int i=0;i<nb;i++){
        points.push_back(points_b[i]);
    }
	vector<Point> convex_hull_vector = convex_hull(points);
    bool ans=true;
	for (auto x : convex_hull_vector) {
		if(st.count(x)){
            ans=false;
            break;;
        }
	}
    if(ans){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}
