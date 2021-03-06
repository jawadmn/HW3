#include <assert.h>
#include <stdlib.h>

#include "list.h"

// Takes a valid, sorted list starting at `head` and adds the element
// `new_element` to the list. The list is sorted based on the value of the
// `index` member in ascending order. Returns a pointer to the head of the list
// after the insertion of the new element.
list_t* insert_sorted(list_t* head, list_t* new_element) {
	list_t* cur;
    list_t* holder;
    list_t* last;
    
    assert(head != NULL);
	assert(new_element != NULL);
    
    // Check if new_elt is less than head
    if((*new_element).index < (*head).index) {
        // If so, new_elt->next = head->next
        (*new_element).next = head;
        
        // Return new head
        return new_element;
    }
    
    // last = head to start off
    last = head;
    
    for(cur = (*head).next; cur != NULL; cur = (*cur).next) {
        if((*new_element).index < (*cur).index) {
            (*last).next = new_element;
            (*new_element).next = cur;
            
            break;
        }

	last = cur;
    }

    // if cur is NULL, then new_element goes at the end
    if(cur == NULL) {
        (*last).next = new_element;
    }
    
	return head;
}

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
list_t* reverse(list_t* head) {
    list_t* last;
    list_t* cur;
    list_t* next;
    
	assert(head != NULL);
    
    last = head;
    cur = (*head).next; 
    (*head).next = NULL; // No matter what, head should point to NULL as last
    
    while(cur != NULL) {
        next = (*cur).next;
        
        (*cur).next = last;
        
        last = cur;
        cur = next;
    }
    
    return last;
}

