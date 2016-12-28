#ifndef FDF_DEFINES_H
# define FDF_DEFINES_H

# define UP 65362
# define DOWN 65364
# define LEFT 65363
# define RIGHT 65361
# define ZOOM 65451
# define DEZOOM 65453
# define Z_MINE 109
# define Z_PLUS 112
# define ECHAP 65307

# define WIDTH 1500
# define HEIGHT 750
# define XCENTER (WIDTH / 2)   
# define YCENTER (HEIGHT / 2)
# define OFF 1.00
# define YOFF 1.00
# define CT1 0.5
# define CT2 0.5
# define SIZX e->coord[0][0]->size_x
# define SIZY e->coord[0][0]->size_y

# define XR1(x) (x*(cos(e->roty)))
# define XR2(x) (x*(cos((e->roty) + M_PI/2)))
# define YR1(y) (y*(sin(e->roty))*(sin(e->rot)))
# define YR2(y) (y*(sin((e->roty) + M_PI/2))*(sin(e->rot)))
# define XA CT1*XR1(e->inc->x1) + CT2*XR2(e->inc->y1)
# define YA -((e->inc->z) * sin((e->rot) + M_PI/2)) + (CT1/2*YR1(e->inc->x1)) + CT2/2*YR2(e->inc->y1)
# define XB CT1*XR1(e->inc->x2) + CT2*XR2(e->inc->y1)
# define YB -((e->inc->z2) * sin((e->rot) + M_PI/2)) + CT1/2*YR1(e->inc->x2) + CT2/2*YR2(e->inc->y1)
# define XC CT1*XR1(e->inc->x1) + CT2*XR2(e->inc->y2)
# define YC -((e->inc->z3) * sin((e->rot) + M_PI/2)) + CT1/2*YR1(e->inc->x1) + CT2/2*YR2(e->inc->y2)

#endif
