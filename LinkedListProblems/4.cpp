#include <iostream>

struct ListNode{
    int value;
    ListNode* next;
    ListNode(int x) : value(x),next(nullptr){}
};

void removeDup(ListNode* head){
    ListNode* cur = head;

    while(cur && cur->next){
        if (cur->value == cur->next->value){
            ListNode* dup = cur->next;
            cur->next = dup->next;
            delete dup;
        }
        else{
            cur = cur->next;
        }
    }
}
int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);
    head->next->next->next->next->next = new ListNode(4);

    removeDup(head);
    while(head){
        std::cout<< head->value<< "->";
        head = head->next;
    }
return 0;
}
