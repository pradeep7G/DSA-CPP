/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool practice(ListNode *head){
        //do split into two lists and reverse one of them and move ptrs from start and compare
        //Or use stack to store nodes upto middle and after that start popping and check isPalindrome or not.
        
        /*
        ListNode *slow=head,*fast=head->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        bool isOdd=fast==NULL?true:false; // not needed in this case, but extra trivia
        ListNode *rev_start=slow->next;
        ListNode *prev=NULL;
        while(rev_start){
            ListNode* tmp=rev_start->next;
            rev_start->next=prev;
            prev=rev_start;
            rev_start=tmp;
        }
        ListNode *l1=head,*l2=prev;
        while(l1 && l2){
            if(l1->val != l2->val)
                return false;
            l1=l1->next;
            l2=l2->next;
        }
        return true;
        */
        
        //Method-2: Using Stack
        stack<ListNode *> st;
        ListNode *slow=head,*fast=head->next;
        st.push(head);
        while(fast && fast->next){
            slow=slow->next;
            st.push(slow);
            fast=fast->next->next;
        }
        if(fast==NULL)
            st.pop();
        ListNode *cur=slow->next;
        while(cur){
            if(cur->val != st.top()->val){
                return false;
            }
            else{
                cur=cur->next;
                st.pop();
            }
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        //find mid compare , reverse and return;
        // //OR traverse upto mid and store values in stack, and start popping from after mid, if at any point not equal return false, else true;
        // ListNode* slow=head,*fast=head->next;
        // while(fast && fast->next){
        //     slow=slow->next;
        //     fast=fast->next->next;
        // }
        // bool flag=true;
        // if(fast==NULL){
        //     flag=false;
        // }
        // ListNode* reverse=slow->next;
        // slow->next=NULL;
        // ListNode* cur=reverse;
        // ListNode* prev=NULL;
        // while(cur){
        //     ListNode* temp=cur->next;
        //     cur->next=prev;
        //     prev=cur;
        //     cur=temp;
        // }
        // ListNode *l1=head,*l2=prev;
        // bool ispal=false;
        // while(l1 && l2){
        //     if(l1->val != l2->val)
        //         return false;
        //     l1=l1->next;l2=l2->next;
        // }
        // return true;
        return practice(head);
        ListNode *slow=head,*fast=head->next;
        stack<ListNode *> st;
        st.push(head);
        while(fast && fast->next){
            slow=slow->next;
            st.push(slow);
            fast=fast->next->next;
        }
        if(fast==NULL){
            st.pop();
        }
        ListNode *cur=slow->next;
        while(cur && !st.empty()){
            if(cur->val != st.top()->val){
                return false;
            }
            else{
                cur=cur->next;
                st.pop();
            }
        }
        if(!st.empty())
            return false;
        return true;
    }
};