ListNode *p = head;
        ListNode *q = head;
        ListNode *pre = NULL;
        
        if(n != 1){
            for(int i=0;i<n-1;i++){
                q = q->next;
            }
        }
        while(q->next!=NULL){
            pre = p;
            p = p->next;
            q = q->next;
        }
        //if(!pre) return NULL;
        if(pre == NULL){
            p = head;
            head = head->next;
            free(p);
        }
        else{
             pre->next = p->next;
        }
       
        //free(p);
        return head;
