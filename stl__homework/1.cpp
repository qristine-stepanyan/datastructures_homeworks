#include <iostream>

struct ListNode{
    int value;
    ListNode* next;
    ListNode(int val) : value(val),next(nullptr){}
};

bool isSorted(ListNode* head){
    if(!head || !head->next){
        return true;  
    }
bool inc = true;
bool dec = true;
    while(head && head->next){
        if(head->value < head->next->value){
        dec = false;
        }
        else if(head->value > head->next->value){
            inc = false;
        }
        if(!inc && ! dec){
            return false;
        }
        head = head->next;
    }
return true;
}

int main(){
    ListNode* list = new ListNode(1);
    list->next = new ListNode(2);
    list->next->next = new ListNode(3);
    list->next->next->next = new ListNode(4);
    list->next->next->next->next = new ListNode(5);

    if(isSorted(list)){
        std::cout<< "true"<< std::endl;
    }
    else{
        std::cout<< "false"<< std::endl;
    }
return 0;
}
