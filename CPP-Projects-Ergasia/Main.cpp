#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <string>
#include "Classes.h"
using namespace std;

int main()
{
	string name_;
	int price_;
	int minimum_lvl_;
	int damage_;
	int mana_;
	int reduction_;
	int increase_;
	int type_;
	string stat_;
	string wield_;

	ifstream myfile;

	myfile.open("Spells.txt");

	FireSpell *firespells[30];
	IceSpell *icespells[30];
	LightningSpell *lightspells[30];
	
	int count1 = 0, count2 = 0, count3 = 0;
	
	for (int i = 0; i < 90; i++)
	{
		myfile >> name_;
		myfile >> price_;
		myfile >> minimum_lvl_;
		myfile >> damage_;
		myfile >> mana_;
		myfile >> reduction_;
		myfile >> type_;
		switch (type_)
		{
		case 1:
			{
				IceSpell *spell1 = new IceSpell(name_, price_, minimum_lvl_, damage_, mana_, reduction_);
				icespells[count1] = spell1;
				count1++;
				break;
			}
		case 2:
			{
				FireSpell *spell2 = new FireSpell(name_, price_, minimum_lvl_, damage_, mana_, reduction_);
				firespells[count2] = spell2;
				count2++;
				break;
			}
		case 3:
			{
				LightningSpell *spell3 = new LightningSpell(name_, price_, minimum_lvl_, damage_, mana_, reduction_);
				lightspells[count3] = spell3;
				count3++;
				break;
			}
		}
	}
	
	myfile.close();
	
	myfile.open("Weapons.txt");

	Weapon *weapons[120];
	for (int i = 0; i < 120; i++)
	{
		myfile >> name_;
		myfile >> price_;
		myfile >> minimum_lvl_;
		myfile >> damage_;
		myfile >> wield_;
		
		bool x = false;
		
		if(wield_ == "true")
			x = true;
		
		Weapon *weapon = new Weapon(name_, price_, minimum_lvl_, damage_, x);
		weapons[i] = weapon;
	}
	myfile.close();

	myfile.open("Armors.txt");

	Armor *armors[80];
	for (int i = 0; i < 80; i++)
	{
		myfile >> name_;
		myfile >> price_;
		myfile >> minimum_lvl_;
		myfile >> reduction_;

		Armor *armor = new Armor(name_, price_, minimum_lvl_, reduction_);
		armors[i] = armor;
	}
	myfile.close();

	myfile.open("Potions.txt");

	Potion *potions[70];
	for (int i = 0; i < 70; i++)
	{
		myfile >> name_;
		myfile >> price_;
		myfile >> minimum_lvl_;
		myfile >> increase_;
		myfile >> stat_;

		Potion *potion = new Potion(name_, price_, minimum_lvl_, increase_, stat_);
		potions[i] = potion;
	}
	myfile.close();
	
	myfile.open("Names.txt");

	string monster_names[100];
	for (int i = 0; i < 100; i++)
	{
		myfile >> name_;
		monster_names[i] = name_;
	}
	
	Hero **heroes;

	int size;
	int temp;
	int hero;
	string name;
	char input;
	char t;

	LightningSpell *mlightspells[10];
	for (int i = 0; i < 10; i++)
		mlightspells[i] = new LightningSpell();
		
	FireSpell *mfire[10];
	for (int i = 0; i < 10; i++)
		mfire[i] = new FireSpell();
		
	IceSpell *mice[10];
	for (int i = 0; i < 10; i++)
		mice[i] = new IceSpell();
		
	Weapon *mweapons[10];
	for (int i = 0; i < 10; i++)
		mweapons[i] = new Weapon();

	Armor *marmors[10];
	for (int i = 0; i < 10; i++)
		marmors[i] = new Armor();

	Potion *mpotions[10];
	for (int i = 0; i < 10; i++)
		mpotions[i] = new Potion();

	srand(time(NULL));
	
	cout << "Welcome to the Game: " << endl;
	cout << "Select Number of Heroes: 1 2 3 " << endl;
	cin >> size;

	heroes = new Hero *[size];

	for (int i = 0; i < size; i++)
	{
		cout << "Select your class: Warrior(1) Sorcerer(2) Paladin(3) : " << endl;
		cin >> temp;

		switch (temp)
		{
		case 1:
			cout << "Select Warrior Name: " << endl;
			cin >> name;
			heroes[i] = new Warrior(name);
			break;
		case 2:
			cout << "Select Sorcerer Name: " << endl;
			cin >> name;
			heroes[i] = new Sorcerer(name);
			break;
		case 3:
			cout << "Select Paladin Name: " << endl;
			cin >> name;
			heroes[i] = new Paladin(name);
			break;
		}
	}

	Grid g = Grid();

	cout << "This is your Map: " << endl;

	g.displayMap();

	cout << "You are represented by the X character. M represents marketplaces and U are places you are you can't pass through." << endl;
	cout << "You can move by pressing your W(up), A(left), S(down), D(right) keys." << endl;
	cout << "Battle Instructions: " << endl;
	cout << "During battle, you can swap out your armor and your weapons as many times as you would like before attacking the enemy monsters or before using a potion." << endl;
	cout << "This means you can only attack or drink once per round with each hero. Once you have chosen your actions the battle commences automatically." << endl;
	cout << "Monsters target your heroes randomly. Battle ends once all monsters are dead or when all your heroes are die. " << endl;
	cout << "Lastly you can display stats for every battling entity (Heroes and Monsters)" << endl;

	while (true)
	{
		cout << "What's your next move? " << endl;
		cout << "Move by pressing your W(up), A(left), S(down), D(right) keys." << endl;
		cout << "Other options: Check Inventory(C), Display Map(G), Equip Items(E), Use Potion(P), Quit Game(Q)" << endl;

		cin >> input;

		t = g.Move(input);

		if (t == 'U' || t == 'u')
		{
			cout << "Select another place to go." << endl;
		}
		else if (t == 'M' || t == 'm')
		{
			cout << "Welcome to our Marketplace. Do you wish to Buy(B) or Sell(S)?" << endl;
			cin >> input;

			switch (input)
			{
			case 'B':
			case 'b':
				{
					int i = 0;
					while (i < 10)
					{
						int random = rand() % 120;
						mweapons[i] = weapons[random];
	
						random = rand() % 80;
						marmors[i] = armors[random];
	
						random = rand() % 70;
						mpotions[i] = potions[random];
	
						random = rand() % 30;
						mfire[i] = firespells[random];
	
						random = rand() % 30;
						mice[i] = icespells[random];
	
						random = rand() % 30;
						mlightspells[i] = lightspells[random];
	
						i++;
					}
	
					cout << "Weapons:" << endl;
					for (int i = 0; i < 10; i++)
						mweapons[i]->print_item();
	
					cout << "Armors:" << endl;
					for (int i = 0; i < 10; i++)
						marmors[i]->print_item();
	
					cout << "Potions:" << endl;
					for (int i = 0; i < 10; i++)
						mpotions[i]->print_item();
	
					cout << "Spells:" << endl;
					cout << "Fire Spells: " << endl;
					for (int i = 0; i < 10; i++)
						mfire[i]->print_spell();
					cout << "Lightning Spells: " << endl;
					for (int i = 0; i < 10; i++)
						mlightspells[i]->print_spell();
					cout << "Ice Spells: " << endl;
					for (int i = 0; i < 10; i++)
						mice[i]->print_spell();
					while (true)
					{
						cout << "Which Hero is buying?" << endl;
						for (int i = 0; i < size; i++)
						{
							cout << " (" << i +1<< ") ";
							heroes[i]->print_info();
						}
	
						cin >> hero;
	
						while (true)
						{
							cout << "What do you want to buy?" << endl;
							cout << "Weapons(1) Armors(2) Potions(3) Spells(4)" << endl;
	
							cin >> temp;
	
							switch (temp)
							{
							case 1:
								cout << "Which Weapon?" << endl;
								for (int i = 0; i < 10; i++)
								{
									cout << " (" << i +1<< ") ";
									mweapons[i]->print_item();
								}
								cin >> temp;
								heroes[hero-1]->buy(mweapons[temp - 1]);
								break;
							case 2:
								cout << "Which Armor?" << endl;
								for (int i = 0; i < 10; i++)
								{
									cout << " (" << i +1<< ") ";
									marmors[i]->print_item();
								}
								cin >> temp;
								heroes[hero-1]->buy(marmors[temp - 1]);
								break;
							case 3:
								cout << "Which Potion?" << endl;
								for (int i = 0; i < 10; i++)
								{
									cout << " (" << i +1<< ") ";
									mpotions[i]->print_item();
								}
								cin >> temp;
								heroes[hero-1]->buy(mpotions[temp - 1]);
								break;
							case 4:
								cout << "What type of spell?" << endl;
								cout << "Ice(1) Fire(2) Lightning(3) " << endl;
								cin >> temp;
								if (temp == 1)
								{
									for (int i = 0; i < 10; i++)
									{
										cout << " (" << i +1<< ") ";
										mice[i]->print_spell();
									}
									cout << "Choose Spells to buy: " << endl;
									cin >> temp;
									heroes[hero-1]->buy(mice[temp - 1]);
									break;
								}
								else if (temp == 2)
								{
									for (int i = 0; i < 10; i++)
									{
										cout << " (" << i +1<< ") ";
										mfire[i]->print_spell();
									}
									cin >> temp;
									heroes[hero-1]->buy(mfire[temp - 1]);
									break;
								}
								else
								{
									for (int i = 0; i < 10; i++)
									{
										cout << " (" << i +1<< ") ";
										mlightspells[i]->print_spell();
									}
									cin >> temp;
									heroes[hero-1]->buy(mlightspells[temp - 1]);
									break;
								}
							}
							cout << "Do you want to keep buying with this hero?" << endl;
							cout << "Yes(Y) No(N)" << endl;
							cin >> input;
	
							if (input == 'n' || input == 'N')
								break;
						}
						cout << "Do you want to keep buying from this shop?" << endl;
						cout << "Yes(Y) No(N)" << endl;
						cin >> input;
	
						if (input == 'n' || input == 'N')
							break;
					}
					break;
				}
			case 's':
			case 'S':
				{
					while (true)
					{
						cout << "Which Hero is selling?" << endl;
						for (int i = 0; i < size; i++)
						{
							cout << " (" << i +1<< ") ";
							heroes[i]->print_info();
						}
	
						cin >> hero;
	
						while (true)
						{
							cout << "What do you want to sell?" << endl;
							cout << "Spell(S) Item(I)" << endl;
							cin >> input;
	
							while (true)
							{
								if (input == 'S' || input == 's')
								{
									heroes[hero - 1]->print_spellbook();
									cout << "Which type of Spell do you want to sell?" << endl;
									cout << "IceSpell(1) FireSpell(2) LightningSpell(3)" << endl;
									cin >> temp;
	
									if (temp == 1)
									{
										if(heroes[hero-1]->no_spells()== true)
										{
											cout<<"You have no spells to sell!"<<endl;
											break;
										}
										else
										{
										heroes[hero - 1 ]->print_icespells();
										cout << "Choose Ice Spell to sell for half of its original price: ";
										cin >> temp;
										heroes[hero - 1]->sell_icespell(temp - 1);
										cout << "Do you want to keep selling Spells?" << endl;
										cout << "Yes(Y) No(N)" << endl;
										cin >> input;
	
										if (input == 'n' || input == 'N')
											break;
										}
									}
									else if (temp == 2)
									{
										if(heroes[hero-1]->no_spells()== true)
										{
											cout<<"You have no spells to sell!"<<endl;
											break;
										}
										else
										{
										heroes[hero - 1]->print_firespells();
										cout << "Choose Fire Spell to sell for half of its original price: ";
										cin >> temp;
										heroes[hero - 1]->sell_firespell(temp - 1);
										cout << "Do you want to keep selling Spells?" << endl;
										cout << "Yes(Y) No(N)" << endl;
										cin >> input;
	
										if (input == 'n' || input == 'N')
											break;
										}
									}
									else if (temp == 3)
									{
										if(heroes[hero-1]->no_spells()== true)
										{
											cout<<"You have no spells to sell!"<<endl;
											break;
										}
										else
										{
										heroes[hero - 1]->print_lightningspells();
										cout << "Choose Lightning Spell to sell for half of its original price: ";
										cin >> temp;
										heroes[hero - 1]->sell_lightning(temp - 1);
										cout << "Do you want to keep selling Spells?" << endl;
										cout << "Yes(Y) No(N)" << endl;
										cin >> input;
	
										if (input == 'n' || input == 'N')
											break;
										}
									}
								}
								else
								{
									heroes[hero - 1]->print_bag();
									cout << "Which type of Item do you want to sell?" << endl;
									cout << "Weapons(1) Armors(2) Potions(3)" << endl;
									cin >> temp;
	
									if (temp == 1)
									{
										if(heroes[hero-1]->no_weapon() == true)
										{
											cout<<"You have no weapons to sell!"<<endl;
											break;
										}
										else
										{
										heroes[hero - 1]->print_weapons();
										cout << "Choose weapon to sell for half of its original price: ";
										cin >> temp;
										if (heroes[hero -1 ]->weapon_to_sell(temp - 1))
										{
											heroes[hero- 1]->sell_weapon(temp - 1);
										}	
										cout << "Do you want to keep selling Items?" << endl;
										cout << "Yes(Y) No(N)" << endl;
										cin >> input;
										if (input == 'n' || input == 'N')
											break;	
										}
									}
									else if (temp == 2)
									{
										if(heroes[hero-1]->no_armor()== true)
										{
											cout<<"You have no armors to sell";
											break;
										}
										else
										{
										heroes[hero- 1]->print_armors();
										cout << "Choose armor to sell for half of its original price: ";
										cin >> temp;
										if (heroes[hero - 1]->armor_to_sell(temp - 1)== true)
										{
											cout<<"before sell armor of heroes"<<endl;
											heroes[hero -1]->sell_armor(temp - 1);
											cout<<"after sell armor of heroes"<<endl;
										}
										cout << "Do you want to keep selling Items?" << endl;
										cout << "Yes(Y) No(N)" << endl;
										cin >> input;
										if (input == 'n' || input == 'N')
											break;	
										}
									}
									else if (temp == 3)
									{
										if(heroes[hero-1]->no_potion()== true)
										{
											cout<<"You have no potions to sell!"<<endl;
											break;
										}
										else
										{
										heroes[hero - 1]->print_potions();
										cout << "Choose potion to sell for half of its original price: ";
										cin >> temp;
										heroes[hero -1]->sell_potion(temp - 1);
										cout << "Do you want to keep selling Items?" << endl;
										cout << "Yes(Y) No(N)" << endl;
										cin >> input;
										if (input == 'n' || input == 'N')
											break;
										}
									}
								}
							}
							cout << "Do you want to keep selling with this hero?" << endl;
							cout << "Yes(Y) No(N)" << endl;
							cin >> input;
	
							if (input == 'n' || input == 'N')
								break;
						}
						cout << "Do you want to keep selling from this shop?" << endl;
						cout << "Yes(Y) No(N)" << endl;
						cin >> input;
	
						if (input == 'n' || input == 'N')
							break;
					}
					break;
				}
			}
		}
		else if (t == 'Q' || t == 'q')
		{
			cout << "Are you sure you want to exit?" << endl;
			cout << "Yes(Y) No(N)" << endl;
			cin >> input;

			if (input == 'Y' || input == 'y')
			{
				cout << "Thanks for playing our game!" << endl;
				for (int i = 0; i < size; i++)
					delete heroes[i];
				delete[] heroes;
				delete[] weapons;
				delete[] armors;
				delete[] potions;
				delete[] firespells;
				delete[] lightspells;
				delete[] icespells;
				return 0;
			}
		}
		else if (t == 'G' || t == 'g')
			g.displayMap();
		else if (t == 'C' || t == 'c')
			for (int i = 0; i < size; i++)
			{
				heroes[i]->print_info();
				heroes[i]->print_bag();
				heroes[i]->print_spellbook();
			}
		else if (t == 'E' || t == 'e')
		{
			while (true)
			{
				cout << "Which Hero is equipping?" << endl;
				for (int i = 0; i < size; i++)
				{
					cout << " (" << i+1 << ") ";
					heroes[i]->print_info();
				}

				cin >> hero;

				while (true)
				{
					cout << "Do you want to equip armor or weapons?" << endl;
					cout << "Armor(1) Weapons(2)" << endl;
					cin >> temp;

					if (temp == 1)
					{
						if(heroes[hero-1]->no_armor()==true)
						{
							cout<<"You have no armors to equip!"<<endl;
							break;
						}
						else
						{
						heroes[hero - 1]->print_armors();
						cout << "Select armor to equip: " << endl;
						cin >> temp;
						heroes[hero - 1]->equip_armor(temp - 1);
						}
					}
					else if (temp == 2)
					{
						if(heroes[hero-1]->no_weapon()==true)
						{
							cout<<"You have no weapons to equip!"<<endl;
							break;
						}
						else
						{
						heroes[hero - 1]->print_weapons();
						cout << "Select weapon to equip: " << endl;
						cin >> temp;
						heroes[hero - 1]->equip_weapon(temp - 1);
						}
					}

					cout << "Keep equipping with this hero?" << endl;
					cout << "Yes(Y) No(N)" << endl;
					cin >> input;

					if (input == 'n' || input == 'N')
						break;
				}

				cout << "Keep equipping?" << endl;
				cout << "Yes(Y) No(N)" << endl;
				cin >> input;

				if (input == 'n' || input == 'N')
					break;
			}
		}
		else if (t == 'P' || t == 'p')
		{
			while (true)
			{
				cout << "Choose hero to use potion?" << endl;
				for (int i = 0; i < size; i++)
				{
					cout << " (" << i + 1 << ") ";
					heroes[i]->print_info();
				}

				cin >> hero;

				while (true)
				{
					if(heroes[hero-1]->no_potion()==true)
					{
						cout<<"You have no potions to drink!"<<endl;
						break;
					}
					else
					{
					heroes[hero - 1]->print_potions();
					cout << "Which potion you want to drink?" << endl;
					cin >> temp;
					heroes[hero - 1]->use(temp - 1);
					cout << "Keep drinking potions with this hero?" << endl;
					cout << "Yes(Y) No(N)" << endl;
					cin >> input;
					if (input == 'n' || input == 'N')
						break;
					}
				}
				cout << "Keep drinking potions?" << endl;
				cout << "Yes(Y) No(N)" << endl;
				cin >> input;

				if (input == 'n' || input == 'N')
					break;
			}
		}
		else
		{
			int temp = rand() % 100;

			if (temp >= 65 && temp <= 100)
				cout << "Fortunately area is clear!" << endl;
			else
			{
				int num = (rand() % 3 )+ 1;
				Monster **monsters;
				monsters = new Monster *[num];

				for (int i = 0; i < num; i++)
				{
					int random = rand() % 3;
					int rand_name = rand() % 100;
					int rand_level = rand() % size;

					switch (random)
					{
					case 0:
						monsters[i] = new Dragon(monster_names[rand_name], heroes[rand_level]->get_level());
						break;
					case 1:
						monsters[i] = new Exoskeleton(monster_names[rand_name], heroes[rand_level]->get_level());
						break;
					case 2:
						monsters[i] = new Spirit(monster_names[rand_name], heroes[rand_level]->get_level());
						break;
					}
				}

				for (int i = 0; i < num; i++)
				{
					cout << "A wild ";
					monsters[i]->print_info();
					cout << " appeared!" << endl;
				}

				int round = 1;
				
				while (true)
				{
					cout << "Round " << round << " !" << endl;

					for (int i = 0; i < size; i++)
					{
						cout << "Choose action for Hero: ";
						heroes[i]->print_stats();
						cout << endl;
						cout << "Attack(A) Cast Spell(S) Equip Weapon(W) Equip Armor(O) Use Potions(U) Display Stats(D)" << endl;
						cin >> input;
						bool f = true;

						while (f)
						{
							if (input == 'D' || input == 'd')
							{
								for (int i = 0; i < size; i++)
									heroes[i]->print_stats();
								for (int i = 0; i < num; i++)
									monsters[i]->print_info();
								cout << "Attack(A) Cast Spell(S) Equip Weapons(W) Equip Armor(O) Use Potions(U) Display Stats(D)" << endl;
								cin >> input;
							}
							if (input == 'u' || input == 'U')
							{
								if(heroes[i]->no_potion() == true)
								{
									cout<<"You have no potions to drink!"<<endl;
									cout << "Attack(A) Cast Spell(S) Equip Weapons(W) Equip Armor(O) Use Potions(U) Display Stats(D)" << endl;
								cin >> input;
								}
								else
								{
								heroes[i]->print_potions();
								cout << "Which potion you want to drink?" << endl;
								cin >> temp;
								heroes[i]->use(temp - 1);
								f = false;
								}
							}
							else if (input == 'W' || input == 'w')
							{
								if(heroes[i]->no_weapon() == true)
								{
									cout<<"You have no weapons to equip!"<<endl;
									cout << "Attack(A) Cast Spell(S) Equip Weapons(W) Equip Armor(O) Use Potions(U) Display Stats(D)" << endl;
								cin >> input;
								}
								else
								{
									heroes[i]->print_weapons();
									cout << "Which item you want to equip?" << endl;
									cin >> temp;
									heroes[i]->equip_weapon(temp - 1);
									f = false;
								}
							}
							else if (input == 'O' || input == 'o')
							{
								if(heroes[i]->no_armor() == true)
								{
									cout<<"You have no armors to equip!"<<endl;
									cout << "Attack(A) Cast Spell(S) Equip Weapons(W) Equip Armor(O) Use Potions(U) Display Stats(D)" << endl;
								cin >> input;
								}
								else
								{
								heroes[i]->print_armors();
								cout << "Which item you want to equip?" << endl;
								cin >> temp;
								heroes[i]->equip_armor(temp - 1);
								f = false;
								}
							}
							else if (input == 'A' || input == 'a')
							{
								cout << "Choose Monster to attack" << endl;
								for (int i = 0; i < num; i++)
								{
									cout << "(" << i + 1 << ") ";
									monsters[i]->print_info();
								}
								cin >> temp;
								int death = temp;
								if (monsters[temp - 1]->get_current_hp() == 0)
								{
									cout << "Stop, he's already dead xD!" << endl;
									cout<<"Choose another monster to attack"<<endl;
									for (int i = 0; i < num; i++)
									{
										cout << "(" << i + 1 << ") ";
										monsters[i]->print_info();
									}
									cin>>temp;
								}
								else
								{
									monsters[temp - 1]->damage(heroes[i]->attack());
									f = false;
								}
							}
							else if (input == 's' || input == 'S')
							{
								if(heroes[i]->no_spells()== false)
								{
								cout << "Choose Monster to cast spell" << endl;
								for (int i = 0; i < num; i++)
								{
									cout << "(" << i + 1 << ") ";
									monsters[i]->print_info();
								}
								cin >> temp;
								int death = temp;
								heroes[i]->print_spellbook();
								cout << "Choose Spell to cast" << endl;
								int spell_in;
								cin >> spell_in;
								Spell *casted = heroes[i]->get_spbook(spell_in);

								if (monsters[temp - 1]->get_current_hp() == 0)
								{
									cout << "Stop, he's already dead xD!" << endl;
									cout<<"Choose another monster to attack"<<endl;
									for (int i = 0; i < num; i++)
									{
										cout << "(" << i + 1 << ") ";
										monsters[i]->print_info();
									}
									cin>>temp;
								}
								else
								{
									if (heroes[i]->castSpell(casted->get_mana()) && casted->get_level()<= heroes[i]->get_level()) 
									{
										cout << "Hero " << heroes[i]->get_name() << " casts " << casted->get_name() << endl;
										monsters[temp - 1]->damage(casted->get_damage(), casted->get_type(), casted->get_reduction(), heroes[i]->get_dexterity());
										f = false;
									}
									else
									{
										cout<<"Unable to cast Spell!"<<endl;
									}
								}

								}
								else
								{
									cout<<"You have no spells to cast!"<<endl;
									cout << "Attack(A) Cast Spell(S) Equip Weapons(W) Equip Armor(O) Use Potions(U) Display Stats(D)" << endl;
								cin >> input;
								}
							}
						}
					}
					int dead = 0;
					for (int i = 0; i < num; i++)
					{
						if (monsters[i]->get_current_hp() != 0)
						{
							int temp_hero = rand() % size;
							heroes[temp_hero]->damage(monsters[i]->attack());
						}
						else
							dead++;
					}
					if (dead == num)
					{
						cout << "Congrats you won!" << endl;
						delete[] monsters;
						for (int i = 0; i < size; i++)
						{
							if (heroes[i]->get_current_hp() == 0)
								heroes[i]->ressurect();
							heroes[i]->won(num);
						}
						break;
					}
					dead = 0;
					for (int i = 0; i < size; i++)
					{
						if (heroes[i]->get_current_hp() == 0)
							dead++;
					}
					if (dead == size)
					{
						cout << "You have the lost the battle :(" << endl;
						delete[] monsters;
						for (int i = 0; i < size; i++)
							heroes[i]->lost();
						break;
					}
					cout << "Round " << round << " ended!" << endl;
					round++;
					for (int i = 0; i < num; i++)
					{
						if (monsters[i]->get_current_hp() != 0)
							monsters[i]->round();
					}
					for (int i = 0; i < size; i++)
					{
						if (heroes[i]->get_current_hp() != 0)
							heroes[i]->round();
					}
				}
			}
		}
	}
}
