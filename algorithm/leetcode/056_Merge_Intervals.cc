/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/

#include <iostream>
#include <vector>

using namespace std;

#ifdef LOCAL
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
#endif

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.size() == 0) return {};

        sort(intervals.begin(), intervals.end(), [](Interval& a, Interval& b) {
            if (a.start != b.start) return a.start < b.start;
            return a.end < b.end;
        });

        vector<Interval> res;
        Interval range = intervals[0];
        for (auto& v: intervals) {
            if (v.start <= range.end) {
                range.end = max(range.end, v.end);
            } else {
                res.push_back(range);
                range = v;
            }
        }
        res.push_back(range);
        return res;
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    vector<Interval> intervals({{1, 3}, {2, 6}, {8, 10}, {15, 18}});
    for (Interval& val: Solution().merge(intervals)) {
        cout << val.start << " " << val.end << endl;
    }
    return 0;
}
#endif
