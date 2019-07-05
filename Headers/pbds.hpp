#ifndef PBDS_HPP_INCLUDED
#define PBDS_HPP_INCLUDED

#include <algorithm>

template <class T>
class pbds
{
    private:
        struct node
        {
            T val;
            std::size_t height,cnt;
            node *left,*right;
        };

        node *root;

        node *new_node(T val)
        {
            node *x=new node;
            x->val=val;
            x->left=nullptr;
            x->right=nullptr;
            x->cnt=1;
            x->height=1;
            return x;
        }

        std::size_t height(node *n)
        {
            if(!n)
                return 0;
            return n->height;
        }

        std::size_t count(node *n)
        {
            if(!n)
                return 0;
            return n->cnt;
        }

        int balance_factor(node *n)
        {
            if(!n)
                return 0;
            return height(n->left)-height(n->right);
        }

        void fix_props(node *n)
        {
            if(!n)
                return;
            n->height=std::max(height(n->left),height(n->right))+1;
            n->cnt=count(n->left)+count(n->right)+1;
        }

        node *l_rotate(node *n)
        {
            node *temp=n->right;
            n->right=temp->left;
            temp->left=n;
            fix_props(n);
            fix_props(temp);
            return temp;
        }

        node *r_rotate(node *n)
        {
            node *temp=n->left;
            n->left=temp->right;
            temp->right=n;
            fix_props(n);
            fix_props(temp);
            return temp;
        }

        node *balance(node *n)
        {
            int fact=balance_factor(n);
            if(fact>1)
            {
                if(balance_factor(n->left)<0)
                    n->left=l_rotate(n->left);
                n=r_rotate(n);
            }
            else if(fact<-1)
            {
                if(balance_factor(n->right)>0)
                    n->right=r_rotate(n->right);
                n=l_rotate(n);
            }
            return n;
        }

        node *insert(node *n,T val)
        {
            if(!n)
                return new_node(val);
            if(val<n->val)
                n->left=insert(n->left,val);
            else if(val>n->val)
                n->right=insert(n->right,val);
            else
                return n;
            fix_props(n);
            return balance(n);
        }

        node *erase(node *n,T val)
        {
            if(!n)
                return nullptr;
            if(val<n->val)
                n->left=erase(n->left,val);
            else if(val>n->val)
                n->right=erase(n->right,val);
            else
            {
                if(!n->left)
                {
                    node *temp=n->right;
                    delete n;
                    return temp;
                }
                if(!n->right)
                {
                    node *temp=n->left;
                    delete n;
                    return temp;
                }
                node *temp=n->left;
                while(temp->right)
                    temp=temp->right;
                n->val=temp->val;
                n->left=erase(n->left,n->val);
            }
            fix_props(n);
            return balance(n);
        }

        node *find_by_value(node *n,T val)
        {
            if(!n)
                return nullptr;
            if(val<n->val)
                return find_by_value(n->left,val);
            if(val>n->val)
                return find_by_value(n->right,val);
            return n;
        }

        node *find_by_index(node *n,std::size_t idx)
        {
            if(!n)
                return nullptr;
            int temp=count(n->left);
            if(idx<temp)
                return find_by_index(n->left,idx);
            if(idx>temp)
                return find_by_index(n->right,idx-temp-1);
            return n;
        }

        std::size_t order(node *n,T val)
        {
            if(!n)
                return 0;
            if(val<n->val)
                return order(n->left,val);
            if(val>n->val)
                return order(n->right,val)+count(n->left)+1;
            return count(n->left);
        }

        void freeall(node *n)
        {
            if(!n)
                return;
            freeall(n->left);
            freeall(n->right);
            delete n;
        }

    public:
        pbds()
        {
            root=nullptr;
        }

        ~pbds()
        {
            freeall(root);
        }

        void insert(const T val)
        {
            root=insert(root,val);
        }

        void erase(const T val)
        {
            root=erase(root,val);
        }

        void clear()
        {
            freeall(root);
            root=0;
        }

        const bool find(const T val)
        {
            return find_by_value(root,val);
        }

        const T find_by_index(const std::size_t idx)
        {
            return find_by_index(root,idx)->val;
        }

        const T min()
        {
            node *n=root;
            while(n->left)
                n=n->left;
            return n->val;
        }

        const T max()
        {
            node *n=root;
            while(n->right)
                n=n->right;
            return n->val;
        }

        const std::size_t order(const T val)
        {
            return order(root,val);
        }

        const std::size_t size()
        {
            return count(root);
        }

        const bool empty()
        {
            return count(root);
        }

        const T operator[](const std::size_t idx)
        {
            return find_by_index(idx);
        }
};

#endif // PBDS_HPP_INCLUDED
