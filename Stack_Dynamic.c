#include "Stack_Dynamic.h"


static uint32 StackFull(Stack_D *pstack);
static uint32 StackEmpty(Stack_D *pstack);


Stack_D *StackCreate(uint32 maxSize, Stack_Status *status){
    *status = STACK_NOK;
    Stack_D *pstack =NULL;
    if(NULL == status){
        *status = STACK_NULL;
        pstack = NULL;
    }
    else{
        pstack = (Stack_D *)malloc(sizeof(Stack_D));
        if(NULL == pstack){
            *status = STACK_NULL;
            pstack = NULL;
        }
        else{
            pstack->StackSize = maxSize;
            pstack->StackTop = -1;
            pstack->StackArray = (void **)calloc(pstack->StackSize, sizeof(void *));
            if(!(pstack->StackArray)){
                *status = STACK_NULL;
                free(pstack);
                pstack = NULL;
            }else{
                *status = STACK_OK;
            }
        }
    }
    return pstack;
}

Stack_D *StackDestroy(Stack_D *pstack, Stack_Status *status){
    if((NULL == status) || (NULL == pstack)){
        *status = STACK_NULL;
    }
    else{
        free(pstack->StackArray);
        free(pstack);
        *status = STACK_OK;
    }
    return NULL;
}

Stack_Status StackPush(Stack_D *pstack, void *pvalue){
    Stack_Status status = STACK_NOK;
    if((NULL == pstack) || (NULL == pvalue)){
        status = STACK_NULL;
    }
    else{
        if(StackFull(pstack)){
                status = STACK_FULL;
        }
        else{
            (pstack->StackTop)++;
           pstack->StackArray[pstack->StackTop] =  pvalue;
            status = STACK_OK;
        }
    }
    return status;
}

void *StackPop(Stack_D *pstack, Stack_Status *status){
    void *value = NULL;
    if((NULL == pstack) || (NULL == status)){
        *status = STACK_NULL;
    }
    else{
        if(StackEmpty(pstack)){
        *status = STACK_EMPTY;
        }
        else{
            value = pstack->StackArray[pstack->StackTop];
            (pstack->StackTop)--;
            *status = STACK_OK;
        }
    }
    return value;
}

void *StackTop(Stack_D *pstack, Stack_Status *status){
    void *value = NULL;
    if((NULL == pstack) || (NULL == status)){
        *status = STACK_NULL;
    }
    else{
        if(StackEmpty(pstack)){
        *status = STACK_EMPTY;
        }
        else{
            value = pstack->StackArray[pstack->StackTop];
            *status = STACK_OK;
        }
    }
    return value;
}

Stack_Status StackSize(Stack_D *pstack, uint32 *psize){
    Stack_Status status = STACK_NOK;
    if((NULL == pstack) || (NULL == psize)){
        status = STACK_NULL;
    }
    else{
        *psize = (pstack->StackTop+1);
        status = STACK_OK;
    }
    return status;
}

static uint32 StackFull(Stack_D *pstack){
    return ((pstack->StackTop)+1 == pstack->StackSize);
}

static uint32 StackEmpty(Stack_D *pstack){
    return ((pstack->StackTop)+1 == 0);
}
