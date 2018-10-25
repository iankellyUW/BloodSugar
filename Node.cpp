#include "Node.h"

Node::Node(float entry)
	: entry_(entry), next_(NULL)
{
}

Node::Node(float entry, Node * next)
	: entry_(entry), next_(next)
{
}

Node::~Node()
{
}

const Node & Node::operator=(const Node & node)
{
	if (&node != this) {
		this -> ~Node();
		entry_ = node.entry_;
		next_ = node.next_;
	}
	return *this;
}
