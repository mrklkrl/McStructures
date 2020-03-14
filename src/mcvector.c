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
 * @file mcvector.c
 * @author Mike Cole
 * @date 14 Mar 2020
 * @brief File containing definitions for vector structure
 */

#include <stdlib.h>
#include <assert.h>
#include "mcvector.h"

void mcVectorInit(McVector* vec)
{
    vec->capacity = MCVECTOR_INIT_CAPACITY_BYTES;
    vec->total = 0;
    vec->items = malloc(sizeof(void*) * vec->capacity);
}

int mcVectorTotal(McVector* vec)
{
    return vec->total;
}

static void mcVectorResize(McVector* vec, int capacity)
{
    void** items = realloc(vec->items, sizeof(void *) * capacity);
    if (items) 
    {
        vec->items = items;
        vec->capacity = capacity;
    }
    else
    {
        // failed to realloc
        assert(0);
    }
}

void mcVectorAdd(McVector* vec, void* item)
{
    if (vec->capacity == vec->total)
        mcVectorResize(vec, vec->capacity * 2);
    vec->items[vec->total++] = item;
}

void mcVectorSet(McVector* vec, int index, void* item)
{
    if (index >= 0 && index < vec->total)
        vec->items[index] = item;
}

void* mcVectorGet(McVector* vec, int index)
{
    if (index >= 0 && index < vec->total)
        return vec->items[index];
    return 0;
}

void mcVectorDelete(McVector* vec, int index)
{
    if (index < 0 || index >= vec->total)
        return;

    vec->items[index] = 0;

    for (int i = index; i < vec->total - 1; i++)
    {
        vec->items[i] = vec->items[i + 1];
        vec->items[i + 1] = 0;
    }

    vec->total--;

    if (vec->total > 0 && vec->total == vec->capacity / 4)
        mcVectorResize(vec, vec->capacity / 2);
}

void mcVectorFree(McVector* vec)
{
    free(vec->items);
}