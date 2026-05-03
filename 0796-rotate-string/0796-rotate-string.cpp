class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        if(s == goal) return true;

        string str = s + s;
        return str.find(goal) != string::npos;
    }
};