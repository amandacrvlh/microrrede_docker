#ifndef DSS_UTILS_C
#define DSS_UTILS_C
/* Include Files */
#include "DSS_Utils.h"

/*
 * Arguments    : emxArray_int32_T **pEmxArray
 *                int numDimensions
 * Return Type  : void
 */
void emxInit_int32_T(emxArray_int32_T** pEmxArray, int numDimensions) {
    emxArray_int32_T* emxArray;
    int               i;
    *pEmxArray              = (emxArray_int32_T*)malloc(sizeof(emxArray_int32_T));
    emxArray                = *pEmxArray;
    emxArray->data          = (int*)NULL;
    emxArray->numDimensions = numDimensions;
    emxArray->size          = (int*)malloc((unsigned int)(sizeof(int) * numDimensions));
    emxArray->allocatedSize = 0;
    emxArray->canFreeData   = true;
    for (i = 0; i < numDimensions; i++) {
        emxArray->size[i] = 0;
    }
}

/*
 * Arguments    : emxArray_real_T **pEmxArray
 *                int numDimensions
 * Return Type  : void
 */
void emxInit_real_T1(emxArray_real_T** pEmxArray, int numDimensions) {
    emxArray_real_T* emxArray;
    int              i;
    *pEmxArray              = (emxArray_real_T*)malloc(sizeof(emxArray_real_T));
    emxArray                = *pEmxArray;
    emxArray->data          = (double*)NULL;
    emxArray->numDimensions = numDimensions;
    emxArray->size          = (int*)malloc((unsigned int)(sizeof(int) * numDimensions));
    emxArray->allocatedSize = 0;
    emxArray->canFreeData   = true;
    for (i = 0; i < numDimensions; i++) {
        emxArray->size[i] = 0;
    }
}

/*
 * Arguments    : int *data
 *                int rows
 *                int cols
 * Return Type  : emxArray_int32_T *
 */
emxArray_int32_T* emxCreateWrapper_int32_T(int* data, int rows, int cols) {
    emxArray_int32_T* emx;
    int               size[2];
    int               numEl;
    int               i;
    size[0] = rows;
    size[1] = cols;
    emxInit_int32_T(&emx, 2);
    numEl = 1;
    for (i = 0; i < 2; i++) {
        numEl *= size[i];
        emx->size[i] = size[i];
    }

    emx->data          = data;
    emx->numDimensions = 2;
    emx->allocatedSize = numEl;
    emx->canFreeData   = false;
    return emx;
}

/*
 * Arguments    : double *data
 *                int rows
 *                int cols
 * Return Type  : emxArray_real_T *
 */
emxArray_real_T* emxCreateWrapper_real_T(double* data, int rows, int cols) {
    emxArray_real_T* emx;
    int              size[2];
    int              numEl;
    int              i;
    size[0] = rows;
    size[1] = cols;
    emxInit_real_T1(&emx, 2);
    numEl = 1;
    for (i = 0; i < 2; i++) {
        numEl *= size[i];
        emx->size[i] = size[i];
    }

    emx->data          = data;
    emx->numDimensions = 2;
    emx->allocatedSize = numEl;
    emx->canFreeData   = false;
    return emx;
}

/*
 * Arguments    : int rows
 *                int cols
 * Return Type  : emxArray_int32_T *
 */
emxArray_int32_T* emxCreate_int32_T(int rows, int cols) {
    emxArray_int32_T* emx;
    int               size[2];
    int               numEl;
    int               i;
    size[0] = rows;
    size[1] = cols;
    emxInit_int32_T(&emx, 2);
    numEl = 1;
    for (i = 0; i < 2; i++) {
        numEl *= size[i];
        emx->size[i] = size[i];
    }

    emx->data          = (int*)calloc((unsigned int)numEl, sizeof(int));
    emx->numDimensions = 2;
    emx->allocatedSize = numEl;
    return emx;
}

/*
 * Arguments    : int rows
 *                int cols
 * Return Type  : emxArray_real_T *
 */
emxArray_real_T* emxCreate_real_T(int rows, int cols) {
    emxArray_real_T* emx;
    int              size[2];
    int              numEl;
    int              i;
    size[0] = rows;
    size[1] = cols;
    emxInit_real_T1(&emx, 2);
    numEl = 1;
    for (i = 0; i < 2; i++) {
        numEl *= size[i];
        emx->size[i] = size[i];
    }

    emx->data          = (double*)calloc((unsigned int)numEl, sizeof(double));
    emx->numDimensions = 2;
    emx->allocatedSize = numEl;
    return emx;
}

/*
 * Arguments    : emxArray_int32_T *emxArray
 * Return Type  : void
 */
void emxDestroyArray_int32_T(emxArray_int32_T* emxArray) {
    emxFree_int32_T(&emxArray);
}

/*
 * Arguments    : emxArray_real_T *emxArray
 * Return Type  : void
 */
void emxDestroyArray_real_T(emxArray_real_T* emxArray) {
    emxFree_real_T(&emxArray);
}

/*
 * Arguments    : emxArray_int32_T **pEmxArray
 * Return Type  : void
 */
void emxFree_int32_T(emxArray_int32_T** pEmxArray) {
    if (*pEmxArray != (emxArray_int32_T*)NULL) {
        if (((*pEmxArray)->data != (int*)NULL) && (*pEmxArray)->canFreeData) {
            free((void*)(*pEmxArray)->data);
        }

        free((void*)(*pEmxArray)->size);
        free((void*)*pEmxArray);
        *pEmxArray = (emxArray_int32_T*)NULL;
    }
}

/*
 * Arguments    : emxArray_real_T **pEmxArray
 * Return Type  : void
 */
void emxFree_real_T(emxArray_real_T** pEmxArray) {
    if (*pEmxArray != (emxArray_real_T*)NULL) {
        if (((*pEmxArray)->data != (double*)NULL) && (*pEmxArray)->canFreeData) {
            free((void*)(*pEmxArray)->data);
        }

        free((void*)(*pEmxArray)->size);
        free((void*)*pEmxArray);
        *pEmxArray = (emxArray_real_T*)NULL;
    }
}
#endif
