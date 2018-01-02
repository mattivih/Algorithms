#pragma once
#include <limits>
#include <list>
#include "node.h"


// List of nodes, with operations to get/remove node
// with smallest estimated total cost, and inserting
// a node without accidentally duplicating it.
class Nodelist : public std::list<Node*>
{
public:

	// Get/remove a node with smallest estimated total cost.
	Node* get_smallest()
	{
		double minval = std::numeric_limits<double>::max();
		Node* retval = 0;

		// Linear search for a node with smallest value.
		for (auto n : *this)
		{
			if (n->_estimated_total_cost <= minval)
			{
				minval = n->_estimated_total_cost;
				retval = n;
			}
		}

		// Remove the node.
		remove(retval);
		return retval;
	}

	// Insert a node but do not duplicate it.
	void insert_unique(Node* n)
	{
		if (find(begin(), end(), n) == end())
		{
			push_back(n);
		}
	}
};
