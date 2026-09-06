#include <stdio.h>

void insertionSort(int a[], int n)
{
    int i, j, key;

    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}

void bucketSort(int a[], int n)
{
    int bucket[10][100];
    int count[10] = {0};
    int i, j, k = 0, index;

    for (i = 0; i < n; i++)
    {
        index = a[i] / 10;
        bucket[index][count[index]++] = a[i];
    }

    for (i = 0; i < 10; i++)
        insertionSort(bucket[i], count[i]);

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < count[i]; j++)
            a[k++] = bucket[i][j];
    }
}

int main()
{
    int a[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements (0-99): ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    bucketSort(a, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}

