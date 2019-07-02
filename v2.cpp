#include "v2.h"
bool Vector2::fitsIn(Vector2 target) {
	if ((x <= target.x&&y <= target.y) || (x <= target.y&&y <= target.x)) return true;
	else return false;
}
void Vector2::set(int u, int v) {
	x = u;
	y = v;
}