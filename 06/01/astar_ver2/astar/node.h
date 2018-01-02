#pragma once
#include <math.h>
#include <string>
#include <vector>


// Node in navigation graph.
//
// A node knows:
// - its name
// - its neighbours (the nodes it is directly connected to)
// - distance to each neighbour
// - its location (x, y coordinates)
// - "cost-so-far", i.e. length of a path from start node to the node
// - "estimated-total-cost", i.e. "cost-so-far" + estimated path lenght to target node 
//
// A node can:
// - calculate its euclidean distance to given another node.
class Node
{
public:

	// Constructors.
	Node() {}
	Node(const std::string& name) : _name(name) {}

	std::string _name;									// Node name.
	std::vector<std::pair<Node*, double>> _neighbours;	// Neighbours (vector of (node, distance) pairs).
	Node* _reached_from = 0;							// From which node was the node reached from along the shortest path.
	double _x = 0;										// Location x-coordinate.
	double _y = 0;										// Location y-coordinate.
	double _cost_so_far = 0;							// Know distance from start node to this node.
	double _estimated_total_cost = 0;					// Estimated total distance to target through this node.

	// Calculates euclidean distance from this node another node n.
	double euclidean(const Node* n)
	{
		// https://fi.wikipedia.org/wiki/V%C3%A4limatka
		return sqrt((n->_x - _x) * (n->_x - _x) + (n->_y - _y) * (n->_y - _y));
	}
};
