class Solution {
public:
    bool isPrime(int x) {
        if (x < 2) return false;

        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0)
                return false;
        }

        return true;
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, vector<int>> divisible;

        // store indices divisible by prime p
        for (int i = 0; i < n; i++) {

            int x = nums[i];

            for (int p = 2; p * p <= x; p++) {

                if (x % p == 0) {

                    if (isPrime(p))
                        divisible[p].push_back(i);

                    while (x % p == 0)
                        x /= p;
                }
            }

            if (x > 1)
                divisible[x].push_back(i);
        }

        queue<pair<int,int>> q;
        vector<int> vis(n, 0);

        q.push({0, 0});
        vis[0] = 1;

        unordered_set<int> usedPrime;

        while (!q.empty()) {

            auto [idx, steps] = q.front();
            q.pop();

            if (idx == n - 1)
                return steps;

            // adjacent left
            if (idx - 1 >= 0 && !vis[idx - 1]) {
                vis[idx - 1] = 1;
                q.push({idx - 1, steps + 1});
            }

            // adjacent right
            if (idx + 1 < n && !vis[idx + 1]) {
                vis[idx + 1] = 1;
                q.push({idx + 1, steps + 1});
            }

            int val = nums[idx];

            // teleport if prime
            if (isPrime(val) && !usedPrime.count(val)) {

                usedPrime.insert(val);

                for (int next : divisible[val]) {

                    if (!vis[next]) {
                        vis[next] = 1;
                        q.push({next, steps + 1});
                    }
                }
            }
        }

        return -1;
    }
};