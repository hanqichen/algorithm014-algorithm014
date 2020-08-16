class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int ans = 0;

        for (int current = 0; current < height.size(); current++) {
            while(!st.empty() && height[st.top()] < height[current]) {
                int low = height[st.top()];
                st.pop();
                if (st.empty()) {
                    break;
                }
                int high = min(height[st.top()], height[current]);
                int distance = current - st.top() - 1;
                ans = ans + (high - low) * distance;
            }
            st.push(current);
        }
        return ans;
    }
};