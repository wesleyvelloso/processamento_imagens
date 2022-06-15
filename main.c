#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// TP processamento de imagens 
// Wesley Velloso Marques - RA: 2016.1.08.023   
// Unifal-MG

int img[1024][1024],mat[1024][1024];

int menu()
{   
    int selecao;
    printf("\n    DIGITE UMA DAS OPCOES ABAIXO:\n"); 
    printf(" --------------------------------------\n");
    printf("|    (1) - Passa Baixa                 |\n");
    printf("|    (2) - Passa Alta                  |\n");
    printf("|    (3) - Sobel                       |\n");
    printf("|    (4) - Prewitt                     |\n");
    printf("|    (5) - Roberts                     |\n");
    printf("|    (6) - Isotrópico                  |\n");
    printf("|    (7) - Sair                        |\n");
    printf(" --------------------------------------\n");
    scanf("%d", &selecao);
        while ((selecao<1)||(selecao>7)) 
        {
            printf("Por favor, digite um numero de 1 a 7: \n");
                scanf("%d",&selecao);
        }
        return(selecao);    
}

void passaBaixa(int linhas, int colunas)
{
 for(int i=0; i<colunas;i++){
    for(int j=0; j<linhas;j++){
        int aux=0,aux2=0;
        float media=0.0;
    
        for(int a=i-1;aux<3;a++){
            for(int b=j-1;aux2<3;b++){   
                media+=img[a][b]; 
                aux2++;
            }
            aux2=0;
            aux++;
        }    
        media=media/9;
        mat[i][j]=round(media);        
    }
 }
}   

void passaAlta(int linhas, int colunas, int tons_cinza)
{
 for(int i=0; i<colunas;i++){
    for(int j=0; j<linhas;j++){
        int aux=0,aux2=0,result=0;
           
        for(int a=i-1;aux<3;a++){
            for(int b=j-1;aux2<3;b++){
                
                if((a==i)&&(b==j))
                    result+=img[a][b]*8; 
                else
                    result+=img[a][b]*(-1); 
                
                aux2++;
            }
            aux2=0;
            aux++;
        }          
        if(result<0) result=0;
        if(result>tons_cinza) result=tons_cinza;
        mat[i][j]=result;        
    }
 }
}    

void prewitt(int linhas, int colunas, int tons_cinza)
{
 for(int i=0; i<colunas;i++){
    for(int j=0; j<linhas;j++){
        int aux=0,aux2=0,gradX=0,gradY=0;
        float result=0.0;
    
        for(int a=i-1;aux<3;a++){
            for(int b=j-1;aux2<3;b++){
                
                if((b==j-1)&&(a!=i)){
                    if(a==i-1){
                        gradX+=img[a][b]*(-1);
                        gradY+=img[a][b]*(-1);           
                    }else{
                        gradX+=img[a][b]*(-1);
                        gradY+=img[a][b];   
                    }    
                }
                if((b==j+1)&&(a!=i)){     
                    if(a==i-1){
                        gradX+=img[a][b];
                        gradY+=img[a][b]*(-1);
                    }else{ 
                        gradX+=img[a][b];
                        gradY+=img[a][b];       
                    }
                }
                if((b==j-1)&&(a==i))
                    gradX+=img[a][b]*(-1);
          
                if((b==j+1)&&(a==i))
                    gradX+=img[a][b];
                        
                if(b==j){
                    if(a==i-1){
                        gradY+=img[a][b]*(-1); 
                    }else if(a==i+1){ 
                        gradY+=img[a][b];
                    }
                }       
            aux2++;
            }
            aux2=0;
            aux++;
        }    
        
        result=round(sqrt(pow(gradX,2)+pow(gradY,2)));
        if(result<0) result=0;
        if(result>tons_cinza) result=tons_cinza;
        mat[i][j]=result;        
    }
 }
}   

void sobel(int linhas, int colunas, int tons_cinza)
{
 for(int i=0; i<colunas;i++){
    for(int j=0; j<linhas;j++){
        int aux=0,aux2=0,gradX=0,gradY=0;
        float result=0.0;
    
        for(int a=i-1;aux<3;a++){
            for(int b=j-1;aux2<3;b++){
                
                if((b==j-1)&&(a!=i)){
                    if(a==i-1){
                        gradX+=img[a][b]*(-1);
                        gradY+=img[a][b]*(-1);           
                    }else{
                        gradX+=img[a][b]*(-1);
                        gradY+=img[a][b];   
                    }    
                }
                if((b==j+1)&&(a!=i)){     
                    if(a==i-1){
                        gradX+=img[a][b];
                        gradY+=img[a][b]*(-1);
                    }else{ 
                        gradX+=img[a][b];
                        gradY+=img[a][b];       
                    }
                }
                if((b==j-1)&&(a==i))
                    gradX+=img[a][b]*(-2);
          
                if((b==j+1)&&(a==i))
                    gradX+=img[a][b]*(2);
                        
                if(b==j){
                    if(a==i-1){
                        gradY+=img[a][b]*(-2); 
                    }else if(a==i+1){ 
                        gradY+=img[a][b]*(2);
                    }
                }       
            aux2++;
            }
            aux2=0;
            aux++;
        }    
        
        result=round(sqrt(pow(gradX,2)+pow(gradY,2)));
        if(result<0) result=0;
        if(result>tons_cinza) result=tons_cinza;
        mat[i][j]=result;        
    }
 }
}   

void isotropico(int linhas, int colunas, int tons_cinza)
{
 for(int i=0; i<colunas;i++){
    for(int j=0; j<linhas;j++){
        int aux=0,aux2=0;
        float result=0.0,gradX=0.0,gradY=0.0;
    
        for(int a=i-1;aux<3;a++){
            for(int b=j-1;aux2<3;b++){
                
                if((b==j-1)&&(a!=i)){
                    if(a==i-1){
                        gradX+=img[a][b]*(-1);
                        gradY+=img[a][b]*(-1);           
                    }else{
                        gradX+=img[a][b];
                        gradY+=img[a][b]*(-1);   
                    }    
                }
                if((b==j+1)&&(a!=i)){     
                    if(a==i-1){
                        gradX+=img[a][b]*(-1);
                        gradY+=img[a][b];
                    }else{ 
                        gradX+=img[a][b];
                        gradY+=img[a][b];       
                    }
                }
                if((b==j-1)&&(a==i))
                    gradY+=img[a][b]*(-sqrt(2));
          
                if((b==j+1)&&(a==i))
                    gradY+=img[a][b]*sqrt(2);
                        
                if(b==j){
                    if(a==i-1){
                        gradX+=img[a][b]*(-sqrt(2)); 
                    }else if(a==i+1){ 
                         gradX+=img[a][b]*sqrt(2); 
                    }
                }       
            aux2++;
            }
            aux2=0;
            aux++;
        }    
        
        result=round(sqrt(pow(gradX,2)+pow(gradY,2)));
        if(result<0) result=0;
        if(result>tons_cinza) result=tons_cinza;
        mat[i][j]=result;        
    }
 }
}    

void roberts(int linhas, int colunas, int tons_cinza)
{
 for(int i=0; i<colunas;i++){
    for(int j=0; j<linhas;j++){
        int aux=0,aux2=0,gradX=0,gradY=0;
        float result=0.0;
    
        for(int a=i-1;aux<3;a++){
            for(int b=j-1;aux2<3;b++){
               
                if((b==j)&&(a==i))    
                    gradX+=img[a][b]*(-1);
                
                if((b==j)&&(a==i+1))    
                    gradY+=img[a][b]*(-1);
          
                if((b==j+1)&&(a==i))
                    gradY+=img[a][b];
          
                if((b==j+1)&&(a==i+1))
                    gradX+=img[a][b];
                                
            aux2++;
            }
            aux2=0;
            aux++;
        }    
        
        result=round(sqrt(pow(gradX,2)+pow(gradY,2)));
        if(result<0) result=0;
        if(result>tons_cinza) result=tons_cinza;
        mat[i][j]=result;        
    }
 }
}    

int main() 
{
    int i,j,linhas,colunas,tons_cinza,selecao=0;
    char tipo[4],comentario[100],nomeimg[50],nome_op[50];
        
    FILE *arq;
        arq = fopen("imagem.pgm","r"); 
        if(arq==NULL){
            printf("Erro de leitura. Verifique se o arquivo 'imagem.pgm' \nse encontra na raiz do programa e esta\nno formato correto.\n");
            return(1);
        }
        fscanf(arq,"%s",&tipo);  
        fscanf(arq," %[^\n]s",&comentario);
        fscanf(arq,"%d",&colunas);
        fscanf(arq,"%d",&linhas);
        fscanf(arq,"%d",&tons_cinza);
                                                       
        for(i=0;i<linhas;i++)
            for(j=0;j<colunas;j++) 
                fscanf(arq,"%d\n",&img[i][j]);
                
        fclose(arq);    
        selecao=menu();
        
        while(selecao!=7)
        {
            switch(selecao) 
            {
                case 1:
                strcpy(nome_op,"Filtro passa Baixa"); 
                passaBaixa(linhas,colunas);   
                break;
                
                case 2:
                strcpy(nome_op,"Filtro passa Alta");
                passaAlta(linhas,colunas,tons_cinza);
                break;
                             
                case 3:
                strcpy(nome_op,"Filtro Sobel");
                sobel(linhas,colunas,tons_cinza); 
                break;
                    
                case 4:
                strcpy(nome_op,"Filtro Prewitt");
                prewitt(linhas,colunas,tons_cinza);
                break;  
                                        
                case 5: 
                strcpy(nome_op,"Filtro Roberts");
                roberts(linhas,colunas,tons_cinza);
               
                break;        
                                                                                
                case 6:
                strcpy(nome_op,"Filtro Isotropico");
                isotropico(linhas,colunas,tons_cinza);
                
                break;
                                                                                                     
            }
            system("clear");
            printf("\nDigite o nome da imagem que deseja salvar:\n");
            scanf(" %s", nomeimg);
            strcat(nomeimg,".pgm");
            arq = fopen(nomeimg,"w"); 
            fprintf(arq,"%s\n",tipo);
            fprintf(arq,"%s\n",comentario);
            fprintf(arq,"%d %d\n",colunas,linhas);
            fprintf(arq,"%d\n",tons_cinza);
	  			
            for (i=0; i<linhas; i++)
            {
                for (j=0; j<colunas; j++) 
                {
	           fprintf(arq,"%d ", mat[i][j]);
	        }
	        fprintf(arq,"\n");
            }	
            fclose (arq);                        
            printf("# %s realizado(a) com sucesso!!! \n\n",nome_op);
            printf("# Nova imagem (%s) gerada no diretorio raiz.\n\n",nomeimg);
            selecao=menu();
        } 
        system("clear");    
}