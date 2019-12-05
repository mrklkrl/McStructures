/* 
 * This file is part of the McStructures distribution (https://github.com/mrklkrl/McStructures).
 * Copyright (c) 2019 Michael Cole.
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * @file mclinkedlist.c
 * @author Mike Cole
 * @date 1 Dec 2018
 * @brief File containing definitions for linked list data structures
 */

#include "mcdoublylinkedlist.h"

int mcDoublyLinkedListInit(McDoublyLinkedList* list)
{
    list->size = 0;
    list->first = 0;
    list->last = 0;
    list->append = mcDoublyLinkedListAppend;
    list->erase = mcDoublyLinkedListErase;
    list->find = mcDoublyLinkedListFind;
    list->insertAfter = mcDoublyLinkedListInsertAfter;
    list->insertBefore = mcDoublyLinkedListInsertBefore;
    list->find = mcDoublyLinkedListFind;
    return 1;
}

int mcDoublyLinkedListAppend( McDoublyLinkedList* list,  McDoublyLinkedListElement* elementToAdd)
{
    // our list is in a bad state
    if ((!list->last || !list->first) && (list->size != 0))
    {
        return 0;
    }
    // we're adding an element for the first time.
    else if (list->size == 0)
    {
        list->first = elementToAdd;
        list->last = elementToAdd;
        elementToAdd->next = 0;
        elementToAdd->previous = 0;
    }
    // add the element to the end of the list
    else
    {
        elementToAdd->previous = list->last;
        list->last->next = elementToAdd;
        elementToAdd->next = 0;
        list->last = elementToAdd; 
    }

    list->size++;  
    reIndexMcDoubly(list);     
    return 1;
}

int mcDoublyLinkedListErase( McDoublyLinkedList* list,  McDoublyLinkedListElement* elementToerase)
{
    if(elementToerase == list->first)
    {
        list->first = elementToerase->next;
        elementToerase->previous = 0;
    }       

    else
    {
        McDoublyLinkedListElement* element = list->find(list, elementToerase->index - 1);
        element->next = elementToerase->next;
        element->previous = elementToerase->previous;
    }
    
    list->size--;  
    reIndexMcDoubly(list);          
    return 1;
}

int mcDoublyLinkedListInsertAfter( McDoublyLinkedList* list,  McDoublyLinkedListElement* elementToInsert,  McDoublyLinkedListElement* elementToInsertAfter)
{
    elementToInsert->next = elementToInsertAfter->next;
    elementToInsert->previous = elementToInsertAfter;
    elementToInsertAfter->next = elementToInsert;
    if (list->last == elementToInsertAfter)
        list->last = elementToInsert;
    
    list->size++;
    reIndexMcDoubly (list);

    return 1;
}

int mcDoublyLinkedListInsertBefore( McDoublyLinkedList* list,  McDoublyLinkedListElement* elementToInsert,  McDoublyLinkedListElement* elementToInsertBefore)
{
    if (list->first == elementToInsertBefore)
    {
        list->first = elementToInsert;
        elementToInsert->next = elementToInsertBefore;
        elementToInsertBefore->previous = elementToInsert;
    }
    else
    {
         McDoublyLinkedListElement* element = list->find(list, elementToInsertBefore->index - 1);
        elementToInsert->next = elementToInsertBefore;
        element->next = elementToInsert;
        element->previous = elementToInsertBefore->previous;
        elementToInsertBefore->previous = elementToInsert;
    }
    
    list->size++;
    reIndexMcDoubly(list);
        
    return 1;
}

 McDoublyLinkedListElement* mcDoublyLinkedListFind( McDoublyLinkedList* list, int index)
{
    McDoublyLinkedListElement* foundElement = list->first;
    //TODO: traverse backwards for elements in the back half of the list
    for(int i = 0; i < list->size; i++)
    {
        if(foundElement->index == index)
            return foundElement;
        else
        {
            foundElement = foundElement->next;
        }
    }

    return 0;
}

int reIndexMcDoubly( McDoublyLinkedList* list)
{
     McDoublyLinkedListElement* element = list->first;
    for(int i = 0; i < list->size; i++)
    {
        element->index = i;
        element = element->next;
    }
    return 1;
}
