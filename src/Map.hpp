/* Map.hpp */

#ifndef MAP_HPP
#define MAP_HPP

#include "Object.hpp"

class Map : public Object {
	private:
		const int _dimension[2];	// width and hight
		unsigned char **_walkable;
		
	public:
		Map();
		~Map();
		int get_width() const;
		int get_hight() const;
};

#endif /* MAP_HPP */
