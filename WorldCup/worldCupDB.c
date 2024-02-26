
#include "worldCupDB.h"

// Function definitions
void init_player_list(player_list_t *list)
{
    list->head = NULL;
    list->tail = NULL;
}

void insert_player(player_list_t *player_list, player_t player)
{
    player_node_t *new_node = (player_node_t *)malloc(sizeof(player_node_t));
    new_node->player = player;
    new_node->next = NULL;

    if (player_list->head == NULL)
    {
        player_list->head = new_node;
        player_list->tail = new_node;
    }
    else
    {
        player_list->tail->next = new_node;
        player_list->tail = new_node;
    }
}

void print_players(player_list_t *player_list)
{
    player_node_t *current = player_list->head;
    while (current != NULL)
    {
        printf("Player code: %d\n", current->player.player_code);
        printf("Player name: %s\n", current->player.player_name);
        printf("Player age: %d\n", current->player.player_age);
        printf("Player club: %s\n", current->player.player_club);
        printf("\n");
        current = current->next;
    }
}

void delete_player(player_list_t *player_list, int player_code)
{
    player_node_t *current = player_list->head;
    player_node_t *previous = NULL;
    while (current != NULL)
    {
        if (current->player.player_code == player_code)
        {
            if (previous == NULL)
            {
                player_list->head = current->next;
            }
            else
            {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

player_t *search_player(player_list_t *player_list, int player_code)
{
    player_node_t *current = player_list->head;
    while (current != NULL)
    {
        if (current->player.player_code == player_code)
        {
            return &current->player;
        }
        current = current->next;
    }
    return NULL;
}

// init team list
void init_team_list(team_list_t *team_list)
{
    team_list->head = NULL;
    team_list->tail = NULL;
}

int count_teams(team_list_t *team_list)
{
    int count = 0;
    team_node_t *current = team_list->head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

int team_code_exists(team_list_t *team_list, int team_code)
{
    team_node_t *current = team_list->head;
    while (current != NULL)
    {
        if (current->team.team_code == team_code)
        {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

// add a team to the end of the list
void add_team(team_list_t *team_list, team_t team)
{
    team_node_t *new_node = malloc(sizeof(team_node_t));
    new_node->team = team;
    new_node->next = NULL;
    if (team_list->head == NULL)
    {
        team_list->head = new_node;
        team_list->tail = new_node;
    }
    else
    {
        team_list->tail->next = new_node;
        team_list->tail = new_node;
    }
}

// search for a team by team code
team_t *search_team(team_list_t *team_list, int team_code)
{
    team_node_t *current = team_list->head;
    while (current != NULL)
    {
        if (current->team.team_code == team_code)
        {
            return &current->team;
        }
        current = current->next;
    }
    return NULL;
}

// delete team from list
void delete_team(team_list_t *team_list, int team_code)
{
    team_node_t *current = team_list->head;
    team_node_t *previous = NULL;
    while (current != NULL)
    {
        if (current->team.team_code == team_code)
        {
            if (previous == NULL)
            {
                team_list->head = current->next;
            }
            else
            {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}