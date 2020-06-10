#ifndef BOUTIQUE_H
#define BOUTIQUE_H


class Boutique
{
    public:
        Boutique();
        virtual ~Boutique();

        vector<Carte*> Gettotalcarte() { return m_totalcarte; }
        void Settotalcarte(vector<Carte*> val) { m_totalcarte = val; }

    protected:

    private:
        vector<Carte*> m_totalcarte;
};

#endif // BOUTIQUE_H
