/*A company stores its organizational hierarchy as a tree — the CEO at the top, managers below, and employees at the leaves.
Different departments need the hierarchy printed in different orders: HR wants each manager printed between their left and
right sub-teams, the archive department wants each manager printed before their sub-teams, the payroll department wants each
manager printed after all their sub-teams are listed, and the floor manager wants everyone printed level by level from top to bottom.
Given a binary tree representing the hierarchy, implement all four printing orders and display the result of each.*/

#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct TreeNode {
    string name;
    TreeNode* left;
    TreeNode* right;
    TreeNode(const string& n) : name(n), left(nullptr), right(nullptr) {}
};

// Build the tree level by level. Enter "-" when a position has no employee.
TreeNode* buildTree() {
    string name;
    cout << "Enter name of the CEO (root): ";
    cin >> name;
    if (name == "-") return nullptr;

    TreeNode* root = new TreeNode(name);
    queue<TreeNode*> q; // queue holds nodes whose children are still to be read
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        cout << "Enter LEFT child of " << current->name << " (- for none): ";
        cin >> name;
        if (name != "-") {
            current->left = new TreeNode(name);
            q.push(current->left);
        }

        cout << "Enter RIGHT child of " << current->name << " (- for none): ";
        cin >> name;
        if (name != "-") {
            current->right = new TreeNode(name);
            q.push(current->right);
        }
    }
    return root;
}

// Left -> Root -> Right (HR)
void inorder(TreeNode* node) {
    if (node == nullptr) return;
    inorder(node->left);
    cout << node->name << " ";
    inorder(node->right);
}

// Root -> Left -> Right (Archive)
void preorder(TreeNode* node) {
    if (node == nullptr) return;
    cout << node->name << " ";
    preorder(node->left);
    preorder(node->right);
}

// Left -> Right -> Root (Payroll)
void postorder(TreeNode* node) {
    if (node == nullptr) return;
    postorder(node->left);
    postorder(node->right);
    cout << node->name << " ";
}

// Level by level using a queue (Floor manager)
void levelOrder(TreeNode* root) {
    if (root == nullptr) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        cout << current->name << " ";
        if (current->left) q.push(current->left);   // children wait behind the current level
        if (current->right) q.push(current->right);
    }
}

void freeTree(TreeNode* node) {
    if (node == nullptr) return;
    freeTree(node->left);
    freeTree(node->right);
    delete node;
}

int main() {
    TreeNode* root = buildTree();

    if (root == nullptr) {
        cout << "Tree is empty." << endl;
        return 0;
    }

    cout << "\nInorder   (HR)            : ";
    inorder(root);
    cout << "\nPreorder  (Archive)       : ";
    preorder(root);
    cout << "\nPostorder (Payroll)       : ";
    postorder(root);
    cout << "\nLevel order (Floor manager): ";
    levelOrder(root);
    cout << endl;

    freeTree(root);
    return 0;
}
