/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if
necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        if (intervals.size() == 0) return {newInterval};

        auto lower_cmp = [](const Interval& l, const Interval& r) { return l.start < r.start; };
        auto upper_cmp = [](const Interval& l, const Interval& r) { return l.end < r.end; };

        auto lower_it = lower_bound(intervals.begin(), intervals.end(), newInterval, lower_cmp);
        auto upper_it = lower_bound(intervals.begin(), intervals.end(), newInterval, upper_cmp);

        vector<Interval> res;
        Interval new_range;
        if (lower_it == intervals.begin()) {
            new_range.start = newInterval.start;
        } else {
            if ((lower_it - 1)->end < newInterval.start) {
                new_range.start = newInterval.start;
                res.insert(res.end(), intervals.begin(), lower_it);
            } else {
                new_range.start = (lower_it - 1)->start;
                res.insert(res.end(), intervals.begin(), lower_it - 1);
            }
        }

        if (upper_it == intervals.end()) {
            new_range.end = newInterval.end;
            res.push_back(new_range);
        } else {
            if (newInterval.end < upper_it->start) {
                new_range.end = newInterval.end;
                res.push_back(new_range);
                res.insert(res.end(), upper_it, intervals.end());
            } else {
                new_range.end = upper_it->end;
                res.push_back(new_range);
                res.insert(res.end(), upper_it + 1, intervals.end());
            }
        }
        return res;
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    vector<Interval> intervals({{1, 3}, {6, 9}});
    for (auto& range: Solution().insert(intervals, {2, 5})) {
        cout << "[" << range.start << " " << range.end << "]" << endl;
    }

    cout << "-------------------------------------------" << endl;

    for (auto& range: Solution().insert(intervals, {0, 5})) {
        cout << "[" << range.start << " " << range.end << "]" << endl;
    }

    cout << "-------------------------------------------" << endl;
    intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    for (auto& range: Solution().insert(intervals, {4, 9})) {
        cout << "[" << range.start << " " << range.end << "]" << endl;
    }

    return 0;
}
#endif
