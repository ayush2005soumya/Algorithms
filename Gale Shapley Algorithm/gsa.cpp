#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

int findIndex(const vector<string>& list, const string& name) {
    return find(list.begin(), list.end(), name) - list.begin();
}

int main() {
    int n = 3;
    vector<string> men = {"A", "B", "C"};
    vector<string> women = {"X", "Y", "Z"};

    unordered_map<string, vector<string>> menPref = {
        {"A", {"X", "Y", "Z"}},
        {"B", {"Y", "X", "Z"}},
        {"C", {"Y", "Z", "X"}}
    };

    unordered_map<string, vector<string>> womenPref = {
        {"X", {"B", "A", "C"}},
        {"Y", {"C", "A", "B"}},
        {"Z", {"A", "C", "B"}}
    };

    unordered_map<string, int> womanIndex;
    for (int i = 0; i < n; ++i) womanIndex[women[i]] = i;

    vector<vector<int>> menPrefs(n), womenRanks(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (const string& w : menPref[men[i]])
            menPrefs[i].push_back(womanIndex[w]);

    for (int i = 0; i < n; ++i)
        for (int rank = 0; rank < n; ++rank)
            womenRanks[i][findIndex(men, womenPref[women[i]][rank])] = rank;

    vector<int> womanPartner(n, -1);
    vector<int> nextProposal(n, 0);
    queue<int> freeMen;
    for (int i = 0; i < n; ++i) freeMen.push(i);

    while (!freeMen.empty()) {
        int m = freeMen.front();
        freeMen.pop();
        int w = menPrefs[m][nextProposal[m]++];
        if (womanPartner[w] == -1) {
            womanPartner[w] = m;
        } else {
            int m1 = womanPartner[w];
            if (womenRanks[w][m] < womenRanks[w][m1]) {
                womanPartner[w] = m;
                freeMen.push(m1);
            } else {
                freeMen.push(m);
            }
        }
    }

    for (int w = 0; w < n; ++w)
        cout << men[womanPartner[w]] << " is matched with " << women[w] << endl;

    return 0;
}
