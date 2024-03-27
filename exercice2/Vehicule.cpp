#include <iostream>
#include <cstring>
using namespace std;
class Vehicule{
    protected:
     char *matricule,*Marque;
     int anneModele;
     float PrxHT;
     public:
      Vehicule(const char *mat,const char *mar, int anne, float prix){
        matricule=new char[strlen(mat)];
        Marque=new char[strlen(mar)];
        strcpy(matricule,mat);
        strcpy(Marque,mar);
        anneModele=anne;
        PrxHT=prix;
      }
      Vehicule(const Vehicule &v){
        matricule=new char[strlen(v.matricule)];
        Marque=new char[strlen(v.Marque)];
        strcpy(matricule,v.matricule);
        strcpy(Marque,v.Marque);
        anneModele=v.anneModele;
        PrxHT=v.PrxHT;
      }
      ~Vehicule() {
       delete[] matricule; 
       delete[] Marque;
       }
      virtual void affiche(){
        cout<<"votre matricule est : "<<matricule<<" est marque est "<<Marque
        <<" , est l'annee de modele est "<<anneModele<<" son prix est "<<PrxHT<<endl;
      }
      void setprixHT(float p){
        PrxHT=p;
      }

      float getPrixTTC(){
        return PrxHT*1.2;
      }

};
class Voiture: public Vehicule{
    static int cpt;
    int nbrePlace;
    public:
     Voiture(int nbrePlace,const char *mat,const char *mar, int anne, float prix): Vehicule(mat,mar,anne,prix){
        this->nbrePlace=nbrePlace;
        cpt++;
     }
     Voiture(const Voiture &v): Vehicule(v.matricule,v.Marque,v.anneModele,v.PrxHT){
        nbrePlace=v.nbrePlace;
        cpt++;
     }
     ~Voiture(){
      cpt--;
     }
     void afficher(){
      cout<<"Matricule : "<<matricule<<" Marque : "<<Marque
      <<" Annee : "<<anneModele<<" PrixHT : "<<PrxHT
      <<" NbrePLace : "<<nbrePlace<<endl;
     }
     static int getNombre() {
       return cpt;
    }

     
};
int Voiture::cpt=0; //initialisation de compteur.

int main(){
    Voiture v1(4,"123-A-50", "Marqx", 2007, 15000), v2(v1);
    v2.afficher();
    cout<<v2.getNombre()<<endl;
    cout<<v2.getPrixTTC()<<endl;
    


    
}