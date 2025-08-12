#pragma once

//libraries
#include "BufferBlockADT.h"


//class
class BufferBlock:BufferBlockADT
{
public:
    BufferBlock(char* data, int sz) : BufferBlockADT(data, sz) {
        block = data;
        blockID = 0;
        blockSize = sz;
    }

    ~BufferBlock() {};

    //read the block from pos to pos + sz-1 (or to the end of the block)
    void getData(int pos, int sz, char* data) {
        if (pos + sz > blockSize) //checks if out of bounds
        {
            sz = blockSize - pos; // clamps the size to the max number of bytes left 
        }
        memcpy(data, block + pos, sz); // copy size bites from block + pos into data
    }

    //setID
    void setID(int id)
    {
        blockID = id;
    }

    //getID
    int getID() const
    {
        return blockID;
    }

    //getBlocksize
    int getBlockSize() const
    {
        return blockSize;
    }

    //return the block
    char* getBlock() const
    {
        return block;
    }

    //set the block
    void setBlock(char* blk)
    {
        block = blk;
    }


private:
    int blockID;
    char* block;
    int blockSize;
};
