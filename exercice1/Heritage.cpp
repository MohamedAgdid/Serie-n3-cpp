#include <iostream>
using namespace std;
class point{
 protected:   
   int x;
   int y;
 public:
 point(){
 x=0;
 y=0;
 }
 point(int a,int b){
 x=a;
 y=b;
 }
 ~point(){};
 int getX(){
 return x;
 }
 int getY(){
 return y;
 }
 
 void afficher(){
 cout<<"("<<x<<","<<y<<")"<<endl;
 } 
};
class cercle: public point{
    protected:
     int r;
    public:
      cercle(int a, int b, int r):point(a,b){
        
        this->r=r;
      }
      void afficher(){
          point::afficher();
          cout<<"rayon est :"<<r<<endl;
      }
      

};
class cylindre: public cercle{
      int l;
      public:
       cylindre(int a, int b, int c, int d) : cercle(a, b, c) {
         l = d;
       }
      void afficher(){
        cercle::afficher();
        cout<<"langeur est : "<<l<<endl;
      }
};

class rectangle : public point {
  protected:
    int l,L;
  public:
   rectangle(int l,int L,int a, int b):point(a,b){
      this->l=l;
      this->L=L;
   }
   int aire() {
        return L * l;
    }

    int perimetre() {
        return 2 * (L +l);
    }
    void afficher(){
      point::afficher();
      cout<<"L "<<L<<" l "<<l<<endl;
    }
  
};

class parallelepipede:public rectangle{
    private:
     int h;
    public:
     parallelepipede(int l,int L,int a,int b,int h):rectangle(l,L,a,b){
      this->h=h;
     }
     void afficher(){
      rectangle::afficher();
      cout<<"heuteur est "<<h<<endl;
     }
};

int main(){
    point a(1,2);
    cercle c(1,2,3);
    cylindre d(1,2,3,4);
    d.afficher();
    rectangle R(1,2,4,5);
    parallelepipede par(1,2,3,4,5);
    par.afficher();

}
