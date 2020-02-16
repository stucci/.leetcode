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
        let mut max_key: i32 = 0;
        let mut max_val: i32 = 0;
        for e in nums {
            let cnt = m.entry(e).or_insert(0);
            *cnt += 1;
            if(max_val<*cnt){
                max_val=*cnt;
                max_key=e;
            }
        }
        max_key
    }
}
// @lc code=end

