
#include <iostream>
using namespace std;

struct node //node structure for linked list
{
string value; //value of the node
node* next; //pointer to the next node
};

int main()
{
node* start = nullptr; // pointer to the start of the list
node* end = nullptr; // pointer to the end of the list

string outputs[3] = { "Enter the first string [-1 to quit]: ", "Enter the second string [-1 to quit]: ", "Enter the third string [-1 to quit]: "}; //array of strings for output
    
for (int i = 0; i < 3; i++){    
    string input; //string for input
    cout << outputs[i]; //output the strings from the array
    getline(cin, input); //get the input from the user
    if (input == "-1"){ //if the user enters -1, the program will stop asking for input
        cout << "No values were entered.\n";
        break;
    }
    node* newnode = new node; //creating a new node
    newnode->value = input; //the value of the node is the input
    newnode->next = nullptr; //the upcoming node is nullptr
    if (start == nullptr){ //if the start is nullptr, the new node is the start and the end
        start = newnode; //the start is the new node
        end = newnode; //the end is the new node
    }
    else{ //if the start is not nullptr, the new node is the end
        end->next = newnode;
        end = newnode;
    }
    }
    cout << endl;
    node* p = start;
    int nodeNumber = 1; //number of the node

    while (p != nullptr){ //transversing the list using a while loop
        cout << p->value << " is stored in node " << nodeNumber << endl;
        p = p->next;
        nodeNumber++;
    }
    while (start != nullptr){ //deallocating the list using a while loop
        node* temp = start;
        start = start->next;
        delete temp;
    }
    return 0;
}
