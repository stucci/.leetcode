/*
 * @lc app=leetcode id=169 lang=rust
 *
 * [169] Majority Element
 */

// @lc code=start
use std::collections::HashMap;
use std::cmp::max;
impl Solution {
    pub fn majority_element(nums: Vec<i32>) -> i32 {
        let mut m: HashMap<i32,i32> = HashMap::new();
        let len = nums.len() as i32;
        for e in nums {
            let cnt = m.entry(e).or_insert(0);
            *cnt += 1;
            if(*cnt>len/2){
                return e
            }
        }
        0
    }
}
// @lc code=end

