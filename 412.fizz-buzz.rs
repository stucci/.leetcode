/*
 * @lc app=leetcode id=412 lang=rust
 *
 * [412] Fizz Buzz
 */

// @lc code=start
impl Solution {
    pub fn fizz_buzz(n: i32) -> Vec<String> {
        let mut v: Vec<String> = Vec::new();
        for i in 1..n+1 {
            // let s: String = i as String;
            if(i%3==0&&i%5==0) {
                v.push("FizzBuzz".to_string());
            } else if(i%3==0) {
                v.push("Fizz".to_string());
            } else if(i%5==0) {
                v.push("Buzz".to_string());
            } else {
                v.push(i.to_string());
            }
        }
        v
    }
}
// @lc code=end

