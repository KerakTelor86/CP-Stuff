#include <stdio.h>
#include <malloc.h>

typedef struct node
{
    int val,hgt;
    struct node *left,*right;
} node;

int max(int a,int b)
{
    return a>b?a:b;
}

node *new_node(int x)
{
    node *temp=(node*)malloc(sizeof(node));
    temp->val=x;
    temp->hgt=1;
    temp->left=0;
    temp->right=0;
    return temp;
}

int height(node *root)
{
    if(!root)
        return 0;
    return root->hgt;
}

void upd_hgt(node *root)
{
    if(!root)
        return;
    root->hgt=max(height(root->left),height(root->right))+1;
}

int bal_factor(node *root)
{
    if(!root)
        return 0;
    return height(root->left)-height(root->right);
}

node *l_rot(node *root)
{
    node *temp=root->right;
    root->right=temp->left;
    temp->left=root;
    upd_hgt(root);
    upd_hgt(temp);
    return temp;
}

node *r_rot(node *root)
{
    node *temp=root->left;
    root->left=temp->right;
    temp->right=root;
    upd_hgt(root);
    upd_hgt(temp);
    return temp;
}

node *bal(node *root)
{
    int fact=bal_factor(root);
    if(fact>1)
    {
        if(bal_factor(root->left)<0)
            root->left=l_rot(root->left);
        root=r_rot(root);
    }
    else if(fact<-1)
    {
        if(bal_factor(root->right)>0)
            root->right=r_rot(root->right);
        root=l_rot(root);
    }
    return root;
}

node *add(node *root,int x)
{
    if(!root)
    {
        root=new_node(x);
        return root;
    }
    else if(x<root->val)
        root->left=add(root->left,x);
    else
        root->right=add(root->right,x);
    upd_hgt(root);
    return bal(root);
}

node *src(node *root,int x)
{
    if(!root)
        return 0;
    else if(x<root->val)
        return src(root->left,x);
    else if(x>root->val)
        return src(root->right,x);
    else
        return root;
}

node *del(node *root,int x)
{
    if(!root)
        return 0;
    else if(x<root->val)
        root->left=del(root->left,x);
    else if(x>root->val)
        root->right=del(root->right,x);
    else
    {
        if(!root->left)
        {
            node *temp=root->right;
            free(root);
            return temp;
        }
        else if(!root->right)
        {
            node *temp=root->left;
            free(root);
            return temp;
        }
        node *m=root->left;
        while(m->right)
            m=m->right;
        root->val=m->val;
        root->left=del(root->left,m->val);
    }
    upd_hgt(root);
    return bal(root);
}

void inorder(node *root)
{
    if(!root)
        return;
    inorder(root->left);
    printf("%d %d %d\n",root->val,root->hgt,bal_factor(root));
    inorder(root->right);
}

int main()
{
    node *root;
    root=add(root,1);
    root=add(root,2);
    root=add(root,3);
    root=add(root,4);
    root=add(root,5);
    root=add(root,6);
    root=add(root,7);
    inorder(root);
    putchar('\n');
    root=del(root,1);
    root=del(root,2);
    root=del(root,3);
    inorder(root);
}
