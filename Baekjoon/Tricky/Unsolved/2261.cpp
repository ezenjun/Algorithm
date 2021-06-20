// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main(){
//     int n; cin >> n;
//     vector<pair<int, int>> v(n);
//     vector<int> ans;

//     for(int i=0; i<n; i++){
//         int x, y; cin >> x >> y;
//         v[i] = {x, y};
//     }

//     for(int i=0; i<v.size(); i++){
//         for(int j=i+1; j<v.size(); j++){
//             ans.push_back((v[i].first-v[j].first)*(v[i].first-v[j].first) + (v[i].second-v[j].second)*(v[i].second-v[j].second));
//         }
//     }
//     sort(ans.begin(), ans.end());
//     cout << ans[0] << "\n";
// }
// //이 방법은 메모리초과 뜸 O(n^2 log n)


// divide and  conqur
// #include <stdio.h>
// #include <stdlib.h>
// #include <algorithm>
// #include <math.h>
// #include <float.h>
// using namespace std;

// struct Point{int x, y;};

// int compareX(const void*a, const void* b){
//     Point *p1 = (Point*)a, *p2 = (Point*)b;
//     return p1->x - p2->x;
// } 

// int compareY(const void*a, const void* b){
//     Point *p1 = (Point*)a, *p2 = (Point*)b;
//     return p1->y - p2->y;
// } 

// float dist(Point p1, Point p2){
//     return sqrt((p1.x-p2.x)*(p1.x-p2.x) +(p1.y-p2.y)*(p1.y-p2.y));
// }

// float bruteforce(Point p[], int n){
//     float min = FLT_MAX;
//     for(int i=0; i<n; ++i){
//         for(int j = i+1; j<n; ++j){
//             if(dist(p[i], p[j]) < min) min = dist(p[i], p[j]);
//         }
//     }
//     return min;
// }

// float stripClosest(Point strip[], int size, float d){
//     float min = d;
//     qsort(strip, size, sizeof(Point), compareY);
//     for(int i=0; i<size; ++i){
//         for(int j = i+1; j<size && (strip[j].y - strip[i].y) < min; ++j){
//             if(dist(strip[i], strip[j]) < min){
//                 min = dist(strip[i], strip[j]);
//             }
//         }
//     }
//     return min;
// }

// float closestUtil(Point p[], int n){
//     if(n<=3) return bruteforce(p,n);
//     int mid = n/2;
//     Point midPoint = p[mid];
//     float dl = closestUtil(p,mid);
//     float dr = closestUtil(p+mid, n-mid);
//     float d = min(dl, dr);
//     Point strip[n];
//     int j = 0; 
//     for(int i=0; i<n; i++){
//         if(abs(p[i].x - midPoint.x) < d)
//             strip[j] = p[i], j++;
//     }
//     return min(d, stripClosest(strip, j, d));
// }

// float closest(Point p[], int n){
//     qsort(p, n, sizeof(Point), compareX);
//     return closestUtil(p,n);
// }

// int main(){
//     int n; scanf("%d",&n);
//     Point p[n];
//     for(int i=0; i<n; i++){
//         int x, y; scanf("%d %d",&x, &y);
//         p[i] = {x,y};
//     }
//     int m = sizeof(p) / sizeof(p[0]);
//     printf("%f",closest(p,m)*closest(p,m));
// }