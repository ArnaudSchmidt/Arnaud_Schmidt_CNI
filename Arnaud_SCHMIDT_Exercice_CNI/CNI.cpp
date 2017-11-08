#include "CNI.h"
#include <string>

CNI::CNI(int Uid, string Unom, string Uprenom, string Uddn, string Uadresse, string Uville, int Ucp)
{

	id = Uid;
	nom = Unom;
	prenom = Uprenom;
	ddn = Uddn;
	adresse = Uadresse;
	ville = Uville;
	cp = Ucp;

}

void CNI::setID(int Uid)
{

	id = Uid;

}

int CNI::getID() const
{

	return id;

}

void CNI::afficheID() const
{

	std::cout << id << std::endl;

}

void CNI::setNOM(string Unom)
{

	nom = Unom;

}

string CNI::getNOM() const
{

	return nom;

}

void CNI::afficheNOM() const
{

	std::cout << nom << std::endl;

}

void CNI::setPRENOM(string Uprenom)
{

	prenom = Uprenom;

}

string CNI::getPRENOM() const
{

	return prenom;

}

void CNI::affichePRENOM() const
{

	std::cout << prenom << std::endl;

}

void CNI::setDDN(string Uddn)
{

	ddn = Uddn;

}

string CNI::getDDN() const
{

	return ddn;

}

void CNI::afficheDDN() const
{

	std::cout << ddn << std::endl;

}

void CNI::setADRESSE(string Uadresse)
{

	adresse = Uadresse;

}

string CNI::getADRESSE() const
{

	return adresse;

}

void CNI::afficheADRESSE() const
{

	std::cout << adresse << std::endl;

}

void CNI::setVILLE(string Uville)
{

	ville = Uville;

}

string CNI::getVILLE() const
{

	return ville;

}

void CNI::afficheVILLE() const
{

	std::cout << ville << std::endl;

}

void CNI::setCP(int Ucp)
{

	cp = Ucp;

}

int CNI::getCP() const
{

	return cp;

}

void CNI::afficheCP() const
{

	std::cout << cp << std::endl;

}

CNI::~CNI()
{



}