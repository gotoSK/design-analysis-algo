#include <stdio.h>
#include <limits.h>

#define V 4

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to reverse an array
void reverse(int arr[], int start, int end) {
    while (start < end) {
        swap(&arr[start], &arr[end]);
        start++;
        end--;
    }
}

// Function to find the next lexicographically greater permutation
int next_permutation(int arr[], int size) {
    int i = size - 2;

    // Find the first element that is not in increasing order from right
    while (i >= 0 && arr[i] >= arr[i + 1])
        i--;

    // If no such element is found, the array is already the last permutation
    if (i < 0)
        return 0;

    int j = size - 1;

    // Find the smallest element to the right of arr[i] and greater than arr[i]
    while (arr[j] <= arr[i])
        j--;

    // Swap arr[i] and arr[j]
    swap(&arr[i], &arr[j]);

    // Reverse the sub-array to the right of arr[i]
    reverse(arr, i + 1, size - 1);

    return 1;
}

// Function to find the minimum of two integers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to compute the cost of the given path
int computePathCost(int graph[V][V], int path[], int s) {
    int cost = 0;
    for (int i = 0; i < V - 1; i++) {
        cost += graph[path[i]][path[i + 1]];
    }
    cost += graph[path[V - 1]][s];
    return cost;
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to find the minimum path using brute-force approach
int travellingSalesmanProblem(int graph[V][V], int s) {
    int vertex[V - 1];
    for (int i = 0, j = 0; i < V; i++) {
        if (i != s) {
            vertex[j] = i;
            j++;
        }
    }

    int minPath = INT_MAX;
    int path[V];
    path[0] = s;

    do {
        for (int i = 0; i < V - 1; i++) {
            path[i + 1] = vertex[i];
        }

        int currentPathCost = computePathCost(graph, path, s);

        minPath = min(minPath, currentPathCost);
    } while (next_permutation(vertex, V - 1));

    return minPath;
}

// Driver program to test the function
int main() {
    // Matrix representation of the graph
    int graph[V][V] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int s = 0;
    printf("%d\n", travellingSalesmanProblem(graph, s));

    return 0;
}
