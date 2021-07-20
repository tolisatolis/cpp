#include <iostream>
#include "Classes.h"
using namespace std;

////////////////////////////////////////////
////////////////////////////////////////////Bag
////////////////////////////////////////////

Bag::Bag()
{
	items = 0;
	for (int i = 0; i < 20; i++)
	{
		weapons[i] = new Weapon();
		armors[i] = new Armor();
		potions[i] = new Potion();
	}
}

Bag::~Bag()
{
	delete[] weapons;
	delete[] armors;
	delete[] potions;
}

bool Bag::buy(Armor *armor)
{
	if (items < 20)
	{
		for (int i = 0; i < 20; i++)
		{
			if (armors[i]->get_price() == 0)
			{
				armors[i] = armor;
				items++;
				return true;
			}
		}
	}
	else
	{
		cout << "Bag is full!" << endl;
		return false;
	}
}

bool Bag::buy(Weapon *weapon)
{
	if (items < 20)
	{
		for (int i = 0; i < 20; i++)
		{
			if (weapons[i]->get_price() == 0)
			{
				weapons[i] = weapon;
				items++;
				return true;
			}
		}
	}
	else
	{
		cout << "Bag is full!" << endl;
		return false;
	}
}

bool Bag::buy(Potion *potion)
{
	if (items < 20)
	{
		for (int i = 0; i < 20; i++)
		{
			if (potions[i]->get_price() == 0)
			{
				potions[i] = potion;
				items++;
				return true;
			}
		}
	}
	else
	{
		cout << "Bag is full!" << endl;
		return false;
	}
}

void Bag::print()
{
	for (int i = 0; i < 20; i++)
		if (armors[i]->get_price() != 0 && armors[i]!=NULL)
		{
			cout << " (" << i +1<< ") ";
			armors[i]->print_item();
		}
	for (int i = 0; i < 20; i++)
		if (weapons[i]->get_price() != 0 && weapons[i]!=NULL)
		{
			cout << " (" << i +1<< ") ";
			weapons[i]->print_item();
		}
	for (int i = 0; i < 20; i++)
		if (potions[i]->get_price() != 0 && potions[i]!=NULL)
		{
			cout << " (" << i +1<< ") ";
			potions[i]->print_item();
		}
}

void Bag::print_weapons()
{
	for (int i = 0; i < 20; i++)
		if (weapons[i]->get_price() != 0 && weapons[i]!=NULL)
		{
			cout << " (" << i +1<< ") ";
			weapons[i]->print_item();
		}
}

void Bag::print_armors()
{
	for (int i = 0; i < 20; i++)
		if (armors[i]->get_price() != 0 && armors[i]!=NULL)
		{
			cout << " (" << i +1<< ") ";
			armors[i]->print_item();
		}
}

void Bag::print_potions()
{
	for (int i = 0; i < 20; i++)
		if (potions[i]->get_price() != 0 && potions[i]!=NULL)
		{
			cout << " (" << i +1<< ") ";
			potions[i]->print_item();
		}
}

string Bag::get_weapon(int i)
{
	return weapons[i]->get_name();
}

string Bag::get_armor(int i)
{
	return armors[i]->get_name();
}

string Bag::get_potion(int i)
{
	return potions[i]->get_name();
}

int Bag::sell_weapon(int i)
{
	int g = (int)weapons[i]->get_price() / 2;
	weapons[i] = NULL;
	for (int j = 0; j < 20; j++)
	{
			for (int k = j; k < 19; k++)
			{
			if(weapons[k]== NULL || weapons[k]->get_price()==0)
			{
				Weapon *temp;
				temp = weapons[k];
				weapons[k] = weapons[k + 1];
				weapons[k + 1] = temp;
			}
			}
	}
	items--;
	return g;
}

int Bag::sell_armor(int i)
{
	int g = (int)armors[i]->get_price() / 2;
	armors[i] = NULL;
	for (int j = 0; j < 20; j++)
	{
		for(int k=j; k< 19; k++ )
		{
			if(armors[k]== NULL || armors[k]->get_price()==0)
			{
				Armor *temp;
				temp = armors[k+1];
				armors[k+1]==armors[k];
				armors[k]==temp;
			}
		}
	}
	items--;
	return g;
}

int Bag::sell_potion(int i)
{
	int g = (int)potions[i]->get_price() / 2;
	potions[i] = NULL;
	for (int j = 0; j < 20; j++)
	{
			for (int k = j; k < 19; k++)
			{
				if(potions[k]== NULL || potions[k]->get_price()==0)
				{
				Potion *temp;
				temp = potions[k];
				potions[k] = potions[k + 1];
				potions[k + 1] = temp;
				}
			}
	}
	items--;
	return g;
}

Armor *Bag::equip_armor(int i)
{
	return armors[i];
}

Weapon *Bag::equip_weapon(int i)
{
	return weapons[i];
}

Potion *Bag::use_potion(int i)
{
	Potion *temp = potions[i];
	potions[i] = NULL;
	for (int k = i; k < 19; k++)
	{
		Potion *temp;
		temp = potions[k];
		potions[k] = potions[k + 1];
		potions[k + 1] = temp;
	}
	items--;
	return temp;
}

int Bag::get_potion_level(int i)
{
	return potions[i]->get_level();
}

bool Bag::no_weapon()
{
	if(weapons[0]->get_price() == 0)
		return true;
	return false;
}

bool Bag::no_armor()
{
	if(armors[0]->get_price() == 0)
		return true;
	return false;
}

bool Bag::no_potion()
{
	if(potions[0]->get_price() == 0)
		return true;
	return false;
}

////////////////////////////////////////////
////////////////////////////////////////////Spellbook
////////////////////////////////////////////

Spellbook::Spellbook()
{
	spells = 0;
	for (int i = 0; i < 10; i++)
	{
		firespells[i] = new FireSpell();
		icespells[i] = new IceSpell();
		lightningspells[i] = new LightningSpell();
	}
}

Spellbook::~Spellbook()
{
	delete[] firespells;
	delete[] icespells;
	delete[] lightningspells;
}

bool Spellbook::buy(IceSpell *spell)
{
	if (spells < 10)
	{
		for (int i = 0; i < 10; i++)
		{
			if (icespells[i]->get_price() == 0)
			{
				icespells[i] = spell;
				spells++;
				return true;
			}
		}
	}
	else
	{
		cout << "You can't learn more spells!" << endl;
		return false;
	}
}

bool Spellbook::buy(FireSpell *spell)
{
	if (spells < 10)
	{
		for (int i = 0; i < 10; i++)
		{
			if (firespells[i]->get_price() == 0)
			{
				firespells[i] = spell;
				spells++;
				return true;
			}
		}
	}
	else
	{
		cout << "You can't learn more spells!" << endl;
		return false;
	}
}

bool Spellbook::buy(LightningSpell *spell)
{
	if (spells < 10)
	{
		for (int i = 0; i < 10; i++)
		{
			if (lightningspells[i]->get_price() == 0)
			{
				lightningspells[i] = spell;
				spells++;
				return true;
			}
		}
	}
	else
	{
		cout << "You can't learn more spells!" << endl;
		return false;
	}
}

void Spellbook::print()
{
	for (int i = 0; i < 10; i++)
		if (firespells[i]->get_price() != 0 && firespells[i]!=NULL)
		{
			cout << " (" << i +1<< ") ";
			firespells[i]->print_spell();
		}
	for (int i = 0; i < 10; i++)
		if (icespells[i]->get_price() != 0 && icespells[i]!=NULL)
		{
			cout << " (" << i +1<< ") ";
			icespells[i]->print_spell();
		}
	for (int i = 0; i < 10; i++)
		if (lightningspells[i]->get_price() != 0 && lightningspells[i]!=NULL)
		{
			cout << " (" << i +1<< ") ";
			lightningspells[i]->print_spell();
		}
}

void Spellbook::print_icespells()
{
	for (int i = 0; i < 10; i++)
		if (icespells[i]->get_price() != 0 && icespells[i]!=NULL)
		{
			cout << " (" << i +1<< ") ";
			icespells[i]->print_spell();
		}
}

void Spellbook::print_lightningspells()
{
	for (int i = 0; i < 10; i++)
		if (lightningspells[i]->get_price() != 0 && lightningspells[i]!=NULL)
		{
			cout << " (" << i +1<< ") ";
			lightningspells[i]->print_spell();
		}
}

void Spellbook::print_firespells()
{
	for (int i = 0; i < 10; i++)
		if (firespells[i]->get_price() != 0 && firespells[i]!=NULL)
		{
			cout << " (" << i +1<< ") ";
			firespells[i]->print_spell();
		}		
}

int Spellbook::sell_icespell(int i)
{
	int g = (int)icespells[i]->get_price() / 2;
	icespells[i] = NULL;
	for (int j = 0; j < 10; j++)
	{
			for (int k = j; k < 9; k++)
			{
				if(icespells[k]== NULL || icespells[k]->get_price()==0)
				{
				IceSpell *temp;
				temp = icespells[k];
				icespells[k] = icespells[k + 1];
				icespells[k + 1] = temp;
				}
			}
	}
	spells--;
	return g;
}

int Spellbook::sell_firespell(int i)
{
	int g = (int)firespells[i]->get_price() / 2;
	firespells[i] = NULL;
	for (int j = 0; j < 10; j++)
	{
			for (int k = j; k < 9; k++)
			{
				if(firespells[k]== NULL || firespells[k]->get_price()==0)
				{
				FireSpell *temp;
				temp = firespells[k];
				firespells[k] = firespells[k + 1];
				firespells[k + 1] = temp;
				}
			}
	}
	spells--;
	return g;
}

int Spellbook::sell_lightningspell(int i)
{
	int g = (int)lightningspells[i]->get_price() / 2;
	lightningspells[i] = NULL;
	for (int j = 0; j < 10; j++)
	{
			for (int k = j; k < 9; k++)
			{
				if(lightningspells[k]==NULL || lightningspells[k]->get_price()==0)
				{
				LightningSpell *temp;
				temp = lightningspells[k];
				lightningspells[k] = lightningspells[k + 1];
				lightningspells[k + 1] = temp;
				}
			}
	}
	spells--;
	return g;
}

bool Spellbook::no_spells()
{
	if(icespells[0]->get_price()==0 && firespells[0]->get_price()==0 && lightningspells[0]->get_price()==0)
		return true;
	return false;
}

Spell *Spellbook::get_spell(int k)
{
int 	count =0;
    for(int i=0;i<10;i++){
        if(firespells[i]->get_price()==0){
        break;
        }else if (count==k-1){
            return firespells[i];
        }else{
            count++;
        }
    }
    for(int i=0;i<10;i++){
        if(icespells[i]->get_price()==0){
        break;
        }else if (count==k-1){
            return icespells[i];
        }else{
            count++;
        }
    }
    for(int i=0;i<10;i++){
        if(lightningspells[i]->get_price()==0){
        break;
        }else if (count==k-1){
            return lightningspells[i];
        }else{
            count++;
        }
    }
}
