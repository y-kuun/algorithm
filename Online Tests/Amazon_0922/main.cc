// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
int largestPalindromicSubmatrix(int N, int M, int** B) {
    // WRITE YOUR CODE HERE
    int x, y;
    x = 0;
    y = 0;
    int max = -1;
    for (x = 0; x < N; x++) {
        for (y = 0; y < M; y++) {
            for (int i = 1; x + i <= N && y + i <= M; i++) {
                bool flag = true;
                for (int ii = x; ii < x + i && flag; ii++) {
                    for (int jj = y; jj < y + i && flag; jj++) {
                        if (B[ii][jj] != B[x + i - 1 - ii][y + i - 1 - jj])
                            flag = false;
                    }
                }
                if (flag && max < i) {
                    max = i;
                }
            }
        }
    }
    return max * max;
}
// FUNCTION SIGNATURE ENDS