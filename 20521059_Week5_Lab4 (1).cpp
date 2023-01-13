#include <iostream>
#include<time.h>
using namespace std;

#define size 100
int count = 0, count1 = 0, count2 = 0, count3 = 0;


void initiateArrayX(int *x, int n) {
    for(int i = 0; i < n; i++) {
        *(x + i) = rand() % 899 + 100;
    }
}


void printArray(int *x, int n) {
    for(int i = 0; i < n; i++) {
        cout << *(x + i) << "\t";
    }
}


void initiateArrayY(int *y, int n) {
    *y = rand() % 31 + 100;
    for(int i = 0; i < n; i++) {
        int range = rand() % 1 + 15;
        *(y + i + 1) = *(y + i) + range;
    }
}

int getCountIncrement(int &count) {
    return count++;
}


bool linearSearch(int *a, int n, int value) {
    for(int i = 0; i < n; i++) {
        if(*(a + i) == value) {
            return true;
            break;
        }
        getCountIncrement(count1);
    }
    return false;
}


bool binarySearch(int *a, int n, int value) {
    int l = 0, r = n - 1, m;
    while(l <= r) {
        m = (l + r) / 2;
        if(a[m] == value) {
            return true;
            break;
        }
        else {
            if(value < a[m])
                r = m - 1;
            else if(value > a[m])
                l = m + 1;
        }
        getCountIncrement(count2);
    }
    return false;
}


bool interpolationSearch(int *a, int n, int value) {
    int l = 0, r = n - 1, m;
    while(l <= r) {
        m = l + (((r - l) / (a[r] - a[l])) * (value - a[l]));
        if(a[m] == value) {
            return true;
            break;
        }
        else {
            if(value < a[m])
                r = m - 1;
            else if(value > a[m])
                l = m + 1;
        }
        getCountIncrement(count3);
    }
    return false;    
}

void print(int *a, int n) {
    for(int i = 0; i < n; i++) {
        cout << *(a + i) << " ";
    }
}

void compareResult() {

    if(count1 > count2 && count1 > count3) {
        if(count2 > count3) 
            cout << "Linear Search (" << count1 << " lan) > Binary Search (" << count2 << " lan) > Interpolation Search(" << count3 << " lan)\n"; 
        else if(count2 < count3) 
            cout << "Linear Search (" << count1 << " lan) > Interpolation Search (" << count3 << " lan) < Binary Search(" << count2 << " lan)\n"; 
        else
            cout << "Linear Search (" << count1 << " lan) > Interpolation Search (" << count2 << " lan) = Binary Search(" << count3 << " lan)\n"; 
    }


    else if(count2 > count1 && count2 > count3) {
        if(count1 > count3) 
            cout << "Binary Search (" << count2 << " lan) > Linear Search (" << count1 << " lan) > Interpolation Search(" << count3 << " lan)\n"; 
        else if(count1 < count3) 
            cout << "Binary Search (" << count2 << " lan) > Interpolation Search (" << count3 << " lan) > Linear Search(" << count1 << " lan)\n"; 
        else
            cout << "Binary Search (" << count2 << " lan) > Interpolation Search (" << count3 << " lan) = Linear Search(" << count1 << " lan)\n"; 
    }


    else if(count3 > count1 && count3 > count2) {
        if(count1 > count3) 
            cout << "Interpolation Search (" << count3 << " lan) > Linear Search (" << count1 << " lan) > Binary Search(" << count2 << " lan)\n"; 
        else if(count1 < count3) 
            cout << "Interpolation Search (" << count3 << " lan) > Binary Search (" << count2 << " lan) > Linear Search(" << count1 << " lan)\n"; 
        else
            cout << "Interpolation Search (" << count3 << " lan) > Binary Search (" << count2 << " lan) = Linear Search(" << count1 << " lan)\n"; 
    }

    else if(count1 == count2 && count2 == count3) 
        cout << "Linear Search (" << count1 << " lan) = Binary Search (" << count2 << " lan) = Interpolation Search(" << count3 << " lan)\n"; 
}

void enterX(int &X) {
    cout << "Nhap phan tu X: ";
    cin >> X;
}

int getElementX(int X) {
    return X;
}

int getCount(int count) {
    return count;
}

int main() {

    srand(time(0));
    int *x = new int[size];
    int *y = new int[size];
    int X;
    int n = rand() % 21 + 30;
    int choose;
    string option;

    while(1) {
        cout << "------------------------ MENU ------------------------\n";
        cout << "1. Tao mang\n";
        cout << "\tA. Tao mang arrayX\n";
        cout << "\tB. Tao mang arrayY\n";
        cout << "2. Xuat mang\n";
        cout << "\tA. Xuat mang arrayX\n";
        cout << "\tB. Xuat mang arrayY\n";
        cout << "3. Tim kiem tuyen tinh\n";
        cout << "\tA. Ap dung mang arrayX\n";
        cout << "\tB. Ap dung mang arrayY\n";
        cout << "4. Tim kiem nhi phan, ap dung mang arrayY\n";
        cout << "5. Tim kiem noi suy, ap dung mang arrayY\n";
        cout << "6. So sanh so lan tim kiem, ap dung mang arrayY\n";
        cout << "------------------------ END -------------------------\n";
        cout << "Xin moi lua chon: "; cin >> choose; 

        switch(choose) {
            case 1: {
                cin >> option;
                if(option == "A") {
                    initiateArrayX(x, n);
                    cout << "Da tao mang arrayX.\n";
                    break;
                }
                else if(option == "B") {
                    initiateArrayY(y, n);
                    cout << "Da tao mang arrayY.\n";
                    break;
                }
                else {
                    cout << "Lua chon khong hop le, xin moi chon lai.\n";
                    break;
                }
                break;
            }

            case 2: {
                cin >> option;
                if(option == "A") {
                    cout << "Mang arrayX:\n";
                    printArray(x, n);
                    cout << endl;
                    break;
                }
                else if(option == "B") {
                    cout << "Mang arrayX:\n";
                    printArray(y, n);
                    cout << endl;
                    break;
                }
                else {
                    cout << "Lua chon khong hop le, xin moi chon lai.\n";
                    break;
                }
                break;
            }

            case 3: {
                cin >> option;
                if(option == "A") {
                    enterX(X);
                    if(linearSearch(x, n, getElementX(X))) {
                        cout << "Phan tu " << X << " co trong mang arrayX.\n";
                        break;
                    }
                    else {
                        cout << "Khong tim thay phan tu " << X << " trong mang arrayX.\n";
                        break;
                    }
                }

                else if(option == "B") {
                    enterX(X);
                    if(linearSearch(y, n, getElementX(X))) {
                        cout << "Phan tu " << X << " co trong mang arrayY.\n";
                        break;
                    }
                    else {
                        cout << "Khong tim thay phan tu " << X << " trong mang arrayY.\n";
                        break;
                    }
                }

                else {
                    cout << "Lua chon khong hop le, xin moi chon lai.";
                    break;
                }
                break;
            }

            case 4: {
                enterX(X);
                if(binarySearch(y, n, getElementX(X))) {
                    cout << "Phan tu " << X << " co trong mang arrayY.\n";
                    break;
                }

                else {
                    cout << "Khong tim thay phan tu " << X << " trong mang arrayY.\n";
                    break;
                }

                break;
            }

            case 5: {
                enterX(X);
                if(interpolationSearch(y, n, getElementX(X))) {
                    cout << "Phan tu " << X << " co trong mang arrayY.\n";
                    break;
                }

                else {
                    cout << "Khong tim thay phan tu " << X << " trong mang arrayY.\n";
                    break;
                }

                break;
            }

            case 6: {
                cout << "Ket qua so sanh: \n";
                compareResult();
                break;
            }

            default:
                cout << "Lua chon khong hop le, xin moi chon lai.\n";
                break;
        }

    }


    return 0;
}

