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
 * @file mcdoublylinkedlist.h
 * @author Mike Cole
 * @date 1 Dec 2018
 * @brief File containing declarations for doubly linked list data structures
 */

#ifndef MCDOUBLYLINKEDLIST_H
#define MCDOUBLYLINKEDLIST_H

/////////////////////////////////////////////
// McDoublyLinkedList
/////////////////////////////////////////////

/**
 * @brief McDoublyLinkedListElement - an element belonging to a McDoublyLinkedList 
 * 
 * This type of element stores a pointer to the previous and next element in the list.
 */

typedef struct McDoublyLinkedListElement 
{
    void* data;
    struct McDoublyLinkedListElement* next;
    struct McDoublyLinkedListElement* previous;
    int index;
} McDoublyLinkedListElement;

/**
 * @brief McDoublyLinkedList - a Doubly Linked List 
 * 
 * This type of list can be traversed in  either forward or reverse direction
 * Elements can be appended, erased, inserted, or found.
 * Must be initialized with mcDoublyLinkedListInit();
 */


typedef struct McDoublyLinkedList
{
    int size;
    struct McDoublyLinkedListElement* first;
    struct McDoublyLinkedListElement* last;
    int (*append) (struct McDoublyLinkedList* list, struct McDoublyLinkedListElement* elementToAdd);
    int (*erase) (struct McDoublyLinkedList* list, struct McDoublyLinkedListElement* elementToerase);
    int (*insertAfter) (struct McDoublyLinkedList* list, struct McDoublyLinkedListElement* elementToInsert, struct McDoublyLinkedListElement* elementToInsertAfter);
    int (*insertBefore) (struct McDoublyLinkedList* list, struct McDoublyLinkedListElement* elementToInsert, struct McDoublyLinkedListElement* elementToInsertBefore);
     McDoublyLinkedListElement* (*find) (struct McDoublyLinkedList* list,int index);
} McDoublyLinkedList;

/**
 * @brief initializes a mcDoublyLinkedList, specifying member functions and initializing data.
 * 
 * @param list the mcDoublyLinkedList to initialize
 * @return int 1 for success, 0 for failure
 */
int mcDoublyLinkedListInit( McDoublyLinkedList* list);

/**
 * @brief Append a mcDoublyLinkedListElement to the end of a mcDoublyLinkedList
 * 
 * @param list the list to do the operation on
 * @param elementToAdd
 * @return int 1 for success, 0 for failure
 */
int mcDoublyLinkedListAppend( McDoublyLinkedList* list,  McDoublyLinkedListElement* elementToAdd);

/**
 * @brief erase an element from a mcDoublyLinkedList
 * 
 * @param list the list to do the operation on
 * @param elementToerase
 * @return int 1 for success, 0 for failure
 */
int mcDoublyLinkedListErase( McDoublyLinkedList* list,  McDoublyLinkedListElement* elementToErase);

/**
 * @brief insert mcDoublyLinkedListElement in the list after a 
 * given mcDoublyLinkedListElement thats already in the list
 * 
 * @param list the list to do the operation on
 * @param elementToInsert the element we want to insert into the list
 * @param elementToInsertAfter the element that's already in the list
 * @return int 1 for success, 0 for failure
 */
int mcDoublyLinkedListInsertAfter( McDoublyLinkedList* list,  McDoublyLinkedListElement* elementToInsert, McDoublyLinkedListElement* elementToInsertAfter);

/**
 * @brief insert mcDoublyLinkedListElement in the list before a 
 * given mcDoublyLinkedListElement thats already in the list
 * 
 * @param list the list to do the operation on
 * @param elementToInsert the element we want to insert into the list
 * @param elementToInsertAfter the element that's already in the list
 * @return int 1 for success, 0 for failure
 */
int mcDoublyLinkedListInsertBefore( McDoublyLinkedList* list,  McDoublyLinkedListElement* elementToInsert, McDoublyLinkedListElement* elementToInsertBefore);

/**
 * @brief find a McDoublyLinkedListElement by its index
 * 
 * @param list the list to do the operation on
 * @param index 
 * @return  McDoublyLinkedListElement* 
 */
 McDoublyLinkedListElement* mcDoublyLinkedListFind( McDoublyLinkedList* list, int index);

/**
 * @brief make sure the indeces of a linkedlist are in order
 * 
 */
int reIndexMcDoubly( McDoublyLinkedList* list); //TODO only reindex the items that need reindexing instead of entire list

#endif // MCDOUBLYLINKEDLIST_H