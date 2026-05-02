class Solution {
public:
   bool wordPattern(string pattern, string s) {
    vector<string> words;
    string word;
    stringstream ss(s);

    while (ss >> word) {
        words.push_back(word);
    }

    if (pattern.size() != words.size()) return false;

    unordered_map<char, int> charIndex;
    unordered_map<string, int> wordIndex;

    for (int i = 0; i < pattern.size(); i++) {
        if (charIndex[pattern[i]] != wordIndex[words[i]]) {
            return false;
        }
        charIndex[pattern[i]] = wordIndex[words[i]] = i + 1;
    }

    return true;
}
};