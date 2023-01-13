#include<iostream>
#include<string>

using namespace std;

struct Sinh_Vien 
{
    string name;
    int mssv;
    float GPA;
    
};
typedef struct Sinh_Vien SV; 


struct node {
    SV data;
    node* pnext;
};
typedef struct node NODE;


struct list{ 
    NODE* pHead; 
    NODE* pTail;
};
typedef struct list LIST;


void creatlist (LIST &l)
{
    l.pHead= NULL;
    l.pTail= NULL;

}
int checklist(LIST l){
    if(l.pHead == NULL){
        return 1;
    }
    return 0;
}


NODE* makenode(SV x){
    NODE *p= new NODE;
    if(p==NULL){
        return NULL;
    }
    p->data.mssv = x.mssv;
    p->data.name = x.name;
    p->data.GPA = x.GPA;
    p->pnext = NULL;
    return p;
}

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


void addlast(LIST &l, NODE *p){
    if(l.pHead==NULL){
        l.pHead = l.pTail =p;
    }
    else{
        l.pTail->pnext=p;
        l.pTail=  p;
    }   
}


void RemoveFirst(list& l)
{
       node* p = l.pHead;
       if (l.pHead == NULL)
             cout << "\nDanh sach rong.";
       else
       {
             l.pHead = p->pnext;
             delete p;
       }
}

void RemoveLast(list& l)
{
       node* p = l.pHead;
       node* r = new node;
       if (l.pHead == NULL)
             cout << "\nDanh sach rong";
       else
       {
            while (p != l.pTail)
            {
                r = p;
                p = p->pnext;
            }
                l.pTail = r;
                r->pnext = NULL;
                delete p;
       }
}

void Nhap(SV &s)
{
       cout << "Ma so sinh vien: ";
       cin >> s.mssv;
       cout << "Ho va ten: ";
       cin >> s.name;
       cout << "Diem trung binh: ";
       cin >> s.GPA;
}

void InputList(list& l)
{
       int n;
       SV s;
       do
       {
             cout << "\nNhap so luong sinh vien: ";
             cin >> n;
             if (n <= 0)
                    cout << "So luong sinh vien phai lon hon 0. Vui long nhap lai.";
       } while (n <= 0);
       for (int i = 1; i <= n; i++)
       {
             NODE* p;
             cout << "\nNhap thong tin sinh vien thu " << i << endl;
             Nhap(s);
             p = makenode(s);
             addlast(l, p);
       }
}

void Xuat(SV s)
{
    cout << "MSSV: " << s.mssv <<"    "<< "Ten: "<< s.name << "   "<< "GPA: "<<s.GPA << endl;
}


void OutputList(LIST l)
{
    int j=1;
       for (node* i = l.pHead; i != NULL; i = i->pnext){
            cout << "Sinhvien: " << j << "   ";
            Xuat(i->data);
            j++;
        }
}


void findname(LIST l)
{
       string x;
       cout << "Nhap ten can tim: ";
       cin >> x;
       for (node* i = l.pHead; i != NULL; i = i->pnext)
       {
             if (i->data.name == x);
             {
                    Xuat(i->data);
                    return;
             }
       }
       cout << "Khong co " << x << endl;
}


void findGPA(list l)
{
       float x;
       cout << "Nhap GPA can tim: ";
       cin >> x;
       for (node* i = l.pHead; i != NULL; i = i->pnext)
       {
             if (i->data.GPA == x);
             {
                    Xuat(i->data);
                    return;
             }
       }
       cout << "Khong co " << x << endl;
}


void findmssv(list l)
{
       int x;
       cout << "Nhap mssv can tim: ";
       cin >> x;
       for (node* i = l.pHead; i != NULL; i = i->pnext)
       {
             if (i->data.mssv == x);
             {
                    Xuat(i->data);
                    return;
             }
       }
       cout << "Khong co " << x << endl;
}

void Xoa(list& l)
{
       int x;
       cout << "Nhap mssv can xoa";
       cin >> x;
       if (l.pHead == NULL)
       {
             cout << "danh sach rong";
             return;
       }
       if (l.pHead->data.mssv == x)
       {
             cout << "Xoa thanh cong";
             RemoveFirst(l);
             OutputList(l);
             return;
       }
       if (l.pTail->data.mssv == x)
       {
             cout << "Xoa thanh cong";
             RemoveLast(l);
             OutputList(l);
             return;
       }
       node* q = l.pHead->pnext;
       node* r = l.pHead;
       while (q != NULL)
       {
             if (q->data.mssv == x)
             {
                    r->pnext = q->pnext;
                    delete q;
                    cout << "Xoa thanh cong";
                    OutputList(l);
                    return;
             }
             r = q;
             q = q->pnext;
       }
       cout << "Khong ton tai";
}

void max(LIST l){
    int temp = l.pHead->data.GPA;
    for(NODE *k =l.pHead->pnext ; k != NULL ; k=k->pnext){
        if ( k->data.GPA > temp){
            temp =k->data.GPA;
        }
    }
    cout << "Gia tri max là: "<< temp << endl;

}

void min(LIST l){
    int temp = l.pHead->data.GPA;
    for(NODE *k =l.pHead->pnext ; k != NULL ; k=k->pnext){
        if ( k->data.GPA < temp){
            temp =k->data.GPA;
        }
    }
    cout << "Gia tri max là: "<< temp << endl;

}


int main(){
    
    LIST l;
    creatlist(l);
    while (true)
    {
        cout << "  ";
        cout << "  ";
        cout << "1. Xay dung cau truc du lieu co ten Sinh_Vien"<<endl;
        cout << "2. Cau truc node de luu tru sinh vien va cau truc dslk don"<<endl;
        cout << "3. Ham khoi tao DSlK va ham khoi tao node tu kieu Sinh_Vien"<<endl;
        cout << "4. Ham them sinh vien vao dau danh sach"<<endl;
        cout << "5. Ham them sinh vien vao cuoi danh sach"<<endl;
        cout << "6. Khoi tao phuong thuc nhap Sv thu cong tu ban phim"<<endl;
        cout << "7. random danh sach lien ket"<<endl;
        cout << "8. in ra DSLK cua sinh vien"<<endl;
        cout << "9. Ham tim danh sach sinh vien theo ID"<<endl;
        cout << "10. Ham tim sinh vien theo ten"<<endl;
        cout << "11. Ham tim sinh vien theo GPA"<<endl;
        cout << "12. Tim SV co GPA cao nhat"<<endl;
        cout << "13. Tim SV co GPA thap nhat"<<endl;
        cout << "14. Xuat 10 SV co GPA cao nhat"<<endl;
        cout << "15. viet ham xoa SV theo ID"<<endl;
        cout << "16. viet MENU"<<endl;
        cout << "17. Thoat"<< endl;
    
        int chon;
        cout << " Nhap lua chon: " << endl;
        cin >> chon;

            switch (chon)
            {
            case 1: case 2: case 3: case 4: case 5:{
                cout << " Câu truc da dc xay dung"<< endl;
                break;
            }
            case 6 :{
                InputList(l);
                break;
            }    
            
            case 7: {

                break;
            }
            case 8: {
                OutputList(l);
                break;
            }
            case 9: {
                findmssv(l);
                break;
            }
            case 10: {
                findname(l);
                break;
            }
            case 11: {
                findGPA(l);
                break;
            }
            case 12: {
                max(l);
                break;
            }
            case 13: {
                min(l);
                break;
            }
            case 14: {

                break;
            }
            case 15: {
                Xoa(l);
                break;
            }
            case 16: {
                cout << "Da viet Menu"<<endl;
                break;
            }
            default:{

                cout << "Tam Biet!!"<< endl;
                break;}
            }    
        
    }
    system("pause");
    return 0;
}
