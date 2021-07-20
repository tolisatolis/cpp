Ομάδα 2 ατόμων: 
ΓΙΩΡΓΟΣ ΓΕΩΡΓΑΚΗΣ ΑΜ:1115201900035
ΑΠΟΣΤΟΛΟΣ ΑΓΡΑΦΑΣ ΑΜ:1115201900002

Σε περιβάλλον Linux, μέσα στο directory της εργασίας:
Compile: g++ *.cpp -o ergasia
Run: ./ergasia

Η εργασία αποτελείται απο 6 (ολογράφως έξι) αρχεία. Από αυτά τα 5 είναι αρχεία .cpp:
Main.cpp, Grid.cpp, Inventory.cpp, Item.cpp, Living.cpp, Spell.cpp
Το 6ο αρχείο είναι αρχέιο .h: Classes.h το οποίο περιέχει όλα τα πρωτότυπα των κλάσεων (μαζί με κάποια forward declaration)
Ο κώδικας των συναρτήσεων της κάθε κλάσης βρίσκεται στο αντίστοιχο .cpp αρχείο

1η ομάδα κλάσεων (Living.cpp)

Αφηρημένη Κλάση Living:

Public: constructor/destructor, virtual void print_info
Private: string name, int level, int healthPower, int current_hp

Αφηρημένη Κλάση Hero (κληρονομεί Living):

Public: constructor/destructor, many many print functions, getters, buy functions, sell functions, functions for drinking pots and equiping armors and weapons, functions used in battle: attack, damage,  castSpell, ressurect, won, lost, round, virtual void levelUp
Private: int magicPower(mana), int current_mana, int strength, int agility, int dexterity, int gold, int experience, int current_exp, int reduction, string class_, Bag bag, Spellbook spellbook, Weapon *weapon1, Weapon *weapon2, Armor *armor

Κλάσεις Warrior, Sorcerer, Paladin (κληρονομούν Hero):

Public: constructor/destructor, levelUp, print_info, print_stats
Private:

Αφηρημένη Κλάση Monster (κληρονομεί Living)

Public: cosntructor/destructor, functions used in battle:damage for simple attacks, damage for spells, attack, round, virtual void print
Private: int power, int defence, int dodge

Κλάσεις Dragon, Exoskeleton, Spirit (κληρονομούν Monster)

Public: constructor/destructor, print
Private:

2η ομάδα κλάσεων (Spell.cpp)

Αφηρημένη Κλάση Spell:

Public: constructor/destructor, getters, virtual void print_spell
Private: string name, int price, int minimum_lvl, int damage, int reduction ,int mana, int type

Κλάσεις FireSpell, IceSpell, LightningSpell (κληρονομούν Spell):

Public: constructor/destructor, print_spell
Private:

3η ομάδα κλάσεων (Item.cpp)

Αφηρημένη Κλάση Item:

Public: constructor/destructor, virtual void print, getters, virtual void type
Private: string name, int price, int minimum_lvl

Κλάση Weapon (κληρονομεί Item):

Public: constructor/destructor, prints, type, getters
Private: int damage, bool wield

Κλάση Armor (κληρονομεί Item):

Public: constructor/destructor, prints, type, getter
Private: int reduction

Κλάση Potion (κληρονομεί Item):

Public: constructor/destructor, prints, type, getters
Private: int increase, bool stat

4η ομάδα Κλάσεων (Inventory.cpp)

Κλάση Bag:

Public: constructor/destructor, buy functions, print functions, getters, sell functions, equip/use functions
Private: int items, Armor *armors[20], Weapon *weapons[20], Potion *potions [20]

Κλάση Spellbook:

Public: constructor/destructor, buy functions, sell functions, print functions, getters
Private: int spells, FireSpell *firespells[10], IceSpell *icespells[10], LightningSpells lightningspells[10]

5η ομάδα Κλάσεων (Grid.cpp)

Κλάση Grid

Public: constructor/destructor, displayMap, Move
Private: char grid[6][10], int x, int y, char previous

Σκοπός μας ήταν να φτιάξουμε ένα terminal based RPG. Λειτουργούμε με δείκτες σε αντικείμενα και πίνακες δεικτών σε αντικείμενα (spells, items). 
Κάθε ήρωας έχει στη διάθεση του ένα Bag για τα αντικείμενα του (weapons, armors, potions), όπου το Bag έχει πίνακα δεικτών 20 θέσεων για το κάθε 
αντικείμενο. Ομοίως λειτουργεί και το Spellbook για τα spells. Στο Market υπάρχει η δυνατότητα πώλησης και αγοράς αντικειμένων και ξορκιών. Εκτός μάχης 
ο πάιχτης μπορεί να δει τα στατιστικά και το Inventory του κάθε ήρωα του, να δει τον Χάρτη, να κάνει equip armors και weapons, να πιεί φίλτρα, να κουνηθεί στο
κόσμο του παιχνιδιού και να βγεί από το παιχνίδι. Στη μάχη ο παίχτης μπορεί να επιτεθεί με attack, spells, να κάνει equip, use, και να δεί όλα τα στατιστικά των τεράτων
και των ηρώων που εμπλέκονται στη μάχη. Κάθε ηρώας έχει το δικό Inventory, άρα οι ήρωες δεν μοιράζονται τίποτα μεταξύ τους (gold, items κλπ).

Συναρτήσεις Grid.cpp:

1) Το grid είναι ένας πίνακας χαρακτήρων ο οποίος αρχικοποιείται με συγκεκριμένους χαρακτήρες ώστε να έχει την αίσθηση ενός map 

2)Η Move δέχεται σαν όρισμα ένα από τα πλήκτρα WASD και είτε εκτυπώνει μήνυμα πως ο παίχτης δεν μπορεί να πάει σε εκείνη την κατεύθηνση, αλλιώς τον μετακινεί εκεί αλλάζοντας και τους χαρακτήρες στο grid (η τοποθεσία των ηρώων είναι το Χ)

Συναρτήσεις Spell.cpp 

Είναι όλες απλές.

Συναρτήσεις Item.cpp

Είναι όλες απλές.

Συναρτήσεις Living.cpp

1)Πολλές συναρτήσεις του Hero::, καλούν τις αντίστοιχες από το bag, spellbook.

2) Οι Hero::buy αγοράζουν αντικείμενα και ξόρικα μειώνοντας τον χρυσό.

3)Οι Hero::sell πουλάνε τα αντικείμενα και ξόρκια , ελέγχοντας αν τα αντικείμενα είναι equipped ή μη και προσθέτουν τον μισό χρυσό σε αξία του αντικειμένου.

4)Οι Hero::equip κάνουν equip όπλα και πανοπλίες ελέγχοντας αν πρόκειται να αντικαταστήσει ήδη equipped
αντικειμένο. Αυξάνουν το αντίστοιχο στατιστικό(reduction->armors, strength->weapons).

5)Η Hero::use καταναλώνει το φίλτρο αυξάνοντας το εκάστοτε στατιστικό (health, experience κλπ).

6)Η Hero::damage είναι η συνάρτηση που οι ήρωες δέχονται ζημιά στη μάχη από τα τέρατα. Ελέγχει πρώτα την πιθανότητα να αποφύγει την επίθεση αλλιώς δέχεται ζημιά μειώνοντας την ανάλογα με το reduction.

7)H Hero::castSpell ελέγχει αν ο ήρωας έχει αρκετό mana για να εκτελέσει το αντίστοιχο ξόρκι.

8)Η Hero::won αυξάνει τον χρυσό και το επίπεδο των ηρώων και ελέγχει αν ο ήρωας πληρεί τις προυποθέσεις
για να κάνει levelUp. Λαμβάνουμε υπόψιν αν πήραμε παραπάνω exp για να κάνουμε levelUp οπότε την αποθηκεύουμε για το επόμενο level.

9)H Hero::lost μειώνει το χρυσό των ηρώων και τους κάνει revive.

10)H Hero::round αυξάνει μετά από κάθε γύρο την ζωή και το mana των ηρωών.

11)Οι Κλάσεις που κληρονομούν την Hero έχουν δικίες τους levelUp, η κάθε μια.

12)Οι Monster::damage είναι οι συναρτήσεις που τα τέρατα δέχονται ζημιά, μια από απλές επιθέσεις και μια από ξόρκια. Τα ξόρκια δεν μπορεί να τα αποφύγουν τα τέρατα. Οι απλές επιθέσεις είναι dodgeable . Τα ξόρκια μειώνουν το αντίστοιχο στατιστικό ανάλογα τον τύπο του ξορκιού

Συναρτήσεις Inventory.cpp

1)Oι Bag:buy αγοράζουν αντικείμενα ελέγχωντας αν έχουμε αρκετό χώρο στο bag

2)Στις Bag::sell/use μετά την πώληση του αντικειμένου κάνουμε "σορτάρισμα του αντίστοιχου πίνακα αντικειμένων

3)Ομοίως οι Spell::sell και Spell::buy

Αρχείο Main.cpp

1)Γέμισμα πινάκων της main με ξόρκια, όπλα, πανοπλίες, φίλτρα, ονόματα τεράτων

2)Δημιουργία πινάκων του Market

3)Δημιουργία Ηρώων

4)Επεξηγηματικά πράγματα για τον παίκτη

5)Εμφάνιση επιλογών και "απάντηση παίχτη"

5α)Market->Buy
	
Γέμισμα πινάκων Market με τυχαίο τρόπο από τους πίνακες της main και εμφάνιση τους
Έπειτα ο παίχτης επιλέγει ποιος ήρωας θα αγοράσει->τι κατηγορία θέλει να αγοράσει->τι θέλει να αγοράσει

Market->Sell

Ποιος ήρωας πουλάει->τι κατηγορία πουλάει-> τι πουλάει

5β)Έξοδος από το παιχνίδι

5γ)Εκτύπωση του χάρτη

5δ)Equip
Ποιος ήρωας->ποια κατηγορία->ποιο αντικείμενο

5ε)Use 
Ποιος ήρωας->Ποιο φίλτρο

5στ)Move 

Υπολογισμός πιθανότητας μάχης. Αν όντως τότε:
1)Δημιουργία πίνακα τυχαίου μεγέθους με τυχαία είδη τεράτων, ανάλογα το επίπεδο των ηρώων( από 1 έως 3)
2)Κίνηση παίχτη(επίθεση, spell κλπ)
3)Επίθεση τεράτων
4)Έλεγχος νίκης ηρώων
5)Έλεγχος ήττας ηρώων
6)Τέλος γύρου 

ΣΗΜΑΝΤΙΚΟ: Η εργασία δεν έχει balancing δηλαδή αντικείμενα, στατιστικά, κλπ, έχουν τυχαίες τιμές και οι συναρτήσεις που τα αυξάνουν και τα αρχικοποιούν έχουν τυχαίους μαθηματικούς αλγορίθμους
