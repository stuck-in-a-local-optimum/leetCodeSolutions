
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        //if only one already element then no NGP possible
        if(n==1){
            return;
        }
        
        //finding the index of last peak element
        int lastPeakIdx=-1;
        for(int i=1; i<n; i++){
            if(nums[i]>nums[i-1]){
                lastPeakIdx = i;
            }
            
        }
        
        
        //special case, if array is sorted in dsc order then then NGP not possible so arrange it in asc order
        if(lastPeakIdx==-1){
             for(int i=0; i<n/2; i++){  //sorting by using swapping
                swap(nums[i], nums[n-i-1]);
    }
            return;
        }
        
        
        //in other cases, swap then swapIndex element with lastPeakIdx-1 element and sort the rest
        //array in sorted asc but first check for a spcecial case that
        //if any element is b/w nums[lastPeakElement-1] and nums[lastPeakIdx] in rest of the array then element to be swapIndex will be that element

        int swapIndex = lastPeakIdx;
        
        for(int i= lastPeakIdx+1; i<n; i++){
            if(nums[i] > nums[lastPeakIdx-1] && nums[i]<nums[lastPeakIdx]){
                swapIndex = i;
            }
        }
        
        swap( nums[lastPeakIdx-1], nums[swapIndex]);
        sort(nums.begin() + lastPeakIdx, nums.end());
        
        
    }
};