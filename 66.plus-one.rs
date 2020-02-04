/*
 * @lc app=leetcode id=66 lang=rust
 *
 * [66] Plus One
 */

// @lc code=start
impl Solution {
    pub fn plus_one(digits: Vec<i32>) -> Vec<i32> {
        let len: usize = digits.len();
        let mut v: Vec<i32> = Vec::new();
        let mut carry: i32 = 1;
        if len==0 {
            return vec![1];
        }
        for i in 0..len {
            let ri: usize = len-1-i;
            v.push((digits[ri]+carry)%10);
            carry = (digits[ri]+carry)/10;
            if ri==0 && carry==1 {
                v.push(1)
            }
        }
        v.reverse();
        return v;
    }
}
// @lc code=end

