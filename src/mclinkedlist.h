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
 * @file mclinkedlist.h
 * @author Mike Cole
 * @date 1 Dec 2018
 * @brief File containing declarations for linked list data structures
 */

#ifndef MCLINKEDLIST_H
#define MCLINKEDLIST_H

/////////////////////////////////////////////
// McSinglyLinkedList
/////////////////////////////////////////////

/**
 * @brief McSinglyLinkedListElement - an element belonging to a McSinglyLinkedList 
 * 
 * This type of element stores a pointer to the next element in the list.
 */

typedef struct McSinglyLinkedListElement 
{
    void* data;
    McSinglyLinkedListElement* next;
    int index;
} McSinglyLinkedListElement;

/**
 * @brief McSinglyLinkedList - a Singly Linked List 
 * 
 * This type of list can be traversed in a single direction only using an iterate function
 * Elements can be appended, erased, inserted, or found.
 * Must be initialized with mcSinglyLinkedListInit();
 */


typedef struct McSinglyLinkedList
{
    int size;
    McSinglyLinkedListElement* first;
    McSinglyLinkedListElement* last;
    int (*append) (McSinglyLinkedList* list, McSinglyLinkedListElement* elementToAdd);
    int (*erase) (McSinglyLinkedList* list, McSinglyLinkedListElement* elementToerase);
    int (*insertAfter) (McSinglyLinkedList* list, McSinglyLinkedListElement* elementToInsert,McSinglyLinkedListElement* elementToInsertAfter);
    int (*insertBefore) (McSinglyLinkedList* list, McSinglyLinkedListElement* elementToInsert,McSinglyLinkedListElement* elementToInsertBefore);
    McSinglyLinkedListElement* (*find) (McSinglyLinkedList* list,int index);
} McSinglyLinkedList;

/**
 * @brief initializes a mcSinglyLinkedList, specifying member functions and initializing data.
 * 
 * @param list the mcSinglyLinkedList to initialize
 * @return int 1 for success, 0 for failure
 */
int mcSinglyLinkedListInit(McSinglyLinkedList* list);

/**
 * @brief Append a mcSinglyLinkedListElement to the end of a mcSinglyLinkedList
 * 
 * @param list the list to do the operation on
 * @param elementToAdd
 * @return int 1 for success, 0 for failure
 */
int mcSinglyLinkedListAppend(McSinglyLinkedList* list, McSinglyLinkedListElement* elementToAdd);

/**
 * @brief erase an element from a mcSinglyLinkedList
 * 
 * @param list the list to do the operation on
 * @param elementToerase
 * @return int 1 for success, 0 for failure
 */
int mcSinglyLinkedListErase(McSinglyLinkedList* list, McSinglyLinkedListElement* elementToErase);

/**
 * @brief insert mcSinglyLinkedListElement in the list after a 
 * given mcSinglyLinkedListElement thats already in the list
 * 
 * @param list the list to do the operation on
 * @param elementToInsert the element we want to insert into the list
 * @param elementToInsertAfter the element that's already in the list
 * @return int 1 for success, 0 for failure
 */
int mcSinglyLinkedListInsertAfter(McSinglyLinkedList* list, McSinglyLinkedListElement* elementToInsert,McSinglyLinkedListElement* elementToInsertAfter);

/**
 * @brief insert mcSinglyLinkedListElement in the list before a 
 * given mcSinglyLinkedListElement thats already in the list
 * 
 * @param list the list to do the operation on
 * @param elementToInsert the element we want to insert into the list
 * @param elementToInsertAfter the element that's already in the list
 * @return int 1 for success, 0 for failure
 */
int mcSinglyLinkedListInsertBefore(McSinglyLinkedList* list, McSinglyLinkedListElement* elementToInsert,McSinglyLinkedListElement* elementToInsertBefore);

/**
 * @brief find a McSinglyLinkedListElement by its index
 * 
 * @param list the list to do the operation on
 * @param index 
 * @return McSinglyLinkedListElement* 
 */
McSinglyLinkedListElement* mcSinglyLinkedListFind(McSinglyLinkedList* list, int index);

/**
 * @brief make sure the indeces of a linkedlist are in order
 * 
 */
int reIndex(McSinglyLinkedList* list);

#endif // MCLINKEDLIST_H