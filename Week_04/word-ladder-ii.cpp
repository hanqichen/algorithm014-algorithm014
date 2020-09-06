class Solution {
public:
    bool helper(unordered_set<string>& head, unordered_set<string>& tail, unordered_set<string>& dict, unordered_map<string, vector<string>>& next, bool flip) {
        flip = !flip;
        if (head.empty()) {
            return 0;
        }
        if (head.size() > tail.size()) {
            return helper(tail, head, dict, next, flip);
        }

        for (auto item : head) {
            dict.erase(item);
        }

        for (auto item : tail) {
            dict.erase(item);
        }

        unordered_set<string> tempset;
        bool reach = false;
        for (auto item : head) {
            string temp = item;
            for (int k = 0; k < item.size(); k++) {
                char origin = temp[k];
                for (int c = 0; c < 26; c++) {
                    temp[k] = 'a' + c;
                    if (tail.find(temp) != tail.end()) {
                        flip ? next[temp].push_back(item) : next[item].push_back(temp);
                        reach = true;
                    }
                    if (!reach && dict.find(temp) != dict.end()) {
                        flip ? next[temp].push_back(item) : next[item].push_back(temp);
                        tempset.insert(temp);
                    }
                }
                temp[k] = origin;
            }
        }

        return reach || helper(tail, tempset, dict, next, flip);
    }

    void getPath(string& beginWord, string& endWord, unordered_map<string, vector<string>>& next, vector<string>& path, vector<vector<string>>& ans) {
        if (beginWord == endWord) {
            ans.push_back(path);
            return;
        }

        for (auto item : next[beginWord]) {
            path.push_back(item);
            getPath(item, endWord, next, path, ans);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        vector<string> path(1, beginWord);

        unordered_set<string> head, tail;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        unordered_map<string, vector<string>> next;

        if (dict.find(endWord) == dict.end()) {
            return ans;
        }

        head.insert(beginWord);
        tail.insert(endWord);
        bool flip = true;

        if (helper(head, tail, dict, next, flip)) {
            getPath(beginWord, endWord, next, path, ans);
        }

        return ans;

    }
};