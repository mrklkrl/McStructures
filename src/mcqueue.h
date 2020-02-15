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
 * @file mcqueue.h
 * @author Mike Cole
 * @date 14 Feb 2020
 * @brief File containing declarations for stack data structure
 */
#ifndef MCQUEUE_H
#define MCQUEUE_H

/////////////////////////////////////////////
// McQueue
/////////////////////////////////////////////

#define MCQUEUE_NUMBER_OF_ITEMS 100

/**
 * @brief McQueue - a first-in-first-out structure
 * 
 */
typedef struct McQueue
{
    void* items[MCQUEUE_NUMBER_OF_ITEMS];
    int (*enqueue)(struct McQueue* queue, void* elementToQueue);
    void* (*dequeue)(struct McQueue* queue);
    void* (*front)(struct McQueue* queue);
    int size;
    int isEmpty;
} McQueue;

/**
 * @brief initializes a McQueue
 * 
 * @param queue - the McQueue to initialize
 * @return int 0 for failure 1 for success
 */
int mcQueueInit (McQueue* queue);

/**
 * @brief remove the oldes element that was added to the queue
 * 
 * @param queue - the queue to pop from
 * @return void* which was last added to the queue
 */
void* mcQueueDeque (McQueue* queue);

/**
 * @brief examine the oldest element added to the queue
 * 
 * @param queue - the queue to examine
 * @return void* which was last added to the stack
 */
void* mcQueueFront (McQueue* queue);

/**
 * @brief place an element onto the back of the queue
 * 
 * @param queue - the queue to enqueue to
 * @param elementToPush - the element to enqueue onto the queue
 * @return int 0 for failure, 1 for success
 */
int mcQueueEnqueue (McQueue* queue, void* elementToEnqueue);

#endif // MCSTACK_H