class Solution {
public:
    int helper(unordered_set<string>& head, unordered_set<string>& tail, unordered_set<string>& dict, int level) {
        if (head.size() > tail.size()) {
            return helper(tail, head, dict, level);
        }
        if (head.empty()) {
            return 0;
        }

        unordered_set<string> temp;
        for (auto word : head) {
            for (int k = 0; k < word.size(); k++) {
                char origin = word[k];
                for (int c = 0; c < 26; c++) {
                    word[k] = 'a' + c;
                    if (tail.find(word) != tail.end()) {
                        return level + 1;
                    }
                    if (dict.find(word) != dict.end()) {
                        dict.erase(word);
                        temp.insert(word);
                    }
                }
                word[k] = origin;
            }
        }
        return helper(tail, temp, dict, level + 1);
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