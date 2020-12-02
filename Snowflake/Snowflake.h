#ifndef SNOWFLAKE_H
#define SNOWFLAKE_H

class Snowflake
{
private:
	sf::RenderWindow * window;
	sf::CircleShape circle;

	int width, height;

	int x, y;
	float r;

private:
	float dist(float x1, float y1, float x2, float y2);

public:
	Snowflake();
	Snowflake(sf::RenderWindow * wnd, int width, int height);
	virtual ~Snowflake();

	void update();
	void render(sf::RenderTarget * target = NULL);
	bool finished();
	bool intersect(std::vector<Snowflake> s);
	int getX();
	int getY();
};

#endif // !SNOWFLAKE_H