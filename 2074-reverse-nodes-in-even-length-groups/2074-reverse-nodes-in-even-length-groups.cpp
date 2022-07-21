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
            else{
                ListNode* pre=cur;
                // while(len-- && cur){
                //     cur=cur->next;
                // }
                return pre;
            }
            return NULL;
        }
        if(id%2 == 1){
            //continue;
             cout<<cur->val<<"\n";
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
            cout<<cur->val<<"\n";
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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        //iterative
        ListNode *cur=head;
        int len=0,id=1;
        while(cur){
            len++;
            cur=cur->next;
        }
        return solve(head,id,len);
        // ListNode *prev=NULL,*next=NULL;
        // cur=head;
        // while(cur){
        //    ListNode *odd=cur;
        //    int skip=id,cnt=0;
        //    //skip
        //    int rem1=len-(skip*(skip+1))/2;
        //    if(rem1>=0){
        //         while(cnt<skip){
        //            cnt++;
        //            prev=odd;
        //            odd=odd->next;
        //        }
        //        next=odd;
        //    }
        //    else{
        //        if(((len-(skip*(skip-1))/2))%2==0){
        //            //reverse
        //            ListNode *lastprev=NULL;
        //            while(odd){
        //                ListNode* tmp=odd->next;
        //                odd->next=lastprev;
        //                lastprev=odd;
        //                odd=tmp;
        //             }
        //            if(prev){
        //                prev->next=lastprev;
        //            }
        //        }
        //        return head;
        //    }
        //    if(next==NULL)
        //         return head;
        //    int reverse=id+1;cnt=0;
        //    int rem=len-((reverse*(reverse+1))/2);
        //    if(rem>=0){
        //        //reverse
        //        ListNode* pre=NULL;
        //        ListNode* even=next;
        //        int cnt=0;
        //        while(cnt<reverse){
        //            ListNode* tmp=even->next;
        //            even->next=pre;
        //            pre=even;
        //            even=tmp;
        //            cnt++;
        //        }
        //        if(prev)
        //            prev->next=pre;
        //        if(next)
        //            next->next=even;
        //        prev=;
        //        cur=even;
        //        id+=2;
        //    }
        //    else{
        //        if(((len-((reverse*(reverse-1))/2))%2)==0){
        //            //reverse
        //            ListNode *lastprev=NULL;
        //            while(next){
        //                ListNode* tmp=next->next;
        //                next->next=lastprev;
        //                lastprev=next;
        //                next=tmp;
        //             }
        //            if(prev){
        //                prev->next=lastprev;
        //            }
        //        }
        //        return head;
        //    }
        // }
        // return head;
    }
};