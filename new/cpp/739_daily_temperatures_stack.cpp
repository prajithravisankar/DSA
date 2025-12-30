class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // idea: stack
        // have a stack to track pair of {temp, index}. 
        // this stack tracks temp that are lesser than current index. 
        // if the top of the stack is less than current index, get its
        // index and the difference is number of days until higher temp. 
        // while loop the stack with current temp and current index until 
        // we go through all the lesser temperatures than current temperatures, 
        // and update our until array which is our resulting arrays of number
        // of days until better temperature. 
        int n = temperatures.size();
        vector<int> until(n);
        stack<pair<int, int>> lower_temp;
        for (int i = 0; i < temperatures.size(); i++) {
            int current_temp = temperatures[i];
            while (!lower_temp.empty() && lower_temp.top().first < current_temp) {
                auto pair = lower_temp.top();
                lower_temp.pop();
                until[pair.second] = i - pair.second;
            }
            lower_temp.push({current_temp, i});
        }

        return until;
    }
    // time: O(n)
    // space: O(n)
};
