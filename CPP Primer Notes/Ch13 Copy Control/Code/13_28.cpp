#include <iostream>
#include <string>

using namespace std;

class TreeNode {
public:
    TreeNode(const string& v = string()) : value(v), count(0), left(nullptr), right(nullptr) {}
    TreeNode(const TreeNode& t) : value(t.value), count(t.count), left(nullptr), right(nullptr) {
        if(t.left)
            //recursively construct the left tree
            left = new TreeNode(*t.left);
        if(t.right)
            // recursively construct the right tree
            right = new TreeNode(*t.right);
    }
    TreeNode& operator=(const TreeNode&);
    ~TreeNode();

private:
    string value;
    int count;
    TreeNode *left;
    TreeNode *right;
};

TreeNode& TreeNode::operator=(const TreeNode& t) {
    value = t.value;
    count = t.count;

    TreeNode *tmp = nullptr;
    if(t.left)
        tmp = new TreeNode(*t.left);
    delete left;
    left = tmp;

    tmp = nullptr;
    if(t.right)
        tmp = new TreeNode(*t.right);
    delete right;
    right = tmp;
    return *this;
}

TreeNode::~TreeNode() {
    delete left;
    delete right;
}

class BinStrTree {
public:
    BinStrTree(const TreeNode& node = TreeNode()) : root(new TreeNode(node)), user(new size_t(0)) {}
    BinStrTree(const BinStrTree& tree) : root(new TreeNode(*tree.root)), user(tree.user) { ++*user; }
    BinStrTree& operator=(const BinStrTree& tree);
    ~BinStrTree();
private:
    TreeNode *root;
    size_t* user;
};

BinStrTree& BinStrTree::operator=(const BinStrTree& tree) {
    ++*tree.user;
    if(--*user == 0) {
        delete root;
        delete user;
    }

    root = tree.root;
    user = tree.user;

    return *this;
}
BinStrTree::~BinStrTree() {
    if(--*user == 0) {
        delete root;
        delete user;
    }
}

int main(int argc, char* argv[]) {
    TreeNode a();

    BinStrTree b();
    return 0;
}