# 学习笔记

#### [思维图谱总结](https://github.com/hanqichen/algorithm014-algorithm014/blob/master/Week_07/Week7.pdf)

##### 双向 BFS 模板
 
```C++
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
```

##### 单词搜索 2 时间复杂度分析

虽然存在递归，但是由于有 visit 的存在，从矩阵每个节点出发，矩阵中所有节点只遍历一次。

因此，若矩阵元素个数为n，则时间复杂度为 O(n^2)