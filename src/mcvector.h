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
 * @file mcvector.h
 * @author Mike Cole
 * @date 14 Mar 2020
 * @brief File containing declarations for vector structure
 */
#ifndef MCVECTOR_H
#define MCVECTOR_H

#define MCVECTOR_INIT_CAPACITY_BYTES 4

#define MCVECTOR_INIT(vec) mcVector vec; mcVectorInit(&vec)
#define MCVECTOR_ADD(vec, item) mcVectorAdd(&vec, (void*) item)
#define MCVECTOR_SET(vec, index, item) mcVectorSet(&vec, index, (void*) item)
#define MCVECTOR_GET(vec, type, index) (type) mcVectorGet(&vec, index)
#define MCVECTOR_DELETE(vec, index) mcVectorDelete(&vec, index)
#define MCVECTOR_TOTAL(vec) mcVectorTotal(&vec)
#define MCVECTOR_FREE(vec) mcVectorFree(&vec)

/////////////////////////////////////////////
// McVector
/////////////////////////////////////////////

/**
 * @brief McVector - a dynamically resizeable container for pointers
 */
typedef struct mcVector 
{
    void** items;
    int capacity;
    int total;
} McVector;

/**
 * @brief initializes a McVector
 * 
 * @param vec - the McVector to initialize
 */
void mcVectorInit(McVector* vec);

/**
 * @brief gets the total number of pointers stored in a McVector
 * 
 * @param vec - the McVector to get the total from
 * @return int - the total number of pointers stored in vec
 */
int mcVectorTotal(McVector* vec);

/**
 * @brief resizes a McVector to be a given capacity.
 * 
 * @param vec - the McVector to resize
 * @param capacity - the desired capacity
 */
static void mcVectorResize(McVector* vec, int capacity);

/**
 * @brief add an item to a aMCVector
 * 
 * @param vec - the McVector to add the item to. appends to end of vector. resizes vector if needed.
 * @param item - the item to be added to the vector
 */
void mcVectorAdd(McVector* vec, void* item);

/**
 * @brief replaces the element in a given vector at a given index with a new item
 * 
 * @param vec - the McVector to resize
 * @param index - the index of the item to replace
 * @param item - the item to place at the index
 */
void mcVectorSet(McVector* vec, int index, void* item);

/**
 * @brief retrieves the element in a given vector at a given index
 * 
 * @param vec - the McVector to resize
 * @param index - the index where the item to retrieve is held
 */
void* mcVectorGet(McVector* vec, int index);

/**
 * @brief Delete the element in a given vector at a given index
 * 
 * @param vec - the McVector to resize
 * @param index - the index where the item to delete is held
 */
void mcVectorDelete(McVector* vec, int index);

/**
 * @brief Free the memory that a McVector was using
 * 
 * @param vec - the McVector to free
 */
void mcVectorFree(McVector* vec);

#endif //MCVECTOR_H