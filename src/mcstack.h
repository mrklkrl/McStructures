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
 * @date 5 Dec 2018
 * @brief File containing declarations for stack data structure
 */
#ifndef MCSTACK_H
#define MCSTACK_H

#include "mclinkedlist.h"

/////////////////////////////////////////////
// McStack
/////////////////////////////////////////////

#define MCSTACK_NUMBER_OF_ITEMS 100

/**
 * @brief McStack - a Last-in-first-out structure
 * 
 */
typedef struct McStack
{
    void* items[MCSTACK_NUMBER_OF_ITEMS];
    void* (*pop)(struct McStack* stack);
    void* (*top)(struct McStack* stack);
    int (*push)(struct McStack* stack, void* elementToPush);
    int size;
    int isEmpty;
} McStack;

/**
 * @brief initializes a McStack
 * 
 * @param stack - the McStack to initialize
 * @return int 0 for failure 1 for success
 */
int mcStackInit (McStack* stack);

/**
 * @brief remove the last element that was added to the stack
 * 
 * @param stack - the stack to pop from
 * @return void* which was last added to the stack
 */
void* mcStackPop (McStack* stack);

/**
 * @brief examine the last element added to the stack
 * 
 * @param stack - the stack to examine
 * @return void* which was last added to the stack
 */
void* mcStackTop (McStack* stack);

/**
 * @brief place an element onto the top of the stack
 * 
 * @param stack - the stack to push to
 * @param elementToPush - the element to push onto the stack
 * @return int 0 for failure, 1 for success
 */
int mcStackPush (McStack* stack, void* elementToPush);

#endif // MCSTACK_H