#include <iostream>
#include <cstring>
using namespace std;
class Contact {
protected:
 char *nom, *mess;
 int age, numContact;
 static int cmp;
public:
 Contact(const char* n="mohamed", int a=0){
    nom= new char[strlen(n)];
    strcpy(nom,n);
    age=a;
    cmp++;
    numContact=cmp;
 }
 ~Contact(){
    delete[] nom,mess;
    cmp--;
 }
 virtual void affiche(){
    cout<<"Numero : "<<numContact<<" Nom : "<<nom<<" Age : "<<age<<" Message : "<<mess<<endl;
 }
 void setMessage(const char* mes="Pas de message..."){
    mess=new char[strlen(mess)];
    strcpy(mess,mes);
 }
 void setAge(int a=18){
    if(a>=18 && a<=60){
    age=a;
    }
 }

};
int Contact::cmp=0;
class ContactSal : public Contact{
      char* mat;
      float salaire;
      bool bonContact;
      public:
       ContactSal(const char* n, int a,float sal,bool bonContact=false):Contact(n,a){
         this->bonContact=bonContact;
         salaire=sal;
       }
       void affiche(){
        Contact::affiche();
        cout<<"Matricule: "<<mat<<" Salaire: "<<salaire<<" Est un bon contact: "<<bonContact<<endl;
        }
        void setBonContact(){
            bonContact=true;
            salaire=calculSalaire();
            
        }
        float calculSalaire(){
            if (bonContact){
            salaire+=salaire*0.1;}
            return salaire;
        }
        friend ostream& operator<<(ostream& out, const ContactSal& C);
     

};
ostream& operator<<(ostream& out, const ContactSal& C) {
    out << "Numero : " << C.numContact << " Nom : " << C.nom << " Age : " << C.age << " Message : " << C.mess << " Matricule: " << C.mat << " Salaire: " << C.salaire << " Est un bon contact: " << C.bonContact;
    return out;
}


int main(){
    Contact c1("Karim",50),c2("laila",23);
    ContactSal s1("Med", 20,10000,true),s2("ayoub",20,10005,false);
    cout<<s2;
    c1.setMessage("hello ayoub");
    c1.affiche();
    s2.setBonContact();
    cout<<s2;
}

