#include <iostream>
using std::cout; using std::cin; using std::endl;

class Node{
public:
    int data;
    Node* next;
};
Node* head = nullptr;

void printMenu(){
    cout << "You have the following options:" << endl;
    cout << "\t1. Add a node to the list" << endl;
    cout << "\t2. Insert a node to the list" << endl;
    cout << "\t3. Remove a node from the list" << endl;
    cout << "\t4. Print the list" << endl;
    cout << "\t5. Quit the program" << endl;
    return;
}

Node* addNode(int data){
    Node* newNode = nullptr;

    if(head == nullptr){
        newNode = new Node;
        if(newNode == nullptr)
            return nullptr;

        newNode->data = data;
        newNode->next = nullptr;
        head = newNode;
        
    }
    else{
        newNode = new Node;
        if(newNode == nullptr)
            return nullptr;
            
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    return newNode;
}

void printList(){
    if(head == nullptr){
        cout << "The list is empty" << endl;
        return;
    }

    Node* current = head;    
    while(current != nullptr){
        cout << current->data << "->";
        current = current->next;
    } 
    return;    
}
int main(){
    printMenu();

    int option = 0;
    while(option != 5){
        printMenu();
        cin >> option;

        if(option > 5 && option <= 5){
            switch(option){
                case 1:{
                    int dataToAdd;
                    cout << "What data should I add: ";
                    cin >> dataToAdd;
                    Node* newNode = addNode(dataToAdd);
                    // Add a node
                    break;
                }
                case 2:{
                    // Insert a node
                    break;
                } 
                case 3:{
                    // Remove a node
                    break;
                }
                case 4:{
                    // Print the list
                    printList();
                    break;
                } 
                case 5:{
                    break;
                } 
            }
        }
    }

    return 0;
}