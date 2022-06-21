/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root){
            return "()";
        }
        string s="(";
        s+=to_string(root->val);
        s+=serialize(root->left);
        s+=serialize(root->right);
        s+=")";
        return s;
    }

    // Decodes your encoded data to tree.
    int findindex(string s,int left,int right){
        if(left>right)
            return -1;
        int i=left;
        int cnt=0;
        for(i=left;i<=right;i++){
            if(s[i]=='(')
                cnt++;
            else if(s[i]==')')
            {
                cnt--;
                if(cnt==0)
                    return i;
            }
        }
        return -1;
    }
    TreeNode* deserialize_helper(string data,int left,int right){
        if(left>right)
            return NULL;
        left++;right--;
        if(left>right)
            return NULL;
        int tmp=left;
        string root_val="";
        while(tmp<right && (data[tmp]!=')' && data[tmp]!='(')){
            root_val+=data[tmp];
            tmp++;
        }
        TreeNode* root=new TreeNode(stoi(root_val));
        if(left==right)
            return root;
        int index=findindex(data,tmp,right);
        if(index!=-1){
            root->left=deserialize_helper(data,tmp,index);
            root->right=deserialize_helper(data,index+1,right);
        }
        return root;
    }
    TreeNode* deserialize(string data) {
        int left=0,right=data.length()-1;
        return deserialize_helper(data,left,right);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));