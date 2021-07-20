#include <iostream>
#include "Classes.h"
using namespace std;

////////////////////////////////////////////
////////////////////////////////////////////Spell
////////////////////////////////////////////

Spell::Spell()
{}

Spell::~Spell()
{}

Spell::Spell(string name_, int price_, int minimum_lvl_, int damage_, int mana_, int reduction_)
{
	name = name_;
	price = price_;
	minimum_lvl = minimum_lvl_;
	damage = damage_;
	mana = mana_;
	reduction = reduction_;
}

int Spell::get_price()
{
	return price;
}

int Spell::get_type()
{
	return type;
}

int Spell::get_damage()
{
	return damage;
}

int Spell::get_reduction()
{
	return reduction;
}

string Spell::get_name()
{
	return name;
}

int Spell::get_mana()
{
	return mana;
}

int Spell::get_level()
{
	return minimum_lvl;
}

////////////////////////////////////////////
////////////////////////////////////////////IceSpell
////////////////////////////////////////////

IceSpell::IceSpell()
{}

IceSpell::~IceSpell()
{}

IceSpell::IceSpell(string name_, int price_, int minimum_lvl_, int damage_, int mana_, int reduction_) : Spell(name_, price_, minimum_lvl_, damage_, mana_, reduction_)
{
	type = 1;
}

void IceSpell::print_spell()
{
	cout << "Spell Name: " << name << " Price: " << price << " Minimum required Level: " << minimum_lvl << " Damage: " << damage << " Mana:" << mana << " Reduction in Damage: " << reduction << endl;
}

////////////////////////////////////////////
////////////////////////////////////////////FireSpell
////////////////////////////////////////////

FireSpell::FireSpell()
{}

FireSpell::~FireSpell()
{}

FireSpell::FireSpell(string name_, int price_, int minimum_lvl_, int damage_, int mana_, int reduction_) : Spell(name_, price_, minimum_lvl_, damage_, mana_, reduction_)
{
	type = 2;
}

void FireSpell::print_spell()
{
	cout << "Spell Name: " << name << " Price: " << price << " Minimum required Level: " << minimum_lvl << " Damage: " << damage << " Mana:" << mana << " Reductionn in enemy Defence: " << reduction << endl;
}

////////////////////////////////////////////
////////////////////////////////////////////LightningSpell
////////////////////////////////////////////

LightningSpell::LightningSpell()
{}

LightningSpell::~LightningSpell()
{}

LightningSpell::LightningSpell(string name_, int price_, int minimum_lvl_, int damage_, int mana_, int reduction_) : Spell(name_, price_, minimum_lvl_, damage_, mana_, reduction_)
{
	type = 3;
}

void LightningSpell::print_spell()
{
	cout << "Spell Name: " << name << " Price: " << price << " Minimum required Level: " << minimum_lvl << " Damage: " << damage << " Mana:" << mana << " Reductionn in enemy Dodge chance: " << reduction << endl;
}

