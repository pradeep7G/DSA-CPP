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
    ListNode* solve(ListNode* head,int id,int len){
        if(!head)
            return head;
        ListNode* cur=head;
        if((len-id) < 0){
            if(len%2==0){
                //reverse
                ListNode* prev=NULL;
                while(len-- && cur){
                    ListNode* nxt=cur->next;
                    cur->next=prev;
                    prev=cur;
                    cur=nxt;
                }
                return prev;
            }
            return cur;
        }
        if(id%2 == 1){
            int cnt=id;
            ListNode* prev=NULL;
            ListNode* pre=cur;
            while(cur && cnt){
                prev=cur;
                cur=cur->next;
                cnt--;
            }
            len-=id;
            id++;
            prev->next=solve(cur,id,len);
            return pre;
        }
        else{
            //reverse in even length;
            ListNode* prev=NULL;
            ListNode* pre=cur;
            int cnt=id;
            while(cur && cnt--){
                ListNode* nxt=cur->next;
                cur->next=prev;
                prev=cur;
                cur=nxt;
            }
            len-=id;
            id++;
            pre->next=solve(cur,id,len);
            return prev;
        }
        return head;
    }
    
    ListNode* practice(ListNode *head,int id,int len){
        if(!head)
            return NULL;
        ListNode* cur=head;
        if(len-id<0){
            //reverse if even else return head;
            if(len%2 == 0){
                ListNode* prev=NULL;
                while(len-- && cur){
                    ListNode* nxt=cur->next;
                    cur->next=prev;
                    prev=cur;
                    cur=nxt;
                }
                return prev;
            }
            return cur;
        }
        
        //reverse based on group
        if(id%2 == 0){
            ListNode* prev=NULL;
            ListNode* pre=cur;
            int count=id;
            while(count-- && cur){
                ListNode* nxt=cur->next;
                cur->next=prev;
                prev=cur;
                cur=nxt;
            }
            len-=id;
            id++;
            pre->next=practice(cur,id,len);
            return prev;
        }
        else{
            int count=id;
            ListNode* pre=cur;
            ListNode* prev=NULL;
            while(cur && count--){
                prev=cur;
                cur=cur->next;
            }
            len-=id;
            id++;
            prev->next=practice(cur,id,len);
            return pre;
        }
    }
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        //iterative
        ListNode *cur=head;
        int len=0,id=1;
        while(cur){
            len++;
            cur=cur->next;
        }
        return practice(head,id,len);
    }
};