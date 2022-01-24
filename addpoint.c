//addpoint: add two points
struct point addPoint(struct point p1, struct point p2){
    p1.x += p2.x;
    p1.y += p2.y;

    return p1;
}
