#include <iostream>
#include "Classes.h"
using namespace std;

class Item;
class FireSpell;
class IceSpell;
class LightningSpell;

////////////////////////////////////////////
////////////////////////////////////////////Item
////////////////////////////////////////////

Item::Item()
{}

Item::Item(string name_, int price_, int minimum_lvl_) 
{
	name = name_;
	price = price_;
	minimum_lvl = minimum_lvl_;
}

Item::~Item()
{}

int Item::get_price()
{
	return price;
}

int Item::get_level()
{
	return minimum_lvl;
}

string Item::get_name()
{
	return name;	
}

////////////////////////////////////////////
////////////////////////////////////////////Weapon
////////////////////////////////////////////

Weapon::Weapon(string name_, int price_, int minimum_lvl_, int damage_, bool wield_) : Item(name_, price_, minimum_lvl_)
{
	damage = damage_;
	wield = wield_;
}

Weapon::Weapon()
{}

Weapon::~Weapon()
{}
	
void Weapon::print_item()
{
	cout << "Weapon Name: " << name << " Price: " << price << " Minimun required Level: " << minimum_lvl << " Damage: " << damage;
	if (wield == false)
		cout << " One-handed Weapon" << endl;
	else
		cout << " Two-handed Weapon" << endl;
}

void Weapon::print_item2()
{
	cout << "Weapon Name: " << name << " Damage: " << damage;
	if (wield == false)
		cout << " One-handed Weapon" << endl;
	else
		cout << " Two-handed Weapon" << endl;
}

char Weapon::type()
{
	return 'W';
}

int Weapon::get_damage()
{
	return damage;
}

bool Weapon::get_wield()
{
	return wield;
}

////////////////////////////////////////////
////////////////////////////////////////////Armor
////////////////////////////////////////////

Armor::Armor()
{}

Armor::~Armor()
{}

Armor::Armor(string name_, int price_, int minimum_lvl_, int reduction_) : Item(name_, price_, minimum_lvl_)
{
	reduction = reduction_;
}
	
void Armor::print_item()
{
	cout << "Armor Name: " << name << " Price: " << price << " Minimun required Level: " << minimum_lvl << " Reduction: " << reduction << endl;
}

void Armor::print_item2()
{
	cout << "Armor Name: " << name << " Reduction: " << reduction << endl;
}
	
char Armor::type()
{
	return 'A';
}
	
int Armor::get_reduction()
{
	return reduction;
}

////////////////////////////////////////////
////////////////////////////////////////////Potion
////////////////////////////////////////////

Potion::Potion()
{}

Potion::~Potion()
{}

Potion::Potion(string name_, int price_, int minimum_lvl_, int increase_, string stat_) : Item(name_, price_, minimum_lvl_)
{
	increase = increase_;
	stat = stat_;
}
	
void Potion::print_item()
{
	cout << "Potion Name: " << name << " Price: " << price << " Minimun required Level: " << minimum_lvl << " Increase in " << stat << " : " << increase << endl;
}

void Potion::print_item2()
{
	cout << "Potion Name: " << name << " Minimun required Level: " << minimum_lvl << " Increase in " << stat << " : " << increase << endl;
}
	
char Potion::type()
{
	return 'P';
}
	
string Potion::get_stat()
{
	return stat;
}
	
int Potion::get_increase()
{
	return increase;
}

