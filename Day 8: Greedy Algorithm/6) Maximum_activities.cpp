
#include <algorithm>

int maximumActivities(vector<int> &start, vector<int> &finish) {
    int n = start.size();
    vector<pair<int, int>> meet(n);

    for (int i = 0; i < n; i++) {
        meet[i].first = finish[i];
        meet[i].second = start[i];
    }

    sort(meet.begin(), meet.end());

    int maxVal = 1;
    int T = meet[0].first;

    for (int i = 1; i < n; i++) {

        if (meet[i].second >= T) {
            maxVal++;
            T = meet[i].first;
        }
    }
    return maxVal;
}
