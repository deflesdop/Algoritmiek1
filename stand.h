// Definitie van klasse Stand.

#ifndef StandHVar  // om te voorkomen dat dit .h bestand meerdere keren
#define StandHVar  // wordt ge-include 

const int Mmax = 20;
const int Nmax = 20;

class Stand
{ public:
    // default constructor, misschien niet zo hard nodig
    // voor deze opdracht...
    Stand ();

    // constructor voor een bord met waardeM rijen en waardeN kolommen
    Stand (int waardeM, int waardeN);

    // destructor
    ~Stand ();

    // Geef waarde van m.
    int getM ();
    // Geef waarde van n.
    int getN ();
    
    int getZetnr();
    
    void setZetnr(int nr);

    // Druk bord af op het scherm.
    void drukaf ();

    // Leg indien mogelijk steen `steennr' op het bord, in een bounding box
    // met linker boven vakje (rij, kolom).
    // Retourneer:
    //   - true, als het lukt om de steen neer te leggen
    //   - false, als het niet lukt om de steen neer te leggen
    
    bool legsteenneer (int rij, int kolom, int steennr);

    // Controleer of huidige stand een eindstand is.
    // Retourneer:
    // - true, als het een eindstand is, dat wil zeggen als er geen zet
    //     meer mogelijk is
    // - false, als het geen eindstand is
    bool eindstand ();

    // Doe zo mogelijk een random zet.
    void doerandomzet ();

    // Bepaal een winnende zet voor de speler die aan de beurt is.
    // Retourneer:
    //   - true, als er een winnende zet bestaat.
    //     In dat geval beschrijft (wrij, wkolom, wsteennr) die zet.
    //   - false, als er geen winnende zet bestaat.
    // Post: aantal is opgehoogd met het aantal standen dat is bekeken
    // voor deze aanroep.
    bool winnend (int &aantal, int &wrij, int &wkolom, int &wsteennr);

    // Bepaal een goede zet voor de speler die aan de beurt is.
    // Zo mogelijk een winnende zet, maar anders een `zo goed mogelijke zet',
    // een zet waarbij een random tegenspeler de grootste kans heeft om
    // een verkeerde zet te kiezen.
    // Retourneer:
    //   - true, als er uberhaupt nog een zet mogelijk is
    //     In dat geval beschrijft (grij, gkolom, gsteennr) een zo goed
    //     mogelijke zet.
    //   - false, als er geen zet meer mogelijk is, d.w.z. als
    //     de huidige stand een eindstand is.
    bool goedezet (int &grij, int &gkolom, int &gsteennr);

  private:
    int m, n, zetnr,    // aantal rijen/kolommen van het bord
        bord[Mmax][Nmax];

    void init_board ();

    bool steenmogelijk(int rij, int kolom, int steennr);
    
    int aantalmogelijkeZetten(int temp[][3]);
    
    void incZetnr();

  // TODO: uw eigen methodes en velden

};

#endif

