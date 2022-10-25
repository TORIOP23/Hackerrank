void postOrder(Node *root) {
    if(root == NULL) return;
    if(root -> left != NULL) {
        postOrder(root -> left);
        if(root -> left -> left == NULL && root -> left -> right == NULL)
            cout << root -> left -> data << " ";
    }
    if(root -> right != NULL) {
        postOrder(root -> right);
        if(root -> right -> left == NULL && root -> right -> right == NULL)
            cout << root -> right -> data << " ";
    }
    if(root -> left != NULL || root -> right != NULL)
        cout << root -> data << " ";
}
