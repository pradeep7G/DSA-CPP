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
        if(!root)
            return "()";
        string res="(";
        res+=to_string(root->val);
        res+=serialize(root->left);
        res+=serialize(root->right);
        res+=")";
        return res;
    }

    // Decodes your encoded data to tree.
    int findindex(string data,int left,int right){
        if(left>right)
            return -1;
        int i=left;
        int cnt=0;
        for(i=left;i<=right;i++)
        {
            if(data[i]=='(')
                cnt++;
            else if(data[i]==')')
            {
                cnt--;
                if(cnt==0)
                    return i;
            }
        }
        return -1;
    }
    TreeNode* deserialize_helper(string data,int left,int right){
        left++,right--;
        if(left>right)
            return NULL;
        int tmp=left;
        string num="";
        while(tmp<=right && data[tmp]!='(' && data[tmp]!=')'){
            num+=data[tmp];
            tmp++;
        }
        int index=findindex(data,tmp,right);
        TreeNode *root=new TreeNode(stoi(num));
        root->left=deserialize_helper(data,tmp,index);
        root->right=deserialize_helper(data,index+1,right);
        return root;
    }
    TreeNode* deserialize(string data) {
        return deserialize_helper(data,0,data.size()-1);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;