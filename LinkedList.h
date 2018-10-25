#pragma once
#ifndef LLIST_H_
#define LLIST_H_
#include "Node.h"
#include <iostream>

class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	bool empty() const;
	void removeFirst();
	void insertAsLast(float x);

	float sum();
	float min();
	float max();
	int getCount();
	int getMaxFloats();

private:
	int maxfloats_ = 0;
	int count = 0;
	Node * first_;
};

#endif