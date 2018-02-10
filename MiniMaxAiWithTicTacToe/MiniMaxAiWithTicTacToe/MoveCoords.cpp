class MoveCoords
{
	int x_;
	int y_;
public:
	MoveCoords(int x, int y) : x_(x), y_(y){}
	MoveCoords(){}

	int GetX() { return x_; }
	int GetY() { return y_; }
	void SetX(int x) { x_ = x; }
	void SetY(int y) { y_ = y; }
};