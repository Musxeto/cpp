#include <iostream>

using namespace std;

class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode() {
        value = 0;
        left = NULL;
        right = NULL;
    }

    TreeNode(int v) {
        value = v;
        left = NULL;
        right = NULL;
    }
};

class BST {
public:
    TreeNode* root;

    BST() {
        root = NULL;
    }

    bool isTreeEmpty() {
        return root == NULL;
    }

    TreeNode* insertRecursive(TreeNode* r, TreeNode* new_node) {
        if (r == NULL) {
            return new_node;
        }

        if (new_node->value < r->value) {
            r->left = insertRecursive(r->left, new_node);
        } else if (new_node->value > r->value) {
            r->right = insertRecursive(r->right, new_node);
        }

        return r;
    }

    TreeNode* iterativeSearch(int v) {
        if (root == NULL) {
            return root;
        } else {
            TreeNode* temp = root;
            while (temp != NULL) {
                if (temp->value == v) {
                    return temp;
                } else if (v < temp->value) {
                    temp = temp->left;
                } else {
                    temp = temp->right;
                }
            }
            return NULL;
        }
    }

    // Additional functions
    int height(TreeNode* r) {
        if (r == NULL) {
            return -1;
        } else {
            int lheight = height(r->left);
            int rheight = height(r->right);

            if (lheight > rheight) {
                return lheight + 1;
            } else {
                return rheight + 1;
            }
        }
    }

    void printLevelOrderBFS(TreeNode* r) {
        int h = height(r);
        for (int i = 0; i <= h; i++) {
            printGivenLevel(r, i);
        }
    }

    void printGivenLevel(TreeNode* r, int level) {
        if (r == NULL) {
            return;
        } else if (level == 0) {
        	
        } else {
            cout << r->value << " ";
            printGivenLevel(r->left, level - 1);
            printGivenLevel(r->right, level - 1);
        }
    }

    TreeNode* minValueNode(TreeNode* root) {
        TreeNode* temp = root;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        return temp;
    }

    TreeNode* maxValueNode(TreeNode* root) {
        TreeNode* temp = root;
        while (temp->right != NULL) {
            temp = temp->right;
        }
        return temp;
    }

    TreeNode* deleteNode(TreeNode* r, int v) {
        // base case
        if (r == NULL) {
            return NULL;
        }

        if (v < r->value) {
            r->left = deleteNode(r->left, v);
        } else if (v > r->value) {
            r->right = deleteNode(r->right, v);
        } else {
            if (r->left == NULL) {
                TreeNode* temp = r->right;
                delete r;
                return temp;
            } else if (r->right == NULL) {
                TreeNode* temp = r->left;
                delete r;
                return temp;
            } else {
                TreeNode* temp = minValueNode(r->right);
                r->value = temp->value;
                r->right = deleteNode(r->right, temp->value);
            }
        }
        return r;
    }
    
    
};

// Definition for recursiveSearch
TreeNode* recursiveSearch(TreeNode* r, int val) {
    if (r == NULL || r->value == val) {
        return r;
    } else if (val < r->value) {
        return recursiveSearch(r->left, val);
    } else if (val > r->value) {
        return recursiveSearch(r->right, val);
    }
    return NULL;
}

int main() {
    BST obj;
    int option, val;

    do {
        cout << "What operation do you want to perform? "
             << "Select Option number. Enter 0 to exit." << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Search Node" << endl;
        cout << "3. Delete Node" << endl;
        cout << "4. Print/Traversal BST values" << endl;
        cout << "5. Height of Tree" << endl;
        cout << "6. Clear Screen" << endl;
        cout << "0. Exit Program" << endl;
        cin >> option;

        TreeNode* new_node = new TreeNode();

        switch (option) {
            case 0:
                break;

            case 1:
                cout << "INSERT" << endl;
                cout << "Enter VALUE of TREE NODE to INSERT in BST: ";
                cin >> val;
                new_node->value = val;
                obj.root = obj.insertRecursive(obj.root, new_node);
                cout << endl;
                break;

            case 2:
                cout << "SEARCH" << endl;
                cout << "Enter VALUE of TREE NODE to SEARCH in BST: ";
                cin >> val;
                new_node = recursiveSearch(obj.root, val);
                if (new_node != NULL) {
                    cout << "Value found" << endl;
                } else {
                    cout << "Value NOT found" << endl;
                }
                break;

            case 3:
                cout << "DELETE" << endl;
                cout << "Enter VALUE of TREE NODE to DELETE in BST: ";
                cin >> val;
                new_node = obj.iterativeSearch(val);
                if (new_node != NULL) {
                    obj.deleteNode(obj.root, val);
                    cout << "Value Deleted" << endl;
                } else {
                    cout << "Value NOT found" << endl;
                }
                break;

            case 4:
                cout << "Print Level Order BFS: \n";
                obj.printLevelOrderBFS(obj.root);
                cout << endl;
                break;

            case 5:
                cout << "TREE HEIGHT" << endl;
                cout << "Height: " << obj.height(obj.root) << endl;
                break;

            case 6:
                system("cls"); // Use "clear" for Linux/Mac
                break;

            default:
                cout << "Enter Proper Option number " << endl;
        }
    } while (option != 0);

    return 0;
}

