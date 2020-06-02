#include<bits/stdc++.h>
using namespace std;

#define int long long

struct pt {
    int x, y;
};

bool cmp_pnts(pt a, pt b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool clockwise(pt a, pt b, pt c) {
    return a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y) < 0;
}

bool counter_cw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y) > 0;
}

void convex_hull(vector<pt>& a) {
    if(a.size() == 1) return;
    sort(a.begin(), a.end(), &cmp_pnts);
    pt p1 = a[0], p2 = a.back();
    vector<pt> up_fig, down_fig;
    up_fig.push_back(p1);
    down_fig.push_back(p1);
    for(int i = 1; i < (int)a.size(); i++) {
        if(i == a.size()-1 || clockwise(p1, a[i], p2)) {
            while(up_fig.size() >= 2 && !clockwise(up_fig[up_fig.size()-2], up_fig[up_fig.size()-1], a[i]))
                up_fig.pop_back();
            up_fig.push_back(a[i]);
        }
        if(i == a.size()-1 || counter_cw(p1, a[i], p2)) {
            while(down_fig.size() >= 2 && !counter_cw(down_fig[down_fig.size()-2], down_fig[down_fig.size()-1], a[i]))
                down_fig.pop_back();
            down_fig.push_back(a[i]);
        }
    }
    a.clear();
    for(int i = 0; i < (int)up_fig.size(); i++)
        a.push_back(up_fig[i]);
    for(int i = down_fig.size()-2; i > 0; i--)
        a.push_back(down_fig[i]);
}

int calc_area(const vector<pt>& fig) {
    int res = 0;
    for(int i = 0; i < fig.size(); i++) {
        int j= i+ 1; if(j==fig.size())j=0;
        int y1= fig[i].y; int x1= fig[i].x;
        int y2= fig[j].y; int x2= fig[j].x;
     //   cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<"\n";
        res+=(x1*y2)-(x2*y1);
    }
    return abs(res);
}

signed main(){
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> v(n), min_vec(n), max_vec(n);
        for(int i = 0; i < n; i++) cin>>v[i];
        for(int i = 0; i < n; i++) { min_vec[i] = v[i]; max_vec[i] = v[i]; }
        for(int i = n-2; i >= 0; i--) { min_vec[i] = min(min_vec[i+1], min_vec[i]); max_vec[i] = max(max_vec[i+1], max_vec[i]); }
        vector<pt> polygon;
        for(int i = 0; i < n-1; i++) {
            struct pt abc;
            abc.x = v[i];
            abc.y = min_vec[i+1];
            polygon.push_back(abc);
            abc.y = max_vec[i+1];
            polygon.push_back(abc);
        }
        convex_hull(polygon);
        int ans = calc_area(polygon);
        cout<<ans<<"\n";
    }
    return 0;
}
