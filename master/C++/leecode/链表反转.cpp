#include <iostream>
struct LinkNode
{
    int num;
    LinkNode *next;
};

class Link
{
private:
    LinkNode *root;

public:
    Link();
    LinkNode *get_root();

    (/* args */);
    ~Link();
};

Link::Link(/* args */)
{
    root = new LinkNode;
    root->num = -1;
    root->next = NULL;
}

Link::~Link()
{
}

const LinkNode *Link::get_root() const
{
    return root;
}
