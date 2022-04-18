//Dania Nasereddin 2-19-20 #19
// Lab 04 - Tamagotchi
// This is a program that allows the user to interact with a virtual pet. The pet has an age
// and hunger and happiness status. The user can choose to feed it or play with it. 
// If the user chooses to play, happiness with increase by 1. If the user chooses to feed,
// hungar with increase by 1. They pet will die at age 5 or if either status reaches 0.
// Each action will increase its age by 1 and for each action a random status will decrease by 1.

#include <iostream>
#include <time.h>
#include <string>
using namespace std;

class Pet
{
	private:
		string name;
		int hunger;
		int happiness;
		int age;
	public:
	Pet(string n)
	{
		name = n;
		hunger = rand() % 5 + 1; //ramdomly generates a number 1-5
		happiness = rand() % 5 + 1;
		age = 0;
	}
	int feed()
	{
		hunger += 1;
		cout << name << " dances with joy and eats some pasta! (+1 Hunger)\n";
		age++;
		return hunger;
	}
	int play()
	{
		happiness += 1;
		cout << name << " plays some games! (+1 Happiness)\n";
		age++;
		return happiness;
	}
	void decrease() //For each action the player takes, a random stat drops by one
	{
		int which = rand() % 2 + 1;
		if (which == 1)
		{
			hunger -= 1;
			cout << name << " is looking hungry (-1 Hunger)\n\n";
		}
		else
		{
			happiness -= 1;
			cout << name << " is looking a little sad (-1 Happiness)\n\n";
		}
	}
	void setName(string n)
	{
		name = n;
	}
	string getName()
	{
		return name;
	}
	int getHunger() //getters
	{
		return hunger;
	}
	int getHappiness()
	{
		return happiness;
	}
	int getAge()
	{
		return age;
	}
	void displayAttributes() //prints out stats to user
	{
		cout << "\n--" << name << "'s stats--" << endl;
		cout << "Hunger: " << hunger << endl;
		cout << "Happiness: " << happiness << endl;
		cout << "Age: " << age << endl << endl;
	}
};

int main()
{
	srand(time(0));
	int choice;
	string name;
	Pet pet(name);
	cout << "Welcome to Orangatain Time! Where you can raise your very own virtual orangutain! \n\n";
	cout << "-Virtual Orangutain-\n";
	cout << "-----m-----m-----\n";
	cout << "     @(o.o)@\n";
	cout << "       (O)~~\n";
	cout << "       m m \n";
	cout << "\nPlease enter a name for your pet orangatain: ";
	cin >> name;
	pet.setName(name);

	pet.displayAttributes();
	while (pet.getHappiness() > 0 && pet.getHunger() > 0 && pet.getAge() != 5) //while pet is still alive
	{
		cout << "\nMain Menu: " << endl;
		cout << "1. Feed \n";
		cout << "2. Play \n";
		cout << "Select 1 or 2: ";
		cin >> choice;
		cout << "\n";

		if (choice == 1) //if they choose to feed
		{
			pet.feed();
			pet.decrease();
			pet.getAge();
			pet.displayAttributes();
		}

		if (choice == 2) // if they choose to play
		{
			pet.play();
			pet.decrease();
			pet.getAge();
			pet.displayAttributes();
		}
	}

	if (pet.getHappiness() == 0 || pet.getHunger() == 0) //if the pet dies from hunger or unhappiness
	{
		cout << pet.getName() << " died tragically.\n";
	}

	if (pet.getAge() == 5) //if the pet dies from old age
	{
		cout << pet.getName() << " died of old age.\n";
	}

	system("PAUSE>nul");
	return 0;
}

