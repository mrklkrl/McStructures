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

#include "mclinkedlist.h"

int mcSinglyLinkedListInit(McSinglyLinkedList* list)
{
    list->size = 0;
    list->first = 0;
    list->last = 0;
    list->append = mcSinglyLinkedListAppend;
    list->erase = mcSinglyLinkedListErase;
    list->find = mcSinglyLinkedListFind;
    list->insertAfter = mcSinglyLinkedListInsertAfter;
    list->insertBefore = mcSinglyLinkedListInsertBefore;
    list->find = mcSinglyLinkedListFind;
    return 1;
}

int mcSinglyLinkedListAppend( McSinglyLinkedList* list,  McSinglyLinkedListElement* elementToAdd)
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
    }
    // add the element to the end of the list
    else
    {
        list->last->next = elementToAdd;
        elementToAdd->next = 0;
        list->last = elementToAdd; 
    }

    list->size++;  
    reIndex(list);     
    return 1;
}

int mcSinglyLinkedListErase( McSinglyLinkedList* list,  McSinglyLinkedListElement* elementToerase)
{
    if(elementToerase == list->first)
        list->first = elementToerase->next;

    else
    {
        McSinglyLinkedListElement* element = list->find(list, elementToerase->index - 1);
        element->next = elementToerase->next;
    }
    
    list->size--;  
    reIndex(list);          
    return 1;
}

int mcSinglyLinkedListInsertAfter( McSinglyLinkedList* list,  McSinglyLinkedListElement* elementToInsert,  McSinglyLinkedListElement* elementToInsertAfter)
{
    elementToInsert->next = elementToInsertAfter->next;
    elementToInsertAfter->next = elementToInsert;
    if (list->last == elementToInsertAfter)
        list->last = elementToInsert;
    
    list->size++;
    reIndex (list);

    return 1;
}

int mcSinglyLinkedListInsertBefore( McSinglyLinkedList* list,  McSinglyLinkedListElement* elementToInsert,  McSinglyLinkedListElement* elementToInsertBefore)
{
    if (list->first == elementToInsertBefore)
    {
        list->first = elementToInsert;
        elementToInsert->next = elementToInsertBefore;
    }
    else
    {
         McSinglyLinkedListElement* element = list->find(list, elementToInsertBefore->index - 1);
        elementToInsert->next = elementToInsertBefore;
        element->next = elementToInsert;
    }
    
    list->size++;
    reIndex(list);
        
    return 1;
}

 McSinglyLinkedListElement* mcSinglyLinkedListFind( McSinglyLinkedList* list, int index)
{
     McSinglyLinkedListElement* foundElement = list->first;
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

int reIndex( McSinglyLinkedList* list)
{
     McSinglyLinkedListElement* element = list->first;
    for(int i = 0; i < list->size; i++)
    {
        element->index = i;
        element = element->next;
    }
    return 1;
}
