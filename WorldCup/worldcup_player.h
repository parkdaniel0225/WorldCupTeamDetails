#ifndef WORLD_CUP_PLAYER_H
#define WORLD_CUP_PLAYER_H

#include "worldcup_team.h"

struct player
{
    int player_code;
    char player_name[50];
    int player_age;
    char player_club[50];
    int team_code;
};
typedef struct player player_t;

// Player Node for linked list
struct player_node
{
    player_t player;
    struct player_node *next;
};
typedef struct player_node player_node_t;

// Player linked list
struct player_list
{
    player_node_t *head;
    player_node_t *tail;
};
typedef struct player_list player_list_t;

void insert_player_b(player_list_t *player_list, team_list_t *teams);
void search_player_b(player_list_t *player_list);
void update_player(player_list_t *player_list);
void print_players_b(player_list_t *player_list);
void print_team_players(player_list_t *player_list, team_list_t *teams, int team_code);
void delete_player_b(player_list_t *player_list);

#endif // WORLD_CUP_PLAYER_H