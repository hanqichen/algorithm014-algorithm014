学习笔记

#### 不同路径 II 转移方程

- if matrix[i][j] == 0  then dp[i][j] = 0

- if matrix[i][j] != 0  then dp[i][j] = dp[i - 1][j] + dp[i][j - 1]

#### 课程中部分困难题尚未做，之后补充思维导图总结