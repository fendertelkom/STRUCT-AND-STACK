#include <stdio.h>

int twoStacks(int maxSum, int a[], int n, int b[], int m) {
    int sum_a[n+1];
    int sum_b[m+1];

    sum_a[0] = 0;
    sum_b[0] = 0;

    for (int i = 1; i <= n; i++) {
        sum_a[i] = sum_a[i-1] + a[i-1];
    }

    for (int i = 1; i <= m; i++) {
        sum_b[i] = sum_b[i-1] + b[i-1];
    }

    int ans = 0;
    int j = m;

    for (int i = 0; i <= n; i++) {
        if (sum_a[i] > maxSum) {
            break;
        }
        while (sum_a[i] + sum_b[j] > maxSum) {
            j--;
        }
        if (i + j > ans) {
            ans = i + j;
        }
    }

    return ans;
}

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int n, m, maxSum;
        scanf("%d %d %d", &n, &m, &maxSum);

        int a[n];
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[j]);
        }

        int b[m];
        for (int j = 0; j < m; j++) {
            scanf("%d", &b[j]);
        }

        int result = twoStacks(maxSum, a, n, b, m);
        printf("%d\n", result);
    }

    return 0;
}
