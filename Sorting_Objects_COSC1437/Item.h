#pragma once
#include <string>

#include "RandomXorShift.h"

enum Type
{
	Sword, Shield, Gun
};

class Item
{
	float price, shopScaler;
	int Atk, Dmg, Def;
	int Spec = 0;

	std::string name;
	std::string description;
	Type type;

	RandomXorShift& rng;

	void generateStats(bool isSpec = false);
	std::string generateName();
	Type getRandType();
public:
	Item(Type type, RandomXorShift& rng, bool spec = false);
	Item(RandomXorShift& rng, bool spec = false);

	inline int getAtk() const { return Atk; }
	inline int getDmg() const { return Dmg; }
	inline int getDef() const { return Def; }
	inline int getSpec() const { return Spec; }

	inline Type getType() const { return type; }

	int getPrice(bool isShop = false) const;

	inline std::string getDescription() const { return description; }
	inline std::string getName() const { return name; }

	void setDescription(std::string newDescription) { description = newDescription; }
};
