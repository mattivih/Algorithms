#include <iostream>
#include <stdio.h>

#define ST_ON_GUARD 1
#define ST_FIGHT 2
#define ST_RUN_AWAY 3

bool see_small_enemy()
{
    printf("Do you see a small enemy 0/1?\n");
    int yes_or_no;
    std::cin >> yes_or_no;
    return (bool)yes_or_no;
}
bool see_big_enemy()
{
    printf("Do you see a big enemy 0/1?\n");
    int yes_or_no;
    std::cin >> yes_or_no;
    return (bool)yes_or_no;
}
bool losing_fight()
{
    printf("Are you losing the fight 0/1?\n");
    int yes_or_no;
    std::cin >> yes_or_no;
    return (bool)yes_or_no;
}
bool escaped()
{
    printf("Run away 0/1?\n");
    int yes_or_no;
    std::cin >> yes_or_no;
    return (bool)yes_or_no;
}
bool got_killed()
{
    printf("Gonna die 0/1?\n");
    int yes_or_no;
    std::cin >> yes_or_no;
    return (bool)yes_or_no;
}

int main() {

    int state = ST_ON_GUARD;
    bool running = true;
    while(running)
    {
        switch (state)
        {
            case ST_ON_GUARD:
                printf("ACTION: On Guard\n");
                if(see_small_enemy())
                    state = ST_FIGHT;
                else if(see_big_enemy())
                    state = ST_RUN_AWAY;
                break;
            case ST_FIGHT:
                printf("ACTION: Fight\n");
                if(losing_fight())
                    state = ST_RUN_AWAY;
                else if(got_killed())
                    running = false;
                break;
            case ST_RUN_AWAY:
                printf("ACTION: Run Away\n");
                if(escaped())
                    state = ST_ON_GUARD;
                break;
        }
    }

    return 0;
}