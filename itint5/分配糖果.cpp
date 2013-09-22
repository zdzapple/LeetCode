//返回最少需要的糖果数
long long minimalCandies(vector<int> &ratings) 
{
	int n = ratings.size();
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	vector<int> candies(n, 1);
	for (int i = 1; i <= n - 1; ++ i)
	{
		if (ratings[i] > ratings[i-1]) {
			candies[i] = candies[i-1] + 1;
		}
	}
	for (int i = n - 2; i >= 0; -- i)
	{
		if (ratings[i] > ratings[i+1]) {
			candies[i] = max(candies[i], candies[i+1] + 1);
		}
	}
	long long result = 0;
	for (int i = 0; i < n; ++ i)
		result += candies[i];
	return result;
}

/**
This can be solved by topological sort. Build a graph by scanning the rating array from left to right: 
g[i][j] = true => c[i] must be less to c[j]. 

Then we can assign the candies according to the topological order.

#include <iostream>
#include <stack>
using namespace std;

const int MAXN = 100000;
int g[MAXN][3];
int indeg[MAXN];
int val[MAXN];
int c[MAXN];
int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> val[i];
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    for (int i = 0; i < n - 1; i++) {
        if (val[i] < val[i + 1]) {
            g[i][++g[i][0]] = i + 1;
            indeg[i + 1]++;
        } else if(val[i] > val[i + 1]) {
            g[i + 1][++g[i + 1][0]] = i;
            indeg[i]++;
        }
    }
    stack<int> sta;
    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0) {
            c[i] = 1;
            sta.push(i);
        }
    }
    
    while (!sta.empty()) {
        int r = sta.top();
        sta.pop();
        for (int j = 1; j <= g[r][0]; j++) {
            c[g[r][j]] = max(c[g[r][j]], c[r] + 1);
            indeg[g[r][j]]--;
            if (indeg[g[r][j]] == 0) sta.push(g[r][j]);
        }
    }
    
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += c[i];
    }
    
    cout << ans << endl;
    return 0;
}
**/