//ptinrect: return 1 if p in r, 0 if not
int ptinrect(struct point p, struct rect r){
    return p.x > r.pt.x && p.x < r.p2.x
        && p.y >= r.pt1.y && p.y < r.pt2.y;
}
