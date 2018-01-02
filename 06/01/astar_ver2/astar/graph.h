#pragma once
#include <limits>
#include <vector>
#include "node.h"
#include "nodelist.h"


// Directed navigation graph, consisting of a collection of nodes.
class Graph
{
public:

	// Graph consists of pointers to its nodes.
	std::vector<Node*> _nodes;

	// A* algorithm for path finding. The path is set
	// as reached_from links from target node backwards.
	void astar
	(
		Node*				start,		// start node
		Node*				target		// end node
	)
		const
	{
		// Lists for open and closed nodes
		Nodelist open;
		Nodelist closed;

		// Initialize graph nodes.
		for (auto n : _nodes)
		{
			n->_cost_so_far				= std::numeric_limits<double>::max();
			n->_estimated_total_cost	= std::numeric_limits<double>::max();
			n->_reached_from			= 0;
		}

		// Initialize start node and push it to open list.
		start->_cost_so_far = 0;
		open.insert_unique(start);

		// A* iterations. Break out when open list is empty or
		// target node is reached.
		while (1)
		{
			// Get the most promising node from open list (the one
			// with the smallest estimated total cost). Break out
			// if the open list is empty.
			Node* s = open.get_smallest();
			if (!s)
				break;

			// Check out all direct neighbours for s, and
			// update them as necessary.
			for (auto n : s->_neighbours)
			{
				// Distance to n through s.
				double distance = s->_cost_so_far + n.second;

				// Update n if we found a shorter route to it (through s).
				if (distance < n.first->_cost_so_far)
				{
					n.first->_cost_so_far = distance;
					n.first->_estimated_total_cost = distance + n.first->euclidean(target);
					n.first->_reached_from = s;
					open.insert_unique(n.first);
					closed.remove(n.first);
				}

				// Exit A* as soon as we have reached target node
				// (this is not the only possibility).
				if (n.first == target)
					return;
			}

			// Mark s as "processed". 
			closed.insert_unique(s);
		}
	}
};
