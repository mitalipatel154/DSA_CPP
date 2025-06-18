#include <iostream>
using namespace std;

class Categorizing
{
    public:
        int size;
        int *arr;

        Categorizing(int size)
        {
            this->size = size;
            this->arr = new int[this->size];

            cout << "Enter array element : " << endl;
            for (int i = 0; i < this->size; i++)
            {
                cout << "arr[" << i << "] : ";
                cin >> this->arr[i];
            }
        }

        ~Categorizing()
        {
            delete[] arr;
        }

        void display_array();
        void selection_sort();
        void merge_sort(int low, int high);
        void merge(int low, int mid, int high);
        int binary_search(int low, int high, int target);
};

int main()
{ 
    int size;
    cout << "Enter array size : ";
    cin >> size;

    int choice, target;
    Categorizing c(size);

    do
    {
        cout << endl << "Press 1 for display" << endl;
        cout << "Press 2 for selection sort" << endl;
        cout << "Press 3 for merge sort" << endl;
        cout << "Press 4 for binary search" << endl;
        cout << "Press 0 for exit" << endl;

        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            c.display_array();
            break;
        case 2:
            c.selection_sort();
            cout << "after Selection Sort: ";
            c.display_array();
            break;
        case 3:
            c.merge_sort(0, c.size - 1);
            cout << "after Merge Sort: ";
            c.display_array();
            break;
        case 4:
            cout << "Note: Binary Search works on sorted array." << endl;
            cout << "Enter element to search: ";
            cin >> target;
            {
                int founded_index = c.binary_search(0, c.size - 1, target);
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
        case 0:
            break;
        default:
            cout << "Invalid choice..." << endl;
            break;
        }
    } while (choice != 0);
    

    return 0;
}


void Categorizing::display_array()
{
    cout << "Your Array is : ";
    for(int i = 0; i < this-> size; i++)
    {
        cout << this->arr[i] << " ";
    }
    cout << endl;
}
void Categorizing::selection_sort()
{
    for (int i = 0; i < this-> size-1; i++)
    {
        int min = i;
        for (int j = i+1; j < this-> size; j++)
        {
            if (this->arr[j] < this->arr[min])
            {
                min = j;
            }
            
        }
        int temp = this->arr[min];
        this->arr[min] = this->arr[i];
        this->arr[i] = temp;
    }
    
}
void Categorizing::merge(int low, int mid, int high) {
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
void Categorizing::merge_sort(int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        merge_sort(low, mid);
        merge_sort(mid + 1, high);
        merge(low, mid, high);
    }
}
int Categorizing::binary_search(int low, int high, int target)
{
    if (low > high)
    {
        return -1;
    }
   
    int mid = (low + high) / 2;
    if (target == this-> arr[mid])
    {
        return mid;
    }
    else if (target < this-> arr[mid])
    {
        return binary_search(low, mid-1, target);
    }
    else
    {
        return binary_search(mid+1, high, target);
    }
}

