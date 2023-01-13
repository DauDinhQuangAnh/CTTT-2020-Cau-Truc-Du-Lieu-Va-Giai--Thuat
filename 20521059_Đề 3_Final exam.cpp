#include <iostream>

using namespace std;

struct HoaDon {
    int maHD;
    char* tenKH;
    float soTien;
};
typedef HoaDon HD;

struct node {
    HD data;
    node *pNext;
};

struct list {
    node *pHead;
    node *pTail;
};

node* createNode(HD x) {
    node *p = new node();
    p->data = x;
    p->pNext = NULL;
    return p;
}

void createList(list &l) {
    l.pHead = NULL;
    l.pTail = NULL;
}

void addHead(list &l, node* p) {
    if(p == NULL) {
        l.pHead = NULL;
        l.pTail = NULL;
    }
    else {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

void nhap(HoaDon &hd) {
    cout << "Nhap ma HD: ";
    cin >> hd.maHD;
    cout << "Nhap tenKH: ";
    cin >> hd.tenKH;
    cout << "Nhap so tien: ";
    cin >> hd.soTien;
}

/*Cau 2: Viet ham xuat danh sach cac hoat don
Input:
    +du lieu cua hoa don
Output:
    +danh sach hoa don
*/
void xuatDSHoaDon(list l) {
    for(node *i = l.pHead; i != NULL; i = i->pNext) {
        cout << i->data.maHD << " " << i->data.tenKH << " " << i->data.soTien << endl;
    }
}

/*Cau3: Tim kiem HD theo ma HD
Input:
    + List l
    + Ma HD
Output:
    + tim thay tra ve dia chi NODE
    + Khong tim thay tra ve NULL
*/
int TimmaHD(list l, int x) {
    HD hd;
    node *p = l.pHead;
    while(p != NULL) {
    if(p->data.maHD == x) {
        return 1;
    }
        p = p->pNext;
    }
    return 0;
}

/*Cau 4: Ham tinh trung binh so tien tat ca hoa don
Input:
    +list
    +so tien cua tat ca hoa don
Ouput:
    +trung binh so tien cua tat ca hoa don
*/

float trungbinhSoTien(list l, float &trungbinh) {
    int dem = 0;
    float tong = 0;
    for(node *i = l.pHead; i != NULL; i = i->pNext) {
        tong += i->data.soTien;
        dem++;
    }
    trungbinh = tong / dem;
    return trungbinh;
}
/*Cau 5: dem HD co so tien cao hon gia tri trung binh
Input:
    +list
    +gia tri trung binh o cau 4
    +count
Output:
    +count
*/
int countAvg(list l, int &count) {
    float avg = trungbinhSoTien(l, avg);
    for(node *i = l.pHead; i != NULL; i = i->pNext) {
        if(i->data.soTien > avg) {
            count++;
        }
    }
    return count;
}

/*Cau 6:ham tim khach hang dau tien co so tien thap nhat
Input:
    +list
Outout:
    +thong tin khach hang dau tien co so tien thap nhat
*/
void searchName(list l) {
    node *min = l.pHead;
    for(node *i = l.pHead; i != NULL; i = i->pNext) {
        if(min->data.soTien > i->data.soTien) {
            min = i;
        }
    }
    cout << min->data.maHD << " " << min->data.tenKH << " " <<min->data.soTien;
}

/*Cau 7: ham tra ve cac ma HD co so tien lon nhat
Input:
    +list
Output:
    +ma HD co so tien lon nhat
*/
int getHoaDonLonNhat(list l) {
    node *max = l.pHead;
    for(node *i = l.pHead; i != NULL; i = i->pNext) {
        if(max->data.soTien < i->data.soTien) {
            max = i;
        }
    }
    return max->data.maHD;
}

/*Cau 8: ham cap nhat ten khach hang theo ma HD
Input:
    +list
Output:
    +updated list
*/
void UpdateList(list &l, int x) {
    node* p;
    for(node *i = l.pHead; i != NULL; i = i->pNext) {
        if(i->data.maHD == x)
            p->data.tenKH = i->data.tenKH;
    }
    for(node *i = l.pHead; i != NULL; i = i->pNext) {
        if(i->data.maHD != x) {
            i->data.tenKH = p->data.tenKH;
        }
    }
}

/*Cau 9: ham sao chep cac HD sang mot danh sach moi
Input:
    +origin list
    +empty new list
Output:
    +copied new list
*/

int main() {
    list l;
    createList(l);
    float avg = 0;
    int count = 0;
    HD p1= {922, "Nguyen A", 8.8e6};
    HD p2= {923, "Nguyen B", 9.7e6};
    HD p3= {924, "Nguyen C", 2.9e6};
    HD p4= {926, "Nguyen D", 9.7e6};
    HD p5= {924, "Nguyen E", 4.8e6};
    HD p6= {928, "Nguyen F", 7.5e6};
    addHead(l,createNode(p1));
    addHead(l,createNode(p2));
    addHead(l,createNode(p3));
    addHead(l,createNode(p4));
    addHead(l,createNode(p5));
    addHead(l,createNode(p6));
        
        cout << "\nCau 2: Danh Sach Hoa Don la : " << endl; xuatDSHoaDon(l);
        cout << "\nCau 3: Tim HD 922 theo ma HD co trong list: " << TimmaHD(l,922);
        cout << "\nCau 3: Tim HD 911 theo ma HD co trong list: " << TimmaHD(l,1);
        cout << "\nCau 4: Tinh trung binh so tien cua tat ca hoa don: " << trungbinhSoTien(l,avg);
        cout << "\nCau 5: Dem so tien HD cao hon TB: " << countAvg(l,count);
        cout << "\nCau 6: Tim khach hang dau tien co so tien thap nhat: "; searchName(l);
        cout << "\nCau 7: Tra ve ma HD co so tien cao nhat: " << getHoaDonLonNhat(l);
        cout << "\nCau 8: Cap nhat ten khach hang theo ma HD 922: "; UpdateList(l, 922); xuatDSHoaDon(l);
        cout << "\nCau 9: Sao chep cac HD sang 1 trang moi:   (em quen roi a huhuhuhuhuhuh :<< )";
    return 0;
}
