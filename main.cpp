#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Variables Feuille 1
int altHaute = 0, altBasse = 0, Hchute, Hchute2;
int DebitEau = 0;

float g = 9.81, WchuteEau = 0,Pbrute = 0,Pbrute2 = 0;

int freseau = 50, VitesseOptiTurbine=0;

float nTurbine, nAlternateur, nTransformateur;
float PmecaEntreeAlt, PelecSortieAlt, PelecReseau, EnergieAnnuelle;
float S;
int p;

void waitForValidation() {
    printf("\nAppuyez sur Entrée pour continuer...\n");
    getchar(); // Wait for user to press Enter
    getchar(); // Consume the newline character left by the previous scanf
}

int main()
{
    system("CHCP 1252 > nul");

printf("\n");
printf(" ______   __   __  ____     _______  __    _  _______  ______    _   ___  \n");
printf("|      | |  |_|  ||    |   |       ||  |  | ||       ||    _ |  | | |   | \n");
printf("|  _    ||       | |   |   |    ___||   |_| ||    ___||   | ||  | |_|   | \n");
printf("| | |   ||       | |   |   |   |___ |       ||   |___ |   |_||_ |       | \n");
printf("| |_|   ||       | |   |   |    ___||  _    ||    ___||    __  ||___    | \n");
printf("|       || ||_|| | |   |   |   |___ | | |   ||   |___ |   |  | |    |   | \n");
printf("|______| |_|   |_| |___|   |_______||_|  |__||_______||___|  |_|    |___| \n");
printf("\n");



        printf("\n-----PAGE 1/6-----\n");
        printf("\nVeuillez entrer la valeur de l'altitude haute (m):");
        scanf("%d", &altHaute);
        printf("\nVeuillez entrer la valeur de l'altitude basse (m):");
        scanf("%d", &altBasse);
        printf("\nVeuillez entrer le débit d'eau dans la conduite forcée (litres/s):");
        scanf("%d", &DebitEau);
        printf("\ng : 9.81 m/s^2\n");
        printf("\nVeuillez entrer la fréquence du réseau électrique (Hz):");
        scanf("%d", &freseau);
        printf("\nVeuillez entrer la vitesse optimale de la turbine (tours/mn):");
        scanf("%d", &VitesseOptiTurbine);

        Hchute = altHaute-altBasse;
        WchuteEau = DebitEau*g*Hchute;
        Pbrute = WchuteEau/1000.0;

        printf("\n1) Hauteur de chute brute = %d m", Hchute);
        printf("\n2) Energie fournie par %d litres d'eau dans la conduite = %.3f joules", DebitEau, WchuteEau);
        printf("\n3) Puissance brute fournier à la turbine avec un debit de %d litres/s = %.2f kW\n", DebitEau, Pbrute);

        printf("\nVeuillez entrer la nouvelle valeur de chute (m):");
        scanf("%d", &Hchute2);

        Pbrute2 = (DebitEau*g*Hchute2)/1000.0;

        printf("\n4) Puissance reelle fournie = %.2f kW", Pbrute2);

        printf("\nVeuillez entrer le rendement turbine :");
        scanf("%f", &nTurbine);
        printf("\nVeuillez entrer le rendement alternateur :");
        scanf("%f", &nAlternateur);
        printf("\nVeuillez entrer le rendement Transformateur :");
        scanf("%f", &nTransformateur);

        PmecaEntreeAlt = Pbrute2*nTurbine;
        PelecSortieAlt = PmecaEntreeAlt*nAlternateur;
        PelecReseau = PelecSortieAlt*nTransformateur;

        printf("\n5) Puissance mécanique à l'entrée de l'alternateur : %.2f kW", PmecaEntreeAlt);
        printf("\n   Puissance électrique fournie par l'alternateur : %.2f kW", PelecSortieAlt);
        printf("\n   Puissance électrique envoyée sur le réseau haute tension : %.2f kW", PelecReseau);

        EnergieAnnuelle = (8760*PelecReseau)/1000;

        printf("\n6) Energie Annuelle = %lg MW.h", EnergieAnnuelle);

        waitForValidation();

        printf("\n\n-----PAGE 2/6-----\n\n");

        int Vprimaire, U;
        float V;
        p = (freseau*60)/VitesseOptiTurbine;

        printf("\n1) nombre de paires de pôles = %d", p);

        printf("\nVeuillez entrer la tension au primaire du transformateur (V):");
        scanf("%d", &Vprimaire);
        V = (float)Vprimaire/sqrt(3);
        U = Vprimaire;

        printf("\n2) V = %.2f V", V);
        printf("\n   U = %d V\n", U);
        printf("\n3) triangle\n");
        printf("\n   Tension aux bornes d'un enroulement: %d V\n", U);
        printf("\n4) étoile\n");
        printf("\n   Tension aux bornes d'un enroulement: = %.2f V\n", V);
        printf("\n5) Les 4 conditions:");
        printf("\n   Ordre successif des phases identique");
        printf("\n   Fréquences identiques");
        printf("\n   Valeurs efficaces de tensions égales");
        printf("\n   Tensions en phase\n");

        waitForValidation();

        printf("\n\n-----PAGE 3/6-----\n\n");

        float I, Omega;
        int Q;

        I = (PelecSortieAlt*1000)/(3.00*V);
        Q = 0;

        printf("\n1) Omega = %d tours/min", VitesseOptiTurbine);
        printf("\n2) I = %.2f A", I);
        printf("\n3) Q = %d kVAR", Q);
        printf("\n4) Signe de la puissance active: négatif");
        printf("\n   Point de fonctionnement alternateur : 2\n");

        waitForValidation();

        printf("\n\n-----PAGE 4/6-----\n\n");

        int Lw;
        float PosA, E, angleInterne;
        PelecSortieAlt = -PelecSortieAlt;

        printf("\nVeuillez entrer la valeur L.w (Ohms):");
        scanf("%d", &Lw);

        PosA = (Lw/(3*V))*PelecSortieAlt*1000;
        E = sqrt(V*V+PosA*PosA);
        angleInterne = (asin(-PosA/E)*180)/M_PI;

        printf("\n1) Position du point A sur l'axe des %%P = %.3f V", PosA);
        printf("\n2) E = %.2f V", E);
        printf("\n3) Tetha = %.2f °", angleInterne);

        waitForValidation();

        printf("\n\n-----PAGE 5/6-----\n\n");

        float P;

        printf("\nVeuillez entrer la nouvelle valeur de la puissance réactive (kVAR):");
        scanf("%d", &Q);

        P = PelecSortieAlt;

        printf("\n1) Puissance active de l'alternateur : %.2f kW", P);
        printf("\n2) Nouveau point de focntionnement de l'alternateur : C");

        waitForValidation();

        printf("\n\n-----PAGE 6/6-----\n\n");

        float cosPhi, PosF;

        S = sqrt((P*P)+(Q*Q));
        I = S*1000/(3*V);
        cosPhi = P/S;
        PosF = (Lw*Q*1000)/(3*V);
        E = sqrt(((V+abs(PosF))*(V+abs(PosF)))+(PosA*PosA));
        angleInterne = acos((V+abs(PosF))/E)*180/M_PI;

        printf("\n1) S = %.2f kVA", S);
        printf("\n2) I = %.2f A", I);
        printf("\n3) cos(Phi) = %.2f", cosPhi);
        printf("\n4) Position du point F sur l'axe des %%Q = %.3f V", PosF);
        printf("\n5) E = %.2f", E);
        printf("\n6) Theta = %.2f °\n\n", angleInterne);



    system("PAUSE");


}
