#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class CNI
{

	//données membres
	int id;
	string nom;
	string prenom;
	string ddn;
	string adresse;
	string ville;
	int cp;

	public:

		//constructeur
		CNI(int Uid, string Unom="", string Uprenom="", string Uddn="", string Uadresse="", string Uville="", int Ucp=0);

		//méthodes relatives à l'id
		void setID(int Uid);
		int getID() const;
		void afficheID() const;

		//méthodes relatives au nom
		void setNOM(string Unom);
		string getNOM() const;
		void afficheNOM() const;

		//méthodes relatives au prénom
		void setPRENOM(string Uprenom);
		string getPRENOM() const;
		void affichePRENOM() const;

		//méthodes relatives à la date de naissance
		void setDDN(string Uddn);
		string getDDN() const;
		void afficheDDN() const;

		//méthodes relatives à l'adresse
		void setADRESSE(string Uadresse);
		string getADRESSE() const;
		void afficheADRESSE() const;

		//méthodes relatives à la ville
		void setVILLE(string Uville);
		string getVILLE() const;
		void afficheVILLE() const;

		//méthodes relatives au code postal
		void setCP(int Ucp);
		int getCP() const;
		void afficheCP() const;

		//destructeur
		~CNI();

};

