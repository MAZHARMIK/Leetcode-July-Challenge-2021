/*
Basically we have to greedily pick the digits with highest frequency and see if we reach half size of array.
You can do it by sorting frequence, or by using priority_queue or by using mylti_set(with comparator for sorting in descending order)
*/

//Approach-1 (Map + priority queue)
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int, int> mp;
        int n = arr.size();
        for(int &x : arr) mp[x]++;
        
        priority_queue<int> pq; //max heap
        
        for(auto &it : mp)
            pq.push(it.second);
        
        int count = 0;
        int sum   = 0;
        
        while(!pq.empty() && sum < n/2) {
            sum += pq.top();
            count++;
            pq.pop();
        }
        return count;
    }
};

//Approach-2 (Map + multiset)
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int, int> mp;
        int n = arr.size();
        for(int &x : arr) mp[x]++;
        
        multiset<int, greater<int>> ms;
        
        for(auto &it : mp)
            ms.insert(it.second);
        
        multiset<int>::iterator itr;
        int count = 0;
        int sum   = 0;
        for(itr = ms.begin(); itr != ms.end() && sum < n/2; itr++) {
            sum += *itr;
            count++;
        }
        
        return count;
        
    }
};

//Approach-3 (Using Map + Sort)
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int, int> mp;
        int n = arr.size();
        for(int &x : arr)
            mp[x]++;
        
        vector<int> freq(mp.size(), 0);
        int i = 0;
        for(auto &it : mp)
            freq[i++] = it.second;
        
        sort(begin(freq), end(freq));
        
        int j     = freq.size()-1;
        int sum   = 0;
        int count = 0;
        while(j >= 0 && sum < n/2) {
            sum += freq[j];
            count++;
            j--;
        }
        
        return count;
    }
};
