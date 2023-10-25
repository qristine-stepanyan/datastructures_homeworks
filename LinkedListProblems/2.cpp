 #include <iostream>

struct ListNode{
    int value;
    ListNode* next;
    ListNode(int x) : value(x),next(nullptr){}
};

ListNode* Middle(ListNode* head){
    ListNode* p1 = head;
    ListNode* p2 = head;

    while(p2 != nullptr && p2->next != nullptr){
        p1 = p1->next;
        p2 = p2->next->next;
    }
return p1;
}
int main(){
    ListNode* head = new ListNode(4);
    head->next = new ListNode(3);
    head->next->next = new ListNode(10);
    head->next->next->next = new ListNode(1);

    ListNode* middle = Middle(head);
    std::cout<< middle->value<< std::endl;

    while(head != nullptr){
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
return 0;
}