//
// Created by t on 8/9/21.
//

#include <string>

#include "DynamicArray.h"


DynamicArray::DynamicArray(){
    mMax = 1024*1024;
    mPszCont = new char[mMax];
    memset(mPszCont, 0, mMax);
    mszSize = 0;
}

void DynamicArray::strcat(char* psz, unsigned int size){
    if (size + mszSize >= mMax){
        unsigned int addLength = 1024*1024;
        if (size > addLength){
            addLength = size;
        }
        mMax += addLength;
        char* tmp = new char[mMax];
        memset(tmp, 0, mMax);
        memmove(tmp, mPszCont, mszSize);
        if (mPszCont != NULL){
            delete mPszCont;
            mPszCont = tmp;
        }
    }
    memmove(mPszCont + mszSize, psz, size);
    mszSize += size;
}

DynamicArray::~DynamicArray(){
    if (mPszCont != NULL){
        delete(mPszCont);
        mPszCont = NULL;
    }
    mMax = 0;
    mszSize = 0;
}