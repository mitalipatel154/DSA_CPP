#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int rollNumber;
    float attendance;
};

class AttendanceTracker {
private:
    Student* students;
    int size;

public:
    AttendanceTracker(int n) {
        size = n;
        students = new Student[size];
    }

    ~AttendanceTracker() {
        delete[] students;
    }

    void input() {
        for (int i = 0; i < size; i++) {
            cout << endl << "Enter details for student " << i + 1 << ":" << endl;
            cout << "Name: ";
            cin.ignore();
            getline(cin, students[i].name);
            cout << "Roll Number: ";
            cin >> students[i].rollNumber;
            cout << "Attendance (%): ";
            cin >> students[i].attendance;
        }
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << "Roll No: " << students[i].rollNumber
                 << ", Name: " << students[i].name
                 << ", Attendance: " << students[i].attendance << "%" << endl;
        }
    }

    void merge(Student arr[], int low, int mid, int high) {
        int n1 = mid - low + 1;
        int n2 = high - mid;

        Student* L = new Student[n1];
        Student* R = new Student[n2];

        for (int i = 0; i < n1; i++) L[i] = arr[low + i];
        for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

        int i = 0, j = 0, k = low;

        while (i < n1 && j < n2) {
            if (L[i].rollNumber <= R[j].rollNumber)
                arr[k++] = L[i++];
            else
                arr[k++] = R[j++];
        }

        while (i < n1) arr[k++] = L[i++];
        while (j < n2) arr[k++] = R[j++];

        delete[] L;
        delete[] R;
    }

    void mergeSort(Student arr[], int low, int high) {
        if (low < high) {
            int mid = (low + high) / 2;
            mergeSort(arr, low, mid);
            mergeSort(arr, mid + 1, high);
            merge(arr, low, mid, high);
        }
    }

    void sortByRollNumber() {
        mergeSort(students, 0, size - 1);
        cout << "Students sorted by roll number." << endl;
    }

    int binarySearch(int key) {
        int low = 0, high = size - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (students[mid].rollNumber == key)
                return mid;
            else if (key < students[mid].rollNumber)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1;
    }

    void searchStudent() {
        int key;
        cout << "Enter roll number to search: ";
        cin >> key;

        int index = binarySearch(key);
        if (index != -1) {
            cout << endl << "Student Found: " << endl;
            cout << "Roll No: " << students[index].rollNumber
                 << ", Name: " << students[index].name
                 << ", Attendance: " << students[index].attendance << "%" << endl;
        } else {
            cout << "Student not found." << endl;
        }
    }
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    AttendanceTracker tracker(n);
    tracker.input();

    int choice;
    do {
        cout << endl << "press 1 for Display All Students" << endl;
        cout << "press 2 for Sort by Roll Number" << endl;
        cout << "press 3 for Search by Roll Number" << endl;
        cout << "press 0 for Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            tracker.display();
            break;
        case 2:
            tracker.sortByRollNumber();
            tracker.display();
            break;
        case 3:
            tracker.sortByRollNumber();
            tracker.searchStudent();
            break;
        case 0:
            break;
        default:
            cout << "Invalid choice..." << endl;
        }
    } while (choice != 0);

    return 0;
}
