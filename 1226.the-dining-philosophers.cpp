#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1226 lang=cpp
 *
 * [1226] The Dining Philosophers
 */

// @lc code=start
class DiningPhilosophers {
public:
    vector<bool> isvalid;
    mutex mtx;
    condition_variable cv;
    static constexpr int N = 5;
    DiningPhilosophers() {
        isvalid.resize(N, true);
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
                        {
                            unique_lock<mutex> lock(mtx);
                            cv.wait(lock, [this, philosopher](){
                                return isvalid[philosopher] && isvalid[(philosopher+1)%N];
                            });
                            isvalid[philosopher] = false;
                            isvalid[(philosopher+1)%N] = false;
                            pickLeftFork();
                            pickRightFork();
                        }
                        eat();
                        {
                            unique_lock<mutex> lock(mtx);
                            putLeftFork();
                            putRightFork();
                            isvalid[philosopher] = true;
                            isvalid[(philosopher+1)%N] = true;
                            cv.notify_all();
                        }
    }
};
// @lc code=end

