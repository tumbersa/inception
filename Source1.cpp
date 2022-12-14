#include <stddef.h>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Node {
    int info;
    Node* next;
};
//?????????????
Node* initList(int x)
{
    Node* p = new Node;
    p->info = x;
    p->next = nullptr;
    return p;
}
//????? ???????? ???? int
Node* search(Node* p, int x) {
    Node* f = nullptr;
    Node* q = p;
    while (q) {
        if (q->info == x) {
            f = q;
        }
        q = q->next;
    }
    return f;
}
//?????????? ????????? ? ????????? ??????
void add(Node* p, int x) {
    Node* q = initList(x);
    Node* r = p;

    while (r->next) {
        r = r->next;
    }
    r->next = q;
}
//??????
int getSize(Node* p) {
    Node* q = p;
    int size = 0;
    while (q->next) {
        size += 1;
        q = q->next;
    }

    return size + 1;
}
//??????
void print(Node* p)
{
    Node* q = p;
    if (getSize(p) == 1) {
        cout << p->info;
    }
    else {
        while (q) {
            cout << q->info << " ";
            q = q->next;
        }
    }
    cout << endl;
}
//???????? ?? ???????
bool isEmpty(Node* p)
{
    return p;
}

//?????????? ????????????? ????????
int max(Node* p) {
    Node* q = p;
    int max = p->info;
    if (getSize(p) == 1) return max;
    else {
        while (q) {
            if (q->info > max) max = q->info;
            q = q->next;
        }
        return max;
    }
}

void sortDescend(Node** p) {
    if (getSize(*p) == 1) {
        return;
    }
    else {
        Node* q = *p;
        Node* x;
        int l = getSize(*p);
        for (int i = 0; i < l; i++) {
            q = *p; Node* m = q;
            for (int j = 0; j < l - i - 1; j++) {
                cout << j << endl;
                if (abs(q->info) < abs(q->next->info)) {
                    
                    if (j == 0) {
                        x = q->next;
                        q->next = x->next;
                        x->next = q;
                        *p = x;
                        cout <<" (*p)->info= "<< (*p)->info << " q->info= " << q->info << " x->info= " << x->info << " j= " << j << endl;
                        print(*p);
                        cout << endl;
                    }
                    else {
                        x = q->next;
                        q->next = x->next;
                        x->next = q;
                        m->next = x;
                        cout <<" m->info= "<<m->info << " q->info= " << q->info << " x->info= " << x->info << " j= " << j << endl;
                        print(*p);
                        cout << endl;
                    }
                    if (j == 0) m = x;
                        q = x;
                }
                    q = q->next; 
                if (j > 0) m = m->next;
            }
        }

    }
}


void addAfter(Node* f, Node* q) {
    if (!f) {
        return;
    }
    q->next = f->next;
    f->next = q;
}
void delFirst(Node** p) {
    Node* q = *p;
    *p = (*p)->next;
    q->next = NULL;
    delete q;
}
void clear(Node** p) {
    while ((*p)->next) {
        delFirst(p);
    }

    (*p)->info = NULL;
}
void pop(Node* p, Node* f) {
    if (f == nullptr) {
        return;
    }
    Node* q = p;

    while (q->next != f) {
        q = q->next;
    }
    q->next = f->next;
    f->next = nullptr;
    delete f;
}
void insertFront(Node** p, int x) {
    Node* q = new Node();
    q->info = x;
    q->next = *p;
    *p = q;
}
void addaf(Node* p, Node* q)
{
    Node* m = p;
    for (int i = 0; i < getSize(p) - 1; i++)
        if (abs(q->info) < abs(m->next->info))
        {
            m = m->next;
        }
        else break;

    addAfter(m, q);

}
int main()
{
    setlocale(LC_ALL, "Russian");
    Node* p; int x, k;

    cout << "??????? ?????????? ????????? ?????? ? ?????" << endl;
    cin >> k >> x;
    if (k == 1) {
        p = initList(x);
        clear(&p);
        cout << "??????? ?????" << endl;
        cin >> x;
        Node* qs = initList(x);
        print(qs);
        clear(&qs);
    }
    else {
        p = initList(x);
        for (int i = 0; i < k - 1; i++) {
            cin >> x;
            add(p, x);
        }
        print(p);
        int m = max(p);
        if (p == search(p, max(p))) {
            delFirst(&p);
        }
        else {
            pop(p, search(p, max(p)));
        }
        print(p);
        sortDescend(&p);
        print(p);
        cout << "??????? ?????" << endl;
        cin >> x;
        Node* q = initList(x);
        if (abs(q->info) > abs(p->info)) {
            insertFront(&p, q->info);
        }
        else {
            addaf(p, q);
        }
        print(p);
        clear(&p);
    }
}