#include <iostream>
#include <stdlib.h>
#include <string>
#include <stack>

#include "CNI.h"

using namespace std;

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

			cout << "Entrez un nom de famille (sans espaces)." << endl;
			cin >> chaine;
			carte.setNOM(chaine);
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << "Entrez un prenom (sans espace)." << endl;
			cin >> chaine;
			carte.setPRENOM(chaine);
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << "Entrez une date de naissance au format JJ/MM/AA." << endl;
			cin >> chaine;
			carte.setDDN(chaine);
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << "Entrez une adresse au format numero/type de rue (rue, place, avenue, etc.)/nom de la rue." << endl;
			cin >> chaine;
			carte.setADRESSE(chaine);
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << "Entrez une ville (sans espace)." << endl;
			cin >> chaine;
			carte.setVILLE(chaine);
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << "Entrez un code postal (exemple : 68000)." << endl;
			cin >> nombre;
			carte.setCP(nombre);
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

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

				cout << "Que souhaitez vous modifier ?" << endl;
				cout << "Nom = 1 / Prenom = 2 / Date de naissance = 3 / Adresse = 4 / Ville = 5 / Code postal = 6" << endl;
				cin >> inpt;

				if (inpt == 1)
				{

					cout << "Nom actuel : " << carte.getNOM() << endl;
					cout << "Entrez le nouveau nom." << endl;
					cin >> chaine;
					carte.setNOM(chaine);

				}
				else if (inpt == 2)
				{

					cout << "Prenom actuel : " << carte.getPRENOM() << endl;
					cout << "Entrez le nouveau prenom." << endl;
					cin >> chaine;
					carte.setPRENOM(chaine);

				}
				else if (inpt == 3)
				{

					cout << "Date de naissance actuelle : " << carte.getDDN() << endl;
					cout << "Entrez la nouvelle date de naissance." << endl;
					cin >> chaine;
					carte.setDDN(chaine);

				}
				else if (inpt == 4)
				{

					cout << "Adresse actuelle : " << carte.getADRESSE() << endl;
					cout << "Entrez la nouvelle adresse." << endl;
					cin >> chaine;
					carte.setADRESSE(chaine);

				}
				else if (inpt == 5)
				{

					cout << "Ville actuelle : " << carte.getVILLE() << endl;
					cout << "Entrez la nouvelle ville." << endl;
					cin >> chaine;
					carte.setVILLE(chaine);

				}
				else if (inpt == 6)
				{

					cout << "Code postal actuel : " << carte.getCP() << endl;
					cout << "Entrez le nouveau code postal." << endl;
					cin >> nombre;
					carte.setCP(nombre);

				}

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