#include "worldCupDB.h"

void insert_player_b(player_list_t *player_list, team_list_t *teams)
{
    player_t player;
    int player_code;
    char player_club[50];
    char player_name[50];
    int player_age;

    printf("   Enter player code: ");
    scanf("%d", &player_code);
    printf("   Enter player name: ");
    scanf(" %[^\n]", player_name);
    printf("   Enter player age: ");
    scanf("%d", &player_age);
    printf("   Enter player club: ");
    scanf(" %[^\n]", player_club);
    printf("   Enter player Team Code: ");
    scanf("%d", &player.team_code);

    if (team_code_exists(teams, player.team_code))
    {
        player.player_code = player_code;
        strcpy(player.player_name, player_name);
        player.player_age = player_age;
        strcpy(player.player_club, player_club);
        insert_player(player_list, player);
        printf("Player inserted successfully\n");
    }
    else
    {
        printf("Team code does not exist\n");
    }
}

void search_player_b(player_list_t *player_list)
{
    int player_code;
    printf("   Enter player code: ");
    scanf("%d", &player_code);
    player_t *player = search_player(player_list, player_code);
    if (player == NULL)
    {
        printf("Player not found\n");
    }
    else
    {
        printf("Player code: %d\n", player->player_code);
        printf("Player name: %s\n", player->player_name);
        printf("Player age: %d\n", player->player_age);
        printf("Player club: %s\n", player->player_club);
        printf("Player Team Code: %d\n", player->team_code);
        printf("\n");
    }
}

void update_player(player_list_t *player_list)
{
    int player_code;
    printf("   Enter player code: ");
    scanf("%d", &player_code);
    player_t *player = search_player(player_list, player_code);
    if (player == NULL)
    {
        printf("Player not found\n");
    }
    else
    {
        printf("   Enter player name: ");
        scanf(" %[^\n]", player->player_name);
        printf("   Enter player age: ");
        scanf("%d", &player->player_age);
        printf("   Enter player club: ");
        scanf(" %[^\n]", player->player_club);
        printf("   Enter player Team Code: ");
        scanf("%d", &player->team_code);
        printf("Player updated successfully\n");
    }
}

void print_players_b(player_list_t *player_list)
{
    player_node_t *current = player_list->head;

    printf("%-20s%-30s%-30s%-30s%-30s\n", "Player Code", "Player Name", "Age", "Club", "Team Code");
    while (current != NULL)
    {
        printf("%-20d%-30s%-30d%-30s%-30d\n", current->player.player_code, current->player.player_name, current->player.player_age, current->player.player_club, current->player.team_code);
        current = current->next;
    }
}

void print_team_players(player_list_t *player_list, team_list_t *teams, int team_code)
{
    if (team_code_exists(teams, team_code))
    {
        player_node_t *current = player_list->head;
        printf("%-20s%-30s%-30s%-30s%-30s\n", "Player Code", "Player Name", "Age", "Club", "Team Code");
        while (current != NULL)
        {
            if (current->player.team_code == team_code)
            {
                printf("%-20d%-30s%-30d%-30s%-30d\n", current->player.player_code, current->player.player_name, current->player.player_age, current->player.player_club, current->player.team_code);
            }
            current = current->next;
        }
    }
    else
    {
        printf("Team code does not exist\n");
    }
}

void delete_player_b(player_list_t *player_list)
{
    int player_code;
    printf("   Enter player code: ");
    scanf("%d", &player_code);
    delete_player(player_list, player_code);
}
