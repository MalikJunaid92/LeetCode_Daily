class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> p;
        for (int i = 0; i < speed.size(); i++) {
            p.push_back({position[i], speed[i]});
        }
        sort(p.rbegin(), p.rend());
        vector<double> st;
        for (auto& s : p) {
            st.push_back((double)(target - s.first) / s.second);
            if (st.size() >= 2 && st.back() <= st[st.size() - 2]) {
                st.pop_back();
            }
        }
        return st.size();
    }
};