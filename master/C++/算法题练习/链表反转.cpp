#include <functional>
#include <iostream>

struct LinkNode {
    int num;
    LinkNode *next;
};

class Link {
  private:
    LinkNode *root;

  public:
    Link();
    const LinkNode *get_root() const;
    void seq_reverse();
    void reverse();
    void tarvel();
    bool push_node(const LinkNode &node);

    ~Link();
};

Link::Link(/* args */) {
    root = new LinkNode;
    root->num = -1;
    root->next = NULL;
}

Link::~Link() {
    LinkNode *node = this->root->next;
    LinkNode *prev_node = node;
    std::cout << "delete num:";
    while (node->next) { // 至少有一个节点
        node = node->next;
        std::cout << prev_node->num << " ";
        delete prev_node;
        prev_node = node;
    }
    std::cout << prev_node->num;
    delete prev_node;
    delete this->root;
}

const LinkNode *Link::get_root() const { return root; }

void Link::seq_reverse() { // 顺序反转链表
    const LinkNode *first_node = get_root()->next;
    if (first_node->next) { // 至少有两个数据节点
        LinkNode *a, *b, *c;

        a = const_cast<LinkNode *>(first_node);
        b = a->next;
        a->next = NULL;
        c = b->next;
        while (c != NULL) {
            b->next = a;
            a = b;
            b = c;
            c = c->next;
        }
        b->next = a;
        this->root->next = b;
    }

    return;
}

void Link::reverse() { // 递归法反转链表
    LinkNode *node = this->root->next;

    std::function<LinkNode* (LinkNode*)> inner_reverse;
    inner_reverse = [&](LinkNode *node)->LinkNode* {
        if (!node->next) { // 如果node->next为NULL。那么说明达到了链表尾部
            this->root->next = node;
            return node;
        }

        LinkNode *get_node = inner_reverse(node->next);
        get_node->next = node;
        return node;
    };

    if(!(node->next)) return;
    node = inner_reverse(node);
    node->next = NULL;

    return;
}

void Link::tarvel() { // 遍历链表
    std::cout << "tarvel:";
    LinkNode *node = this->root->next;
    if (!node)
        return; // 存在至少一个数据节点
    while (node) {
        std::cout << node->num << " ";
        node = node->next;
    }
    std::cout << "\n";
}

bool Link::push_node(const LinkNode &add_node) {
    LinkNode *node = this->root;
    while (node->next) {
        node = node->next;
    }
    LinkNode *new_node = new LinkNode;
    new_node->num = add_node.num;
    new_node->next = NULL;
    node->next = new_node;
}

int main() {
    Link l;
    for (int i = 0; i < 10; i++) {
        LinkNode n = LinkNode{i, NULL};
        l.push_node(n);
    }
    l.tarvel();
    // l.seq_reverse();
    l.reverse();
    l.tarvel();

    return 0;
}