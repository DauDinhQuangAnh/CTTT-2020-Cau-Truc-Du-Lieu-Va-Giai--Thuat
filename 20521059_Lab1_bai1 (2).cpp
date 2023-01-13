#include<iostream>
#include<time.h>
#include <cstdlib>
using namespace std;

//Câu 1: Xây dựng cấu trúc node và cấu trúc liên kết đơn
struct node //khai báo cấu trúc node
{
    int data;
    struct node *pnext; // node tự trỏ
};
typedef struct node NODE; //Thay thế struct node bằng NODE


struct list{ // cấu trúc Da liên kết đơn
    NODE * pHead; 
    NODE * pTail;
};
typedef struct list LIST;//Thay thế struct list bằng LIST

//Câu 2: Viết Hàm khởi tạo danh sách liên kết đơn và hàm 
//khởi tạo địa chỉ node từ một số nguyên
void creatlist (LIST &l)
{
    l.pHead= NULL;
    l.pTail= NULL;

}

NODE *createNODE(int x){
    NODE *p= new NODE;
    if(p==NULL){
        return NULL;
    }
    p -> data = x;
    p -> pnext = NULL;
    return p;
}

//Câu 3: Viết hàm chèn vào đầu danh sách
void addhead(LIST &l, NODE *p){
    if(l.pHead==NULL){
        l.pHead = l.pTail =p;
        p->pnext=NULL;
    }
    else{
        p->pnext = l.pHead;
        l.pHead = p; 
    }
}

//Câu 4: Viết hàm chèn vào cuối danh sách
void addlast(LIST &l, NODE *p){
    if(l.pHead==NULL){
        l.pHead = l.pTail =p;
    }
    else{
        l.pTail->pnext=p;
        l.pTail=  p;
    }   
}

//Câu 5: Nhập giá trị cho danh sách liên kết 
//phương pháp thủ công từ bàn phím (dùng hàm 
//chèn đầu danh sách). Điều kiện kết thúc là 
//tự quy định
void nhaphamdau(LIST &l, int n){

    for (int i =1;i<=n;i++){
        int x;
        cout << " Nhap vao cac gia tri: ";
        cin>> x;
        NODE *p = createNODE(x);
        addhead(l, p);
    }
}

//Câu 6: Random NODE 
void randnode(LIST &l){
    int n = 39 + rand()%21;
    for (int i =0 ; i<n ; i++){
            int value =-99+rand ()%199;
            addlast (l, createNODE(value));
        }
}


//Câu 7: Nhập giá trị cho danh sách từ mảng 1 chiều


//Câu 8: Hàm chèn node vào vị trí giữa danh sách

//câu 9: Hàm chèn thêm vào danh sách một giá trị x đằng
// sau 1 giá trị y
void themxsauy(LIST l){
    int x;
    cin >> x;
    NODE *q= createNODE(x);
    if(q->data == l.pHead ->data && l.pHead->pnext == NULL){
        addlast(l,q);
    }
}
//câu 10: Hàm chèn thêm vào danh sách một giá trị x đằng
// trước 1 giá trị y
void themxtruocy(LIST l){
    int x;
    cin >> x;
    NODE *q= createNODE(x);
    if(q->data == l.pHead ->data && l.pHead->pnext == NULL){
        addhead(l,q);
    }
}
// Câu 11: Xuat danh sach lien ket
void xuatdanhsach(LIST l){
    int i=1;
    for(NODE *k =l.pHead ; k != NULL ; k=k->pnext){
        cout <<"Gia tri node "<< i++ <<" la: " <<k->data << endl;
    }

}

//Câu 12: In ra giá trị kèm địa chỉ của từng node trong dang sách
void xuatdanhsachvadiachi(LIST l){
    int i=1;
    for(NODE *k =l.pHead ; k != NULL ; k=k->pnext){
        cout <<"Gia tri node va dia chi"<< i++ <<" la: " <<k->data << "  " << &k->data << endl;
    }

}
//câu 13: In ra 2 giá trị và địa chỉ đầu và cuối của danh sách
void indaucuoi(list l){
    cout << "gia tri dau la: " << l.pHead->data << " vs dia chi "<< &l.pHead->data<<endl;
    cout << "gia tri cuoi la: " << l.pTail->data << " vs dia chi "<< &l.pTail->data<<endl;
}
//câu 14: Kiểm Tra danh sách có rỗng hay không, trả về true false
bool checklist (LIST l){
    if (l.pTail == NULL){
        return true;
    }
    else {return false;}
}
//câu 15: Hàm viết trả về node thứ n trong danh sách
void timgiatri(LIST l, NODE *p){
    int c=0;
    for(NODE *k =l.pHead ; k != NULL ; k=k->pnext){
        c++;
        if(p->data == k ->data){
            cout << "Node ban tim o vi tri "<< c <<endl; 
        }
        else{cout << "Null";}
    }
}
//câu 16: Tìm node có giá trị X trong danh sách, không có trả về NULL
void timkiemnode(LIST l, NODE *p){
    for(NODE *k =l.pHead ; k != NULL ; k=k->pnext){
        
        if(p->data == k ->data){
            cout << &k->data<<endl;
             break;
        }
        else{cout << "Null";}
    }
}
//Câu 17: Giống câu 16 nhưng in ra địa chỉ, ko có thì NULL
void timkiemcacnode(LIST l, NODE *p){
    for(NODE *k =l.pHead ; k != NULL ; k=k->pnext){
        if(p->data == k ->data){
            cout << &k->data<<endl; 
        }
        else{cout << "Null";}
    }
}
//Câu 18: Tính Tổng các node trong danh sách
void tongdanhsach(LIST l){
    int i=0;
    for(NODE *k =l.pHead ; k != NULL ; k=k->pnext){
        i+=k->data;
    }
        cout <<"Tong gia tri node la: "<< i << endl;
}

//Câu 19: Đếm số lượng các node trong danh sách
void soluongdanhsach(LIST l){
    int i=0;
    for(NODE *k =l.pHead ; k != NULL ; k=k->pnext){
        i++;
    }
        cout <<"So luong node node la: "<< i << endl;
}

//Câu 20: Đếm số lượng giá trị chẵn lẻ có trong danh sách
void soluongchanle(LIST l){
    int c=0;
    int le=0;
    for(NODE *k =l.pHead ; k != NULL ; k=k->pnext){
        if(k->data % 2== 0){
            c++;
        }
        else{le++;}
    }
        cout <<"So luong chan la: "<< c << endl;
        cout <<"So luong le la: "<< le << endl;
}
//Câu 21: Đếm số lượng giá trị âm dương có trong danh sách
void soluongamduong(LIST l){
    int am=0;
    int duong=0;
    for(NODE *k =l.pHead ; k != NULL ; k=k->pnext){
        if(k->data < 0){
            am++;
        }
        else{duong++;}
    }
        cout <<"So luong chan la: "<< am << endl;
        cout <<"So luong le la: "<< duong << endl;
}

//Câu 22: Tìm hàm node có giá trị MAX va Min trong danh sách
void max(LIST l){
    int temp = l.pHead->data;
    for(NODE *k =l.pHead->pnext ; k != NULL ; k=k->pnext){
        if ( k->data > temp){
            temp =k->data;
        }
    }
    cout << "Gia tri max là: "<< temp << endl;

}
void min (LIST l){
    int temp = l.pHead->data;
    for(NODE *k =l.pHead->pnext ; k != NULL ; k=k->pnext){
        if ( k->data < temp){
            temp =k->data;
        }
    }
    cout << "Gia tri min là: "<< temp << endl;   
}
//Câu 23: Node có giá trị âm lớn nhất, node có giá trị lẻ nhỏ nhấ
void ammax(LIST l){
    int temp = l.pHead->data;
    for(NODE *k =l.pHead->pnext ; k != NULL ; k=k->pnext){
        while(k->data < 0 && k->data >temp)
        {
            temp =k->data;           
        }        
    }
    cout << "Gia tri am max la: "<<temp <<endl;
}
void lemin (LIST l){
    int temp = l.pHead->data;
    for(NODE *k =l.pHead->pnext ; k != NULL ; k=k->pnext){
        if(abs(k->data) % 2 == 1 && abs(k->data <temp)){
                temp =k->data;
        }    
    }
    cout << "Gia tri le min la: "<< temp << endl;   
}
//Câu 24: Tìm MAX các số âm và min các số lẻ trong danh sách
void ammax2(LIST l){
    int temp = l.pHead->data;
    for(NODE *k =l.pHead->pnext ; k != NULL ; k=k->pnext){
        while(k->data < 0 && k->data >temp)
        {
            temp =k->data;           
        }        
    }
    cout << "Gia tri am max la: "<<temp <<endl;

}
void lemin2(LIST l){
    int temp = l.pHead->data;
    for(NODE *k =l.pHead->pnext ; k != NULL ; k=k->pnext){
        if(abs(k->data) % 2 == 1 && abs(k->data <temp)){
                temp =k->data;
        }    
    }
    cout << "Gia tri le min la: "<< temp << endl;     
}
//Câu 25: Cập nhật giá trị x bằng giá trị y mới

//Câu 26: Cập nhật tất cả các giá trị x bằng giá trị y mới


//Câu 27: tính tổng các số chẵn và tổng các số lẻ
// nếu chẵn lớn hơn lẻ thì trả về 1, còn chẵn nhỏ hơn lẻ
//thì trả lại là -1, bằng nhau thì 0
void sosanhchanle(LIST l){
    int c=0;
    int le=0;
    for(NODE *k =l.pHead ; k != NULL ; k=k->pnext){
        if(k->data % 2== 0){
            c+=k->data;
        }
        else{le+=k->data;}
    }
    if( c > le) {
        cout << "1";
    }
    else if (c = le){
        cout << "0";
    }
    else{ 
        cout << "-1";
    }
        
}



//Câu 28: tìm hàm node đứng trước node có giá trị là x, ko thấy
//trả về NULL



//Câu 29: viết hàm đảo ngược danh sách
void daonguoc(LIST l){
    NODE *parent = l.pHead;
    NODE *current = l.pHead->pnext;
    l.pHead= current->pnext;
    parent->pnext=NULL;
    current->pnext=parent;
    while(l.pHead->pnext){
        parent = current;
        current = l.pHead;
        l.pHead = l.pHead->pnext;
        current->pnext=parent;
    }
    l.pHead->pnext = parent;
}


//Câu 30: Tách một danh sách liên kết thành 2, nếu lẻ thì 
//chiều dài danh sách thứ nhất sẽ ít hơn thứ 2 một giá trị

//Câu 32: Xóa node đầu tiên

void xoadau(LIST l, int &value){
    NODE *p=l.pHead;
    l.pHead=p->pnext;
    value = p->data;
    delete p;
    xuatdanhsach(l);
}

//Cau 33: Xóa node cuối cùng
void xoacuoi(LIST l, int &value){
    for( NODE *k = l.pHead; k!= NULL ;k=k->pnext){
        if(k->pnext = l.pTail){
            delete l.pTail;
            k->pnext = NULL;
            l.pTail = k;
        }
    }
}

// cau 34: Xóa node có giá trị X (Node đầu tiên)


int main(){
    LIST l;
    creatlist(l);


    cout<< "1. Xay dung cau truc node va danh sach liên ket don."<< endl;
    cout<< "2. viet ham khoi tao danh sach lien ket don."<< endl;
    cout<< "3. Ham chen node vao dau danh sach."<< endl;
    cout<< "4. Ham chen node vao cuoi danh sach."<< endl;
    cout<< "5. Nhap ham thu cong tu ban phim"<< endl;
    cout<< "6. Nhap danh sach theo phuong phap tu dong"<< endl;
    cout<< "7. nhap gia tri danh sach tu mang 1 chieu"<< endl;
    cout<< "8. Chen ham node vao vie tri giua danh sach"<< endl;
    cout<< "9. Them gia tri X vao sau 1 gia tri Y"<< endl;
    cout<< "10. Them gia tri X va truoc 1 gia tri Y"<< endl;
    cout<< "11. In danh sach da nhap"<< endl;
    cout<< "12. In gia tri kem dia chi"<< endl;
    cout<< "13. In gia tri va dia chi cua node dau va cuoi"<< endl;
    cout<< "14. Kiem tra danh sach rong hay khong"<< endl;
    cout<< "15. Ham tra ve node thu n trong danh sach"<< endl;
    cout<< "16. Tim node co gia tri x trong danh sach"<< endl;
    cout<< "17. Giong cau 16 nhung xuat r a dia chi"<< endl;
    cout<< "18. Tổng node trong danh sach"<< endl;
    cout<< "19. Tinh do dai node"<< endl;
    cout<< "20. dem so luong node chan vs node le"<< endl;
    cout<< "21. Dem so lương node am dương"<< endl;
    cout<< "22. Ham tim max min trong list"<< endl;
    cout<< "23. ham tim Max so am va min so le"<< endl;
    cout<< "24. Giong cau 23"<< endl;
    cout<< "25. Cap nhap gia tri node X bang gia tri y"<< endl;
    cout<<"26. Cap nhat tat ca node x  bang gia tri y"<< endl;
    cout<<"27. Tinh tong chan vs tong le chan<le=1, chan>le=-1, chan=le=0"<< endl;
    cout<<"28.Tim node dung truoc node co gia tri X"<< endl;
    cout<<"29. Dao ngươc danh sach"<< endl;
    cout<<"30. Chia danh sach, neu le thì danh sách 2 dai hon danh sach 1"<< endl;
    cout<<"31. chia danh sach ngat tai phan tu X, x thuoc danh sach 1"<< endl;
    cout<<"32. Xoa node dau tien trong danh sach"<< endl;
    cout<<"33. Xoa node cuoi cung trong danh sach"<< endl;
    cout<<"34. Xoa node có gai tri x, la node dau tien tim thay"<< endl;
    cout<<"35. Noi 2 danh sach thanh 1 danh sach"<< endl;
    cout<<"36. Xoa tat ca cac node co gia tri xtrong list "<< endl;
    cout<<"37. xoa toan bo node trong list"<< endl;
    cout<<"38. Sap xep danh sach tang giam "<< endl;
    cout<<"39. viet ham main để cho phep lua chon cac tinh nang tren"<< endl;
    cout << "Nhap lua chon cua ban" << endl;
    
    int m;
    cin >>m;
    switch (m)
    {
    case 1: case 2: case 3: case 4:
        cout << "Cau nay da lam. HIHI :33"<<endl;
        break;
    case 5:{
        int v;
        cout << "Nhap so luong note can them: ";
        cin >>v;
        nhaphamdau(l,v);
        xuatdanhsach(l);}
        break;
    case 6:{            
        randnode(l);
        xuatdanhsach(l);}
        break;

    case 7:
        
        break;
        
    case 8:

        break;
        
    case 9:
        {themxsauy(l);}
        break;
    case 10:
        themxtruocy(l);
        break;
            
    case 11:
        xuatdanhsach(l);
        break;
        
    case 12:
        xuatdanhsachvadiachi(l);
        break;
        
    case 13:
        indaucuoi(l);
        break;
        
    case 14:
        {checklist (l);
        if(checklist (l)==1)
        {
            cout << "TRUE";
        }
        else {cout << "FALSE";
        }
    }
        break;
    case 15:
       { int j;
        cout << "Nhap gia tri can tim: ";
        cin >> j;
        NODE *p = createNODE(j);
        timgiatri(l,p);}
        break;
    case 16 : 
        {int tim;
        cout << "Nhap gia tri can tim: ";
        cin >> tim;
        NODE *p=createNODE(tim);
        timkiemnode(l,p);}
        break;
    case 17:
        {int g;
        cout << "Nhap gia tri can tim: ";
        cin >> g;
        NODE *p=createNODE(g);
        timkiemcacnode(l, p);}
        break;
    case 18:
        tongdanhsach(l);
        break;
    case 19:
        soluongdanhsach(l);
        break;
    case 20:
        soluongchanle(l);
        break;
    case 21:
        soluongamduong(l);
        break;
    case 22:
        max(l);
        min(l);
        break;
    case 23:
        ammax(l);
        lemin(l);
        break;
    case 24:
        ammax2(l);
        lemin2(l);
        break;
    case 25:

        break;
    case 26:

        break;
    case 27:
        sosanhchanle(l);
        break;
    case 28:

        break;
    case 29:
        daonguoc(l);
        break;
    
    case 30:

        break;

    case 31:

        break;

    case 32:{
        int a;
        xoadau(l,a);
    }
        break;
    case 33:

        break;
    case 34:

        break;
    case 35:

        break;
    case 36:

        break;
    case 37:

        break;
    case 38:

        break;
    case 39:

        break;

    default:
        m=0;
        break;
    }

    system("pause");
    return 0;
}
