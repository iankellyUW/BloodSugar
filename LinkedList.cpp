#include "LinkedList.h"

LinkedList::LinkedList()
	: first_(NULL)
{
}

LinkedList::~LinkedList()
{
	while (!empty()) {
		removeFirst();
	}
}

bool LinkedList::empty() const
{
	return first_ == NULL;
}

void LinkedList::removeFirst()
{
	Node * tempPtr = first_;
	first_ = first_->next_;
	delete tempPtr;
	count--;
	return;
}

void LinkedList::insertAsLast(float x)
{
	Node * append = new Node(x);
	if (!empty()) {
		Node * tempPtr = first_;
		while (tempPtr->next_ != NULL)
		{
			tempPtr = tempPtr->next_;
		}
		tempPtr->next_ = append;
	}
	else {
		first_ = append;
	}
	count++;
}

float LinkedList::sum()
{
	float sum = 0.0;
	maxfloats_ = 0;
	if (!empty())
	{
		Node * ptr = first_;
		while (ptr != NULL)
		{
			if ((sum + ptr->entry_) == INFINITY) {
				if (sum > ptr->entry_) {
					sum = sum - FLT_MAX;
					sum += ptr->entry_;
					maxfloats_++;
				} else {
					float thing = 0;
					thing = ptr->entry_ - FLT_MAX;
					sum += thing;
					maxfloats_++;
				}
			}
			else {
				sum += ptr->entry_;
			}
			ptr = ptr->next_;
		}
	}
	return sum;
}

float LinkedList::min()
{
	float min = 0.0;
	if (!empty())
	{
		Node * tempPtr = first_;
		min = tempPtr->entry_;
		while (tempPtr != NULL)
		{
			if (min >= tempPtr->entry_) {
				min = tempPtr->entry_;
			}
			tempPtr = tempPtr->next_;
		}
	}
	return min;
}

float LinkedList::max()
{
	float max = 0.0;
	if (!empty())
	{
		Node * tempPtr = first_;
		max = tempPtr->entry_;
		while (tempPtr != NULL)
		{
			if (max <= tempPtr->entry_) {
				max = tempPtr->entry_;
			}
			tempPtr = tempPtr->next_;
		}
	}
	return max;
}

int LinkedList::getCount()
{
	return count;
}

int LinkedList::getMaxFloats() {
	return maxfloats_;
}
