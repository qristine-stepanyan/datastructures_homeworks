#include <iostream>

struct ListNode{
    int value;
    ListNode* next;
    ListNode(int x) : value(x), next(nullptr){}
};
void assort(ListNode* head){
    if(!head || !head->next){
        return;
    }
    ListNode* p1 = head;
    ListNode* p2 = head;

    while(p2->next && p2->next->next){
        p1 = p1->next;
        p2 = p2->next->next;
    }
    ListNode* half2 = p1->next;
    p1->next = nullptr;
    ListNode* prev = nullptr;
    ListNode* cur = half2;

    while(cur){
        ListNode* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    ListNode* half1 = head;
    half2 = prev;
    while(half2){
        ListNode* next1 = half1->next;
        ListNode* next2 = half2->next;

        half1->next = half2;
        half2->next = next1;
        half1 = next1;
        half2 = next2;
    }
}
int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    assort(head);
    while(head){
        std::cout<< head->value << "->";
        head = head->next;
    }
return 0;
}
