#include <iostream>
#include <cstdlib>
using namespace std;

class BinarySearchTree
{
private:
    /*
    struct to store data about a node
    */
    struct tree_node
    {
        tree_node *left = NULL;
        tree_node *right = NULL;
        int data;
    };
    tree_node *root; //root node

public:
    BinarySearchTree()
    {
        root = NULL;
    }
    bool isEmpty() const { return root == NULL; }
    void print_inorder();
    void inorder(tree_node *);
    void print_preorder();
    void preorder(tree_node *);
    void print_postorder();
    void postorder(tree_node *);
    void insert(int);
    void remove(int);
    int search(int);
};

/*
inserts a node into the tree
*/
void BinarySearchTree::insert(int d)
{
    // new node
    tree_node *input = new tree_node;
    input->data = d;

    // 2 nodes to traverse
    tree_node *t = new tree_node;
    tree_node *parent;

    // if empty tree
    if (root == NULL)
        root = input;

    // if not empty tree
    else
    {
        t = root;

        // finding perfect leaf position
        while (t != NULL)
        {
            parent = t;

            if (d < t->data)
                t = t->left;

            else if (d > t->data)
                t = t->right;
        }

        // comparing again at the end
        if (d < parent->data)
            parent->left = input;

        else if (d > parent->data)
            parent->right = input;
    }
}

/*
searches & returns 1 if found
*/
int BinarySearchTree::search(int d)
{
    // if empty tree
    if (root == NULL)
    {
        return -1;
    }

    else
    {
        // traversing until found or last level reached
        tree_node *current = root;
        while (current != NULL && current->data != d)
        {
            if (d > current->data)
                current = current->right;
            else
                current = current->left;
        }

        if (current == NULL)
        {
            return -1;
        }
        else
        {
            return 1;
        }
    }
}

/*
removes the given value
*/
void BinarySearchTree::remove(int d)
{
    if (search(d) == -1)
    {
        return;
    }
    else
    {
        // traversing thru the tree
        tree_node *prev = NULL;
        tree_node *curr = root;

        while (curr != NULL && curr->data != d)
        {
            prev = curr;
            if (d > curr->data)
            {
                curr = curr->right;
            }
            else
            {
                curr = curr->left;
            }
        }
        //Three cases
        // If current node is a leaf
        if (curr->right == NULL && curr->left == NULL)
        {
            // attaching to parent
            if (prev->right == curr)
            {
                prev->right = NULL;
            }

            else
            {
                prev->left = NULL;
            }

            delete curr;
            return;
        }

        // if it has only one child
        else if (curr->right == NULL || curr->left == NULL)
        {
            // link the child to its parent
            if (prev->right == curr)
            {
                if (curr->right != NULL)
                {
                    prev->right = curr->right;
                }

                else
                {
                    prev->right = curr->left;
                }
            }

            else
            {
                if (curr->right != NULL)
                {
                    prev->left = curr->right;
                }
                else
                {
                    prev->left = curr->left;
                }
            }

            delete curr;
        }

        // If both childs exist
        else
        {
            //Smallest number in right subtree
            tree_node *n_prev = NULL;
            tree_node *n = curr->right;

            while (n->left != NULL)
            {
                n_prev = n;
                n = n->left;
            }

            // breaking the link
            n_prev->left = NULL;

            // swapping the data
            curr->data = n->data;
            delete n;
        }
    }
}

/*
prints in-order from root
*/
void BinarySearchTree::print_inorder()
{
    if (root != NULL)
        inorder(root);

    else
        cout << "Tree is empty.\n";
}

/*
recursive in-order traversal
*/
void BinarySearchTree::inorder(tree_node *p)
{
    if (p != NULL)
    {
        inorder(p->left);
        cout << p->data << "  ";
        inorder(p->right);
    }

    return;
}

/*
prints pre-order from root
*/
void BinarySearchTree::print_preorder()
{
    if (root != NULL)
        preorder(root);

    else
        cout << "Tree is empty.\n";
}

/*
recursive pre-order traversal
*/
void BinarySearchTree::preorder(tree_node *p)
{
    if (p != NULL)
    {
        cout << p->data << "  ";
        preorder(p->left);
        preorder(p->right);
    }

    return;
}

/*
prints post-order from root
*/
void BinarySearchTree::print_postorder()
{
    if (root != NULL)
        postorder(root);

    else
        cout << "Tree is empty.\n";
}

/*
recursive post-order traversal
*/
void BinarySearchTree::postorder(tree_node *p)
{
    if (p != NULL)
    {
        postorder(p->left);
        postorder(p->right);
        cout << p->data << "  ";
    }

    return;
}

int main()
{
    BinarySearchTree *bst = new BinarySearchTree();

    int input = 0;
    int data;

    while (input != -1)
    {
        cout << "\n\tMENU\n\n1 - Insert into Binary Search Tree\n";
        cout << "2 - Remove from Binary Search Tree\n";
        cout << "3 - Display Pre-Order Traversal\n";
        cout << "4 - Display Post-Order Traversal\n";
        cout << "5 - Display In-Order Traversal\n";
        cout << "-1 - Exit the program\n\n";
        cout << "Enter your choice number: ";

        cin >> input;

        switch (input)
        {
        case 1:
            cout << "\nEnter the integer to insert: ";
            cin >> data;

            bst->insert(data);
            break;

        case 2:
            cout << "\nEnter the integer to delete: ";
            cin >> data;

            bst->remove(data);
            break;

        case 3:
            cout << "\nPre-Order Traversed Tree:\n";
            bst->print_preorder();
            cout << endl;
            break;

        case 4:
            cout << "\nPost-Order Traversed Tree:\n";
            bst->print_postorder();
            cout << endl;
            break;

        case 5:
            cout << "\nIn-Order Traversed Tree:\n";
            bst->print_inorder();
            cout << endl;
            break;

        case -1:
            cout << "\nProgram exited successfully.\n";
            break;

        default:
            cout << "\nInvalid Input... Choose from the given menu.\n";
            break;
        }
    }
}