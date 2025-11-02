//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {

        data[size] = idx;
        upheap(size, weightArr);
        size = size + 1;
        return;
    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        if (size == 0) {
            return -1;
        }
        int popped = data[0];

        data[0] = data[size - 1];
        size = size - 1;
        downheap(0, weightArr);

        return popped; // placeholder
    }

    void upheap(int pos, int weightArr[]) {

        int parent = (pos - 1) / 2;
        if (pos == 0) {
            return;
        }
        while (pos > 0 && weightArr[data[pos]] < weightArr[data[parent]]) {
            int temp = data[parent];
            data[parent] = data[pos];
            data[pos] = temp;
            pos = parent;
            parent = (pos - 1) / 2;
        }
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        int leftChild = (2 * pos) + 1;
        int rightChild = (2 * pos) + 2;
        if (leftChild >= size) {
            return;
        }
        if (rightChild >= size) {
            if (weightArr[data[pos]] > weightArr[data[leftChild]]) {
                int temp = data[leftChild];
                data[leftChild] = data[pos];
                data[pos] = temp;
            }
            return;
        }

        while (pos < size && leftChild < size && rightChild < size && (weightArr[data[pos]] > weightArr[data[leftChild]] || weightArr[data[pos]] > weightArr[data[rightChild]])) {


            if (weightArr[data[leftChild]] > weightArr[data[rightChild]]) {
                int temp = data[rightChild];
                data[rightChild] = data[pos];
                data[pos] = temp;
                pos = rightChild;
                rightChild = (pos * 2) + 2;
                leftChild = (pos * 2) + 1;
            }
            else {
                int temp = data[leftChild];
                data[leftChild] = data[pos];
                data[pos] = temp;
                pos = leftChild;
                rightChild = (pos * 2) + 2;
                leftChild = (pos * 2) + 1;
            }
            if (leftChild >= size) {
                return;
            }
            if (rightChild >= size) {
                if (weightArr[data[pos]] > weightArr[data[leftChild]]) {
                    int temp = data[leftChild];
                    data[leftChild] = data[pos];
                    data[pos] = temp;
                }
                break;
            }
        }
    }
};

#endif