#include <iostream>
#include <iomanip>
using namespace std;

struct binaryTree
{
    int val;
    struct binaryTree *l; //left branch
    struct binaryTree *r; //right branch
};

struct binaryTree *createtree(int value)
{
    struct binaryTree *n = new struct binaryTree[1];
    n->l = NULL;
    n->r = NULL;
    n->val = value;
    return n;
}

void insertion(struct binaryTree *t, int key)
{

    struct binaryTree *node = NULL;

    while (t != NULL)
    {
        node = t;
        if (key == t->val)
        {
            return;
        }
        else if (key < t->val)
        {
            t = t->l;
        }
        else
        {
            t = t->r;
        }
    }

    if (key < node->val)
    {
        node->l = createtree(key);
    }
    else
    {
        node->r = createtree(key);
    }

    // we cannot do:
    // t = createtree(key)
    // as t is "NULL" and is not pointed by previous pointer as it does not point any address
    // so we use previous node reference to create a new node
}

int Height(struct binaryTree *p)
{
    int x, y;
    if (p == NULL)
        return 0;
    x = Height(p->l);
    y = Height(p->r);

    return x > y ? x + 1 : y + 1;
}

struct binaryTree* Inorder_pred(struct binaryTree* p){
    while(p!=NULL && p->r!=NULL){
        p = p->r;
    }
    return p;
}

struct binaryTree* Inorder_succ(struct binaryTree* p){
    while(p!=NULL && p->l!=NULL){
        p = p->l;
    }
    return p;
}

struct binaryTree *deletion(struct binaryTree *p, int key)
{
    struct binaryTree* q;

    if (p == NULL)
    {
        return NULL;
    }
    if (p->l == NULL && p->r == NULL)
    { // p is leaf node
        free(p);
        return NULL;
    }

    if (key < p->val)
    {
        p->l = deletion(p->l, key);
    }
    else if (key > p->val)
    {
        p->r = deletion(p->r, key);
    }
    else
    {   // the deleted element will be replaced by its inorder predecessor or successor
        if (Height(p->l) > Height(p->r))
        {
            q = Inorder_pred(p->l);
            p->val = q->val;
            p->l = deletion(p->l, q->val);
        }
        else
        {
            q = Inorder_succ(p->r);
            p->val = q->val;
            p->r = deletion(p->r, q->val);
        }

        // we cannot free(q), since then the location of inorder_pred / inorder_succ will not exist
    }

    return p;
}

// -----------------------------------------------

class queue
{
private:
    int size;
    struct binaryTree **arr; // to make dynamic array to store pointers of binarytree
    int r = 0;
    int f;

public:
    queue(int len)
    {
        f = 0;
        r = 0;
        size = len;
        arr = new struct binaryTree *[size]; // stores pointers to binarytrees
    }

    int isEmpty()
    {
        if (f == r)
        {
            return 1;
        }
        return 0;
    }

    int isFull()
    {
        if (r == size - 1)
        {
            return 1;
        }
        return -1;
    }

    void enqueue(struct binaryTree *node)
    {
        if (r < size - 1)
        {
            r++;
            arr[r] = node; // storing the pointer
        }
        else
        {
            cout << "Queue is full" << endl;
        }
    }

    struct binaryTree *dequeue()
    {
        if (f < r)
        {
            f++;
            struct binaryTree *a = arr[f]; // taking the pointer
            return a;
        }
        else
        {
            cout << "Queue is empty" << endl;
        }
    }
};

void levelorder(struct binaryTree *p, queue q)
{
    q.enqueue(p);

    while (!q.isEmpty())
    {
        struct binaryTree *node = q.dequeue();
        if (node != NULL)
        {

            cout << node->val << " ";
            struct binaryTree *left = node->l;
            struct binaryTree *right = node->r;

            if (left != NULL)
            {
                q.enqueue(left);
            }
            if (right != NULL)
            {
                q.enqueue(right);
            }
            // we can do it opposite for traversing from opposite side
        }
    }
}

// -----------------------------------------------

int main()
{

    //EXAMPLE
    //constructing a binaryTree structure using createtree function

    queue q1(12);
    queue q2(12);

    struct binaryTree *p = createtree(4);

    insertion(p, 32);
    insertion(p, 25);
    insertion(p, 12);
    insertion(p, 16);
    insertion(p, 45);
    insertion(p, 13);
    insertion(p, 91);
    insertion(p, 52);

    levelorder(p, q1);

    deletion(p, 32);

    cout<<endl;
    levelorder(p,q2);

    // only changing the value while deletion. The pointer points the same location only. So, p is still root node

    return 0;
}