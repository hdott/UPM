
class Fractie{
    private:
        int numitor,
            numarator;
    public:
        Fractie(int numarator=0, int numitor=1);
        Fractie(int numarator, int numitor=1);
        Fractie(const Fractie&);
        ~Fractie();

        virtual Fractie aduna(Fractie);
        virtual Fractie scadere(Fractie);
        virtual Fractie inmultire(Fractie);
        virtual Fractie impartire(Fractie);
        static int cmmdc(Fractie);
        virtual Fractie simplifica();
        virtual Fractie reciproc();
        virtual bool egal(const Fractie&);
        virtual void print();
};