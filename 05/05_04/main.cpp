#include <iostream>
#include <stdio.h>
#define ST_WAIT 1
#define ST_ATTACK 2
#define ST_FLEE 3
#define ST_HEAL 4

class Game_World
{
public:

    static bool is_opponent_nearby()
    {
        std::cout << "Is opponent nearby (0/1)?\n";
        return (bool)get_int_from_stdin();
    }

    static bool is_friend_wounded()
    {
        std::cout << "Is friend wounded (0/1)?\n";
        return (bool)get_int_from_stdin();
    }

    static bool am_i_wounded()
    {
        std::cout << "Am I wounded (0/1)?\n";
        return (bool)get_int_from_stdin();
    }

    static int get_int_from_stdin()
    {
        int retval;
        std::cin >> retval;
        return retval;
    }
};

int main()
{
    Game_World* Game = new Game_World;
    int state = ST_WAIT;

    while(1)
    {
        switch (state)
        {
            case ST_WAIT:
                printf("STATE: Waiting\n");
                if(Game->is_friend_wounded())
                    state = ST_HEAL;
                else if(Game->is_opponent_nearby())
                    state = ST_ATTACK;
                break;
            case ST_ATTACK:
                printf("STATE: Attack\n");
                if(Game->am_i_wounded())
                    state = ST_FLEE;
                else if(Game->is_friend_wounded())
                    state = ST_HEAL;
                else if(!Game->is_opponent_nearby())
                    state = ST_WAIT;
                break;
            case ST_HEAL:
                printf("STATE: Heal\n");
                if(Game->am_i_wounded())
                    state = ST_FLEE;
                else if(!Game->is_friend_wounded())
                    state = ST_ATTACK;
                break;
            case ST_FLEE:
                printf("STATE: Flee\n");
                if(!Game->am_i_wounded())
                    state = ST_WAIT;
                break;
        }
    }

    return 0;
}
