#include <iostream>
#include "chessLib.h"
using namespace std;
void oyunStart(void){

 int i;
    struct position **board;
    Tas **beyazTaslar=(Tas **)malloc(sizeof (Tas*)*16);
    Tas **siyahTaslar=(Tas **)malloc(sizeof (Tas*)*16);
    board = (struct position**)malloc(8*sizeof(struct position*));
    for(i=1; i<=8; i++)
    {
        board[i]=(struct position*)malloc(8*sizeof(struct position));

    }

    Kale  *beyazKale1 =new Kale(setPoz('A',1));beyazTaslar[0]=beyazKale1;
    Kale  *beyazKale2 =new Kale(setPoz('H',1));beyazTaslar[1]=beyazKale2;
    At    *beyazAt1 =new At(setPoz('B',1));beyazTaslar[2]=beyazAt1;
    At    *beyazAt2 =new At(setPoz('G',1));beyazTaslar[3]=beyazAt2;
    Fil   *beyazFil1 =new Fil(setPoz('C',1));beyazTaslar[4]=beyazFil1;
    Fil   *beyazFil2 =new Fil(setPoz('F',1));beyazTaslar[5]=beyazFil2;
    Vezir *beyazVezir =new Vezir(setPoz('D',1));beyazTaslar[6]=beyazVezir;
    Sah   *beyazSah =new Sah(setPoz('E',1));beyazTaslar[7]=beyazSah;
    BeyazPiyon *beyazPiyon1 =new BeyazPiyon(setPoz('A',2));beyazTaslar[8]=beyazPiyon1;
    BeyazPiyon *beyazPiyon2 =new BeyazPiyon(setPoz('B',2));beyazTaslar[9]=beyazPiyon2;
    BeyazPiyon *beyazPiyon3 =new BeyazPiyon(setPoz('C',2));beyazTaslar[10]=beyazPiyon3;
    BeyazPiyon *beyazPiyon4 =new BeyazPiyon(setPoz('D',2));beyazTaslar[11]=beyazPiyon4;
    BeyazPiyon *beyazPiyon5 =new BeyazPiyon(setPoz('E',2));beyazTaslar[12]=beyazPiyon5;
    BeyazPiyon *beyazPiyon6 =new BeyazPiyon(setPoz('F',2));beyazTaslar[13]=beyazPiyon6;
    BeyazPiyon *beyazPiyon7 =new BeyazPiyon(setPoz('G',2));beyazTaslar[14]=beyazPiyon7;
    BeyazPiyon *beyazPiyon8 =new BeyazPiyon(setPoz('H',2));beyazTaslar[15]=beyazPiyon8;

    /* Siyah Taşlar */

    Kale  *siyahKale1 =new Kale(setPoz('A',8));siyahTaslar[0]=siyahKale1;
    Kale  *siyahKale2 =new Kale(setPoz('H',8));siyahTaslar[1]=siyahKale2;
    At    *siyahAt1 =new At(setPoz('B',8));siyahTaslar[2]=siyahAt1;
    At    *siyahAt2 =new At(setPoz('G',8));siyahTaslar[3]=siyahAt2;
    Fil   *siyahFil1 =new Fil(setPoz('C',8));siyahTaslar[4]=siyahFil1;
    Fil   *siyahFil2 =new Fil(setPoz('F',8));siyahTaslar[5]=siyahFil2;
    Vezir *siyahVezir =new Vezir(setPoz('D',8));siyahTaslar[6]=siyahVezir;
    Sah   *siyahSah =new Sah(setPoz('E',8));siyahTaslar[7]=siyahSah;
    SiyahPiyon *siyahPiyon1 =new SiyahPiyon(setPoz('A',7));siyahTaslar[8]=siyahPiyon1;
    SiyahPiyon *siyahPiyon2 =new SiyahPiyon(setPoz('B',7));siyahTaslar[9]=siyahPiyon2;
    SiyahPiyon *siyahPiyon3 =new SiyahPiyon(setPoz('C',7));siyahTaslar[10]=siyahPiyon3;
    SiyahPiyon *siyahPiyon4 =new SiyahPiyon(setPoz('D',7));siyahTaslar[11]=siyahPiyon4;
    SiyahPiyon *siyahPiyon5 =new SiyahPiyon(setPoz('E',7));siyahTaslar[12]=siyahPiyon5;
    SiyahPiyon *siyahPiyon6 =new SiyahPiyon(setPoz('F',7));siyahTaslar[13]=siyahPiyon6;
    SiyahPiyon *siyahPiyon7 =new SiyahPiyon(setPoz('G',7));siyahTaslar[14]=siyahPiyon7;
    SiyahPiyon *siyahPiyon8 =new SiyahPiyon(setPoz('H',7));siyahTaslar[15]=siyahPiyon8;


    beyazPiyon4->printPiece();
    movePiece(beyazPiyon4,setPoz('D',3),beyazTaslar,siyahTaslar,'P');
    beyazPiyon4->printPiece();

    cout<< "***********************"<<endl<<endl;

    siyahPiyon4->printPiece();
    movePiece(siyahPiyon4,setPoz('D',6),siyahTaslar,beyazTaslar,'p');
    siyahPiyon4->printPiece();
    cout<< "***********************"<<endl<<endl;

    beyazFil1->printPiece();
    movePiece(beyazFil1,setPoz('E',3),beyazTaslar,siyahTaslar,'F');
    beyazFil1->printPiece();
    cout<< "***********************"<<endl<<endl;

    siyahAt1->printPiece();
    movePiece(siyahAt1,setPoz('D',7),siyahTaslar,beyazTaslar,'A');
    siyahAt1->printPiece();
    cout<< "***********************"<<endl<<endl;

    beyazVezir->printPiece();
    movePiece(beyazVezir,setPoz('D',2),beyazTaslar,siyahTaslar,'V');
    beyazVezir->printPiece();

    siyahAt1->printPiece();
    movePiece(siyahAt1,setPoz('C',7),siyahTaslar,beyazTaslar,'A');
    siyahAt1->printPiece();
    cout<< "***********************"<<endl<<endl;

     beyazVezir->printPiece();
    movePiece(beyazVezir,setPoz('H',6),beyazTaslar,siyahTaslar,'V');
    beyazVezir->printPiece();

     siyahAt1->printPiece();
    movePiece(siyahAt1,setPoz('B',5),siyahTaslar,beyazTaslar,'A');
    siyahAt1->printPiece();
    cout<< "***********************"<<endl<<endl;
     beyazVezir->printPiece();
    movePiece(beyazVezir,setPoz('F',8),beyazTaslar,siyahTaslar,'V');
    beyazVezir->printPiece();
    cout<< "***********************"<<endl<<endl;
     siyahFil2->printPiece();
    movePiece(siyahFil2,setPoz('F',8),siyahTaslar,beyazTaslar,'F');
    siyahFil2->printPiece();


}

int main(void)
{

oyunStart();
/*
    void gameStart()
    {
        cout<<"* * * * * * *  Oyun Basliyor * * * * * * * "<<endl;
        cout<<"Ilk hamle beyaz tasin"<<endl;
        int i;
        string tas;

        for(i=0; i<5; i++)
        {
            cout<<"Oynamak istediginiz tasi secin: "<<endl;
    cin>>tas;Tas::pos(pa);
        }
    };
*/
    return 0;
}
