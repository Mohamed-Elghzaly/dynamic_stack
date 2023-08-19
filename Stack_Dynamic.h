#ifndef STACK_DYNAMIC_H
#define STACK_DYNAMIC_H

#include <stdio.h>
#include <stdlib.h>
#include "Platform_Types.h"

typedef struct{
    void **StackArray;
    sint32 StackTop;
    uint32 StackSize;
}Stack_D;

typedef enum{
    STACK_OK=0,
    STACK_NOK,
    STACK_FULL,
    STACK_EMPTY,
    STACK_NULL,
}Stack_Status;








/** \brief  create dynamic stack with known size in heap
 *
 * \param   (maxSize) size of stack
 * \param   (status)  status returned while performed this operation
 * \return   pointer to the allocated stack
 *
 */

Stack_D *StackCreate(uint32 maxSize, Stack_Status *status);

/** \brief  destroy dynamic stack from the heap
 *
 * \param   (pstack) stack that will be destroyed
 * \param   (status)   status returned while performed this operation
 * \return   NULL instead of stack
 *
 */

Stack_D *StackDestroy(Stack_D *pstack, Stack_Status *status);

/** \brief  Push an element to the stack
 *
 * \param   (pstack) the stack that element will be pushed in
 * \param   (pvalue)  the element that will be pushed
 * \return   status returned while performed this operation
 *
 */

Stack_Status StackPush(Stack_D *pstack, void* pvalue);

/** \brief  Pop an element from the stack
 *
 * \param   (pstack) the stack that element will be pop out
 * \param   (status) status returned while performed this operation
 * \return   element returned from stack which popped
 *
 */
void *StackPop(Stack_D *pstack, Stack_Status *status);



/** \brief  return an element from the stack
 *
 * \param   (pstack) the stack that element will returned
 * \param   (status) status returned while performed this operation
 * \return   element returned from stack
 *
 */
void *StackTop(Stack_D *pstack, Stack_Status *status);


/** \brief  return size of the stack
 *
 * \param   (pstack) the stack that element will returned
 * \param   (psize) number of the elements in the stack
 * \return   status returned while performed this operation
 *
 */
Stack_Status StackSize(Stack_D *pstack, uint32 *psize);


#endif // STACK_DYNAMIC_H
