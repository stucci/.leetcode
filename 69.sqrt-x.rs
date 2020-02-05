/*
 * @lc app=leetcode id=69 lang=rust
 *
 * [69] Sqrt(x)
 */

// @lc code=start
impl Solution {
    pub fn my_sqrt(x: i32) -> i32 {
        let y: f64 = x as f64;
        let z: i32 = y.sqrt() as i32;
        z
    }
}
// @lc code=end

