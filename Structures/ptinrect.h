/* ptinrect: возвращает 1, если р в г, и 0 в противном случае */
int ptinrect(struct point p, struct rect r)
{
	return p.x >= r.ptl.x && p.x < r.pt2.x && p.y >= r.ptl.y && p.y < r.pt2.y;
}
