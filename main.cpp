#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;


struct CarInfo{
    string Make;
    string Mileage;

   CarInfo(string make, string mileage) : Make(make), Mileage(mileage) {}
   CarInfo(){};
};


/*
//part of quick sort
int partition(CarInfo *array, int low, int high){
    //choose the pivot

    int pivot=atoi(array[high].Mileage.c_str());
    //Index of smaller element and Indicate
    //the right position of pivot found so far
    int i=(low-1);

    for(int j=low;j<=high;j++){
        //If current element is smaller than the pivot
        if(atoi(array[j].Mileage.c_str())<pivot){
            //Increment index of smaller element
            i++;
            swap(array[i],array[j]);
        }
    }
    swap(array[i+1],array[high]);
    return (i+1);
}


// The Quicksort function Implement
void quickSort(CarInfo *array,int low,int high){
    // when low is less than high
    if(low<high){
        // pi is the partition return index of pivot

        int pi=partition(array,low,high);

        //Recursion Call
        //smaller element than pivot goes left and
        //higher element goes right
        quickSort(array,low,pi-1);
        quickSort(array,pi+1,high);
    }
}
*/

 //Part of quick sort
int partition(CarInfo *array, int low, int high) {
//    int randomIndex = low + rand() % (high - low + 1);
    int pivot = atoi(array[high].Mileage.c_str());
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (atoi(array[j].Mileage.c_str())< pivot) {
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[high]);
    return (i + 1);
}

// Iterative quickSort function
void quickSort(CarInfo *array, int low, int high) {
    vector<pair<int, int>> stack;
    stack.push_back(make_pair(low, high));

    while (!stack.empty()) {
        int start = stack.back().first;
        int end = stack.back().second;
        stack.pop_back();

        int pivot = partition(array, start, end);

        if (pivot - 1 > start)
            stack.push_back(make_pair(start, pivot - 1));
        if (pivot + 1 < end)
            stack.push_back(make_pair(pivot + 1, end));
    }
}


// Merge sort helper
void merge(CarInfo *array, int const left, int const mid, int const right){
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;

    // Create temp arrays
    auto *leftArray = new CarInfo[subArrayOne], *rightArray = new CarInfo[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        int leftVal = atoi(leftArray[indexOfSubArrayOne].Mileage.c_str());
        int rightVal = atoi((rightArray[indexOfSubArrayTwo]).Mileage.c_str());

        if (leftVal <= rightVal) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

// Merge sort function
void mergeSort(CarInfo *array, int const begin, int const end){
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

// Gets data and puts it into a vector of tuples
void GetCarVector(vector<CarInfo> &Cars){

    // Open the CSV file
    ifstream file("Electric_Vehicle_Population_Data.csv");

    // Check if the file is opened successfully
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return;
    }

    string line;
    getline(file, line);

    // Read each line from the file
    while (getline(file, line)) {
        // Create a string stream from the line
        stringstream ss(line);

        // Vector to store each field in the line
        vector<string> fields;
        string field;

        // Tokenize the line by comma (CSV)
        while (getline(ss, field, ',')) {
            fields.push_back(field);
        }

        CarInfo Individual_Car = CarInfo(fields.at(5) + " " + fields.at(6) + " " +  fields.at(7), (fields.at(10)));
        Cars.push_back(Individual_Car);
    }

    // Close the file
    file.close();

}


int main() {
    char cwd[1024];

    // Get the current working directory
//    if (getcwd(cwd, sizeof(cwd)) != NULL) {
//        std::cout << "Current working directory: " << cwd << std::endl;
//    } else {
//        std::cerr << "Error getting current working directory" << std::endl;
//        return 1;
//    }


    vector<CarInfo> Cars;
    GetCarVector(Cars);
    const int size = Cars.size();

    //convert the vector into two separate arrays, one for quicksort, another for mergesort
    CarInfo *arr_merge = new CarInfo[Cars.size()];
    CarInfo *arr_quick = new CarInfo[Cars.size()];
    for (int i = 0; i < Cars.size(); ++i) {
        arr_merge[i] = Cars[i];
        arr_quick[i] = Cars[i];
    }

    cout << "Calculating MergeSort execution speed..." << endl;
    // mergesort timer & process
    auto start = std::chrono::high_resolution_clock::now();
    mergeSort(arr_merge, 0, size-1);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "MergeSort execution time: " << duration.count() << " seconds" << std::endl;

    cout << "Calculating QuickSort execution speed..." << endl;
    // quicksort timer & process
    start = std::chrono::high_resolution_clock::now();
    quickSort(arr_quick, 0, size-1);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "QuickSort execution time: " << duration.count() << " seconds" << std::endl;

/*
    for (int i = 0; i < Cars.size(); i++){
        cout << i << ": " <<  (arr_merge[i]).Make << ", " << (arr_merge[i]).Mileage  << endl;
    }

    for (int i = 0; i < Cars.size(); i++)
        cout << i << ": " <<  (arr_quick[i]).Make << ", " << (arr_quick[i]).Mileage  << endl;
*/

    cout << "-------------------------------------------------------------------" <<endl << "*TYPE 1, 2, OR 3*" << endl << endl << "Menu: " << endl << "1. Highest Range Car Model:" << endl << "2. Lowest Range Car Model:" << endl << "3. Quit\n" << endl;
    while(true){
        string input;
        cin >> input;

       if(input == "1"){
            cout << "Highest Range Car Max: " << arr_merge[size-1].Make << " - " << arr_merge[size-1].Mileage << endl;
        }else if(input == "2"){
            cout << "Lowest Range Car Max: " << arr_merge[0].Make << " - " << arr_merge[0].Mileage << endl;
        }else if(input == "3"){
            cout << "Quitting..." << endl;
            break;
        }else{
            cout << "Incorrect Input" << endl;
        }
    }

    delete[] arr_merge;
    delete[] arr_quick;
    return 0;
}
