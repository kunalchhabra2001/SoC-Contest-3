#include <bits/stdc++.h>

using namespace std;

#define int long long 
const int mod = 1e9 + 7;
const int nax = 1e5 + 5;


void add(int a, int b){
    a  = (a + b)%mod;
    if(mod < 0) a+=mod;
}

struct point {
    int x;
    int y;
    int cost;

    bool operator < (point b) {
        if (y != b.y)
            return y < b.y;
        return x < b.x;
    }
};

point base;


int ang_finder(point a,point b,point c){

    int val1 = (a.y - b.y) * (a.x - c.x);
    int val2 = (a.x - b.x) * (a.y - c.y);
    

    if(val1 == val2) return 0;
    else if(val1 < val2) return 2;
    else return 1;

}

int dist_sq(point p1,point p2){
    int dx = (p1.x - p2.x);
    int dy = (p2.y - p1.y);

    return dx*dx + dy*dy;
}

bool cmp_func(point p1,point p2){

    int val = ang_finder(base,p1,p2);
    if(val == 0){
        return dist_sq(base,p1) < dist_sq(base,p2);
    }else {
        return (val == 2);
    }

    
}

stack<point> ghram_Scan(vector<point> &corr,int n){

    int id = 0;
    for(int i=1;i<n;i++){
        if(corr[i] < corr[id]){
            id = i;
        }
    }

    swap(corr[0],corr[id]);
    base = corr[0];

    sort(corr.begin()+1,corr.end(),cmp_func);
    
    stack<point> st;

    st.push(corr[0]);
    st.push(corr[1]);
    

    for(int i=2;i<n;i++){
        point p1 = st.top();
        st.pop();
        while(st.size()!=0 && (ang_finder(st.top(),p1,corr[i])!=2)){
            p1 = st.top();
            st.pop();
        }
        st.push(p1);
        st.push(corr[i]);
    }

    return st;


}

signed main()
{
    int n;
    cin>>n;

    vector<point> corr;
    for(int i=0;i<n;i++) corr.push_back(point());

    for(int i=0;i<n;i++){
        int x,y,c;
        cin>>x>>y>>c;
        corr[i] = {x,y,c};
       
    }

    if(n < 3){
        int ans = 0;
        for(int i=0;i<n;i++) ans+=(corr[i].cost);
        cout<<ans<<endl;
        return 0;
    }

    stack<point> st = ghram_Scan(corr,n);

    int ans = 0;
    while(!st.empty()){
       
        point p = st.top();
        ans+=(p.cost);
        st.pop();
    }

    cout<<ans<<endl;
    

    return 0;
}

