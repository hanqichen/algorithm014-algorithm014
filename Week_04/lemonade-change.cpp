class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int m_5 = 0;
        int m_10 = 0;

        for (auto item : bills) {
            if (item == 5) {
                m_5++;
            } else if (item == 10) {
                m_5--;
                m_10++;
            } else {
                if (m_10 == 0) {
                    m_5 -= 3;
                } else {
                    m_10--;
                    m_5--;
                }
            }

            if (m_5 < 0) return false;
        }
        return true;

    }
};