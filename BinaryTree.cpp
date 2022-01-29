#include <iostream>
#define SIZE 100

using namespace std;

/*
Creates a binary tree, defines its methods & functions
*/
class BinaryTree
{
    public:
    int arr[SIZE];

    BinaryTree()
    {
        // popualting the array with MIN_INT as empty
        for (int i = 0; i < SIZE; i++)
        {
            arr[i] = INT_MIN;
        }
    }

    // to insert a left child
    int InsertLeftNode(int parent, int data)
    {
        // if index is negative
        if(parent < 1 || parent >= SIZE)
            return -1;

        // if index is empty
        else if(arr[parent] == INT_MIN)
            return -1;

        // if index is valid
        else
            arr[2 * parent] = data;

        return 1;
    }

    // to insert a right child
    int InsertRightNode(int parent, int data)
    {
        // if index is negative
        if(parent < 1 || parent >= SIZE)
            return -1;

        // if index is empty
        else if(arr[parent] == INT_MIN)
            return -1;

        // if index is valid
        else 
            arr[2 * parent + 1] = data;
        
        return 1;
    }

    // to insert the root
    void InsertRootNode(int data)
    {
        // inserting root node
        arr[1] = data;
    }

    // to delete a node
    int DeleteNode(int index)
    {
        // if index is negative
        if(index < 1 || index >= SIZE)
            return -1;
        
        // if node has children
        else if(arr[2 * index] != INT_MIN || arr[2 * index + 1] != INT_MIN)
            return -1;
        
        // if index is valid
        else
            arr[index] = INT_MIN;

        return 1;
    }

    // takes a node's index, returns its degree
    int ComputeNodeDegree(int index)
    {
        int degree = 0;

        // if index is empty or invalid
        if (index < 1 || index >= SIZE)
            return -1;

        if (arr[index] == INT_MIN)
            return -1;

        // left child found
        if (arr[2 * index] != INT_MIN)
            ++degree;
        
        // right child found
        if (arr[2 * index + 1] != INT_MIN)
            ++degree;

        return degree;
    }

    // takes an index, checks for leaves downwards
    void DisplayLeafNodes(int index)
    {
        if(index < 1 || index >= SIZE)
            return;

        else if (arr[index] == INT_MIN)
            return;

        // if no children found
        if (arr[2 * index] == INT_MIN && arr[2 * index + 1] == INT_MIN)
            cout << arr[index] << "  ";

        // if a child found
        if (arr[2 * index] != INT_MIN)
            this->DisplayLeafNodes(2 * index);

        if (arr[2 * index + 1] != INT_MIN)
            this->DisplayLeafNodes(2 * index + 1);
    }

    // takes a node index, returns its height
    int ComputeTreeHeight(int index)
    {
        if(index < 1 || index >= SIZE)
            return -1;

        else if (arr[index] == INT_MIN)
            return 0;

        else
        {
            // height of subtrees
            int left_height = this->ComputeTreeHeight(2 * index);
            int right_height = this->ComputeTreeHeight(2 * index + 1);

            if (left_height >= right_height)
                return left_height + 1;

            else
                return right_height + 1;
        }
    }

    // returns if tree is balanced
    bool isBalancedTree(int index)
    {
        if (arr[index] == INT_MIN)
            return true;
        
        // if diff of height of left & right subtrees is more than 1
        int left_height = this->ComputeTreeHeight(2 * index);
        int right_height = this->ComputeTreeHeight(2 * index + 1);

        if ((left_height - right_height) <= 1 && this->isBalancedTree(2 * index) && this->isBalancedTree(2 * index + 1))
            return true;

        return false;
    }
    
};

int main()
{
    BinaryTree *bt = new BinaryTree();

    bt->InsertRootNode(2);
    bt->InsertLeftNode(1, 7);
    bt->InsertRightNode(1, 5);
    bt->InsertLeftNode(2, 2);
    bt->InsertRightNode(2, 6);
    bt->InsertRightNode(3, 9);
    bt->InsertLeftNode(5, 5);
    bt->InsertRightNode(5, 11);
    bt->InsertLeftNode(7, 4);

    cout << "Leaves: ";
    bt->DisplayLeafNodes(1);
    cout << endl << endl;

    cout << "Height: " << bt->ComputeTreeHeight(1) << endl;

    cout << "Degree of 1st: " << bt->ComputeNodeDegree(1) << endl;

    cout << "Degree of 7th: " << bt->ComputeNodeDegree(7) << endl;
}