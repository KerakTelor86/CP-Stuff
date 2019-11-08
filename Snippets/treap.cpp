struct node
{
    int val, prio, size;
    node *left, *right;
};

void clear_subtree(node *a)
{
    if(!a)
        return;
    clear_subtree(a->left);
    clear_subtree(a->right);
    delete a;
}

int subtree_size(node *a)
{
    if(!a)
        return 0;
    return a->size;
}

void update_size(node *a)
{
    a->size = 1 + subtree_size(a->left) + subtree_size(a->right);
}

int get_kth(node *a, int k)
{
    if(!a)
        return -1;
    int lsize = subtree_size(a->left);
    if(k > lsize)
        return get_kth(a->right, k - lsize - 1);
    if(k < lsize)
        return get_kth(a->left, k);
    return a->val;
}

int get_index(node *a, int k)
{
    if(!a)
        return 0;
    int lsize = subtree_size(a->left);
    if(k > a->val)
        return lsize + 1 + get_index(a->right, k);
    else 
        return get_index(a->left, k);
}

node *find(node *a, int value)
{
    if(!a)
        return 0;
    if(value < a->val)
        return find(a->left, value);
    if(value > a->val)
        return find(a->right, value);
    return a;
}

node *merge(node *a, node *b)
{
    if(!a)
        return b;
    if(!b)
        return a;
    if(a->prio > b->prio)
    {
        a->right = merge(a->right, b);
        update_size(a);
        return a;
    }
    else
    {
        b->left = merge(a, b->left);
        update_size(b);
        return b;
    }
}

pair<node*, node*> split(node *a, int s)
{
    if(!a)
        return {0, 0};
    if(a->val < s)
    {
        auto x = split(a->right, s);
        a->right = x.fi;
        update_size(a);
        return {a, x.se};
    }
    else
    {
        auto x = split(a->left, s);
        a->left = x.se;
        update_size(a);
        return {x.fi, a};
    }
}

pair<node*, node*> split_k(node *a, int k)
{
    if(!a)
        return {0, 0};
    int sz = subtree_size(a->left);
    if(sz < k)
    {
        auto x = split_k(a->right, k - sz - 1);
        a->right = x.fi;
        update_size(a);
        return {a, x.se};
    }
    else
    {
        auto x = split_k(a->left, k);
        a->left = x.se;
        update_size(a);
        return {x.fi, a};
    }
}

node *insert(node *a, int value)
{
    auto x = split(a, value);
    node *n = new node;
    n->val = value;
    n->prio = rand();
    n->size = 1;
    n->left = 0;
    n->right = 0;
    x.fi = merge(x.fi, n);
    return merge(x.fi, x.se);
}

node *erase(node *a, int value)
{
    int idx = get_index(a, value);
    auto x = split_k(a, idx);
    auto y = split_k(x.se, 1);
    clear_subtree(y.fi);
    return merge(x.fi, y.se);
}
