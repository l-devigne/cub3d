MATHS TO COMPUTE RAYS AND GET THE REAL DISTANCE TO WALL COORDINATES

create player :
```
typedef struct s_player
{
    double x;        // player position in map (coordinate in origin, middle of the tile so float/double)
    double y;

    double dir_x;    // direction vector (where the player face)
    double dir_y;

    double plane_x;  // 2D camera plane (field of view angle of view from one side need to * 2 to ahve the whole view)
    double plane_y;

}            t_player;
```

ray direction calculation ():
```
rayDir = dir + plane * cameraX;

dir : vector (dir_x, dir_y);
plane : vector (plane_x, plane_y);
cameraX : we break the range of possibility of view [-1, 1] in number if stripe of pixels rays.
        cameraX = 2 * x / (double)screen_width - 1; with x the digit of each stripe x.
```

example :
```
rayDir = (0, -1) + (0.66, 0) * (-1)
       = (0, -1) + (-0.66, 0)
       = (-0.66, -1)
```
DDA algorithm (incrementation of) step by step for one ray :

start position :
```
    double rayPosX = player.x;
    double rayPosY = player.y;
```
tab cell associated :
```
    int mapX = (int)rayPosX;
    int mapY = (int)rayPosY;
```
calculate the difference to move to the next tile :
```
    double deltaDistX = fabs(1 / rayDirX);
    double deltaDistY = fabs(1 / rayDirY);
```
determine how do we increment in the map(char **) and how to increment on x and y in the grid(real grid with tiles)
```
    if (rayDirX < 0) { stepX = -1; sideDistX = (rayPosX - mapX) * deltaDistX; }
    else             { stepX = +1; sideDistX = (mapX + 1.0 - rayPosX) * deltaDistX; }

    if (rayDirY < 0) { stepY = -1; sideDistY = (rayPosY - mapY) * deltaDistY; }
    else             { stepY = +1; sideDistY = (mapY + 1.0 - rayPosY) * deltaDistY; }
```
advance on the grid and map until 1 is found in the map
```
int hit = 0;
int side; // 0 = x-side, 1 = y-side
while (hit == 0)
{
    if (sideDistX < sideDistY)
    {
        sideDistX += deltaDistX;
        mapX += stepX;
        side = 0;
    }
    else
    {
        sideDistY += deltaDistY;
        mapY += stepY;
        side = 1;
    }
    if (map->grid[mapY][mapX] == '1')
        hit = 1;
}
```
and then we have : 
- the cell coordinate with a wall in the map
- the side that we hit with the ray (side or face)

calculate the real distance to the wall and determine the height on the screen and fill the whole stripe
```
double perpWallDist;
if (side == 0)
    perpWallDist = (mapX - rayPosX + (1 - stepX) / 2) / rayDirX;
else
    perpWallDist = (mapY - rayPosY + (1 - stepY) / 2) / rayDirY;
```
RENDERING AND STRIPE TRACING

wall height computing
```
    int lineHeight = (int)(screen_height / perpWallDist);
```
wall start and end on a stripe
```
    int drawStart = -lineHeight / 2 + screen_height / 2;
    if (drawStart < 0) drawStart = 0;

    int drawEnd = lineHeight / 2 + screen_height / 2;
    if (drawEnd >= screen_height) drawEnd = screen_height - 1;
```
choose textures
```
    char *texture;
    if (side == 0 && rayDirX > 0)
        texture = map->east_texture;
    else if (side == 0 && rayDirX < 0)
        texture = map->west_texture;
    else if (side == 1 && rayDirY > 0)
        texture = map->south_texture;
    else
        texture = map->north_texture;
```
draw the full stripe
```
    for (int y = 0; y < screen_height; y++)
    {
        if (y < drawStart)
        {
            // ceiling
            put_pixel(x, y, map->ceiling_color);
        }
        else if (y >= drawStart && y <= drawEnd)
        {
            // wall (use texture sampling here, simple example = solid color)
            put_pixel(x, y, 0xFFFFFF); // white wall
        }
        else
        {
            // floor
            put_pixel(x, y, map->floor_color);
        }
    }
```





