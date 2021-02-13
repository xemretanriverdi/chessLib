#ifndef CHESSLIB_H
#define CHESSLIB_H

struct position {
          char dusey;
          short yatay;
};
struct position setPoz(char ,short );
class Tas {
protected:
          struct position pos;
          struct position* hamle;
public:
          Tas();
          Tas(Tas &t);
          Tas(struct position poz);

          ~Tas();

          struct position* getHamle();
          void setHamle(struct position* h);

          struct position getPos();

          void setPos(struct position );
};
class Vezir: public Tas {

public:
          Vezir(struct position pos);

          void printPiece(void);
};
class Sah: public Tas {
public:
          Sah(struct position pos);

          void printPiece(void);
};
class At: public Tas
{
public:
    At(struct position pos);

    void printPiece(void);
    };
class Fil: public Tas
{

public:
    Fil(struct position pos);

    void printPiece(void);

};
class BeyazPiyon: public Tas
{

public:
    BeyazPiyon(struct position pos);

    void printPiece(void);

};
class SiyahPiyon: public Tas
{

public:
    SiyahPiyon(struct position pos);

    void printPiece(void);

};
class Kale: public Tas
{

public:
    Kale(struct position pos);

    void printPiece(void);

};
void movePiece(Tas *,struct position , Tas **,Tas **,char );
#endif // CHESSLIB_H
