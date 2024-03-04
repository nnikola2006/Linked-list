#include <iostream>
using std::cout; using std::cin; using std::endl;

class Node{
public:
    int data;
    Node* next;
};
Node* head = nullptr;

void printMenu(){
    cout << "\nYou have the following options:" << endl;
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

Node* insertNode(int data, int position){
    Node* current = head;

    // Gets the current->next ptr into the node we want to insert by going "through" 
    // the list by looping until position is 0
    while(current != nullptr && position != 0){
        current = current->next;
        position--; 
    }
    if(position != 0){
        cout << "Requested position too far into the list" << endl;
        return nullptr;
    }
    
    Node* newNode = new Node;
    if(newNode == nullptr)
        return nullptr;

    newNode->data = data;
    newNode->next = current->next;
    current->next = newNode;

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
    int option = 0;
    while(option != 5){
        printMenu();
        cin >> option;

        if(option > 0 && option <= 5){
            switch(option){
                case 1:{
                    // Add a node
                    int dataToAdd;
                    cout << "What data should I add: ";
                    cin >> dataToAdd;
                    Node* newNode = addNode(dataToAdd);
                    
                    if(newNode == nullptr)
                        cout << "Failed to add a node";
                    break;
                }
                case 2:{
                    // Insert a node
                    int dataToInsert, position;
                    cout << "What data should I insert: ";
                    cin >> dataToInsert;
                    cout << "In what position: ";
                    cin >> position;
                    Node* newNode = insertNode(dataToInsert, position);

                    if(newNode == nullptr)
                        cout << "Failed to insert a node";
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