#include <iostream>
#include <vector>

using namespace std;

struct Node {
  int weight;
  int value;
  bool taken;
};

int knapsack(vector<Node> items, int cap) {
  int n = items.size();
  vector<vector<int>> dp(n + 1, vector<int>(cap + 1, -1));

  function<int(int, int)> dfs = [&](int i, int j) {
    if (i == n) {
      return 0;
    }

    if (dp[i][j] != -1) {
      return dp[i][j];
    }

    int take = 0;
    if (j >= items[i].weight) {
      take = items[i].value + dfs(i + 1, j - items[i].weight);
    }

    int leave = dfs(i + 1, j);

    return dp[i][j] = max(take, leave);
  };

  return dfs(0, cap);
}

int main() {
  int n;
  cin >> n;

  vector<Node> items(n);
  for (int i = 0; i < n; ++i) {
    cin >> items[i].weight >> items[i].value;
    items[i].taken = false;
  }

  int cap;
  cin >> cap;

  int max_value = knapsack(items, cap);

  cout << "Maximum value = " << max_value << endl;

  return 0;
}