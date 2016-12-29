#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {

    int Nnodes; // Number of nodes

    do {
        printf("Please choose between 4,10,15 & 20 for the numbers of nodes: ");
        scanf("%d", &Nnodes);
    } while (Nnodes > 20 && Nnodes < 2);

    int x [Nnodes]; // value x for each node
    int y [Nnodes]; // value y for each node
    char nodes [Nnodes]; // name of node

    // Random values [1,10] for x & y attributes
    int i;
    srand(time(NULL));
    printf("--Nodes--\n");
    for(i=0; i<Nnodes; i++) {
        nodes[i] = i;
        x[i] = rand()%10+1;
        y[i] = rand()%10+1;
        printf("%i: %i,%i\n", nodes[i], x[i], y[i]);
    }

    int tmpcost;
    int cheapest_cost = 0;
    char tmp[Nnodes];
    char cheap_path[Nnodes];

    // Find all possible permutations
    // and calculate their cost
    printf("\n--Routes--\n");
    sort(nodes, nodes+Nnodes);
    do {
        tmpcost = 0;
        for (i = 0; i < Nnodes; i++) {
            tmp[i] = nodes[i];
            printf("%d ", nodes[i]);
            if (i != 0) {
                tmpcost += sqrt((pow(x[nodes[i]] - x[nodes[i-1]], 2)) + (pow(y[nodes[i]] - y[nodes[i-1]] ,2)));
            }
        }
        if (cheapest_cost == 0 || tmpcost < cheapest_cost) {
            cheapest_cost = tmpcost;
            for (i = 0; i < Nnodes; i++) {
                cheap_path[i] = tmp[i];
            }
        }
        printf("--> cost = %d", tmpcost);
        printf("\n");
    } while (next_permutation(nodes, nodes + Nnodes));

    // Results
    printf("\nThe shortest path is: ");
    for (i = 0; i < Nnodes; i++) {
        printf("%i ", cheap_path[i]);
    }
    printf("and its cost is: %d\n", cheapest_cost);

    return 0;
}
