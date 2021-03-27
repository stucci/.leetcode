#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1195 lang=cpp
 *
 * [1195] Fizz Buzz Multithreaded
 */

// @lc code=start
class FizzBuzz {
private:
    int n;
    int count;
    mutex m;
    condition_variable cv;

public:
    FizzBuzz(int n) {
        this->n = n;
        this->count = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while(true){
            unique_lock<mutex> lock(m);
            cv.wait(lock, [&](){return (count>n || (count%3==0 && count%5!=0));});
            if(count>n) return;
            printFizz();
            ++count;
            //lock.unlock();
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while(true){
            unique_lock<mutex> lock(m);
            cv.wait(lock, [&](){return (count>n || (count%3!=0 && count%5==0));});
            if(count>n) return;
            printBuzz();
            ++count;
            //lock.unlock();
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while(true){
            unique_lock<mutex> lock(m);
            cv.wait(lock, [&](){return (count>n || (count%3==0 && count%5==0));});
            if(count>n) return;
            printFizzBuzz();
            ++count;
            //lock.unlock();
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while(true){
            unique_lock<mutex> lock(m);
            cv.wait(lock, [&](){return (count>n || (count%3!=0 && count%5!=0));});
            if(count>n) return;
            printNumber(count);
            ++count;
            //lock.unlock();
            cv.notify_all();
        }
    }
};
// @lc code=end

