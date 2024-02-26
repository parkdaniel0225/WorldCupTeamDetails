#ifndef WORLD_CUP_TEAM_H
#define WORLD_CUP_TEAM_H

#define TOTAL_TEAMS_DB 32

struct team
{
    int team_code;
    char team_name[25];
    char group_seeding[3];
    char primary_kit;
};

typedef struct team team_t;

// team node for linked list
struct team_node
{
    team_t team;
    struct team_node *next;
};
typedef struct team_node team_node_t;

// linked list of teams
struct team_list
{
    team_node_t *head;
    team_node_t *tail;
};
typedef struct team_list team_list_t;

void insert_team(team_list_t *teams);
void search_team_b(team_list_t *teams);
void update_team(team_list_t *teams);
void delete_team_b(team_list_t *teams);
void print_teams(team_list_t *teams);
void quit();

#endif // WORLD_CUP_TEAM_H