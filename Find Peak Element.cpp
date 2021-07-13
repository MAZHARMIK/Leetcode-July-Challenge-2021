//Approach-1 (Simple binary search)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        
        int l = 0, r = n-1;
        while(l < r) {
            int mid = l + (r-l)/2;
            
            if(nums[mid] < nums[mid+1])
                l = mid+1;
            else
                r = mid;
        }
        return l;
    }
};

//Approach-2 (More intuitive)
class Solution {
public:
    int findPeakElement(vector<int> &A) {
        int n = A.size();
        if(n == 1)
            return 0;
        
        if(A[0] > A[1]) return 0;
        if(A[n-1] > A[n-2]) return n-1;

        int l = 1, r = n-2; //since, we already checked for 0 and (n-1) indices above
        int mid;
        
        /*
            case-1:
              mid(peak)
                /\
            .../  \...
            
            
            case-2:
              (peak)
                /\
            .../  \mid...
            
            
            case-3:
                 (peak)
                   /\
            ...mid/  \...
        */
        
        while(l < r) {
            mid = l + (r-l)/2;
            
            if(A[mid] > A[mid-1] && A[mid] > A[mid+1]) //1. mid is PEAK
                return mid;
            
            if(A[mid] < A[mid-1])      //2. mid is right to PEAK. So, go towards left
                r = mid-1;
            else if(A[mid] < A[mid+1]) //3. mid is left to PEAK. So, go towards right
                l = mid+1;
        }
        return l;
    }
};
