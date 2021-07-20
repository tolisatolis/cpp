#include <iostream>
using namespace std;

class FireSpell;
class IceSpell;
class LightningSpell;
class Spellbook;
class Spell;
class Bag;

class Item
{
public:
	Item();
	virtual ~Item();
	Item(string name_, int price_, int minimum_lvl_);
	virtual void print_item() = 0;
	virtual void print_item2() = 0;
	int get_price();
	int get_level();
	string get_name();
	virtual char type() = 0;
protected:
	string name;
	int price;
	int minimum_lvl;
};

class Weapon: public Item
{
public:
	Weapon();
	~Weapon();
	Weapon(string name_, int price_, int minimum_lvl_, int damage_, bool wield_);
	void print_item();
	void print_item2();
	char type();
	int get_damage();
	bool get_wield();
private:
	int damage;
	bool wield;	
};

class Armor : public Item
{
public:
	Armor();
	~Armor();
	Armor(string name_, int price_, int minimum_lvl_, int reduction_);
	void print_item();
	void print_item2();
	char type();
	int get_reduction();
private:
	int reduction;
};

class Potion : public Item
{
public:
	Potion();
	~Potion();
	Potion(string name_, int price_, int minimum_lvl_, int increase_, string stat_);
	void print_item();
	void print_item2();
	char type();
	string get_stat();
	int get_increase();
private:
	int increase;
	string stat;
};

class Bag
{
public:
	Bag();
	~Bag();
	bool buy(Armor *armor);
	bool buy(Weapon *weapon);
	bool buy(Potion *potion);
	void print();
	void print_weapons();
	void print_armors();
	void print_potions();
	string get_weapon(int i);
	string get_armor(int i);
	string get_potion(int i);
	int sell_weapon(int i);
	int sell_armor(int i);
	int sell_potion(int i);
	Armor *equip_armor(int i);
	Weapon *equip_weapon(int i);
	Potion *use_potion(int i);
	int get_potion_level(int i);
	bool no_weapon();
	bool no_armor();
	bool no_potion();
private:
	int items;
	Armor *armors[20];
	Weapon *weapons[20];
	Potion *potions[20];
};

class Spellbook
{
public:
	Spellbook();
	~Spellbook();
	bool buy(IceSpell *spell);
	bool buy(FireSpell *spell);
	bool buy(LightningSpell *spell);
	void print();
	void print_icespells();
	void print_lightningspells();
	void print_firespells();
	int sell_icespell(int i);
	int sell_firespell(int i);
	int sell_lightningspell(int i);
	Spell *get_spell(int k);
	bool no_spells();
private:
	int spells;
	FireSpell *firespells[10];
	IceSpell *icespells[10];
	LightningSpell *lightningspells[10];
};

class Living
{
public:
	Living(string name_);
	virtual ~Living();
	virtual void print_info() = 0;
protected:
	string name;
	int level;
	int healthPower;
	int current_hp;
};

class Hero : public Living
{
public:
	Hero(string name_);
	virtual ~Hero();
	string get_name();
	void print_spellbook();
	void print_bag();
	void print_weapons();
	void print_armors();
	void print_potions();
	void print_icespells();
	void print_firespells();
	void print_lightningspells();
	virtual void print_stats() = 0;
	virtual void levelUp() = 0;
	void buy(Weapon *weapon);
	void buy(Armor *armor);
	void buy(Potion *potion);
	void buy(IceSpell *spell);
	void buy(FireSpell *spell);
	void buy(LightningSpell *spell);
	bool weapon_to_sell(int i);
	bool armor_to_sell(int i);
	void sell_weapon(int i);
	void sell_armor(int i);
	void sell_potion(int i);
	void sell_firespell(int i);
	void sell_icespell(int i);
	void sell_lightning(int i);
	void equip_armor(int i);
	void equip_weapon(int i);
	void use(int i);
	int attack();
	int get_level();
	int get_dexterity();
	void damage(int i);
	bool castSpell(int i);
	int get_current_hp();
	int ressurect();
	void won(int i);
	void lost();
	void round();
	Spell *get_spbook(int k);
	virtual void print_info() = 0;
	bool no_weapon();
	bool no_armor();
	bool no_potion();
	bool no_spells();
protected:
	int magicPower;
	int current_mana;
	int strength;
	int dexterity;
	int agility;
	int gold;
	int experience;
	int current_exp;
	string class_;
	Bag bag;
	Spellbook spellbook;
	Weapon *weapon1;
	Weapon *weapon2;
	Armor *armor;
	int reduction;
};

class Warrior : public Hero
{
public:
	Warrior(string name_);
	~Warrior();
	void levelUp();
	void print_info();
	void print_stats();
private:
};

class Sorcerer : public Hero
{
public:
	Sorcerer(string name_);
	~Sorcerer();
	void levelUp();
	void print_info();
	void print_stats();
private:
};

class Paladin : public Hero
{
public:
	Paladin(string name_);
	~Paladin();
	void levelUp();
	void print_info();
	void print_stats();
private:
};

class Monster : public Living
{
public:
	Monster(string name_, int level_);
	virtual ~Monster();
	void damage(int i);
	void damage(int damage, int type_, int reduction, int dexterity);
	int get_current_hp();
	int attack();
	void round();
	virtual void print_info() = 0;
protected:
	int power;
	int defence;
	int dodge;
};

class Dragon : public Monster
{
public:
	Dragon(string name_, int level_);
	~Dragon();
	void print_info();
private:
};

class Exoskeleton : public Monster
{
public:
	Exoskeleton(string name_, int level_);
	~Exoskeleton();
	void print_info();			
private:
};

class Spirit : public Monster
{
public:
	Spirit(string name_, int level_);
	~Spirit();
	void print_info();
private:
};

class Grid
{
public:
	Grid();
	~Grid();
	void displayMap();
	char Move(char c);			
private:
	char grid [6][10];
	int x;
	int y;
	char previous;
};

class Spell
{
public:
	Spell();
	virtual ~Spell();
	Spell(string name_, int price_, int minimum_lvl_, int damage_, int mana_, int reduction_);
	virtual void print_spell() = 0;
	int get_price();
	int get_type();
	int get_damage();
	int get_reduction();
	string get_name();
	int get_mana();
	int get_level();
protected:
	string name;
	int price;
	int minimum_lvl;
	int damage;
	int mana;
	int reduction;
	int type;
};

class IceSpell : public Spell
{
public:
	IceSpell();
	~IceSpell();
	IceSpell(string name_, int price_, int minimum_lvl_, int damage_, int mana_, int reduction_);
	void print_spell();
private:
};

class FireSpell : public Spell
{
public:
	FireSpell();
	~FireSpell();
	FireSpell(string name_, int price_, int minimum_lvl_, int damage_, int mana_, int reduction_);
	void print_spell();
private:
};

class LightningSpell : public Spell
{
public:
	LightningSpell();
	~LightningSpell();
	LightningSpell(string name_, int price_, int minimum_lvl_, int damage_, int mana_, int reduction_);
	void print_spell();
private:
};

