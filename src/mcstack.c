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
 * @file mcstack.c
 * @author Mike Cole
 * @date 5 Dec 2018
 * @brief File containing definitions for stack data structure
 */
#include "mcstack.h"

int mcStackInit(McStack* stack)
{
    for(int i = 0; i < MCSTACK_NUMBER_OF_ITEMS; i++)
    {
        stack->items[i] = 0;
    }
    stack->size = 0;
    stack->pop = mcStackPop;
    stack->top = mcStackTop;
    stack->push = mcStackPush;
    stack->isEmpty = 1;

    return 1;
}

void* mcStackPop(McStack* stack)
{
    if(!stack->isEmpty)
    {
        void* topElement = stack->items[stack->size - 1];
        stack->items[stack->size - 1] = 0;
        stack->size --;
        if(stack->size == 0)
        {
            stack->isEmpty = 1;
        }
        return topElement;
    }
    else return 0;
}

void* mcStackTop(McStack* stack)
{
    return stack->items[stack->size - 1];
}

int mcStackPush(McStack* stack, void* elementToPush)
{
    if(stack->size == MCSTACK_NUMBER_OF_ITEMS)
    {
        return 0;
    }
        
    else
    {
        stack->size++;
        stack->isEmpty = 0;
        stack->items[stack->size - 1] = elementToPush;
        return 1;
    }
}