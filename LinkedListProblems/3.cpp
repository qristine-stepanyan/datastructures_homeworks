#include <iostream>

struct ListNode{
    int value;
    ListNode* next;
    ListNode(int x) : value(x), next(nullptr){}
};

ListNode* Remove(ListNode* head,int k){
    ListNode* a = new ListNode(0);
    a->next = head;
    ListNode* cur = a;

    while(cur->next){
        if(cur->next->value == k){
            ListNode* temp = cur->next;
            cur->next = cur->next->next;
            delete temp;
        }
        else
        {
            cur = cur->next;
        }
    }
    ListNode* secondHead = a->next;
    delete a;
    return secondHead;
}
int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(3);

    int k = 3;
    ListNode* secondHead = Remove(head, k);

    while(secondHead){
        std::cout <<secondHead->value<< "->";
        secondHead = secondHead->next;
    }
return 0;
}
 