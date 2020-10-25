void abc(Node * root, int hd, map<int,int> &m)
{
    if(root==NULL)
    return;
    else
    {
        abc(root->left,hd-1,m);
        m[hd]+=root->data;
        abc(root->right,hd+1,m);
    }
}
vector <int> verticalSum(Node *root) 
{
map<int,int>m;
int h=0;
abc(root,h,m);
vector<int> v;
for(auto itr:m)
v.push_back(itr.second);

return v;
}