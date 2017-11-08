#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class CNI
{

	//donn�es membres
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

		//m�thodes relatives � l'id
		void setID(int Uid);
		int getID() const;
		void afficheID() const;

		//m�thodes relatives au nom
		void setNOM(string Unom);
		string getNOM() const;
		void afficheNOM() const;

		//m�thodes relatives au pr�nom
		void setPRENOM(string Uprenom);
		string getPRENOM() const;
		void affichePRENOM() const;

		//m�thodes relatives � la date de naissance
		void setDDN(string Uddn);
		string getDDN() const;
		void afficheDDN() const;

		//m�thodes relatives � l'adresse
		void setADRESSE(string Uadresse);
		string getADRESSE() const;
		void afficheADRESSE() const;

		//m�thodes relatives � la ville
		void setVILLE(string Uville);
		string getVILLE() const;
		void afficheVILLE() const;

		//m�thodes relatives au code postal
		void setCP(int Ucp);
		int getCP() const;
		void afficheCP() const;

		//destructeur
		~CNI();

};

