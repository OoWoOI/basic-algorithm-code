class Solution {
public:
    bool backspaceCompare(string s, string t) {
            vector<char> s1, s2;

            for (int i = 0; s[i]; i++) {
                switch(s[i]) {
                    case '#' : {
                        if (s1.size() == 0) continue;
                        s1.pop_back();
                    } break;
                    default : {
                        s1.push_back(s[i]);
                    } break;
                }
            }

            for (int i = 0; t[i]; i++) {
                switch(t[i]) {
                    case '#' : {
                        if (s2.size() == 0) continue;
                        s2.pop_back();
                    } break;
                    default : {
                        s2.push_back(t[i]);
                    } break;
                }
            }

            if (s1.size() != s2.size()) return false;    
            for (int i = 0; i < s1.size(); i++) {
                if (s1[i] != s2[i]) return false;
            }
            return true;
    }
};
