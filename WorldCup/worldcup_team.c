#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "worldCupDB.h"

void insert_team(team_list_t *teams)
{
    int team_code;
    printf("   Enter team code: ");
    scanf("%d", &team_code);
    
    if (team_code < 0 || team_code > 31)
    {
        printf("Team code must be between 0 and 31 inclusive\n");
        return;
    }
    else if (team_code_exists(teams, team_code))
    {
        printf("Team code already exists.\n");
        return;
    }
    else if (count_teams(teams) == TOTAL_TEAMS_DB)
    {
        printf("Database is full\n");
        return;
    }

    char team_name[25];
    // read the team name
    printf("   Enter team name: ");
    scanf(" %[^\n]", team_name);
    // check if the team name is too long
    if (strlen(team_name) > 24)
    {
        printf("Team name is too long\n");
        return;
    }

    char group_seeding[3];
    printf("   Enter group seeding: ");
    scanf("%s", group_seeding);
    if (strlen(group_seeding) != 2)
    {
        printf("Group seeding must be two characters\n");
        return;
    }

    char group = group_seeding[0];
    char seed = group_seeding[1];
    if (group < 'A' || group > 'H')
    {
        printf("Group must be between A and H inclusive\n");
        return;
    }
    else if (seed < '1' || seed > '4')
    {
        printf("Seed must be between 1 and 4 inclusive\n");
        return;
    }

    char primary_kit;
    printf("   Enter primary kit colour: ");
    scanf(" %c", &primary_kit);
    if (primary_kit != 'R' && primary_kit != 'O' && primary_kit != 'Y' && primary_kit != 'G' && primary_kit != 'B' && primary_kit != 'I' && primary_kit != 'V')
    {
        printf("Primary kit colour must be one of R, O, Y, G, B, I, V\n");
        return;
    }


    printf("\n");

    // create a new team
    team_t team;
    team.team_code = team_code;
    strcpy(team.team_name, team_name);
    strcpy(team.group_seeding, group_seeding);
    team.primary_kit = primary_kit;

    // add the team to the linked list
    add_team(teams, team);

    printf("Team inserted successfully\n\n");
}

void search_team_b(team_list_t *teams)
{
    int team_code;
    printf("   Enter team code: ");
    scanf("%d", &team_code);
    if (team_code < 0 || team_code > 31)
    {
        printf("\nTeam code must be between 0 and 31 inclusive\n");
        return;
    }
    else if (!team_code_exists(teams, team_code))
    {
        printf("\nTeam code does not exist\n");
        return;
    }

    printf("\n");
    team_t *team = search_team(teams, team_code);
    if (team != NULL)
    {
        printf("Team code: %d\n", team->team_code);
        printf("Team name: %s\n", team->team_name);
        printf("Group seeding: %s\n", team->group_seeding);
        printf("Primary kit colour: %c\n", team->primary_kit);
    }
    else
    {
        printf("Team code does not exist\n");
    }
    printf("\n");
}

void update_team(team_list_t *teams)
{
    int team_code;
    printf("   Enter team code: ");
    scanf("%d", &team_code);
    if (team_code < 0 || team_code > 31)
    {
        printf("\nTeam code must be between 0 and 31 inclusive\n");
        return;
    }
    else if (!team_code_exists(teams, team_code))
    {
        printf("\nTeam code does not exist\n");
        return;
    }

    char team_name[25];
    // read the team name
    printf("   Enter team name: ");
    scanf(" %[^\n]", team_name);
    // check if the team name is too long
    if (strlen(team_name) > 24)
    {
        printf("\nTeam name is too long\n");
        return;
    }

    char group_seeding[3];
    printf("   Enter group seeding: ");
    scanf("%s", group_seeding);
    if (strlen(group_seeding) != 2)
    {
        printf("\nGroup seeding must be two characters\n");
        return;
    }

    char group = group_seeding[0];
    char seed = group_seeding[1];
    if (group < 'A' || group > 'H')
    {
        printf("\nGroup must be between A and H inclusive\n");
        return;
    }
    else if (seed < '1' || seed > '4')
    {
        printf("\nSeed must be between 1 and 4 inclusive\n");
        return;
    }

    char primary_kit;
    printf("   Enter primary kit colour: ");
    scanf(" %c", &primary_kit);
    if (primary_kit != 'R' && primary_kit != 'O' && primary_kit != 'Y' && primary_kit != 'G' && primary_kit != 'B' && primary_kit != 'I' && primary_kit != 'V')
    {
        printf("\nPrimary kit colour must be one of R, O, Y, G, B, I, V\n");
        return;
    }

    printf("\n");

    // find the first empty spot in the array
    team_t *team = search_team(teams, team_code);
    if (team != NULL)
    {
        strcpy(team->team_name, team_name);
        strcpy(team->group_seeding, group_seeding);
        team->primary_kit = primary_kit;
    }

    printf("Team updated successfully\n\n");
}

// delete a team prompt
void delete_team_b(team_list_t *teams)
{
    int team_code;
    printf("   Enter team code: ");
    scanf("%d", &team_code);
    if (team_code < 0 || team_code > 31)
    {
        printf("\nTeam code must be between 0 and 31 inclusive\n");
        return;
    }
    else if (!team_code_exists(teams, team_code))
    {
        printf("\nTeam code does not exist\n");
        return;
    }

    printf("\n");
    delete_team(teams, team_code);

    printf("Team deleted successfully\n\n");
}

void print_teams(team_list_t *teams)
{
    // Give 30 spaces each
    printf("%-20s%-30s%-30s%-30s\n", "Team Code", "Team Name", "Group Seeding", "Primary Kit Colour");
    team_node_t *current = teams->head;
    while (current != NULL)
    {
        printf("%-20d%-30s%-30s%-30c\n", current->team.team_code, current->team.team_name, current->team.group_seeding, current->team.primary_kit);
        current = current->next;
    }
}

void quit()
{
    printf("Bye!\n");
    exit(0);
}

int main()
{
    team_list_t *teams = malloc(sizeof(team_list_t) * TOTAL_TEAMS_DB);
    init_team_list(teams);
    // initialise the array set each node team_code to -1
    team_node_t *node = teams->head;
    while (node != NULL)
    {
        node->team.team_code = -1;
        node = node->next;
    }

    player_list_t player_list;
    init_player_list(&player_list);

    printf("******************\n");
    printf("* 2211 World Cup *\n");
    printf("******************\n");
    printf("\n");

    // print the menu
    while (1)
    {
        printf("h. Help\n");
        printf("t. Control teams\n");
        printf("p. Control players\n");
        printf("q. Quit\n");
        printf("Enter operation code: ");

        char choice;
        scanf(" %c", &choice);

        printf("\n");
        switch (choice)
        {
        case 'h':
            printf("This program manages the teams and players for the World Cup\n");
            printf("To control teams, enter t\n");
            printf("To control players, enter p\n");
            printf("To quit, enter q\n");
            break;
        case 'q':
            quit();
            break;
        case 't':
            while (1)
            {
                printf("   i. Insert a team\n");
                printf("   s. Search a team\n");
                printf("   u. Update a team\n");
                printf("   p. Print all teams\n");
                printf("   d. Delete a team\n");
                printf("   r. Print team registered players\n");
                printf("   b. Back to the Main Menu\n");
                printf("   Enter operation code: ");

                char choice;
                scanf(" %c", &choice);

                printf("\n");
                switch (choice)
                {
                case 'i':
                    insert_team(teams);
                    continue;
                case 's':
                    search_team_b(teams);
                    continue;
                case 'u':
                    update_team(teams);
                    continue;
                case 'p':
                    print_teams(teams);
                    continue;
                case 'd':
                    delete_team_b(teams);
                    continue;
                case 'r':
                    printf("Enter team code: ");
                    int team_code;
                    scanf("%d", &team_code);
                    print_team_players(&player_list, teams, team_code);
                    continue;
                case 'b':
                    break;
                default:
                    printf("Invalid choice\n");
                    continue;
                }

                if (choice == 'b')
                {
                    break;
                }

                printf("\n");
            }
            break;
        case 'p':
            while (1)
            {
                printf("   i. Insert player\n");
                printf("   s. Search player\n");
                printf("   u. Update player\n");
                printf("   p. Print players\n");
                printf("   d. Delete player\n");
                printf("   b. Back to main Menu\n");
                printf("   Enter operation code: ");

                char choice;
                scanf(" %c", &choice);

                printf("\n");
                switch (choice)
                {
                case 'i':
                    insert_player_b(&player_list, teams);
                    continue;
                case 's':
                    search_player_b(&player_list);
                    continue;
                case 'u':
                    update_player(&player_list);
                    continue;
                case 'p':
                    print_players_b(&player_list);
                    continue;
                case 'd':
                    delete_player_b(&player_list);
                    continue;
                case 'b':
                    break;
                default:
                    printf("Invalid choice\n");
                }

                if (choice == 'b')
                {
                    break;
                }

                printf("\n");
            }
            break;
        default:
            printf("Invalid choice\n");
            break;
        }

        printf("\n");
    }

    return 0;
}