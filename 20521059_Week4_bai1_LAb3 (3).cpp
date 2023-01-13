#include <bits/stdc++.h>     // Đậu Đình Quang Anh - 20521059
#include <cstdlib>          
#include <ctime>           

using namespace std;
struct node
{
    int data;
    node *pleft;
    node *pright;

};
struct tree
{
    node *root;
};

node *createnode(int x)
{
    node *p = new node;
    if (p == NULL) return NULL;
    p->data =x;
    p->pleft = NULL;
    p->pright = NULL;
    return p;
}
void createtree(tree &t)
{
    t.root = NULL;
}
void addnode(tree &t, node *p)
{
    if (t.root == NULL)
    {
        t.root = p;
    }
    else
    {
        node *i = t.root;
        node *vt = NULL;
        while ( i != NULL)
        {
            vt = i;
            if (p->data < i->data)
            {
                i = i->pleft;
            }
            else if ( p->data > i->data)
            {
                i = i->pright;
            }
            else break;
        }
        if ( p->data < vt->data)
        {
            vt->pleft = p;
        }
        else if ( p->data > vt ->data)
        {
            vt->pright = p;
        }
    }
}


void in_node(node *p)
{
    cout<<"\t\t";
    if (p->pleft != NULL)
        cout<<"<L: "<< p->pleft <<">";
    else cout<<"<L: null>";
    cout<<" ("<< p->data <<"~"<<p<<") ";

    if (p->pright != NULL)
        cout<<"<R: "<< p->pright <<"> \n";
    else cout<<"<R: null> \n";
}
bool search_x (tree t, int x)
{
    node *i = t.root;
    while (i != NULL)
    {
        if (x == i->data) return true;
        else if (x < i->data) i = i->pleft;
        else  i = i->pright;
    }
    return false;

}
void delete_tree(node *&t)
{
    if (t !=NULL)
    {
        delete_tree(t->pleft);
        delete_tree(t->pright);
        delete t;
        t = NULL;
    }
}
void NLR(node *t)
{

    if (t != NULL)
    {
        cout << t->data <<" "<< t<<"\t\t\t pLeft: "<<t->pleft<<"\t\t\t pRight: "<<t->pright<<"\n";
        NLR(t->pleft);
        NLR(t->pright);
    }
}
void Duyet_nhanh_NLR(node *t)
{
    if (t != NULL)
    {
        cout <<"pLeft: "<<t->pleft<<"\t pRight: "<<t->pright<<"\n";
        Duyet_nhanh_NLR(t->pleft);
        Duyet_nhanh_NLR(t->pright);
    }

}
void LNR(node *t)
{
    if (t != NULL)
    {
        LNR(t->pleft);
        cout << t->data <<" "<< t<<"\t pLeft: "<<t->pleft<<"\t pRight: "<<t->pright<<"\n";
        LNR(t->pright);
    }
}
void LRN(node *t)
{
    if (t != NULL)
    {
        LRN(t->pleft);
        LRN(t->pright);
        cout << t->data <<" "<< t<<"\t pLeft: "<<t->pleft<<"\t pRight: "<<t->pright<<"\n";
    }
}

void Find_Replace(node *&p, node *&q)
{
    if (q->pleft)
        Find_Replace(p, q->pleft);
    else
    {
        p->data = q->data;
        p = q;
        q = q->pright;
    }
}
void DeleteNode(node *&t, int x)
{
    if (t)
    {
        if (x > t->data)
            DeleteNode(t->pright, x);
        else if (x < t->data)
            DeleteNode(t->pleft, x);
        {
            node *p = t;
            if (!t->pleft)
                t = t->pright;
            else if (!t->pright)
                t = t->pleft;
            else
                Find_Replace(p, t->pright);
            delete p;
            p = NULL;
        }
    }
    else
    {
        cout << "Not found!\n";
    }
}
int tong(node *i)
{
    if (i != NULL)
    {
        return i->data + tong(i->pleft) + tong(i->pright);
    }
    else return 0;
}
int dem_all_node(node *t)
{
    if(t==NULL) return 0;
    else return 1+dem_all_node(t->pleft)+dem_all_node(t->pright);
}
int dem_node_chan(node *t)
{
    if(t==NULL) return 0;
    else if ( t->data %2==0) return 1+dem_node_chan(t->pleft)+dem_node_chan(t->pright);
        else return dem_node_chan(t->pleft)+dem_node_chan(t->pright);
}
int tong_node_chan(node *t)
{
    if(t==NULL) return 0;
    else if ( t->data %2==0) return t->data+ tong_node_chan(t->pleft)+ tong_node_chan(t->pright);
        else return  tong_node_chan(t->pleft)+ tong_node_chan(t->pright);
}
int dem_node_la(node *t)
{
    if (t==NULL) return 0;
    if (t->pleft == NULL && t->pright==NULL) return 1;
    return dem_node_la(t->pleft) + dem_node_la(t->pright);
}
int dem_node_nho(node *t, int x)
{
    if (t==NULL) return 0;
    else if (t->data >= x) return dem_node_nho(t->pright,x) + dem_node_nho(t->pleft,x);
    else return 1 + dem_node_nho(t->pright,x) + dem_node_nho(t->pleft,x);
}
int dem_node_lon(node *t, int x)
{
    if (t==NULL) return 0;
    else if (t->data <= x ) return dem_node_lon(t->pright,x)+dem_node_lon(t->pleft,x);
    else return 1 + dem_node_lon(t->pright,x) + dem_node_lon(t->pleft,x);
}
int dem_node_x_node_y(node *t, int x, int y)
{
    return dem_node_lon(t,x)-(dem_all_node(t)-dem_node_nho(t,y));
}
node *max_node(tree t)
{
    node *i=t.root;
    while(i->pright!=NULL)
    {
        i = i->pright;
    }
    return i;
}
node *min_node(tree t)
{
    node *i=t.root;
    while(i->pleft!=NULL)
    {
        i = i->pleft;
    }
    return i;
}
int menu()
{
    cout<<"\n1: Them node thu cong";
    cout<<"\n2: Them node tu dong";
    cout<<"\n3: Duyet cay theo NLR";
    cout<<"\n4: Duyet cay theo LNR";
    cout<<"\n5: Duyet cay theo LRN";
    cout<<"\n6: Tim x trong cay";
    cout<<"\n7: Xoa x khoi cay";
    cout<<"\n8: Xoa cay";
    cout<<"\n9: Dem node trong cay";
    cout<<"\n10: Dem node la trong cay";
    cout<<"\n11 In node nhanh NLR";
    cout<<"\n12: Dem so node nho hon x";
    cout<<"\n13: Dem so node lon hon x";
    cout<<"\n14: Dem so node lon hon x nho hon y";
    cout<<"\n15: so sanh cau 7 va 8";
    cout<<"\n16: So sanh so luong chan le trong cay";
    cout<<"\n17: Tinh tong cac node trong cay";
    cout<<"\n18: Tinh tong cac node chan trong cay";
    cout<<"\n19: Tinh tong cac node le trong cay";
    cout<<"\n20: Tim max node trong cay";
    cout<<"\n21: Tim min node trong cay";
    cout<<"\n0: Thoat";
    cout<<"\n---------------------------------------------";
    cout<<"\nNhap lua chon: ";
    int choose ; cin>>choose;
    return choose;
}
int main()
{
    tree t;
    createtree(t);
    int choice;
    srand(time(NULL));
    bool flag=true, flag_1= true;
    int x,n,y;
    while (flag == true)
    {
        choice = menu();
        switch(choice)
        {
            case 1:
                while(true)
                {
                    cin>>x;
                    if (x==0) break;
                    addnode(t,createnode(x));
                }
                break;
            case 2:
                srand(time(NULL));
                int n ;
                n = 10 + rand()%(10+1);
                for (int i=1;i<=n;i++)
                {
                    int res = rand() % (1358 + 358 + 1) - 358;
                    node* q = createnode(res);
                    addnode(t,q);
                }
                break;
            case 3:
                NLR(t.root);
                break;
            case 4:
                LNR(t.root);
                break;
            case 5:
                LRN(t.root);
                break;
            case 6:
                cout<<"Nhap gia tri can tim: ";
                cin>>x;
                if (search_x(t,x)==true ) cout<< x <<" co trong cay \n";
                    else cout<<x <<" khong co trong cay \n";
                break;
            case 7:
                cout<<"Nhap gia tri can xoa: ";
                cin>>x;
                if ( search_x(t,x) == true ) DeleteNode(t.root,x);
                else cout<<x<<" khong tim thay  \n";
                break;
            case 8:
                delete_tree(t.root);
                break;
            case 9:
                cout<<"Cay co "<<dem_all_node(t.root)<<" node\n";
                break;
            case 10:
                cout<<"Cay co "<<dem_node_la(t.root)<<" node la \n";
                break;
            case 11:
                Duyet_nhanh_NLR(t.root);
                break;
            case 12:
                cin>>x;
                cout<<dem_node_nho(t.root,x);
                break;
            case 13:
                cin>>x;
                cout<<dem_node_lon(t.root,x);
                break;
            case 14:
                cin>>x>>y;
                cout<<dem_node_x_node_y(t.root,x,y);
                break;
            case 15:
                cout<<"Tree co "<<dem_all_node(t.root)<<" node\n";
                cout<<"Trong do co "<<dem_node_la(t.root)<<" node la \n";
                break;
            case 16:
                cout<<"So node chan: "<< dem_node_chan(t.root);
                cout<<"So node le:   "<< dem_all_node(t.root)- dem_node_chan(t.root);
                break;
            case 17:
                cout<<"Tong nhac: "<<tong(t.root);
                break;
            case 18:
                cout<<"Tong node chan: "<<tong_node_chan(t.root);
                break;
            case 19:
                cout<<"Tong node le:   "<<tong(t.root)- tong_node_chan(t.root);
                break;
            case 20:
                cout<<"node lon nhat: "<<max_node(t)<<" : "<<max_node(t)->data;
                break;
            case 21:
                cout<<"node nho nhat: "<<min_node(t)<<" : "<<min_node(t)->data;
                break;
            case 0:
                delete_tree(t.root);
                flag = false;
                break;
        }
    }
    return 0;
}
