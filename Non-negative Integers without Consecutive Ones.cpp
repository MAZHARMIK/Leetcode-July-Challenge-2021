//Approach-1 (Brute Force (TLE))
class Solution {
public:
    int findIntegers(int n) {
        int count = 0;
        for(int i = 0; i<=n; i++) {
            bitset<32> bt(i);
            bool found = true;
            for(int i = 1; i<32; i++) {
                if(bt[i] == 1 && bt[i-1] == 1) {
                    found = false;
                    break;
                }
            }
            if(found)
                count++;
        }
        
        return count;
    }
};

//Approach-2 (DP Accepted)
class Solution {
public:
    int findIntegers(int n) {
        vector<vector<int>> t(2, vector<int>(32));
        /*
            t[i][j] -> i can be either 0 or 1
            t[0][j] = Total possibility when number starts with 0 and having length = j
            t[1][j] = Total possibility when number starts with 1 and having length = j
        */
        
        t[0][0] = 1;
        for(int len = 1; len < 32; len++) {
            t[0][len] = t[0][len-1] + t[1][len-1];
            t[1][len] = t[0][len-1]; //I can't add consecutive 1
        }
        
        bitset<32> bt(n);
        string str   = bt.to_string();
        int result   = 0;
        int prevBit  = -1;
        bool consOne = false;
        for(int i = str.length()-1; i>=0; i--) {
            int lastBit = ((n>>i)&1);
            
            if(lastBit == 1) {
                result += t[0][i+1];
                if(prevBit == 1) {
                    consOne = true;
                    break;
                }
            }
            prevBit = lastBit;
        }
        if(!consOne)
            result++;
        return result;
    }
};
