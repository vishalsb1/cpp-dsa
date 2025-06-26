// 1st maximumpoints abtained from an card

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int max_sum=INT_MIN;
        int left_sum=0;
        int right_sum=0;

        for(int i=0;i<k;i++){
            left_sum+=cardPoints[i];
        }
        max_sum=left_sum;

        int right_index=cardPoints.size()-1;
        for(int i=k-1;i>=0;i--){
            left_sum-=cardPoints[i];
            right_sum+=cardPoints[right_index];

            max_sum=max(max_sum,(left_sum+right_sum));
            right_index--;
        }
        return max_sum;
    }
};

// 2nd 3. Longest Substring Without Repeating Characters
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        int hash[256];
        fill(hash, hash + 256, -1);


        int max_length=0;

        while(r<s.size()){
            
            if(hash[s[r]]!=-1 && hash[s[r]]>=l){
                    // apla left pointer jo element presemt hait tyachya +1 la ala pahijel
                    l=hash[s[r]]+1;
            }
            int leng=r-l+1;
            max_length=max(max_length,leng);

            // jar present nasla tr 
            hash[s[r]]=r;
            r++;

        }
        return max_length;
    }
};

//3rd -> 1004. Max Consecutive Ones III
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0;
        int zeros=0;
        int max_len=INT_MIN;

        // better approch
        // while(r<nums.size()){

        //     if(nums[r]==0) zeros++;

        //     while(zeros>k){
        //         if(nums[l]==0) zeros--;
        //         l++;
        //     }
        //     int cur_len=r-l+1;
        //     max_len=max(max_len,cur_len);
        //     r++;
        // }

        // optimal approch

        while(r<nums.size()){

            if(nums[r]==0) zeros++;

            if(zeros>k){
                if(nums[l]==0)zeros--;
                l++;
            }
            if(zeros<=k){
                int len=r-l+1;
                max_len=max(max_len,len);
            }
            r++;
        }
        return max_len;
    }
};

// 