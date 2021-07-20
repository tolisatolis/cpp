#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Classes.h"
using namespace std;

////////////////////////////////////////////
////////////////////////////////////////////Living
////////////////////////////////////////////

Living::Living(string name_)
{
	name = name_;
	level = 1;
}

Living::~Living()
{}
	
////////////////////////////////////////////
////////////////////////////////////////////Hero
////////////////////////////////////////////

Hero::Hero(string name_) : Living(name_)
{
	gold = 1000;
	experience = 50;
	current_exp = 0;
	weapon1 = NULL;
	weapon2 = NULL;
	armor = NULL;
	reduction = 0;
}

Hero::~Hero()
{}

string Hero::get_name()
{
	return name;
}

void Hero::print_spellbook()
{
	spellbook.print();
}
	
void Hero::print_bag()
{
	bag.print();
}

void Hero::print_weapons()
{
	bag.print_weapons();
}

void Hero::print_armors()
{
	bag.print_armors();
}

void Hero::print_potions()
{
	bag.print_potions();
}

void Hero::print_icespells()
{
	spellbook.print_icespells();
}

void Hero::print_firespells()
{
	spellbook.print_firespells();
}

void Hero::print_lightningspells()
{
	spellbook.print_lightningspells();
}

void Hero::buy(Weapon *weapon)
{
	int value = weapon->get_price();
	if (gold >= value)
	{
		if (bag.buy(weapon))
		{
			cout<<"Weapon: "<<weapon->get_name()<<" bought successfully!"<<endl;
			gold -= value;
		}
	}
	else
		cout << "You don't have enough gold to buy this weapon" << endl;
}

void Hero::buy(Armor *armor)
{
	int value = armor->get_price();
	if (gold >= value)
	{
		if (bag.buy(armor))
		{
			cout<<"Armor: "<<armor->get_name()<<" bought successfully!"<<endl;
			gold -= value;
		}
	}
	else
		cout << "You don't have enough Gold to buy this armor" << endl;
}

void Hero::buy(Potion *potion)
{
	int value = potion->get_price();
	if (gold >= value)
	{
		if (bag.buy(potion))
		{
			cout<<"Potion: "<<potion->get_name()<<" bought successfully!"<<endl;
			gold -= value;
		}
	}
	else
		cout << "You don't have enough gold to buy this potion" << endl;
}

void Hero::buy(IceSpell *spell)
{
	int value = spell->get_price();
	if (gold >= value)
	{
		if (spellbook.buy(spell))
		{
			cout<<"Ice Spell: "<<spell->get_name()<<" bought successfully!"<<endl;
			gold -= value;
		}
	}
	else
		cout << "You don't have enough gold to buy this Ice spell" << endl;
}

void Hero::buy(FireSpell *spell)
{
	int value = spell->get_price();
	if (gold >= value)
	{
		if (spellbook.buy(spell))
		{
			cout<<"Fire Spell: "<<spell->get_name()<<" bought successfully!"<<endl;
			gold -= value;
		}
	}
	else
		cout << "You don't have enough gold to buy this spell" << endl;
}

void Hero::buy(LightningSpell *spell)
{
	int value = spell->get_price();
	if (gold >= value)
	{
		if (spellbook.buy(spell))
		{
			cout<<"Lighting Spell: "<<spell->get_name()<<" bought successfully!"<<endl;
			gold -= value;
		}
	}
	else
		cout << "You don't have enough gold to buy this spell" << endl;
}

bool Hero::weapon_to_sell(int i)
{
	if(weapon2->get_name() == bag.get_weapon(i))
		return false;
	if(weapon1 == NULL)
	{
		if(weapon2 == NULL)
			return true;
	}
	else if(weapon1 -> get_name() == bag.get_weapon(i))
		return false;
	return true;
}

bool Hero::armor_to_sell(int i)
{
	if(armor == NULL)
		return true;
	if (bag.get_armor(i) == armor->get_name())
		return false;
	else
		return true;
}

void Hero::sell_weapon(int i)
{
	gold += bag.sell_weapon(i);
}

void Hero::sell_armor(int i)
{
	gold += bag.sell_armor(i);
}

void Hero::sell_potion(int i)
{
	gold += bag.sell_potion(i);
}

void Hero::sell_firespell(int i)
{
	gold += spellbook.sell_firespell(i);
}

void Hero::sell_icespell(int i)
{
	gold += spellbook.sell_icespell(i);
}

void Hero::sell_lightning(int i)
{
	gold += spellbook.sell_lightningspell(i);
}

void Hero::equip_armor(int i)
{
	char input;

	if (bag.equip_armor(i)->get_level() > level)
		cout << "You are unable to equip this item" << endl;
	else
	{
		if (armor == NULL)
		{
			armor = bag.equip_armor(i);
			reduction = armor->get_reduction();
			cout<<"Armor: "<<armor->get_name()<<" equipped successfully!"<<endl;
		}
		else
		{
			cout << "Are you sure you want to replace you current armor?" << endl;
			cout << "Yes(Y) No(N)" << endl;
			cin >> input;

			if (input == 'Y' || input == 'y')
			{
				armor = bag.equip_armor(i);
				reduction = armor->get_reduction();
				cout<<"Armor: "<<armor->get_name()<<" equipped successfully!"<<endl;
			}
		}
	}
}

void Hero::equip_weapon(int i)
{
	char input;
	if (bag.equip_weapon(i)->get_level() > level)
		cout << "You are unable to equip this item" << endl;
	else
	{
		if (weapon1 == NULL)
		{
			weapon1 = bag.equip_weapon(i);
			strength += weapon1->get_damage();
			cout<<"Weapon: "<<weapon1->get_name()<<" equipped successfully!"<<endl;
		}
		else if (bag.equip_weapon(i)->get_wield() == false)
		{
			if (weapon1->get_wield() == true)
			{
				cout << "You can't equip a second weapon?" << endl;
				cout << "Do you want to replace the current weapon?" << endl;
				cout << "Yes(Y) No(N)" << endl;
				cin >> input;

				if (input == 'y' || input == 'Y')
				{
					strength -= weapon1->get_damage();
					weapon1 = bag.equip_weapon(i);
					strength += weapon1->get_damage();
					cout<<"Weapon: "<<weapon1->get_name()<<" equipped successfully!"<<endl;
				}
			}
			else
			{
				cout << "Do you want this to be your primary or your secondary weapon?" << endl;
				cout << "Primary(P) Secondary(S)" << endl;
				cin >> input;

				if (input == 'P' || input == 'p')
				{
					strength -= weapon1->get_damage();
					weapon1 = bag.equip_weapon(i);
					strength = +weapon1->get_damage();
					cout<<"Weapon: "<<weapon1->get_name()<<" equipped successfully!"<<endl;
				}
				else
				{
					if (weapon2 == NULL)
					{
						weapon2 = bag.equip_weapon(i);
						strength += weapon2->get_damage();
						cout<<"Weapon: "<<weapon2->get_name()<<" equipped successfully!"<<endl;
					}
					else
					{
						cout << "Do you want to replace your current second weapon?" << endl;
						cout << "Yes(Y) No(N)" << endl;
						cin >> input;

						if (input == 'y' || input == 'Y')
						{
							strength -= weapon2->get_damage();
							weapon2 = bag.equip_weapon(i);
							strength += weapon2->get_damage();
							cout<<"Weapon: "<<weapon2->get_name()<<" equipped successfully!"<<endl;
						}
					}
				}
			}
		}
	}
}

void Hero::use(int i)
{
	if (bag.get_potion_level(i) > level)
		cout << "You are unable to drink this potion." << endl;
	else
	{
		Potion *temp = bag.use_potion(i);
		if (temp->get_stat() == "healthPower")
		{
			current_hp += temp->get_increase();
			if (current_hp > healthPower)
				current_hp = healthPower;
		}
		else if (temp->get_stat() == "manaPower")
		{
			current_mana += temp->get_increase();
			if (current_mana > magicPower)
				current_mana = magicPower;
		}
		else if (temp->get_stat() == "strength")
			strength += temp->get_increase();
		else if (temp->get_stat() == "dexterity")
			dexterity += temp->get_increase();
		else if (temp->get_stat() == "agility")
			agility += temp->get_increase();
		else if (temp->get_stat() == "experience")
		{
			current_exp += temp->get_increase();
			while (true)
			{
				if (current_exp == experience)
					levelUp();
				else if (current_exp > experience)
				{
					int temp2 = current_exp - experience;
					levelUp();
					current_exp == temp2;
				}
				else
					break;
			}
		}
		cout<<"Potion:"<<temp->get_name()<<" consumed successfully!"<<endl;
	}
}

int Hero::attack()
{
	return strength;
}

int Hero::get_level()
{
	return level;
}

int Hero::get_dexterity()
{
	return dexterity;
}

void Hero::damage(int i)
{
	int num = rand() % 100;
	if (num > agility)
	{
		int temp;
		if(reduction<i)
			temp = i - reduction;
		else
			temp=0;
		current_hp -= temp;
		if (current_hp <= 0)
		{
			cout << "Hero " << name << " died :(" << endl;
			current_hp = 0;
		}
		else
			cout << name << " suffered " << temp << " damage " << current_hp << "/" << healthPower << endl;
	}
	else
		cout << name << " dodged the attack!" << endl;
}

bool Hero::castSpell(int i)
{
	if (current_mana >= i)
	{
		current_mana -= i;
		return true;
	}
	else
	{
		cout << "Hero " << name << " hasn't enough mana" << endl;
		return false;
	}
}

int Hero::get_current_hp()
{
	return current_hp;
}

int Hero::ressurect()
{
	current_hp = (int)healthPower / 2;
}

void Hero::won(int i)
{
	gold += (level * i) * 10;
	current_exp += (level * i) * 20;

	while (true)
	{
		if (current_exp == experience)
			levelUp();
		else if (current_exp > experience)
		{
			int temp = current_exp - experience;
			levelUp();
			current_exp == temp;
		}
		else
			break;
	}
}

void Hero::lost()
{
	current_hp = healthPower;
	current_mana = magicPower;
	gold -= (int)gold / 2;
}

void Hero::round()
{
	current_hp += (int)healthPower * 10 / 100;
	if(current_hp>healthPower)
		current_hp=healthPower;
	current_mana += (int)magicPower * 10 / 100;
	if(current_mana>magicPower)
		current_mana=magicPower;
}

Spell *Hero::get_spbook(int k)
{
	return spellbook.get_spell(k);
}

bool Hero::no_armor()
{
	return bag.no_armor();
}

bool Hero::no_weapon()
{
	return bag.no_weapon();
}

bool Hero::no_potion()
{
	return bag.no_potion();
}

bool Hero::no_spells()
{
	return spellbook.no_spells();
}

////////////////////////////////////////////
////////////////////////////////////////////Warrior
////////////////////////////////////////////

Warrior::Warrior(string name_) : Hero(name_)
{
	strength = 15;
	agility = 12;
	dexterity = 10;
	healthPower = 80;
	current_hp = healthPower;
	magicPower = 40;
	current_mana = magicPower;
	class_ = "Warrior";
}

Warrior::~Warrior()
{}

void Warrior::levelUp()
{
	level++;
	strength += 3;
	agility += 2;
	dexterity += 1;
	healthPower += 10;
	current_hp += 10;
	magicPower += 5;
	current_mana += 5;
	current_exp = 0;
	experience += 50;
	cout << "Warrior " << name << " leveled up to " << level << endl;
}

void Warrior::print_info()
{
	cout << "Name: " << name << " Class: Warrior"<< " Gold:" << gold << " Level: " << level << "/15 Health: " << current_hp << "/" << healthPower << " Mana: " << current_mana << "/" << magicPower << " Current Experience: " << current_exp << "/" << experience << " Strength: " << strength << " Dexterity: " << dexterity << " Agility: " << agility<<endl;
}

void Warrior::print_stats()
{
	cout << "Name: " << name << " Class: Warrior"
		 << " Level: " << level << " Health: " << current_hp << "/" << healthPower << " Mana: " << current_mana << "/" << magicPower << " Strength: " << strength << " Dexterity: " << dexterity << " Agility: " << agility << endl;
	if (weapon1 != NULL)
		weapon1->print_item2();
	if (weapon2 != NULL)
		weapon2->print_item2();
	if (armor != NULL)
		armor->print_item2();
}

////////////////////////////////////////////
////////////////////////////////////////////Sorcerer
////////////////////////////////////////////

Sorcerer::Sorcerer(string name_) : Hero(name_)
{
	dexterity = 15;
	agility = 12;
	strength = 10;
	healthPower = 60;
	current_hp = healthPower;
	magicPower = 60;
	current_mana = magicPower;
	class_ = "Sorcerer";
}

Sorcerer::~Sorcerer()
{}

void Sorcerer::levelUp()
{
	level++;
	strength += 1;
	agility += 2;
	dexterity += 3;
	healthPower += 5;
	current_hp += 5;
	magicPower += 10;
	current_mana += 10;
	current_exp = 0;
	experience += 50;
	cout << "Sorcerer " << name << " leveled up to " << level << endl;
}

void Sorcerer::print_info()
{
	cout << "Name: " << name << " Class: Sorcerer"<< " Gold:" << gold << " Level: " << level << "/15 Health: " << current_hp << "/" << healthPower << " Mana: " << current_mana << "/" << magicPower << " Current Experience: " << current_exp << "/" << experience << " Strength: " << strength << " Dexterity: " << dexterity << " Agility: " << agility<<endl;
}

void Sorcerer::print_stats()
{
	cout << "Name: " << name << " Class: Sorcerer"
		 << " Level: " << level << " Health: " << current_hp << "/" << healthPower << " Mana: " << current_mana << "/" << magicPower << " Strength: " << strength << " Dexterity: " << dexterity << " Agility: " << agility << endl;
	if (weapon1 != NULL)
		weapon1->print_item2();
	if (weapon2 != NULL)
		weapon2->print_item2();
	if (armor != NULL)
		armor->print_item2();
}

////////////////////////////////////////////
////////////////////////////////////////////Paladin
////////////////////////////////////////////

Paladin::Paladin(string name_) : Hero(name_)
{
	dexterity = 13;
	strength = 13;
	agility = 10;
	healthPower = 70;
	current_hp = healthPower;
	magicPower = 50;
	current_mana = magicPower;
	class_ = "Paladin";
}

Paladin::~Paladin()
{}

void Paladin::levelUp()
{
	level++;
	strength += 2;
	agility += 1;
	dexterity += 2;
	healthPower += 8;
	current_hp += 8;
	magicPower += 8;
	current_mana += 8;
	current_exp = 0;
	experience += 50;
	cout << "Paladin " << name << " leveled up to " << level << endl;
}

void Paladin::print_info()
{
	cout << "Name: " << name << " Class: Paladin"<< " Gold:" << gold << " Level: " << level << "/15 Health: " << current_hp << "/" << healthPower << " Mana: " << current_mana << "/" << magicPower << " Current Experience: " << current_exp << "/" << experience << " Strength: " << strength << " Dexterity: " << dexterity << " Agility: " << agility<<endl;
}

void Paladin::print_stats()
{
	cout << "Name: " << name << " Class: Paladin"
		 << " Level: " << level << " Health: " << current_hp << "/" << healthPower << " Mana: " << current_mana << "/" << magicPower << " Strength: " << strength << " Dexterity: " << dexterity << " Agility: " << agility << endl;
	if (weapon1 != NULL)
		weapon1->print_item2();
	if (weapon2 != NULL)
		weapon2->print_item2();
	if (armor != NULL)
		armor->print_item2();
}

////////////////////////////////////////////
////////////////////////////////////////////Monster
////////////////////////////////////////////

Monster::Monster(string name_, int level_) : Living(name_)
{
	level = level_;
}

Monster::~Monster()
{}

void Monster::damage(int i)
{
	int num = rand() % 100;
	if (num > dodge)
	{
		int temp;
		if(defence<i)
			temp = i - defence;
		else 
			temp=0;
		current_hp -= temp;
		if (current_hp <= 0)
		{
			cout << "You killed " << name << endl;
			current_hp = 0;
		}
		else
			cout << "You dealt " << temp << " damage " << current_hp << "/" << healthPower << endl;
	}
	else
		cout << name << " dodged the attack!" << endl;
}

void Monster::damage(int damage, int type_, int reduction, int dexterity)
{
	int temp = damage + dexterity - defence;
	current_hp -= temp;
	if (current_hp <= 0)
	{
		cout << "You killed " << name << endl;
		current_hp = 0;
	}
	else
		cout << "You dealt " << temp << " damage " << current_hp << "/" << healthPower << endl;

	switch (type_)
	{
	case 1:
		defence -= reduction;
		if (defence < 0)
			defence = 0;
		cout << "It's super effective! " << name << " has reduced defence!" << endl;
		break;
	case 2:
		power -= reduction;
		if (power < 0)
			power = 0;
		cout << "It's super effective! " << name << " has reduced attack!" << endl;
		break;
	case 3:
		dodge -= reduction;
		if (dodge < 0)
			dodge = 0;
		cout << "It's super effective! " << name << " has reduced dodge chance!" << endl;
		break;
	}
}

int Monster::get_current_hp()
{
	return current_hp;
}

int Monster::attack()
{
	return power;
}

void Monster::round()
{
	current_hp += (int)healthPower * 5 / 100;
	if(current_hp>healthPower)
		current_hp=healthPower;
}

////////////////////////////////////////////
////////////////////////////////////////////Dragon
////////////////////////////////////////////

Dragon::Dragon(string name_, int level_) : Monster(name_, level_)
{
	healthPower = 30;
	power = 13;
	defence = 10;
	dodge = 10;
	current_hp = 30;
}

Dragon::~Dragon()
{}

void Dragon::print_info()
{
	cout << "Name: " << name << " Monster type: Dragon"<< " Level: " << level << " Health: " << current_hp << "/" << healthPower << " Power: " << power << " Defence: " << defence << " Dodge Chance: " << dodge << endl;
}

////////////////////////////////////////////
////////////////////////////////////////////Exoskeleton
////////////////////////////////////////////

Exoskeleton::Exoskeleton(string name_, int level_) : Monster(name_, level_)
{
	healthPower = 30;
	power = 10;
	defence = 13;
	dodge = 10;
	current_hp = 30;
}

Exoskeleton::~Exoskeleton()
{}

void Exoskeleton::print_info()
{
	cout << "Name: " << name << " Monster type: Exoskeleton"<< " Level: " << level << " Health: " << current_hp << "/" << healthPower << " Power: " << power << " Defence: " << defence << " Dodge Chance: " << dodge << endl;
}

////////////////////////////////////////////
////////////////////////////////////////////Spirit
////////////////////////////////////////////

Spirit::Spirit(string name_, int level_) : Monster(name_, level_)
{
	healthPower = 30;
	power = 10;
	defence = 10;
	dodge = 13;
	current_hp = 30;
}

Spirit::~Spirit()
{}

void Spirit::print_info()
{
	cout << "Name: " << name << " Monster type: Spirit" << " Level: " << level << " Health: " << current_hp << "/" << healthPower << " Power: " << power << " Defence: " << defence << " Dodge Chance: " << dodge << endl;
}

