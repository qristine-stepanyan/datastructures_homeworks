#include <iostream>

struct ListNode{
    int value;
    ListNode* next;
    ListNode(int x) : value(x),next(nullptr){}
};

bool Symetric(ListNode* head){
    if(!head || !head->next){
        return true;
    }
    ListNode* p1 = head;
    ListNode* p2 = head;
    while(p2->next && p2->next->next){
        p1 = p1->next;
        p2 = p2->next->next;
    }
    ListNode* half = p1->next;
    p1->next = nullptr;
    ListNode* prev = nullptr;
    ListNode* cur = half;

    while(cur){
        ListNode* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    ListNode* half2 = head;
    while(half2 && prev){
        if(half2->value != prev->value){
            return false;
        }
        half2 = half2->next;
        prev = prev->next;
    }
return true;
}
int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(1);

    std::cout<< Symetric(head) << std::endl;

return 0;
}
