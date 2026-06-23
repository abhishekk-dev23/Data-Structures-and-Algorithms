class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {

        unordered_map<int, int> freq;
        for(int i=0; i<arr1.size(); i++) {
            freq[arr1[i]]++;
        }
        int k = 0;
        for(auto x: arr2) {
            while(freq[x] > 0) {
                arr1[k++] = x;
                freq[x]--;
            }
        }
        vector<int> rem;
        for(auto x: freq) {
            while(x.second > 0) {
                rem.push_back(x.first);
                x.second--;
            }
        }
        sort(rem.begin(), rem.end());

        for(auto x: rem) {
            arr1[k++] = x;
        }

        return arr1;
    }
};