#include <iostream>

/*
	Game world interface.
*/

class Game_World
{
public:

    static void do_run()				{ std::cout << "RUNNING\n";				}
    static void do_shoot()				{ std::cout << "SHOOTING\n";			}
    static void find_target()			{ std::cout << "FINDING TARGET\n";		}
    static void find_safe_area()		{ std::cout << "FINDING SAFE AREA\n";	}
    static void search_shot_source()	{ std::cout << "SEARCHING SOURCE\n";	}
};

/*
	Implement your exercises here.
*/
int main()
{
    bool input;

    std::cout << "Is the shooter visible? 1(yes), 0(no) ?" << std::endl;
    std::cin >> input;

    if(input) {
        std::cout << "Is the shooter friendly? 1(yes), 0(no) ?" << std::endl;
        std::cin >> input;
        if(input)
            Game_World::find_target();
        else
            std::cout << "Do you have less than 10 ammo left? 1(yes), 0(no) ?" << std::endl;
            std::cin >> input;
            if(input)
                Game_World::do_run();
            else
                Game_World::do_shoot();
    }else
        std::cout << "Do you have support available? 1(yes), 0(no) ?" << std::endl;
        std::cin >> input;
        if(input)
            Game_World::search_shot_source();
        else
            Game_World::find_safe_area();

    return 0;
}