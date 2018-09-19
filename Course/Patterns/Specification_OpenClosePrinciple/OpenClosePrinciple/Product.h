#pragma once

enum class Color { red, green, blue };
enum class Size { small, medium, large };

struct Product
{
	string name;
	Color color;
	Size size;
};
