#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, m;

    if (scanf("%d %d", &n, &m) != 2) {
        return 0;
    }

    int *head = (int *)malloc(((size_t)n + 1) * sizeof(int));
    int *to = (int *)malloc((size_t)m * sizeof(int));
    int *next = (int *)malloc((size_t)m * sizeof(int));
    int *indegree = (int *)calloc((size_t)n + 1, sizeof(int));
    int *queue = (int *)malloc(((size_t)n + 1) * sizeof(int));
    int *answer = (int *)malloc(((size_t)n + 1) * sizeof(int));

    if (head == NULL || to == NULL || next == NULL ||
        indegree == NULL || queue == NULL || answer == NULL) {
        free(head);
        free(to);
        free(next);
        free(indegree);
        free(queue);
        free(answer);
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        head[i] = -1;
    }

    /* 建立有向图，并统计入度 */
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        to[i] = b;
        next[i] = head[a];
        head[a] = i;

        indegree[b]++;
    }

    int queue_head = 0;
    int queue_tail = 0;

    /* 将所有入度为 0 的节点入队 */
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            queue[queue_tail++] = i;
        }
    }

    int answer_count = 0;

    while (queue_head < queue_tail) {
        int current = queue[queue_head++];
        answer[answer_count++] = current;

        /* 删除 current 的所有出边 */
        for (int edge = head[current];
             edge != -1;
             edge = next[edge]) {
            int next_node = to[edge];

            indegree[next_node]--;

            if (indegree[next_node] == 0) {
                queue[queue_tail++] = next_node;
            }
        }
    }

    /* 未能输出全部节点，说明图中有环 */
    if (answer_count < n) {
        printf("-1\n");
    } else {
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                printf(" ");
            }

            printf("%d", answer[i]);
        }

        printf("\n");
    }

    free(head);
    free(to);
    free(next);
    free(indegree);
    free(queue);
    free(answer);

    return 0;
}