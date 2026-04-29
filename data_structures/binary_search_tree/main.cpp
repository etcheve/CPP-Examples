#include <algorithm>
#include <iostream>
#include <memory>
#include <queue>

struct Node {
    int value;
    std::unique_ptr<Node> left, right;
    explicit Node(int v) : value(v) {}
};

class BST {
public:
    void insert(int v) { insert(root_, v); }
    bool search(int v) const { return search(root_.get(), v); }
    void remove(int v) { remove(root_, v); }

    void inorder()   const { inorder(root_.get());   std::cout << "\n"; }
    void preorder()  const { preorder(root_.get());  std::cout << "\n"; }
    void postorder() const { postorder(root_.get()); std::cout << "\n"; }

    void level_order() const {
        if (!root_) return;
        std::queue<const Node*> q;
        q.push(root_.get());
        while (!q.empty()) {
            const Node* n = q.front(); q.pop();
            std::cout << n->value << " ";
            if (n->left)  q.push(n->left.get());
            if (n->right) q.push(n->right.get());
        }
        std::cout << "\n";
    }

    int height() const { return height(root_.get()); }

private:
    std::unique_ptr<Node> root_;

    void insert(std::unique_ptr<Node>& node, int v) {
        if (!node)          node = std::make_unique<Node>(v);
        else if (v < node->value) insert(node->left, v);
        else if (v > node->value) insert(node->right, v);
        // duplicate: ignore
    }

    bool search(const Node* node, int v) const {
        if (!node)          return false;
        if (v == node->value) return true;
        return v < node->value ? search(node->left.get(), v)
                               : search(node->right.get(), v);
    }

    // replaces node with its in-order successor
    void remove(std::unique_ptr<Node>& node, int v) {
        if (!node) return;
        if (v < node->value) {
            remove(node->left, v);
        } else if (v > node->value) {
            remove(node->right, v);
        } else {
            if (!node->left)       node = std::move(node->right);
            else if (!node->right) node = std::move(node->left);
            else {
                Node* successor = node->right.get();
                while (successor->left) successor = successor->left.get();
                node->value = successor->value;
                remove(node->right, successor->value);
            }
        }
    }

    void inorder(const Node* n)   const { if (!n) return; inorder(n->left.get());   std::cout << n->value << " "; inorder(n->right.get()); }
    void preorder(const Node* n)  const { if (!n) return; std::cout << n->value << " "; preorder(n->left.get());  preorder(n->right.get()); }
    void postorder(const Node* n) const { if (!n) return; postorder(n->left.get()); postorder(n->right.get()); std::cout << n->value << " "; }

    int height(const Node* n) const {
        if (!n) return 0;
        return 1 + std::max(height(n->left.get()), height(n->right.get()));
    }
};

int main() {
    BST tree;
    for (int v : {50, 30, 70, 20, 40, 60, 80})
        tree.insert(v);

    std::cout << "inorder (sorted): ";   tree.inorder();
    std::cout << "preorder:         ";   tree.preorder();
    std::cout << "postorder:        ";   tree.postorder();
    std::cout << "level-order:      ";   tree.level_order();
    std::cout << "height: "             << tree.height() << "\n";

    std::cout << "\nsearch 40: " << tree.search(40) << "\n";
    std::cout << "search 99: " << tree.search(99) << "\n";

    std::cout << "\nremove 30 (node with two children)\n";
    tree.remove(30);
    std::cout << "inorder: "; tree.inorder();

    std::cout << "\nremove 20 (leaf)\n";
    tree.remove(20);
    std::cout << "inorder: "; tree.inorder();

    std::cout << "\nremove 50 (root)\n";
    tree.remove(50);
    std::cout << "inorder: "; tree.inorder();
}
