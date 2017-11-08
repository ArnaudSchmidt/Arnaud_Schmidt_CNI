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

	//pr�paration de la pile
	stack<CNI> BaseCNI;
	//pr�paration du compteur qui donnera les ID
	int compteur = BaseCNI.size();
	//pr�paration de la carte pas laquelle transiteront les entr�es de l'utilisateur et qui stockera la derni�re carte entr�e dans la base
	CNI carte(compteur);
	//variable qui d�terminera la fin du programme
	int fin = 0;
	//variable qui stock les inputs entr�s par l'utilisateur
	int inpt = 0;
	//variables pour les entr�es de donn�es d'une carte d'identit�
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
				cout << "La derni�re carte entree dans la base a bien ete supprimee." << endl;

			}

		}
		else if (inpt == 4)
		{

			if (BaseCNI.size() > 0)
			{

				modifcarte(inpt, carte);

				//suppression de la derniere entree
				BaseCNI.pop();
				//nouvelle entr�e similaire mais qui contient la modification
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
//But : permettre � l'utilisateur de modifier la derni�re carte entr�e dans la base
//Entr�e : l'input du joueur correspondant � l'�l�ment � modifier ainsi que la carte � modifier
//Sortie : l'�l�ment de la carte est modifi�
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
//But : permettre � l'utilisateur de remplir une nouvelle carte d'identit�
//Entr�e : la carte qui sert � stocker les informations
//Sortie : une nouvelle carte ajout�e � la base
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