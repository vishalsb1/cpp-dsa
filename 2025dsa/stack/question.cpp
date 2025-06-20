//  next greatest element 

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<pair<int,int>> v;
        stack<int> st;
        pair<int,int> p;
        for(int i=nums2.size()-1;i>=0;i--){

            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            if(st.empty()){
                p.first=nums2[i];
                p.second=-1;
                v.push_back(p);
            }
            else if(nums2[i]<st.top()){
                pair<int,int> p;
                p.first=nums2[i];
                p.second=st.top();
                v.push_back(p);
            }
            st.push(nums2[i]);
        }
        reverse(v.begin(), v.end());

        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < v.size(); j++) {
                if (v[j].first == nums1[i]) {
                    ans.push_back(v[j].second);
                    break;
                }
            }
        }

        return ans;
    }
};

// next greatest elemnt II

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> c_st;  // to store circular iterator bigger num
        stack<int> st;  //simple stack that store element that come from behind
        vector<int> ans;
        for(int i=nums.size()-1;i>=0;i--){
            // previous logic

            while(!st.empty() && st.top()<=nums[i]){
                st.pop();
            }
            if(!st.empty() && st.top()>nums[i]){
                ans.push_back(st.top());
            }
            else if(!c_st.empty() && c_st.top() > nums[i]){
                ans.push_back(c_st.top());
            }
            else if(st.empty() && c_st.empty()|| c_st.top()<=nums[i]){
                for(int j=0;j<i;j++){
                    if(nums[j]>nums[i]){
                        c_st.push(nums[j]);
                        break;
                    }
                }
                if(!c_st.empty() && c_st.top()>nums[i]){
                    ans.push_back(c_st.top());}
                else{
                    ans.push_back(-1);
                }
            }
            else if (!c_st.empty() && c_st.top() < nums[i] || st.empty() ) {
                ans.push_back(-1);
            }
            st.push(nums[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// trapping water question (yz question)

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n - 1;
        int res = 0;
        int maxLeft = 0, maxRight = 0;

        while (left <= right) {
            if (height[left] <= height[right]) {
                if (height[left] >= maxLeft) {
                    maxLeft = height[left];
                } 
                else {
                    res += maxLeft - height[left];
                }
            left++;
            } 
            else {
                if (height[right] >= maxRight) {
                    maxRight = height[right];
                } 
                else {
                    res += maxRight - height[right];
                }
            right--;
            }
        }
        return res;
    }
};

// Sum of subarray minimum (yz question)
class Solution {
public:
    vector<int>find_nse(vector<int>&arr){
        int n=arr.size();
        stack<int>st;
        vector<int>nse(n,0);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()) nse[i]=n;
            else nse[i]=st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int>find_pse(vector<int>&arr){
        int n=arr.size();
        stack<int>st;
        vector<int>nse(n,0);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty()) nse[i]=-1;
            else nse[i]=st.top();
            st.push(i);
        }
        return nse;
    }

    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse=find_nse(arr);
        vector<int> pse=find_pse(arr);

        int sum=0;
        int mod=1e9+7;

        for(int i=0;i<arr.size();i++){
            int left=i-nse[i];
            int right=pse[i]-i;

            sum=(sum+(right*left*1LL*arr[i])%mod)%mod;
        }

        return sum;
    }
};

// Asteroid Collision
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        
        for(int i = 0; i < asteroids.size(); i++) {
            bool destroyed = false;
            
            if(asteroids[i] > 0) {
                // Positive asteroid - moving right, just add to stack
                st.push(asteroids[i]);
            } else {
                // Negative asteroid - moving left, check for collisions
                while(!st.empty() && st.top() > 0 && !destroyed) {
                    if(abs(asteroids[i]) > st.top()) {
                        // Current asteroid destroys the one in stack
                        st.pop();
                    } else if(abs(asteroids[i]) == st.top()) {
                        // Both asteroids destroy each other
                        st.pop();
                        destroyed = true;
                    } else {
                        // Current asteroid gets destroyed
                        destroyed = true;
                    }
                }
                
                // If current asteroid survived, add it to stack
                if(!destroyed) {
                    st.push(asteroids[i]);
                }
            }
        }
        
        // Convert stack to result vector
        vector<int> result;
        while(!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        
        // Reverse to get correct order
        reverse(result.begin(), result.end());
        return result;
    }
};
// Sum of subarray ranges
// Remove k Digits
// Largest rectangle in a histogram
// Maximal Rectangles