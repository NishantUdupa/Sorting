#include"sorts.h"; 





void input(int* arr, int& size)
{
	cout << "Enter size of array : ";
	cin >> size;
	arr = new int[size];
	cout << "Enter Array Elements : ";
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
}





int main() {


	Sorting obj; 

	int choice; 
	int * arr = NULL;
	int size;





	switch (obj.menu())
	{
	case 1:  // bucket 
		input(arr, size); 


		obj.bucketSort(arr, size); 


		cout << "Sorted array is \n";
		obj.printArray(arr, size);

		break; 
	case 2: // heapsort



		obj.heapSort(arr, size); 

		input(arr, size);


		cout << "Sorted array is \n";
		obj.printArray(arr, size);

		break;

	case 3: // insertion sort
		input(arr, size);



		obj.InsertionSort(arr, size);



		cout << "Sorted array is \n";
		obj.printArray(arr, size);

		break;

	case 4: // merge sort 
		input(arr, size);

	
		
		obj.mergeSort(arr, 0, size - 1);

		
		
		
		
		

		cout << "Sorted array is \n";
		obj.printArray(arr, size);
		
		break;

	case 5: // quick sort 
		input(arr, size);


		obj.quickSort(arr,0, size -1);

		

		cout << "Sorted array is \n";
		obj.printArray(arr, size);
		break;

	case 6: 
		input(arr, size);


		//obj.radix_sort(arr);




		cout << "Sorted array is \n";
		obj.printArray(arr, size);
		break;

	case 7:
		input(arr, size);



		obj.shellSort(arr, size);

		
		
		
		
		

		cout << "Sorted array is \n";
		obj.printArray(arr, size);
		break;






	default:

		cout << "Your input is out of bound" << endl; 
		break;
	}









	return 0; 
}














