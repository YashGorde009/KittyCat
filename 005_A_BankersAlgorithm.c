#include <stdio.h>

int main() {
    // P0, P1, P2, P3, P4 are the Process names here
  
    int n, m, i, j, k;
    n = 5; // Number of processes
    m = 3; // Number of resources

    int alloc[5][3] = { { 0, 1, 0 }, // P0    // Allocation Matrix
                        { 2, 0, 0 }, // P1
                        { 3, 0, 2 }, // P2
                        { 2, 1, 1 }, // P3
                        { 0, 0, 2 } }; // P4
  
    int max[5][3] = { { 7, 5, 3 }, // P0    // MAX Matrix
                      { 3, 2, 2 }, // P1
                      { 9, 0, 2 }, // P2
                      { 2, 2, 2 }, // P3
                      { 4, 3, 3 } }; // P4
  
    int avail[3] = { 3, 3, 2 }; // Available Resources
  
    int f[n], ans[n], ind = 0;

    for (k = 0; k < n; k++) {
        f[k] = 0; // This array keeps track of processes that have completed. Initially, all entries are set to 0 (indicating incomplete processes).
    }

    int need[n][m];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j]; //the additional resources each process might need to complete
    }

    int y = 0;
    for (k = 0; k < 5; k++) {
        for (i = 0; i < n; i++) {
            if (f[i] == 0) {
                int flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0) {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                        avail[y] += alloc[i][y];
                    f[i] = 1;
                }
            }
        }
    }
  
    printf("Following is the SAFE Sequence\n");
    for (i = 0; i < n - 1; i++)
        printf(" P%d ->", ans[i]);
    printf(" P%d", ans[n - 1]);
  
    return 0;
}

The algorithm uses a safety check loop to determine a safe sequence where resources can be allocated to each process without leading to deadlock.
Flag Array (f): This array keeps track of processes that have completed. Initially, all entries are set to 0 (indicating incomplete processes).
The outer loop runs through each process to determine whether it can finish with the current available resources. If it can, it’s marked as safe, and its allocated resources are added back to avail.

Once the algorithm finds a safe sequence, it stores this sequence in the ans array and prints the order of processes that can safely run to completion.