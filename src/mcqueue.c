/* 
 * This file is part of the McStructures distribution (https://github.com/mrklkrl/McStructures).
 * Copyright (c) 2020 Michael Cole.
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
 * @file mcqueue.c
 * @author Mike Cole
 * @date 14 Feb 2020
 * @brief File containing definitions for queue data structure
 */
#include "mcqueue.h"

int mcQueueInit (McQueue* queue)
{
    for(int i = 0; i < MCQUEUE_NUMBER_OF_ITEMS; i++)
    {
        queue->items[i] = 0;
    }
    queue->size = 0;
    queue->dequeue = mcQueueDeque;
    queue->enqueue = mcQueueEnqueue;
    queue->front = mcQueueFront;
    queue->isEmpty = 1;

    return 1;
}

void* mcQueueDeque (McQueue* queue)
{
    if(!queue->isEmpty)
    {
        void* frontElement = queue->items[0];
        queue->items[queue->size - 1] = 0;
        queue->size --;
        if(queue->size == 0)
        {
            queue->isEmpty = 1;
        }
        return frontElement;
    }
    else return 0;
}

void* mcQueueFront (McQueue* queue)
{
    return queue->items[0];
}

int mcQueueEnqueue (McQueue* queue, void* elementToEnqueue)
{
    if(queue->size == MCQUEUE_NUMBER_OF_ITEMS)
    {
        return 0;
    }
        
    else
    {
        queue->size++;
        queue->isEmpty = 0;
        queue->items[queue->size - 1] = elementToEnqueue;
        return 1;
    }
}