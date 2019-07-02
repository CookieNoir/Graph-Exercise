class Vector2 {
public:
	int x;
	int y;
	Vector2() {
		x = 0;
		y = 0;
	}
	Vector2(int u, int v) {
		set(u, v);
	}
	bool fitsIn(Vector2 target);
	void set(int u, int v);
};
