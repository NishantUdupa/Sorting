#pragma once

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std; 

class Sorting {
public:


    int menu() {
    
        int choice = 0;

        cout << "-----------Sorting Options-----------" << endl;

        cout << "1. Bucket Sort" << endl;
        cout << "2. Heap Sort" << endl;
        cout << "3. Insertion Sort" << endl;
        cout << "4. Merge Sort" << endl;
        cout << "5. Quick Sort" << endl;
        cout << "6. Radix Sort" << endl;
        cout << "7. Shell Sort" << endl << endl;


        cout << "Input your choice: ";
        cin >> choice;

        return choice;
    
    
    }

    //-------------------
    void bucketSort(int arr[], int n) {

        vector<int> b[n];

        for (int i = 0; i < n; i++) {
            int bi = n * arr[i];
            b[bi].push_back(arr[i]);
        }

        for (int i = 0; i < n; i++)
            sort(b[i].begin(), b[i].end());

        int index = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < b[i].size(); j++)
            {
                arr[index++] = b[i][j];

            }
    
    }

    //------------
    void heapify(int arr[], int N, int i) {
    

        int largest = i;

        int l = 2 * i + 1;

        int r = 2 * i + 2;

        if (l < N && arr[l] > arr[largest])
            largest = l;

        if (r < N && arr[r] > arr[largest])
            largest = r;

        if (largest != i) {
            swap(arr[i], arr[largest]);

            heapify(arr, N, largest);
        }
    
    }
    void heapSort(int arr[], int N) {
        for (int i = N / 2 - 1; i >= 0; i--)
            heapify(arr, N, i);

        for (int i = N - 1; i > 0; i--) {

            swap(arr[0], arr[i]);

            heapify(arr, i, 0);
        }
    
    }

    //--------------------
    void InsertionSort(int arr[], int size) {
        for (int i = 0; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (arr[i] > arr[j])
                {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    
    }
    
    //---------------
    void merge(int array[], int const left, int const mid, int const right) {
    
        auto const subArrayOne = mid - left + 1;
        auto const subArrayTwo = right - mid;

        auto* leftArray = new int[subArrayOne],
            * rightArray = new int[subArrayTwo];

        for (auto i = 0; i < subArrayOne; i++)
            leftArray[i] = array[left + i];
        for (auto j = 0; j < subArrayTwo; j++)
            rightArray[j] = array[mid + 1 + j];

        auto indexOfSubArrayOne
            = 0,
            indexOfSubArrayTwo
            = 0;
        int indexOfMergedArray
            = left;

        while (indexOfSubArrayOne < subArrayOne
            && indexOfSubArrayTwo < subArrayTwo) {
            if (leftArray[indexOfSubArrayOne]
                <= rightArray[indexOfSubArrayTwo]) {
                array[indexOfMergedArray]
                    = leftArray[indexOfSubArrayOne];
                indexOfSubArrayOne++;
            }
            else {
                array[indexOfMergedArray]
                    = rightArray[indexOfSubArrayTwo];
                indexOfSubArrayTwo++;
            }
            indexOfMergedArray++;
        }
        while (indexOfSubArrayOne < subArrayOne) {
            array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
            indexOfMergedArray++;
        }
        while (indexOfSubArrayTwo < subArrayTwo) {
            array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
            indexOfMergedArray++;
        }
        delete[] leftArray;
        delete[] rightArray;
    
    }
    void mergeSort(int array[], int const begin, int const end) {
        if (begin >= end)
            return;

        auto mid = begin + (end - begin) / 2;
        mergeSort(array, begin, mid);
        mergeSort(array, mid + 1, end);
        merge(array, begin, mid, end);
    
    }

    //---------
    void swap(int* a, int* b) {
        int t = *a;
        *a = *b;
        *b = t;
    
    }
    int partition(int arr[], int low, int high) {
        int pivot = arr[high];
        int i
            = (low
                - 1);
        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[high]);
        return (i + 1);
    
    
    }
    void quickSort(int arr[], int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);

            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    
    
    
    }

   

    //------------
    struct node {
        int data;
        node* next;
    };

    struct node* create(int x)
    {
        node* temp = new node();
        temp->data = x;
        temp->next = NULL;

        return temp;
    };
    void insert(node*& head, int n) {
        if (head == NULL) {
            head = create(n);
            return;
        }

        node* t = head;
        while (t->next != NULL)
            t = t->next;
        t->next = create(n);
    
    
    
    }
    int del(node*& head) {
    
        if (head == NULL)
            return 0;
        node* temp = head;
        int val = head->data;

        head = head->next;

        delete temp;
        return val;
    
    
    
    }
    int digits(int n) {
    
        int i = 1;
        if (n < 10)
            return 1;

        while (n > (int)pow(10, i))
            i++;
        return i;
    
    }
    void radix_sort(vector<int>& arr) {
    
        int sz = arr.size();

        int max_val = *max_element(arr.begin(), arr.end());

        int d = digits(max_val);

        node** bins;


        bins = new node * [10];

        for (int i = 0; i < 10; i++)
            bins[i] = NULL;

        for (int i = 0; i < d; i++) {
            for (int j = 0; j < sz; j++)
                insert(bins[(arr[j] / (int)pow(10, i)) % 10],
                    arr[j]);

            int x = 0, y = 0;

            while (x < 10) {
                while (bins[x] != NULL)
                    arr[y++] = del(bins[x]);
                x++;
            }
        }
    
    
    
    }
    
    //------------------
    int shellSort(int arr[], int n) {
        for (int gap = n / 2; gap > 0; gap /= 2)
        {
            for (int i = gap; i < n; i += 1)
            {
                int temp = arr[i];

                int j;
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                    arr[j] = arr[j - gap];
                arr[j] = temp;
            }
        }
        return 0;
    
    
    
    
    }

    //------------------
    void printArray(int arr[], int N) {
    
        int i;
        for (i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    
    
    
    
    
    }


};




