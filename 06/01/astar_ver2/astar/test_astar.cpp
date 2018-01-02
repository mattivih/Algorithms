#include <iostream>
#include "graph.h"
#include "node.h"


// For testing A* algorithm
int main()
{

	// Create a graph object.
	Graph g;

    // Generate the grid
    Node grid[100][100];
    for (unsigned x = 1; x < 99; ++x)
        for (unsigned y = 1; y < 99; ++y)
        {
            grid[x][y]._neighbours.push_back(std::pair<Node*,double>(&grid[x][y-1], 1));    // Visualition in order:
            grid[x][y]._neighbours.push_back(std::pair<Node*,double>(&grid[x-1][y], 1));    //    3
            grid[x][y]._neighbours.push_back(std::pair<Node*,double>(&grid[x][y+1], 1));    //  2 X 4
            grid[x][y]._neighbours.push_back(std::pair<Node*,double>(&grid[x+1][y], 1));    //    1
            grid[x][y]._x = x;
            grid[x][y]._y = y;
            grid[x][y]._name = "(" + std::to_string(x) + "," + std::to_string(y) + ")";
            g._nodes.push_back(&grid[x][y]);
        }

    // Add 'wall' to the grid
    int wall_length = 10;
    int start_pos_x = 10;
    int start_pos_y = 10;
    for(start_pos_x; 0 < wall_length; --wall_length)
    {
        grid[start_pos_x][start_pos_y]._x = 0;
        grid[start_pos_x][start_pos_y]._y = 0;
        start_pos_y++;

    }

	// Call A* to find a path.
	Node* start = &grid[5][15];
	Node* target = &grid[25][15];
	g.astar(start, target);

	// Print path by following reached_from links.
	Node* s = target;
	while (s)
	{
		std::cout << s->_name << " (" << s->_cost_so_far << ")\n";
		s = s->_reached_from;
	}

	return 0;
}
