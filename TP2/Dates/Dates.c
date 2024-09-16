enum Mois {
    Janvier;
    Fevrier;
    Mars;
    Avril;
    Mai;
    Juin;
    Juillet;
    Aout;
    Septembre;
    Octobre;
    Novembre;
    Décembre;
};
struct Date
{
    int jours;
    enum Mois;
    
};
 

int main (){
    Date d;
    initialiseDate(&d); //Pourquoi a t-on ajouté un &?
    afficheDate(&d);
} 