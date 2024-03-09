#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int data;
    int swapCounter;
    struct list *next;
} list;

void bubbleSort(list *head, int size);
void selectionSort(list *head, int size);
void initialize(list *head, int dataArray[], int size);
void freeList(list *head);
int getListValue(list *head, int index);
void swap(list **head, int index1, int index2);
void incrementSwapCounter(list* head, int index1);

int main()
{
    int size = 9;
    int array1[] = {97, 16 ,45 ,63 ,13 ,22 ,7 ,58 ,72};
    list *head = (list*)malloc(sizeof(list));
    head->data = array1[0];
    head->next = NULL;
    head->swapCounter = 0;
    initialize(head, array1, size);

    printf("Array 1 Bubble Sort:\n");
    bubbleSort(head, size);

    freeList(head);
    head = (list*)malloc(sizeof(list));
    head->data = array1[0];
    head->next = NULL;
    head->swapCounter = 0;
    initialize(head, array1, size);

    printf("Array 1 Selection Sort:\n");
    selectionSort(head, size);

    freeList(head);
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    head = (list*)malloc(sizeof(list));
    head->data = array2[0];
    head->next = NULL;
    head->swapCounter = 0;
    initialize(head, array2, size);

    printf("Array 2 Bubble Sort:\n");
    bubbleSort(head, size);

    freeList(head);
    head = (list*)malloc(sizeof(list));
    head->data = array2[0];
    head->next = NULL;
    head->swapCounter = 0;
    initialize(head, array2, size);

    printf("Array 2 Selection Sort:\n");
    selectionSort(head, size);
    free(head);


}
void bubbleSort(list *head, int size)
{
    int swapsTotal = 0;
    for (int i = 0; i < size - 1; i ++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (getListValue(head, j + 1) < getListValue(head, j))
            {
                incrementSwapCounter(head, j);
                incrementSwapCounter(head, j + 1);
                swap(&head, j, j + 1);
                swapsTotal++;
            }
        }
    }
    list* current = head;
    for (int i = 0; i < size; i++)
    {
        printf("%d: %d\n", current->data, current->swapCounter);
        current = current->next;
    }
    printf("%d\n\n", swapsTotal);
}
void selectionSort(list *head, int size)
{
    int swapsTotal = 0;
    int minIndex;
    for (int i = 0; i < size - 1; i++)
    {
        minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (getListValue(head, j) < getListValue(head, minIndex))
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            swapsTotal++;
            incrementSwapCounter(head, i);
            incrementSwapCounter(head, minIndex);

            swap(&head, i, minIndex);
        }
    }
    list* current = head;
    for (int i = 0; i < size; i++)
    {
        printf("%d: %d\n", current->data, current->swapCounter);
        current = current->next;
    }
    printf("%d\n\n", swapsTotal);
}
int getListValue(list *head, int index)
{
    list *current = head;
    int valueAtIndex;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }
    valueAtIndex = current->data;
    return valueAtIndex;
}
void incrementSwapCounter(list* head, int index1)
{
    list *current = head;
    for (int i = 0; i < index1; i++)
    {
        current = current->next;
    }
    (current->swapCounter)++;
}
void swap(list **head, int index1, int index2)
{
    if (index1 == index2)
    {
        return;
    }

    list *prev1 = NULL;
    list *curr1 = *head;
    list *prev2 = NULL;
    list *curr2 = *head;

    int count = 0;
    while (curr1 && count != index1) {
        prev1 = curr1;
        curr1 = curr1->next;
        count++;
    }
    count = 0;
    while (curr2 && count != index2) {
        prev2 = curr2;
        curr2 = curr2->next;
        count++;
    }

    if (!curr1 || !curr2 || curr1 == curr2)
    {
        return;
    }

    if (prev1 == NULL) {
        *head = curr2;
    } else {
        prev1->next = curr2;
    }

    if (prev2 == NULL) {
        *head = curr1;
    } else {
        prev2->next = curr1;
    }

    list *temp = curr2->next;
    curr2->next = curr1->next;
    curr1->next = temp;
}
void initialize(list *head, int dataArray[], int size)
{
    list *current = head;
    list *newNode;
    for (int i = 1; i < size; i++)
    {
        newNode = (list *)malloc(sizeof(list));
        current->next = newNode;
        current = current->next;
        current->data = dataArray[i];
        current->swapCounter = 0;
    }
    current->next = NULL;
}
void freeList(list *head)
{
    list *current = head;
    while (head != NULL)
    {
        current = current->next;
        free(head);
        head = current;
    }
}
