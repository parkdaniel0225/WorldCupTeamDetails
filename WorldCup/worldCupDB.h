#ifndef WORLD_CUP_DB_H
#define WORLD_CUP_DB_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "worldcup_player.h"
#include "worldcup_team.h"

void init_player_list(player_list_t *list);
void insert_player(player_list_t *player_list, player_t player);
void print_players(player_list_t *player_list);
void delete_player(player_list_t *player_list, int player_code);
player_t *search_player(player_list_t *player_list, int player_code);

void init_team_list(team_list_t *team_list);
void add_team(team_list_t *team_list, team_t team);
void print_team_list(team_list_t *team_list);
void delete_team(team_list_t *team_list, int team_code);
team_t *search_team(team_list_t *team_list, int team_code);
int team_code_exists(team_list_t *team_list, int team_code);
int count_teams(team_list_t *teams);

#endif // WORLD_CUP_DB_H