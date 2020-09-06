class Solution {
public:
    int helper(unordered_set<string>& head, unordered_set<string>& tail, unordered_set<string>& dict, int level) {
        if (head.empty()) {
            return 0;
        }
        if (head.size() > tail.size()) {
            return helper(tail, head, dict, level);
        }

        unordered_set<string> tempset;
        for (auto item : head) {
            for (int k = 0; k < item.size(); k++) {
                char origin = item[k];
                for (int c = 0; c < 26; c++) {
                    item[k] = 'a' + c;
                    if (tail.find(item) != tail.end()) {
                        return level + 1;
                    }
                    if (dict.find(item) != dict.end()) {
                        dict.erase(item);
                        tempset.insert(item);
                    }
                }
                item[k] = origin;
            }
        }

        return helper(tail, tempset, dict, level + 1);
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> head, tail;
        unordered_set<string> dict(wordList.begin(), wordList.end());

        if (dict.find(endWord) == dict.end()) {
            return 0;
        }

        head.insert(beginWord);
        tail.insert(endWord);
        dict.erase(beginWord);
        dict.erase(endWord);

        return helper(head, tail, dict, 1);
    }
};