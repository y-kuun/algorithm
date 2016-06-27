# Node 2016-06-27

It is very clear to utilize DFS or BFS to solve such problems.

However, I allocate extra memory for the visited matrix which is no need in this situation.

We can just set the corresponding grid value as below: 

```c++
grid[i][j] = 0;
```
