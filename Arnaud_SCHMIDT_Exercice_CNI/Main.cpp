#include <iostream>
#include <stdlib.h>
#include <string>
#include <stack>

#include "CNI.h"

using namespace std;

void modifcarte(int& choix, CNI& cartamod);
void remplicarte(CNI& cartaremplir);

int main()
{

	//préparation de la pile
	stack<CNI> BaseCNI;
	//préparation du compteur qui donnera les ID
	int compteur = BaseCNI.size();
	//préparation de la carte pas laquelle transiteront les entrées de l'utilisateur et qui stockera la dernière carte entrée dans la base
	CNI carte(compteur);
	//variable qui déterminera la fin du programme
	int fin = 0;
	//variable qui stock les inputs entrés par l'utilisateur
	int inpt = 0;
	//variables pour les entrées de données d'une carte d'identité
	int nombre = 0;
	string chaine = "";

	while (fin == 0)
	{

		cout << "Que souhaitez-vous faire ?" << endl;
		cout << "Tapez 1 pour entrer une nouvelle carte d'identite dans la base." << endl;
		if (BaseCNI.size() > 0)
		{

			cout << "Tapez 2 pour afficher la derniere carte d'identite rentree dans la base." << endl;
			cout << "Tapez 3 pour supprimer la derniere carte d'identite rentree dans la base." << endl;
			cout << "Tapez 4 pour modifier la derniere carte entree dans la base." << endl;

		}
		cout << "Tapez 5 pour quitter le programme." << endl;
		cin >> inpt;

		if (inpt == 1)
		{

			remplicarte(carte);

			cin.clear();

			carte.setID(compteur + 1);

			BaseCNI.push(carte);

			cout << "La nouvelle carte d'identite a ete ajoutee a la base." << endl;

		}
		else if (inpt == 2)
		{

			if (BaseCNI.size() > 0)
			{

				cout << "Voici les donnees de la derniere carte d'identite rentree dans la base :" << endl;
				cout << "ID : " << carte.getID() << endl;
				cout << "Nom : " << carte.getNOM() << endl;
				cout << "Prenom : " << carte.getPRENOM() << endl;
				cout << "Date de naissance : " << carte.getDDN() << endl;
				cout << "Adresse : " << carte.getADRESSE() << endl;
				cout << "Ville : " << carte.getVILLE() << endl;
				cout << "Code postal : " << carte.getCP() << endl;

			}

		}
		else if (inpt == 3)
		{

			if (BaseCNI.size() > 0)
			{

				BaseCNI.pop();
				cout << "La dernière carte entree dans la base a bien ete supprimee." << endl;

			}

		}
		else if (inpt == 4)
		{

			if (BaseCNI.size() > 0)
			{

				modifcarte(inpt, carte);

				//suppression de la derniere entree
				BaseCNI.pop();
				//nouvelle entrée similaire mais qui contient la modification
				BaseCNI.push(carte);

				cout << "Modification effectuee." << endl;

			}

		}
		else if (inpt == 5)
		{

			cout << "Au revoir." << endl;
			system("pause");
			fin = 1;

		}

		compteur = BaseCNI.size();

	}

	return 0;

}


void modifcarte(int& choix, CNI& cartamod)
//But : permettre à l'utilisateur de modifier la dernière carte entrée dans la base
//Entrée : l'input du joueur correspondant à l'élément à modifier ainsi que la carte à modifier
//Sortie : l'élément de la carte est modifié
{

	string chaine = "";
	int nombre = 0;

	cout << "Que souhaitez vous modifier ?" << endl;
	cout << "Nom = 1 / Prenom = 2 / Date de naissance = 3 / Adresse = 4 / Ville = 5 / Code postal = 6" << endl;
	cin >> choix;

	if (choix == 1)
	{

		cout << "Nom actuel : " << cartamod.getNOM() << endl;
		cout << "Entrez le nouveau nom." << endl;
		cin >> chaine;
		cartamod.setNOM(chaine);

	}
	else if (choix == 2)
	{

		cout << "Prenom actuel : " << cartamod.getPRENOM() << endl;
		cout << "Entrez le nouveau prenom." << endl;
		cin >> chaine;
		cartamod.setPRENOM(chaine);

	}
	else if (choix == 3)
	{

		cout << "Date de naissance actuelle : " << cartamod.getDDN() << endl;
		cout << "Entrez la nouvelle date de naissance." << endl;
		cin >> chaine;
		cartamod.setDDN(chaine);

	}
	else if (choix == 4)
	{

		cout << "Adresse actuelle : " << cartamod.getADRESSE() << endl;
		cout << "Entrez la nouvelle adresse." << endl;
		cin >> chaine;
		cartamod.setADRESSE(chaine);

	}
	else if (choix == 5)
	{

		cout << "Ville actuelle : " << cartamod.getVILLE() << endl;
		cout << "Entrez la nouvelle ville." << endl;
		cin >> chaine;
		cartamod.setVILLE(chaine);

	}
	else if (choix == 6)
	{

		cout << "Code postal actuel : " << cartamod.getCP() << endl;
		cout << "Entrez le nouveau code postal." << endl;
		cin >> nombre;
		cartamod.setCP(nombre);

	}

}

void remplicarte(CNI& cartaremplir)
//But : permettre à l'utilisateur de remplir une nouvelle carte d'identité
//Entrée : la carte qui sert à stocker les informations
//Sortie : une nouvelle carte ajoutée à la base
{

	string chaine = "";
	int nombre = 0;

	cout << "Entrez un nom de famille (sans espaces)." << endl;
	cin >> chaine;
	cartaremplir.setNOM(chaine);
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	cout << "Entrez un prenom (sans espace)." << endl;
	cin >> chaine;
	cartaremplir.setPRENOM(chaine);
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	cout << "Entrez une date de naissance au format JJ/MM/AA." << endl;
	cin >> chaine;
	cartaremplir.setDDN(chaine);
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	cout << "Entrez une adresse au format numero/type de rue (rue, place, avenue, etc.)/nom de la rue." << endl;
	cin >> chaine;
	cartaremplir.setADRESSE(chaine);
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	cout << "Entrez une ville (sans espace)." << endl;
	cin >> chaine;
	cartaremplir.setVILLE(chaine);
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	cout << "Entrez un code postal (exemple : 68000)." << endl;
	cin >> nombre;
	cartaremplir.setCP(nombre);
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

}