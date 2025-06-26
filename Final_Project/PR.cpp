#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        this->data = val;
        next = NULL;
    }
};

class Linkedlist
{
public:
    Node *HEAD;
    int count;

    Linkedlist()
    {
        HEAD = NULL;
        count = 0;
    }

    void insert_array(int elem);
    void display_array();
    int binary_search(int low, int high, int target);
    void merge_sort(); 
    void merge_sort(int arr[], int low, int high); 
    void merge(int arr[], int low, int mid, int high);
    void quick_sort();
    void quick_sort(int arr[], int low, int high);
    int quick(int arr[], int low, int high);
};

int main()
{
    int size;
    cout << "Enter array size : ";
    cin >> size;

    int choice, target;
    Linkedlist list;

    int elem;

    cout << "Enter " << size << " elements: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> elem;
        list.insert_array(elem);
    }

    do
    {
        cout << endl
             << "Press 1 for Display" << endl;
        cout << "Press 2 for Binary search" << endl;
        cout << "Press 3 for Merge sort" << endl;
        cout << "Press 4 for Quick sort" << endl;
        cout << "Press 0 for exit" << endl;

        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            list.display_array();
            break;
        case 2:
            cout << "Note: Binary Search works on sorted array." << endl;
            cout << "Enter element to search: ";
            cin >> target;
            {
                int founded_index = list.binary_search(0, list.count - 1, target);
                if (founded_index == -1)
                {
                    cout << "Element not founded..." << endl;
                }
                else
                {
                    cout << "Element founded at " << founded_index << " position" << endl;
                }
            }
            break;
        case 3:
            list.merge_sort();
            list.display_array();
            break;
        case 4:
            list.quick_sort();
            list.display_array();
            break;
        case 0:
            break;
        default:
            cout << "Invalid choice..." << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}

void Linkedlist::insert_array(int elem)
{
    Node *newNode = new Node(elem);
    if (HEAD == NULL) {
        HEAD = newNode;
    } else {
        Node *temp = HEAD;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    count++;
}
void Linkedlist::display_array()
{
    cout << "Your array is : ";
    Node *ptr = HEAD;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}
int Linkedlist::binary_search(int low, int high, int target)
{
    if (count == 0)
    {
        cout << "List is empty.\n";
        return -1;
    }

    int *arr = new int[count];
    Node *temp = HEAD;
    for (int i = 0; i < count; i++)
    {
        arr[i] = temp->data;
        temp = temp->next;
    }

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int swap = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = swap;
            }
        }
    }

    int result = -1;
    if (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            result = mid;
        }
        else if (target < arr[mid])
        {
            result = binary_search(low, mid - 1, target);
        }
        else
        {
            result = binary_search(mid + 1, high, target);
        }
    }

    delete[] arr;
    return result;
}
void Linkedlist::merge(int arr[], int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[low + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = low;

    while (i < n1 && j < n2) {
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void Linkedlist::merge_sort(int arr[], int low, int high) {
    if (low >= high)
        return;

    int mid = (low + high) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

void Linkedlist::merge_sort() {
    if (count == 0) return;

    int* arr = new int[count];
    Node* temp = HEAD;

    for (int i = 0; i < count; i++) {
        arr[i] = temp->data;
        temp = temp->next;
    }

    merge_sort(arr, 0, count - 1);

    temp = HEAD;
    for (int i = 0; i < count; i++) {
        temp->data = arr[i];
        temp = temp->next;
    }

    delete[] arr;
}

int Linkedlist::quick(int arr[], int low, int high) {
    int pivot = arr[high], i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot)
            swap(arr[++i], arr[j]);
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void Linkedlist::quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = quick(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

void Linkedlist::quick_sort() {
    if (count == 0) return;

    int* arr = new int[count];
    Node* temp = HEAD;

    for (int i = 0; i < count; i++) {
        arr[i] = temp->data;
        temp = temp->next;
    }

    quick_sort(arr, 0, count - 1);

    temp = HEAD;
    for (int i = 0; i < count; i++) {
        temp->data = arr[i];
        temp = temp->next;
    }

    delete[] arr;
}


