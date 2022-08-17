/**
 * @param {number[]} nums
 * @return {number}
 */
var findDuplicate = function(nums) {
    let cache = {};
    for ( let i=0;i<nums.length;++i){
        if(nums[i] in cache){
            console.log("hey")
            console.log(nums[i])
            return nums[i];
        }
        else cache[nums[i]]=nums[i];
    }
  return -1;  
};