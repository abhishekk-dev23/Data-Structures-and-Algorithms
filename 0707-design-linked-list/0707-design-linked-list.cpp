class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
    
};

class MyLinkedList {
public:
    Node* dummy;
    int size;
    MyLinkedList() {
        dummy = new Node(-1);
        size = 0;
    }
    
    int get(int index) {
        if(index < 0 || index >= size) {
            return -1;
        }
        Node* temp = dummy->next;
        for(int i=0; i<index; i++) {
            temp = temp->next;
        }
        return temp->val;
    }
    
    void addAtHead(int val) {
        Node* node = new Node(val);
        node->next = dummy->next;
        dummy->next = node;
        size++;
    }
    
    void addAtTail(int val) {
        Node* temp = dummy;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new Node(val);
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0 || index > size) return;

        Node* t = dummy;
        for(int i=0; i<index; i++) {
            t = t->next;
        }
        Node* node = new Node(val);
        node->next = t->next;
        t->next = node;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size) return;

        Node* t = dummy;
        for(int i=0; i<index; i++) {
            t = t->next;
        }
        Node* toDelete = t->next;
        t->next = toDelete->next;
        delete toDelete;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */