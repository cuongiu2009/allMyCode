#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Stack
{
    string data;
    Stack* next;
} *TOS = NULL;

void Push(string value)
{
    Stack* new_node = new Stack();
    new_node->data = value;
    new_node->next = TOS;
    TOS = new_node;
}
void Pop()
{
    if (TOS == NULL)
        return;
    else
    {
        Stack* temp;
        temp = TOS;
        TOS = TOS->next;
        temp->next = NULL;
        delete temp;
    }
}