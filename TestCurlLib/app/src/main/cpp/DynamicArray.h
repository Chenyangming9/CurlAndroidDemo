//
// Created by t on 8/9/21.
//

#ifndef TESTZIP_DYNAMICARRAY_H
#define NOTESTZIP_DYNAMICARRAY_H


class DynamicArray {
public:
    DynamicArray();
    ~DynamicArray();
    char* mPszCont;
    unsigned int mszSize;
    unsigned int mMax;
    void strcat(char* psz, unsigned int size);
};


#endif //TESTZIP_DYNAMICARRAY_H
