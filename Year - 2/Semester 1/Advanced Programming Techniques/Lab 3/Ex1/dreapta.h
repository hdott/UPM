#pragma once


class Dreapta{
    private:
        double m,
                n;
    
    public:
        Dreapta(double m=1, double n=0): m(m), n(n){};
        Dreapta(const Dreapta&);
        // ~Dreapta();

        friend class Punct;
};