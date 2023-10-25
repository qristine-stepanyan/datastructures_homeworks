#include <iostream>

struct ListNode{
    int value;
    ListNode* next;
    ListNode(int x) : value(x),next(nullptr){}
};
int binaryToDecimal(ListNode* head){
    int decimalValue = 0;
    while(head != nullptr){
        decimalValue = (decimalValue << 1) | head->value;
        head = head->next;
    }
return decimalValue;
}

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(0);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(1);

    int decimal = binaryToDecimal(head);
    std::cout<< decimal;

    while(head != nullptr){
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
return 0;
}
