#include<iostream>
int i, j, k, a, b, u, v, n, ne = 1;
int min, mincost = 0, cost[9][9], parent[9];
int find(int i)
{
  while (parent[i])
    i = parent[i];
  return i;
}

int uni(int i, int j)
{
  if (i != j)
  {
    parent[j] = i;
    return 1;
  }
  return 0;
}

int main()
{
  // Get the number of vertices in the graph.
  int n;
  std::cin >> n;

  // Create a cost adjacency matrix to represent the graph.
  int cost[n][n];
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      std::cin >> cost[i][j];
      if (cost[i][j] == 0)
        cost[i][j] = 999;
    }
  }

  // Create a forest to represent the minimum spanning tree.
  int parent[n];
  for (int i = 0; i < n; i++)
    parent[i] = i;

  // Find the minimum spanning tree.
  int mincost = 0;
  int ne = 1;
  while (ne < n)
  {
    // Find the edge with the minimum weight.
    int min = 999;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (cost[i][j] < min)
        {
          min = cost[i][j];
          a = u = i;
          b = v = j;
        }
      }
    }

    // Check if the edge does not create a cycle.
    u = find(u);
    v = find(v);
    if (u != v)
    {
      // Add the edge to the forest.
      parent[v] = u;
      mincost += min;
      std::cout << ne++ << " edge = (" << a + 1 << ", " << b + 1 << ", " << min << ")\n";
    }

    // Set the weight of the edge to infinity to prevent it from being chosen again.
    cost[a][b] = cost[b][a] = 999;
  }

  // Print the minimum cost.
  std::cout << "Minimum cost = " << mincost << "\n";
}
