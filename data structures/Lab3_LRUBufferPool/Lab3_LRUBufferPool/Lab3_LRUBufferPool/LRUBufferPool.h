#pragma once

// libraries

#include "BufferPoolADT.h"
#include "BufferBlock.h"
#include <vector>
#include <fstream>

//class
class LRUBufferPool: BufferPoolADT
{
public:

    //constructor
    LRUBufferPool(string fname, int pSize, int bSize): BufferPoolADT(fname,pSize,bSize) 
    {
        //initializing values
        filename = fname;
        polSz = pSize;
        blkSz = bSize;

        //opening file
        fin.open(filename.c_str(), fstream::in | fstream::binary); //opens filename


        //reading file into buffer block
        for (int i = 0; i < 5; i++)
        {
            char* buffer = new char[blkSz]; // char array buffer storage
            fin.seekg(blkSz * i); //goes to start of each block
            fin.read(buffer, blkSz); //stores file values into the buffer
            BufferBlock temp(buffer, blkSz); //stores buffer into buffer block
            temp.setID(i); //sets block id
            pool.push_back(temp); //saves buffer block in pool

        }

    }

    //destructor
    ~LRUBufferPool(){
        fin.close(); // closing file 
    }

    // Copy "sz" bytes from position "pos" of the buffered
    //   storage to "space".
    void getBytes(char* space, int sz, int pos)
    {
        int blockID = 0;
        blockID = pos / blkSz; // chunk of data we are looking 
        for (int i = 0; i < polSz; i++)
        {
            if (pool[i].getID() == blockID) // checks if block exists 
            {
                BufferBlock temp = pool[i];
                temp.getData(pos % blkSz, sz, space); //gets data
                for (int j = i; j > 0; j--) //starting at pos working backwards 
                {
                    pool[j] = pool[j - 1];
                }
                pool[0] = temp; //start of pool
                return; //stops loop
            }
        }

        fin.seekg(0, fin.end); // seeks start of file
        int length = fin.tellg(); // gets length of file
        if (pos + sz > length) //out of bounds check
        {
            cout << "Error! Reading outside of bounds." << endl;
            return;
        }

        char* buffer = new char[blkSz]; // creates a buffer storage 
        fin.seekg(blkSz * blockID); // goes to the start of each block in file 
        fin.read(buffer, blkSz); //reads block sz bytes into buffer 
        BufferBlock temp(buffer, blkSz); //creates a new buffer block 
        temp.setID(blockID); //sets id

        if (pool.size() >= polSz) // checks if pool is full 
        {
            pool.pop_back(); // deleting the last buffer 
        }

        pool.insert(pool.begin(), temp); // insert new buffer in pool 
        temp.getData(pos % blkSz, sz, space); //gets data from block
    }

    // Print the order of the buffer blocks using the block id
    //	 numbers.
    void printBufferBlockOrder()
    {
        cout << "printing buffer list!" << endl;
        for (int i = 0; i < polSz; i++)
        {
            cout << pool[i].getID() << ", "; //printing block ids in pool
        }
        cout << endl;

    }

    // Get the block id number of the least recently used 
    //	 buffer block.
    int getLRUBlockID()
    {
        return pool[polSz - 1].getID();
    }

private:
    string filename;
    int polSz;
    int blkSz;
    vector<BufferBlock> pool;
    fstream fin; //input file
};
