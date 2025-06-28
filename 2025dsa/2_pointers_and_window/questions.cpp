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

// 4th 904. Fruit Into Baskets
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0,r=0;
        map<int,int> mp;
        int max_len=INT_MIN;


// brute force
        // for(int i=0;i<fruits.size();i++){
        //     set<int> st;
        //     for(int j=i;j<fruits.size();j++){
        //         st.insert(fruits[j]);
        //         if(st.size()<=2){
        //             max_len=max(max_len,j-i+1);
        //         }else break;
        //     }
        // }
        // return max_len;


// better solution 
        // while(r<fruits.size()){

        //     mp[fruits[r]]++;

        //     if(mp.size()>2){
        //         while(mp.size()>2){
        //             mp[fruits[l]]--;
        //             if(mp[fruits[l]]==0){
        //                 mp.erase(fruits[l]);
        //             }
        //             l++;
        //         }
                
        //     }
        //     if(mp.size()<=2){
        //         max_len=max(max_len,r-l+1);
        //     }
        //     r++;
        // }

        // return max_len;


// optimal solution 
        while(r<fruits.size()){

            mp[fruits[r]]++;

            if(mp.size()>2){

                mp[fruits[l]]--;

                if(mp[fruits[l]]==0){
                    mp.erase(fruits[l]);
                }

                l++;
                
            }
            if(mp.size()<=2){
                max_len=max(max_len,r-l+1);
            }
            r++;
        }

        return max_len;
    }
};


// 6th Longest Substring with K Uniques

// User function template for C++

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // your code here
        
        // its same as fruits inbasket problem
        
        int l=0,r=0;
        int max_len=0;
        map<char,int> mp;
        
        while(r<s.size()){
            // adding element that are on r
            mp[s[r]]++;
            
            // if size is greatere than k then the given is not following the given rule thus 
            if(mp.size()>k){
                // as its dont follows remove the l'th element (reduce count)
                mp[s[l]]--;
                // is the count reduces to 0 that means no requirent of that eement for now 
                if(mp[s[l]]==0){
                    mp.erase(s[l]);
                }
                // iterate l as that element is not needed 
                l++;
            }
            // if the map or the string contains the <= k elements that upate max_length is max
            if(mp.size()<=k){
                max_len=max(max_len,r-l+1);
            }
            // for iteration array ,tring
            r++;
        }
        
        // is the map or basket (string )doesnt  contains < than k elements than return -1
        if(mp.size()<k){
            return -1;
        }
        return max_len;
    }
};

// 7th 1358. Number of Substrings Containing All Three Characters

class Solution {
public:
    int numberOfSubstrings(string s) {
        int last_seen[3]={-1,-1,-1};
        int count=0;

        for(int i=0;i<s.size();i++){
            last_seen[s[i]-'a']=i;

            if(last_seen[0]!=-1&& last_seen[1]!=-1 && last_seen[2]!=-1){
                count=count+(1+min(last_seen[0],min(last_seen[1],last_seen[2])));
            }
        }
        return count;
    }
};

// 8th 424. Longest Repeating Character Replacement

class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int l=0,r=0,max_fre=0,max_len=0;
        int hash[26]={0};
        
        while(r<s.length()){

            hash[s[r]-'A']++;
            max_fre=max(max_fre,hash[s[r]-'A']);

            if((r-l+1)-max_fre >k){
                hash[s[l]-'A']--;
                l++;
            }

            if((r-l+1)-max_fre <= k){
                max_len=max(max_len,r-l+1);
            }
            r++;
        }
        return max_len;
    }
};