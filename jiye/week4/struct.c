#include "struct.h"

void set_point(t_point *point);

int main(){
    t_point point;

    set_point(&point);
    printf("%d, %d, %s\n", point.x, point.y, point.str);
    return(0);
}

void set_point(t_point *point){
    point->x = 42;
    point->y = 21;
    strcpy(point->str, "good");
}