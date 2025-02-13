#include "so_long.h"

void find_enemy(t_vars *game)
{
    int x;
    int y;

    y = 0;
    while (game->map[y])
    {
        x = 0;
        while (game->map[y][x])
        {
            if (game->map[y][x] == 'H')
            {
                game->enemy_x = x;
                game->enemy_y = y;
                return;
            }
            x++;
        }
        y++;
    }
}
void move_enemy(t_vars *game)
{
    int next_x = game->enemy_x;
    int next_y = game->enemy_y;

    // نختار اتجاه عشوائي (0: يمين، 1: يسار، 2: فوق، 3: تحت)
    int direction = rand() % 4;

    if (direction == 0)      // يمين
        next_x++;
    else if (direction == 1) // يسار
        next_x--;
    else if (direction == 2) // فوق
        next_y--;
    else if (direction == 3) // تحت
        next_y++;

    // نتحقق إذا المكان الجديد ما فيهش حاجز ('1') أو بيت ('E') أو هدية ('C')
    if (game->map[next_y][next_x] != '1' && 
        game->map[next_y][next_x] != 'E' &&
        game->map[next_y][next_x] != 'C')
    {
        game->map[game->enemy_y][game->enemy_x] = '0'; // نحرك العدو من مكانه القديم
        game->enemy_x = next_x;                       // نحدد الإحداثيات الجديدة
        game->enemy_y = next_y;
        game->map[game->enemy_y][game->enemy_x] = 'H'; // نضع العدو في المكان الجديد
    }
}

int game_loop(t_vars *game)
{
    static int count = 0;
    
    count++;
    if (count % game->enemy_speed == 0) // كتتحرك العدو كل `enemy_speed` دورات
    {
        move_enemy(game);
        render_map(game);  // كتحدث الخريطة بعد الحركة
    }
    
    check_enemy_collision(game); // كتتحقق من التصادم
    animation_loop(game);       // كتحدث الرسوم المتحركة
    
    return (0);
}

void check_enemy_collision(t_vars *game)
{
    if (game->player_x == game->enemy_x && game->player_y == game->enemy_y)
    {
        printf("\nGame Over! L3zwa klatk!\n");
        ft_exit(game);
    }
}
