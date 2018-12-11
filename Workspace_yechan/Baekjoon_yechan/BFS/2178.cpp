// baekjoon 2178 reference
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX_INPUT_SIZE 101

// -- Global variables

typedef unsigned int	(u32);
typedef unsigned short  (u16);
typedef unsigned char	(u8);

typedef signed int		(s32);
typedef signed short	(s16);
typedef signed char		(s8);

// Input
u32 g_width, g_height;
u8 input_buf[MAX_INPUT_SIZE][MAX_INPUT_SIZE];

// BFS - Queue
typedef struct _tag_POSITION{
	u32 pos_x;
	u32 pos_y;
}__POS;

u32 Q_front_flag;

u32 Q_rear_flag;

__POS Queue[MAX_INPUT_SIZE * MAX_INPUT_SIZE];

#define ENQUEUE(x, y, Q_pos) 	do { Queue[Q_pos].pos_x = (u32)x; Queue[Q_pos].pos_y = (u32)y; Q_pos++; } while(0)
#define DEQUEUE(x, y, Q_pos) 	do { x = Queue[Q_pos].pos_x; y = Queue[Q_pos].pos_y; Q_pos++; } while(0)

//BFS - visit buf
u8 visit_buf[MAX_INPUT_SIZE][MAX_INPUT_SIZE];

// Result
u32 g_opt_length;

static void SetInputBuffer( void )
{
	u32 i, j;

	scanf("%d %d", &g_height, &g_width);

	for (i = 0; i < g_height; i++)
	{
		for (j = 0; j < g_width; j++)
		{
			scanf(" %c", &input_buf[i][j]);
		}
	}
}

static __inline void CheckUnvisitedNode( s32 pos_x, s32 pos_y )
{
	if ((visit_buf[pos_y][pos_x] == 0) && (input_buf[pos_y][pos_x] == '1'))
	{
		ENQUEUE(pos_x, pos_y, Q_rear_flag);
		visit_buf[pos_y][pos_x] = 1;
	}
}

static void BFS( s32 pos_x, s32 pos_y )
{
	if (pos_y + 1 < g_height) 	CheckUnvisitedNode( pos_x, pos_y + 1);
	if (pos_y >= 1) 			CheckUnvisitedNode( pos_x, pos_y - 1);
	if(pos_x + 1 < g_width)		CheckUnvisitedNode( pos_x + 1, pos_y);
	if(pos_x >= 1) 				CheckUnvisitedNode( pos_x - 1, pos_y);
}

s32 main(void)
{
	u32 bound_for_next_step = 0;

	SetInputBuffer();

	ENQUEUE(0, 0, Q_rear_flag);
	visit_buf[0][0] = 1;
	bound_for_next_step = Q_rear_flag;
	do {
		u32 curr_pos_x, curr_pos_y;

		DEQUEUE(curr_pos_x, curr_pos_y, Q_front_flag);
		BFS(curr_pos_x, curr_pos_y);

		if ((curr_pos_x == (g_width - 1)) && (curr_pos_y == (g_height - 1))){
			break;
		}

		if(Q_front_flag == bound_for_next_step)
		{
			bound_for_next_step = Q_rear_flag;
			g_opt_length++;
		}

	} while (Q_front_flag < Q_rear_flag);

	printf("%d\n", g_opt_length + 1);

	return 0;
}