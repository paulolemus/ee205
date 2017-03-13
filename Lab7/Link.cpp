#include <vector>
#include <iostream>
using namespace std;


struct Link{

    int value;
    Link* next;

    Link(int v, Link* ptr):
        value(v), next(ptr){}

};

/* ALGORITHM
 * Copy the parameter ptr into a local ptr.
 * If the ptr is null, print that the list is empty.
 * Otherwise, iterate through list printing each node's
 * value until we've reaced a NULLPTR, the stop.
 */
void print(Link* ptr){
    Link* curr = ptr;

    if(!curr){
        cout << "List is empty" << endl;
        return;
    }

    while(curr){
        cout << curr->value << endl;
        curr = curr->next;
    }
}

/* ALGORITHM
 * As long as the given node is not NULL,
 * Iterate through each node, incrementing a counter each loop.
 * Stop when the next ptr is NULL.
 * Return the count value.
 */
int length(Link* head){
    int count = 0;
    Link* curr = head;

    while(curr){
        count++;
        curr = curr->next;
    }
    return count;
}

bool is_last_link(Link* head){
    return (head->next == NULL);
}

void append(Link* head, int i){
    Link* ptr = head;
    Link* L = new Link(i, NULL);

        while(ptr->next != NULL){
            ptr = ptr->next;
        }
    ptr->next = L;
}

bool has_cycle(Link* ptr){

    vector<Link*> v;
    Link* curr = ptr;
    while(curr){
        for(int i = 0; i < v.size(); i++){
            if(v[i] == curr) return true;
        }
        v.push_back(curr);
        curr = curr->next;
    }
    return false;
}


int main(){

    Link link1(1, NULL);
    Link link2(2, NULL);
    Link link3(3, NULL);

    link1.next = &link2;
    link2.next = &link3;
    Link* testptr = NULL;

    print(&link1);
    cout << length(&link1) << endl;
    cout << length(testptr) << endl;

    cout << "Is link1 last? " << is_last_link(&link1) << endl;
    cout << "Is link3 last? " << is_last_link(&link3) << endl;

    cout << "Has cycle? " << has_cycle(&link1) << endl;
    link3.next = &link1;
    cout << "Has cycle? " << has_cycle(&link1) << endl;
    cout << "Has cycle? " << has_cycle(testptr) << endl;

    return 0;
}
