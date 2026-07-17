class Solution {
public:
    vector<string> ans;

    bool valid(string s) {
        if (s.size() > 1 && s[0] == '0')
            return false;

        int num = stoi(s);

        return num >= 0 && num <= 255;
    }

    void backtrack(string &s, int idx, vector<string> &parts) {

        // If 4 parts are formed
        if (parts.size() == 4) {
            if (idx == s.size()) {

                string ip = "";

                for (int i = 0; i < 4; i++) {
                    ip += parts[i];
                    if (i != 3)
                        ip += '.';
                }

                ans.push_back(ip);
            }
            return;
        }

        // Try lengths 1, 2, and 3
        for (int len = 1; len <= 3; len++) {

            if (idx + len > s.size())
                break;

            string part = s.substr(idx, len);

            if (!valid(part))
                continue;

            parts.push_back(part);

            backtrack(s, idx + len, parts);

            parts.pop_back();
        }
    }

    vector<string> restoreIpAddresses(string s) {

        vector<string> parts;

        backtrack(s, 0, parts);

        return ans;
    }
};