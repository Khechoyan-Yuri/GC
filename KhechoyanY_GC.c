/*This program will generate a program that reads in DNA sequences
from a file and determines the content of A, T, C, and G in the sequence.

Created: 11-26-2015

Yuri Khechoyan
*/

#include <stdio.h>

int seq, i;
void printToFile(int seq, float content[seq][4], float avgGC);
float averageGC(int seq, float content[seq][4]), avgGC, seqGC, total;
char isPathogenic(float avgGC, float seqGC);

int main (void){

//Declaring Variables
int i, j, a, t, c, g, data_in_file;
int readSequence;
char seqChar, A, T, C, G;
char isPathogenic(float avg, float seqGC);
void printToFile(int seq, float content[seq][4], float avgGC);

    //Read file sequences.txt
    FILE *read_DNA = fopen ("sequences.txt", "r");
    fscanf(read_DNA, "%d", &data_in_file);


        ////Creating Array that will be used
        float content[data_in_file][4];


        //Read in the Characters
        fscanf(read_DNA, "%c", &seqChar);

        //Have the program store each line of the sequences in its own array
        for(i = 0; i < data_in_file; i++){

                a= 0;
                t= 0;
                c= 0;
                g= 0;
            fscanf(read_DNA, "%c", &seqChar);

       while(seqChar!='\n'){

           switch (seqChar){
                case 'A':
                    a++;
                    break;
                case 'T':
                    t++;
                    break;
                case 'C':
                    c++;
                    break;
                case 'G':
                    g++;
                    break;

            }

            fscanf(read_DNA, "%c", &seqChar);
         }


    //Calculating the Percentages for A, T, C, G
    content[i][0]=((A/(A+T+C+G))*100);
    content[i][1]=((T/(A+T+C+G))*100);
    content[i][2]=((C/(A+T+C+G))*100);
    content[i][3]=((G/(A+T+C+G))*100);
    }
            //Turning averageGC into a variable "total"
        float total = averageGC(data_in_file, content);

        //Printing the information to the display
        printToFile(data_in_file, content, total);
}

//Defining the averageGC Function
            float averageGC(int seq, float content[seq][4]){
        int i;
        float avgGC;
        for(i=0; i<seq; i++){
            avgGC=(content[i][2]+content[i][3])/(float)seq;
            }
        return avgGC;
        }

//Defining the isPathogenic Function
        float avgGC, seqGC;
        char isPathogenic(float avg, float seqGC){

        if(avgGC > seqGC){
            printf("Y");
        }
        else{
            printf("N");
        }
        return seqGC;
    }


//Defining the printToFile
void printToFile(int seq, float content[seq][4], float avgGC){
    FILE *write_DNA = fopen ("Answers.txt", "w");
fprintf(write_DNA, "%%A \t %%T \t %%C \t %%GC \t Pathologic?", content, total);
fclose (write_DNA);

}
