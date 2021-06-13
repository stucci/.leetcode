#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=721 lang=cpp
 *
 * [721] Accounts Merge
 */

// @lc code=start
class UnionFind {
public:
    vector<int> parent;
    // initialize
    UnionFind(int n) : parent(n) {
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
    }
    // return the parent of x
    int find(int x){
        if(parent[x]!=x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    // unite x and y
    void unite(int x, int y){
        x = find(x), y = find(y);
        if(x!=y) parent[x] = y;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        UnionFind uf(10001);
        map<string, string> email_name;
        map<string, int> email_id;

        // 一番最初のemailを親として、UnionFindでグループを形成
        int id = 0;
        for(auto acc : accounts){
            string name = acc[0];
            for(int i=1; i<acc.size(); i++){
                string email = acc[i];
                email_name[email] = name;
                if(!email_id.count(email)){
                    email_id[email] = id;
                    id++;
                }
                uf.unite(email_id[acc[1]], email_id[email]);
            }
        }

        // UnionFindにより、あるemailの親はfind()で再帰的に求まるので、
        // 以下のコードにより、全てのemailがある親emailのもとに集まる。
        map<int, vector<string>> ans;
        for(auto p : email_name){
            int id = email_id[p.first];
            ans[uf.find(id)].emplace_back(p.first);
        }

        // 指定された戻り値に変形する。
        vector<vector<string>> ret;
        for(auto p : ans){
            vector<string> tmp(p.second.begin(), p.second.end());
            sort(tmp.begin(), tmp.end());
            tmp.insert(tmp.begin(), email_name[p.second[0]]);
            ret.emplace_back(tmp);
        }
        return ret;
    }
};
// @lc code=end

