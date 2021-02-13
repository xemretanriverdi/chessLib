#include <iostream>
#include "chessLib.h"
using namespace std;


struct position setPoz(char dsy,short yty) {
          struct position p1;
          p1.dusey=dsy;
          p1.yatay=yty;
          return p1;
}
Tas::Tas() {
};
Tas::Tas(Tas &t) {
          pos =t.pos;
}
Tas::Tas(struct position poz) {
          this->pos=poz;

          cout << "Tas olusturuldu\n";


};

Tas::~Tas() {
          cout << "Tas silindi\n";
};

struct position* Tas::getHamle() {
          return this->hamle;

};
void Tas::setHamle(struct position* h) {
          this->hamle=h;
};

struct position Tas::getPos() {
          return this->pos;

};

void Tas::setPos(struct position p) {
          this->pos=p;
};

struct position *haraketSah(struct position ilkpoz) {
          struct position *sonuc=(position *)malloc(8*sizeof(struct position));

          sonuc[0]=setPoz((char)(ilkpoz.dusey),ilkpoz.yatay+1);
          sonuc[1]=setPoz((char)(ilkpoz.dusey),ilkpoz.yatay-1);
          sonuc[2]=setPoz((char)(ilkpoz.dusey +1),ilkpoz.yatay);
          sonuc[3]=setPoz((char)(ilkpoz.dusey -1),ilkpoz.yatay);
          sonuc[4]=setPoz((char)(ilkpoz.dusey +1),ilkpoz.yatay+1);
          sonuc[5]=setPoz((char)(ilkpoz.dusey -1),ilkpoz.yatay-1);
          sonuc[6]=setPoz((char)(ilkpoz.dusey -1),ilkpoz.yatay+1);
          sonuc[7]=setPoz((char)(ilkpoz.dusey +1),ilkpoz.yatay-1);
          int i;

          for(i=0; i<8; i++) {
                    /*
                    if((sonuc[i].dusey==beyazTaslar[i]->getPos().dusey && sonuc[i].yatay==beyazTaslar[i]->getPos().yatay) ||
                     (sonuc[i].dusey==siyahTaslar[i]->getPos().dusey && sonuc[i].yatay==siyahTaslar[i]->getPos().yatay) ){
                    	sonuc[i]=setPoz('0',-1);
                    }
                    */
          }

          return sonuc;
}
struct position *haraketVezir(struct position ilkpoz) {
          struct position *sonuc=(position *)malloc(64*sizeof(struct position));
          int moveCount=0;
          int i,j;

          for(i=0; i<8; i++) { //dusey gitme
                    if(i !=ilkpoz.yatay-1) {
                              sonuc[moveCount]=setPoz(ilkpoz.dusey,i+1);
                              moveCount++;
                    }
          }

          for(i=0; i<8; i++) { //yatay gitme
                    if(i !=(short)(ilkpoz.dusey-65)) {
                              sonuc[moveCount]=setPoz((char)(i+65),ilkpoz.yatay);
                              moveCount++;
                    }
          }

          int birim=1;
          short control =0;

          for(i=0; i<8; i++) { //ust capraz gitme
                    if(i<ilkpoz.yatay &&control !=1) {
                              for(j=0; j<(int)(ilkpoz.dusey-65)  ; j++) {
                                        sonuc[moveCount]=setPoz((char)((int)(ilkpoz.dusey-birim)),ilkpoz.yatay+birim);
                                        moveCount++;
                                        birim++;
                              }

                              control=1;

                    } else if(i>ilkpoz.yatay&&control ==1 ) {
                              birim=1;

                              for(j=0; j<(8- ((int)(ilkpoz.dusey)-65)) ; j++) {
                                        sonuc[moveCount]=setPoz((char)((int)(ilkpoz.dusey+birim)),ilkpoz.yatay+birim);
                                        moveCount++;
                                        birim++;
                              }

                              control =0;
                    }

          }

          birim=1;

          for(i=0; i<8; i++) { //alt capraz gitme
                    if(i<ilkpoz.yatay &&control !=1) {
                              for(j=0; j<(int)(ilkpoz.dusey-65)  ; j++) {
                                        sonuc[moveCount]=setPoz((char)((int)(ilkpoz.dusey-birim)),ilkpoz.yatay-birim);
                                        moveCount++;
                                        birim++;
                              }

                              control=1;

                    } else if(i>ilkpoz.yatay&&control ==1 ) {
                              birim=1;

                              for(j=0; j<(8- ((int)(ilkpoz.dusey)-65)) ; j++) {
                                        sonuc[moveCount]=setPoz((char)((int)(ilkpoz.dusey+birim)),ilkpoz.yatay-birim);
                                        moveCount++;
                                        birim++;
                              }

                              control =0;
                    }

          }

          return sonuc;
}
struct position *haraketFil(struct position ilkpoz) {
          struct position *sonuc=(position *)malloc(16*sizeof(struct position));

          int moveCount=0;
          int i,j;
          int birim=1;
          int control =0;

          for(i=0; i<8; i++) { //ust capraz gitme
                    if(i<ilkpoz.yatay &&control !=1) {
                              for(j=0; j<(int)(ilkpoz.dusey-65)  ; j++) {
                                        sonuc[moveCount]=setPoz((char)((int)(ilkpoz.dusey-birim)),ilkpoz.yatay+birim);
                                        moveCount++;
                                        birim++;
                              }

                              control=1;

                    } else if(i>ilkpoz.yatay&&control ==1 ) {
                              birim=1;

                              for(j=0; j<(8- ((int)(ilkpoz.dusey)-65)) ; j++) {
                                        sonuc[moveCount]=setPoz((char)((int)(ilkpoz.dusey+birim)),ilkpoz.yatay+birim);
                                        moveCount++;
                                        birim++;
                              }

                              control =0;
                    }

          }

          birim=1;

          for(i=0; i<8; i++) { //alt capraz gitme
                    if(i<ilkpoz.yatay &&control !=1) {
                              for(j=0; j<(int)(ilkpoz.dusey-65)  ; j++) {
                                        sonuc[moveCount]=setPoz((char)((int)(ilkpoz.dusey-birim)),ilkpoz.yatay-birim);
                                        moveCount++;
                                        birim++;
                              }

                              control=1;

                    } else if(i>ilkpoz.yatay&&control ==1 ) {
                              birim=1;

                              for(j=0; j<(8- ((int)(ilkpoz.dusey)-65)) ; j++) {
                                        sonuc[moveCount]=setPoz((char)((int)(ilkpoz.dusey+birim)),ilkpoz.yatay-birim);
                                        moveCount++;
                                        birim++;
                              }

                              control =0;
                    }

          }

          return sonuc;
}

struct position *haraketKale(struct position ilkpoz) {
          struct position *sonuc=(position *)malloc(16*sizeof(struct position));
          int moveCount=0;
          int i;

          for(i=0; i<8; i++) { //dusey gitme
                    if(i !=ilkpoz.yatay-1) {
                              sonuc[moveCount]=setPoz(ilkpoz.dusey,i+1);
                              moveCount++;
                    }
          }

          for(i=0; i<8; i++) { //yatay gitme
                    if(i !=(int)(ilkpoz.dusey-65)) {
                              sonuc[moveCount]=setPoz((char)(i+65),ilkpoz.yatay);
                              moveCount++;
                    }
          }

          return sonuc;
}
struct position *haraketBeyazPiyon(struct position ilkpoz) {
          struct position *sonuc=(position *)malloc(4*sizeof(struct position));
          if(ilkpoz.yatay==2){
                    sonuc[3]=setPoz((char)(ilkpoz.dusey ),ilkpoz.yatay+2);

          }
          sonuc[0]=setPoz((char)(ilkpoz.dusey ),ilkpoz.yatay+1);
          sonuc[1]=setPoz((char)(ilkpoz.dusey+1 ),ilkpoz.yatay+1);
        sonuc[2]=setPoz((char)(ilkpoz.dusey-1 ),ilkpoz.yatay+1);
          return sonuc;
}
struct position *haraketSiyahPiyon(struct position ilkpoz) {
          struct position *sonuc=(position *)malloc(4*sizeof(struct position));
           if(ilkpoz.yatay==7){
          sonuc[4]=setPoz((char)(ilkpoz.dusey ),ilkpoz.yatay-2);

          }
          sonuc[0]=setPoz((char)(ilkpoz.dusey ),ilkpoz.yatay-1);
        sonuc[1]=setPoz((char)(ilkpoz.dusey+1 ),ilkpoz.yatay-1);
        sonuc[2]=setPoz((char)(ilkpoz.dusey-1 ),ilkpoz.yatay-1);


          return sonuc;
}
struct position *haraketAt(struct position ilkpoz) {
          struct position *sonuc=(position *)malloc(8*sizeof(struct position));
          sonuc[0]=setPoz((char)((int)(ilkpoz.dusey+2)),ilkpoz.yatay+1);
          sonuc[1]=setPoz((char)((int)(ilkpoz.dusey-2)),ilkpoz.yatay+1);
          sonuc[2]=setPoz((char)((int)(ilkpoz.dusey+2)),ilkpoz.yatay-1);
          sonuc[3]=setPoz((char)((int)(ilkpoz.dusey-2)),ilkpoz.yatay-1);
          sonuc[4]=setPoz((char)((int)(ilkpoz.dusey+1)),ilkpoz.yatay+2);
          sonuc[5]=setPoz((char)((int)(ilkpoz.dusey+1)),ilkpoz.yatay-2);
          sonuc[6]=setPoz((char)((int)(ilkpoz.dusey-1)),ilkpoz.yatay+2);
          sonuc[7]=setPoz((char)((int)(ilkpoz.dusey-1)),ilkpoz.yatay-2);
          return sonuc;
}




/*  V E Z İ R -************************************/
Vezir::Vezir(struct position pos) {
          this->pos=pos;

          this->hamle=haraketVezir(pos); //yapabilecegi hamleler

};

void Vezir::printPiece(void) {
          cout<<"Type        : "<<" Vezir"<<endl;
          cout<<"Current Pos : "<<this->pos.dusey<<this->pos.yatay<<endl;
          int i;
          cout<<"Possible Moves : "<<endl;

          for(i=0; i<=32; i++) {

                    if(hamle[i].dusey<73 &&hamle[i].dusey>=65&&hamle[i].yatay<8 &&hamle[i].yatay>0  ) {

                              cout<<this->hamle[i].dusey<<this->hamle[i].yatay<<" ";

                    }

          }cout<<endl<<endl;

}
/*  SAH -************************************/

Sah::Sah(struct position pos) {
          this->pos=pos;


          this->hamle=haraketSah(pos); //yapabilecegi hamleler

};

void Sah::printPiece(void) {
          cout<<"Type        : "<<" Sah"<<endl;
          cout<<"Current Pos : "<<this->pos.dusey<<this->pos.yatay<<endl;
          int i;
          cout<<"Possible Moves : "<<endl;

          for(i=0; i<4; i++) {

                    if(hamle[i].dusey<73 &&hamle[i].dusey>=65&&hamle[i].yatay<8 &&hamle[i].yatay>0 ) {

                              cout<<this->hamle[i].dusey<<this->hamle[i].yatay<<" ";

                    }

          }cout<<endl<<endl;

}
/*  AT -************************************/

At::At(struct position pos) {
          this->pos=pos;


          this->hamle=haraketAt(pos); //yapabilecegi hamleler

};

void At::printPiece(void) {
          cout<<"Type        : "<<" At"<<endl;
          cout<<"Current Pos : "<<this->pos.dusey<<this->pos.yatay<<endl;
          int i;
          cout<<"Possible Moves : "<<endl;

          for(i=0; i<=16; i++) {

                    if(hamle[i].dusey<73 &&hamle[i].dusey>=65&&hamle[i].yatay<8 &&hamle[i].yatay>0 ) {

                              cout<<this->hamle[i].dusey<<this->hamle[i].yatay<<" ";

                    }

          }

          cout<<endl<<endl;

}
/*  Fil -************************************/

Fil::Fil(struct position pos) {
          this->pos=pos;
          this->hamle=haraketFil(pos); //yapabilecegi hamleler

};

void Fil::printPiece(void) {
          cout<<"Type        : "<<" Fil"<<endl;
          cout<<"Current Pos : "<<this->pos.dusey<<this->pos.yatay<<endl;
          int i;
          cout<<"Possible Moves : "<<endl;

          for(i=0; i<=16; i++) {

                    if(hamle[i].dusey<73 &&hamle[i].dusey>=65&&hamle[i].yatay<8 &&hamle[i].yatay>0 ) {

                              cout<<this->hamle[i].dusey<<this->hamle[i].yatay<<" ";

                    }

          }
cout<<endl<<endl;
}

/*  P İ Y O N -************************************/

BeyazPiyon::BeyazPiyon(struct position pos) {
          this->pos=pos;
          this->hamle=haraketBeyazPiyon(pos); //yapabilecegi hamleler

};

void BeyazPiyon::printPiece(void) {
          cout<<"Type        : "<<" Piyon"<<endl;
          cout<<"Current Pos : "<<this->pos.dusey<<this->pos.yatay<<endl;
          int i;
          cout<<"Possible Moves : "<<endl;

          for(i=0; i<=1; i++) {
                    if(hamle[i].dusey<73 &&hamle[i].dusey>=65&&hamle[i].yatay<8 &&hamle[i].yatay>0 ) {

                              cout<<this->hamle[i].dusey<<this->hamle[i].yatay<<" ";

                    }


          }
cout<<endl<<endl;
}

SiyahPiyon::SiyahPiyon(struct position pos) {
          this->pos=pos;
          this->hamle=haraketSiyahPiyon(pos); //yapabilecegi hamleler

};

void SiyahPiyon::printPiece(void) {
          cout<<"Type        : "<<" Piyon"<<endl;
          cout<<"Current Pos : "<<this->pos.dusey<<this->pos.yatay<<endl;
          int i;
          cout<<"Possible Moves : "<<endl;

          for(i=0; i<=1; i++) {
                    if(hamle[i].dusey<73 &&hamle[i].dusey>=65&&hamle[i].yatay<8 &&hamle[i].yatay>0 ) {

                              cout<<this->hamle[i].dusey<<this->hamle[i].yatay<<" ";

                    }


          }
cout<<endl<<endl;
}

/*  K A L E -************************************/

Kale::Kale(struct position pos) {
          this->pos=pos;
          this->hamle=haraketKale(pos); //yapabilecegi hamleler

};

void Kale::printPiece(void) {
          cout<<"Type        : "<<" Kale"<<endl;
          cout<<"Current Pos : "<<this->pos.dusey<<this->pos.yatay<<endl;
          int i;
          cout<<"Possible Moves : "<<endl;

          for(i=0; i<=16; i++) {

                    if(hamle[i].dusey<73 &&hamle[i].dusey>=65&&hamle[i].yatay<8 &&hamle[i].yatay>0 ) {

                              cout<<this->hamle[i].dusey<<this->hamle[i].yatay<<" ";

                    }
          }
cout<<endl<<endl;
}
void movePiece(Tas *k,struct position newP, Tas **seninTaslar,Tas **karsiTaslar,char tas ) {
          int i,j;
          bool kontrol = false;

          for(i=0; i<16; i++) {

                              for(j=0; j<16; j++) {
                                        if(seninTaslar[j]->getHamle()[j].dusey==newP.dusey&& seninTaslar[j]->getHamle()[j].yatay==newP.yatay) {
                                        cout<<"imkansız hamle!!!!"<<endl;
                                                  break;

                                        } else {
                                                  if(karsiTaslar[j]->getPos().dusey==newP.dusey&& karsiTaslar[j]->getPos().yatay==newP.yatay) {
                                                            karsiTaslar[j]->~Tas();
                                                            cout<<"tas yediniz"<<endl;

                                                  }

                                                  k->setPos(newP);

                                                  if(tas=='S') {
                                                            k->setHamle(haraketSah(newP));

                                                  }

                                                  if(tas=='V') {
                                                            k->setHamle(haraketVezir(newP));
                                                  }

                                                  if(tas=='F') {
                                                             k->setHamle(haraketFil(newP));
                                                  }

                                                  if(tas=='K') {
                                                            k->setHamle(haraketKale(newP));
                                                  }

                                                  if(tas=='P') {   //Beyaz
                                                             k->setHamle(haraketBeyazPiyon(newP));

                                                  }if(tas=='p') { //siyah
                                                             k->setHamle(haraketSiyahPiyon(newP));

                                                  }

                                                  if(tas=='A') {
                                                             k->setHamle(haraketAt(newP));
                                                  }

                                                  kontrol = true;
                                                  break;

                                        }
                              }

                              if(kontrol) {
                                        break;
                              }

          };

          if(!kontrol) {
                    cout<<"Error: Move is not suitable!"<<endl;
          }
};


