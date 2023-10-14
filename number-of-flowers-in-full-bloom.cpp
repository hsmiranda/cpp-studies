/*
https://leetcode.com/problems/number-of-flowers-in-full-bloom/
*/
class Solution {
public:
    vector<int> fullBloomFlowers(
        vector<vector<int>>& flowers, 
        vector<int>& people
    ) {

       map<int,int> mp;
       for (const auto& flower : flowers) {
           ++mp[flower[0]];
           --mp[flower[1]+1];
       }

       int sum = 0;
    //    for (auto& key_val : mp) {
    //        cout << key_val.first << ":" << key_val.second << " ";
    //    }
    //    cout << "\n";
       for (auto& key_val : mp) {
           sum += key_val.second;
           key_val.second = sum;
        //    cout << key_val.first << ":" << key_val.second << " ";
       }

       vector<int> answer(people.size(), 0);
       for (int p = 0; p < people.size(); ++p) {
           const auto target = people[p];
           auto it = mp.lower_bound(target); //primeiro valor que não é < que target

            if (mp.begin() == it) {
                if (it->first == target) {
                    answer[p] = it->second;
                }
                continue;
            }

            if (it == mp.end() || it->first != target) {
                --it;
            }

            answer[p] = it->second;
       }
        return answer;
    }
};
