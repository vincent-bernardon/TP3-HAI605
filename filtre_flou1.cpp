

#include <stdio.h>
#include "image_ppm.h"

int main(int argc, char* argv[])
{
  char cNomImgLue[250], cNomImgEcrite[250];
  int nH, nW, nTaille;
  
  if (argc != 3) 
     {
       printf("Usage: ImageIn.pgm ImageOut.pgm\n"); 
       exit (1) ;
     }
   
   sscanf (argv[1],"%s",cNomImgLue) ;
   sscanf (argv[2],"%s",cNomImgEcrite);



   OCTET *ImgIn, *ImgOut; //tableau d'octect contenant les couleurs de chaque pixel
   
   lire_nb_lignes_colonnes_image_pgm(cNomImgLue, &nH, &nW);
   nTaille = nH * nW;
  
   allocation_tableau(ImgIn, OCTET, nTaille); //calcul qui permet de représenter les différents pixel de l'img dans un tableau ID
   lire_image_pgm(cNomImgLue, ImgIn, nH * nW);
   allocation_tableau(ImgOut, OCTET, nTaille);

int count,gauche,haut,bas,droite,centre;


 for (int i=0; i < nH; i++) //hauteur donc ligne
    {
   for (int j=0; j < nW; j++) //largeur donc colone
     {
        centre=ImgIn[i*nW+j];
        count=1;
        gauche=0;
        haut=0;
        bas=0;
        droite=0;
        for(int col=-1; col<=1;col++){
            if(col==-1 && j!=0){
                gauche=ImgIn[i*nW+(j-1)];
                count++;
            }else if(col==1 && j!=nW-1){
                droite=ImgIn[i*nW+(j+1)];
                count++;
            }else{
                if(i!=0){
                    haut=ImgIn[(i-1)*nW+j];
                    count++;
                }else if(i!=nH-1){
                    bas=ImgIn[(i+1)*nW+j];
                    count++;
                }
            }
        }
        ImgOut[i*nW+j]=((centre+haut+bas+gauche+droite)/count);
/*
        if ((i) >= 1 && (i) < (nH-1) && (j) >= 1 && (j) < (nW-1)) { // si on est dans notre borne
            ImgOut[i*nW+j]= ((ImgIn[i*nW+j]+
            ImgIn[(i-1)*nW+j]+
            ImgIn[(i+1)*nW+j]+
            ImgIn[i*nW+(j-1)]+
            ImgIn[i*nW+(j+1)])
            /5);
        }else if(i==0 && j==0){
            ImgOut[i*nW+j]= ((ImgIn[i*nW+j]+
            ImgIn[(i+1)*nW+j]+
            ImgIn[i*nW+(j+1)])
            /3);
        }else if(i==0 && j==nW-1){
            ImgOut[i*nW+j]= ((ImgIn[i*nW+j]+
            ImgIn[(i+1)*nW+j]+
            ImgIn[i*nW+(j-1)])
            /3);
        }else if(j==0 && i==nH-1){
            ImgOut[i*nW+j]= ((ImgIn[i*nW+j]+
            ImgIn[(i-1)*nW+j]+
            ImgIn[i*nW+(j+1)])
            /3);
        }else if(j==nW-1 && i==nH-1){
            ImgOut[i*nW+j]= ((ImgIn[i*nW+j]+
            ImgIn[(i-1)*nW+j]+
            ImgIn[i*nW+(j-1)])
            /3);
        }else if(i==nH-1){
            ImgOut[i*nW+j]= ((ImgIn[i*nW+j]+
            ImgIn[(i-1)*nW+j]+
            ImgIn[i*nW+(j-1)]+
            ImgIn[i*nW+(j+1)])
            /4);
        }else if(j==0){
            ImgOut[i*nW+j]= ((ImgIn[i*nW+j]+
            ImgIn[(i-1)*nW+j]+
            ImgIn[(i+1)*nW+j]+
            ImgIn[i*nW+(j+1)])
            /4);
        }else if(j==nW-1){
            ImgOut[i*nW+j]= ((ImgIn[i*nW+j]+
            ImgIn[(i-1)*nW+j]+
            ImgIn[(i+1)*nW+j]+
            ImgIn[i*nW+(j-1)])
            /4);
        }else if(i==0){
            ImgOut[i*nW+j]= ((ImgIn[i*nW+j]+
            ImgIn[(i+1)*nW+j]+
            ImgIn[i*nW+(j-1)]+
            ImgIn[i*nW+(j+1)])
            /4);
        }else{
            printf("artug alarm!!!\n");
        }*/
     }
    }
   ecrire_image_pgm(cNomImgEcrite, ImgOut,  nH, nW);
   free(ImgIn); free(ImgOut);

   return 1;
}


