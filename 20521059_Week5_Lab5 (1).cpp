#include <iostream>
#include <time.h>
using namespace std;

#define size 100000
double time1 = 0;
double time2 = 0;

void initiateManual(double *a, int n) {
    for(int i = 0; i < n; i++) {
        cin >> *(a + i);
    }
}

void initiateAuto(double *a, int n) {
    for(int i = 0; i < n; i++) {
        *(a + i) = rand() + (rand() % 100) / 100.0;
    }
}

void printArray(double *a, int n) {
    for(int i = 900; i < n; i++) {
        cout << *(a + i) << "\t";
    }
}

void print(int *x, int n) {
    *(x) = 10;
    *(x + 1) = 15;
    *(x + 2) = 20;
    *(x + 3) = 28;
    *(x + 4) = 31;
    *(x + 5) = 35;
    *(x + 6) = 49;
    *(x + 7) = 60;
    cout << *(x) << "\t" << *(x + 1) << "\t" << *(x + 2) << "\t" << *(x + 3) << "\t" << *(x + 4) << "\t" << *(x + 5) << "\t" <<  *(x + 6) << "\t" << *(x + 7) << "\t" ;
}

void selectionSort(double* a, int n) {
    int min;
    for(int i = 0; i < n - 1; i++) {
        min = i;
        for(int j = i + 1; j < n; j++) {
            if(a[j] < a[min]) 
                min = j; 
        }
        swap(a[i],a[min]);
    }
}

void insertionSort(double* a, int n) {
    int i = 1, j;
    double k;
    for(int i = 1; i < n; i++) {
        k = *(a + i);
        j = i - 1;
        while(j >= 0 && *(a + j) > k) {
            *(a + j + 1) = *(a + j);
            j = j - 1;
        }
        *(a + j + 1) = k;
    }
}

double calculateTime1(double* a, int n) {
	clock_t start, end;
	double cpu_time_used;
	start = clock();
	selectionSort(a, n);
	end = clock();
    time1 = (double) (end - start) / CLOCKS_PER_SEC;
	return time1;
}

double calculateTime2(double* b, int n) {
	clock_t start, end;
	double cpu_time_used;
	start = clock();
	insertionSort(b, n);
	end = clock();
	time2 = (double) (end - start) / CLOCKS_PER_SEC;
	return time2;
}

double getTime(double time) {
    return time;
}

void compareSortingTime(double *a, double *b, int n) {
    if(time1 > time2)
        cout << "Insertion Sort is faster than Selection Sort.\n (" << getTime(time2) << " < " << getTime(time1) << ")";
    else if(time1 < time2)
        cout << "Selection Sort is faster than Insertion Sort.\n (" << getTime(time1) << " > " << getTime(time2) << ")";
    else
        cout << "Selection Sort is equal than Insertion Sort.\n (" << getTime(time1) << " = " << getTime(time2) << ")";
}

int main()
{
    srand(time(0));
    double *a = new double[size];
    double *b = new double[size];
    int n = 1e5;
    int choose;
    string option;
    
    while(1) {
        cout << "------------------------- MENU -------------------------\n";
        cout << "1. Input value for array arrayA\n";
        cout << "\tA. Manual\n";
        cout << "\tB. Automatic\n";
        cout << "2. Print value in array\n";
        cout << "3. Sort array by ascending order\n";
        cout << "\tA. Selection Sort\n";
        cout << "\tB. Insertion Sort\n";
        cout << "4. Calculate sorting time\n";
        cout << "\tA. Selection Sort\n";
        cout << "\tB. Insertion Sort\n";
        cout << "5. Compare sorting time of two Sort algorithms\n";
        cout << "Please choose: "; cin >> choose;

        switch(choose) {
            case 1: {
                cin >> option;
                if(option == "A") {
                    cout << "Input value: \n";
                    initiateManual(a, n);
                    cout << endl;
                }

                else if(option == "B") {
                    initiateAuto(a, n);
                    initiateAuto(b, n);
                    cout << "Initiated array automatically.\n";
                }

                else {
                    cout << "Invalid option, please choose again!!\n";
                    break;
                }
                break;
            }

            case 2: {
                cout << "Array: \n";
                printArray(a, n);
                cout << endl;
                break;
            }

            case 3: {
                cin >> option;
                if(option == "A") {
                    cout << "Used Selection Sort.\n";
                    selectionSort(a, n);
                    cout << endl;
                }

                else if(option == "B") {
                    insertionSort(b, n);
                    cout << "Used Insertion Sort.\n";
                }

                else {
                    cout << "Invalid option, please choose again!!\n";
                    break;
                }
                break;
            }

            case 4: {
                cin >> option;
                if(option == "A") {
                    cout << "Sorting time on array A: " << calculateTime1(a, n);
                    cout << endl;
                }

                else if(option == "B") {
                    cout << "Sorting time on array B: " << calculateTime2(b, n);
                    cout << endl;
                }

                else {
                    cout << "Invalid option, please choose again!!\n";
                    break;
                }
                break;
            }

            case 5: {
                cout << "Comparision result: \n";
                compareSortingTime(a, b, n);
                cout << endl;
            }

            default: {
                cout << "Invalid option, please choose again!!\n";
                break;
            }
        }
    }
    
    return 0;
}
