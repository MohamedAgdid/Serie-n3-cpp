#include <iostream>
#include <cstring>
using namespace std;
class Distributeur{
  protected:
  float sommeArgent;
  public:
   Distributeur(int a=0){
    sommeArgent=a;
   }
   void ajoutePiece(float x){
     sommeArgent+=x;
   }
   void delivreBoisson(){
    if(sommeArgent>=5){
        cout<<"Voila"<<endl;
        sommeArgent-=5;
        cout<<"Somme rendu est : "<<sommeArgent<<" dirhams"<<endl;
    }
    else if(sommeArgent<5){
    cout<<"Pas assez"<<endl;}
   }
   ~Distributeur(){}

};
class DistributeurMulti : public Distributeur{
    int nbrTypes;
    int typeBoisson;
    public:
    DistributeurMulti(){
        nbrTypes=1;
        typeBoisson=1;
    }
    DistributeurMulti(int n){
        nbrTypes=n;
    }
    void selection(int t){
        if (t<1 || nbrTypes<t) cout<<"Erreur de selection"<<endl;
        else typeBoisson=t;
    }
    void delivreBoisson(){
        if (typeBoisson==0) cout<<"Selectionnez une boisson"<<endl;
       else {
        Distributeur::delivreBoisson();
        typeBoisson=0;
       }
    }
};
int main(){
    Distributeur a(1);
    a.ajoutePiece(5);
    a.delivreBoisson();
    DistributeurMulti b(3);
    b.ajoutePiece(6);
    b.selection(2);
    b.delivreBoisson();
}
