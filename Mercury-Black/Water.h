#ifndef WATER_H
#define WATER_H

#include <SFML\Graphics.hpp>
#include <vector>
#include <map>

const enum WaterType {
	WATERTYPE_INK,
	WATERTYPE_WATER
};

class Spring {

public:

	void update();

	Spring(float x, float targetHeight);

	float x;

	float speed;
	float height;
	float targetHeight;

};

class Water {

public:

	void splash(size_t index, float speed);

	void update();
	void draw(sf::RenderWindow * window);

	void clean();

	Water(sf::Vector2f corner1, sf::Vector2f corner2, WaterType type);

	//private:

	sf::VertexArray waterShape;
	std::vector<Spring *> springs;

	sf::Vector2f topLeft;
	sf::Vector2f bottomRight;

	WaterType type;
	sf::RectangleShape rect;

	float targetHeight;
	float x;
	float length;
	float depth;

};

class WaterHandler {

public:

	std::map<float, Water *>::iterator selected;

	void insert(sf::Vector2f topLeft, sf::Vector2f, WaterType type);
	void remove();

	void dealDamage(struct World * world);
	void updateWaves(float dt);
	void update();
	void draw(sf::RenderWindow * window);

	std::map <float, Water *>::iterator findClosest(sf::Vector2f);
	std::map <float, Water *>::iterator findRight(float x);
	std::map <float, Water *>::iterator findLeft(float x);

	void clean();

	void save();
	void load();

	//private:

	float waveOffset;
	std::map<float, Water *> map;

};

#endif