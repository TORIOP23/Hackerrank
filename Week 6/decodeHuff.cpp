void decode_huff(node * root, string s) {
    int idx = 0;
    while(idx < s.size()) {
        node* walk = root;
        while(walk -> left != NULL || walk -> right != NULL) {
            if(s[idx] == '0') walk = walk -> left;
            else walk = walk -> right;
            idx++;
        }
        cout << walk -> data;
    }
}
