#include <iostream>
#include <fstream>
#include <math.h>
#include <cmath>
#include <cmath>
using namespace std;
//method that randomizes for GaussianDistribution
double randomNumber()
{
  double temp = (double)rand() / (RAND_MAX) - 1;
  return temp;
}
//method for GaussianDistribution when printed out in a file 
double GaussianDistribution () {
  double temp1 = sqrt(2 * exp( 1.0 / randomNumber()));
  double temp2 = cos ( 2 * 3.14 * randomNumber() );
  return temp1 * temp2;
}

double Value(double mean, double standardeviation) {
  return standardeviation * GaussianDistribution() + mean;
}



int main(int argc, char const *argv[]) {

//variable names
  ofstream myfile;
  string dnaLine;
  float A = 0, C = 0, T = 0, G = 0, AA = 0, AC = 0, AT = 0, AG = 0, CA = 0, CC = 0, CT = 0, CG = 0, TA = 0, TC = 0, TT = 0, TG = 0, GA = 0, GC = 0, GT = 0, GG = 0; // keep track of each bigram to calculate the probability
  float probA, probC, probT, probG, probAA, probAC, probAT, probAG, probCA, probCC, probCT, probCG, probTA, probTC, probTT, probTG, probGA, probGC, probGT, probGG;
  float sum = 0, mean = 0, varience = 0, standardeviation = 0, variance = 0 ; // adds all the lengts of the different lines.
  int nlines = 0;
  int total = 0;
  int totBigram = 0;
  string nameFileout;


  if (argc > 1) {
      nameFileout = argv[1];
  }

  fstream file (nameFileout);

  while (getline(file, dnaLine)){ // Loop that goes through the file for the first time
    sum += dnaLine.length();  // adds to the sum the whole length of a line
    mean += dnaLine.length();
    nlines += 1;


    //for loop that reitirates throughout the string to check if its the beggining of a bigram
    for (int a = 0; a < dnaLine.length() ; a++ ) {
        //this adds a count to later on calculate each probability of bigrams.
      if( dnaLine[a] == 'A') {
        A += 1;
        total++;
      }

      else if (dnaLine[a] == 'C') {
        C += 1;
        total++;
      }

      else if (dnaLine[a] == 'T') {
        T += 1;
        total++;
      }

      else if (dnaLine[a] == 'G') {
        G += 1;
        total++;
      }
  /* This if statements are to find the different bigrams
  */
       if ( dnaLine[a] == 'A' && dnaLine[a+1] == 'A') {
        AA += 1;
        totBigram++;     }

      else if (  dnaLine[a] == 'A' && dnaLine[a+1] == 'C') {
        AC += 1;
        totBigram++;
      }


      else if (  dnaLine[a] == 'A' && dnaLine[a+1] == 'T' ) {
        AT += 1;
        totBigram++;
      }

      else if ( dnaLine[a] == 'A' && dnaLine[a+1] == 'G' ) {
        AG += 1;
        totBigram++;
      }

      else if ( dnaLine[a] == 'C' && dnaLine[a+1] == 'A' ) {
        CA += 1;
        totBigram++;
      }
      else if ( dnaLine[a] == 'C' && dnaLine[a+1] == 'C') {
        CC += 1;
        totBigram++;
      }

      else if ( dnaLine[a] == 'C' && dnaLine[a+1] == 'T') {
        CT += 1;
        totBigram++;
      }

      else  if (  dnaLine[a] == 'C' && dnaLine[a+1] == 'G') {
        CG += 1;
        totBigram++;
      }

      else if ( dnaLine[a] == 'T' && dnaLine[a+1] == 'A') {
        TA += 1;
        totBigram++;
      }

      else if ( dnaLine[a] == 'T' && dnaLine[a+1] == 'C') {
        TC += 1;
        totBigram++;
      }

      else if ( dnaLine[a] == 'T' && dnaLine[a+1] == 'T') {
        TT += 1;
        totBigram++;
      }

      else if ( dnaLine[a]== 'T' && dnaLine[a+1] == 'G') {
        totBigram++;
        TG += 1;
      }

      else if ( dnaLine[a]== 'G' && dnaLine[a+1] == 'A') {
        GA += 1;
        totBigram++;
      }

      else if ( dnaLine[a] == 'G' && dnaLine[a+1] == 'C') {
        GC += 1;
        totBigram++;
      }

      else if ( dnaLine[a] == 'G' && dnaLine[a+1] == 'T') {
        GT += 1;
        totBigram++;
      }

      else if ( dnaLine[a] == 'G' && dnaLine[a+1] == 'G') {
        GG += 1;
        totBigram++;
      }

    }

    }



  //probability of each letter to appear as well as each bigram

  probA = A * 1.0 / total * 100.0;
  probC = C * 1.0 / total * 100.0;
  probT = T * 1.0 / total * 100.0;
  probG = G * 1.0 / total * 100.0;

  probAA = AA * 1.0 / totBigram * 100.0;
  probAC = AC * 1.0 / totBigram * 100.0;
  probAG = AG * 1.0 / totBigram * 100.0;
  probAT = AT * 1.0 / totBigram * 100.0;

  probCA = CA * 1.0 / totBigram * 100.0;
  probCC = CC * 1.0 / totBigram * 100.0;
  probCT = CT * 1.0 / totBigram * 100.0;
  probCG = CG * 1.0 / totBigram * 100.0;

  probTA = TA * 1.0 / totBigram * 100.0;
  probTC = TC * 1.0 / totBigram * 100.0;
  probTT = TT * 1.0 / totBigram * 100.0;
  probTG = TG * 1.0 / totBigram * 100.0;

  probGA = GA * 1.0 / totBigram * 100.0;
  probGC = GC * 1.0 / totBigram * 100.0;
  probGT = GT * 1.0 / totBigram * 100.0;
  probGG = GG * 1.0 / totBigram * 100.0;
  // Clear file and start from the beggining to find the top again.

  file.clear();
  file.seekg(0, file.beg);
  mean = mean / nlines;
  while (getline(file, dnaLine))
  {
    variance = (dnaLine.length() - mean) * (dnaLine.length() - mean);
  }
  // variance and standardeviation equation
  variance = variance / nlines;
  standardeviation = sqrt(variance);

  //creating file that prints out
  myfile.open ("Alejandro.out");
  myfile << "Alejandro Ferrer-Peasley" << '\n';
  myfile << "2289045" << '\n';
  myfile << "The mean is = " << mean << '\n';
  myfile << "the sum is = " << sum << '\n';
  myfile << "the varience is = " << variance << '\n';
  myfile << "the standar deviation is = " << standardeviation << '\n';

  myfile << "The relative probability for A =" << probA <<  "%" << '\n';
  myfile << "The relative probability for C =" << probC <<  "%" << '\n';
  myfile << "The relative probability for G =" << probG <<  "%" << '\n';
  myfile << "The relative probability for T =" << probT <<  "%" << '\n';

  myfile << "The relative probability for AA =" << probAA <<  "%" << '\n';
  myfile << "The relative probability for AC =" << probAC <<  "%" << '\n';
  myfile << "The relative probability for AT =" << probAT <<  "%" << '\n';
  myfile << "The relative probability for AG =" << probAG <<  "%" << '\n';

  myfile << "The relative probability for CA =" << probCA <<  "%" << '\n';
  myfile << "The relative probability for CC =" << probCC <<  "%" << '\n';
  myfile << "The relative probability for CT =" << probCT <<  "%" << '\n';
  myfile << "The relative probability for CG =" << probCG <<  "%" << '\n';

  myfile << "The relative probability for TA =" << probTA <<  "%" << '\n';
  myfile << "The relative probability for TC =" << probTC <<  "%" << '\n';
  myfile << "The relative probability for TT =" << probTT << "%" <<  '\n';
  myfile << "The relative probability for TG =" << probTG <<  "%" << '\n';

  myfile << "The relative probability for GA =" << probGA <<  "%" << '\n';
  myfile << "The relative probability for GC =" << probGC <<  "%" << '\n';
  myfile << "The relative probability for GT =" << probGT << "%" <<  '\n';
  myfile << "The relative probability for GG =" << probGG << "%" << '\n';





//for loop that prints the DNA strings.

probC += probA;
probG += probC;
  for ( int i = 0; i < 1000; i++ ) {
    int temp = (int) Value(mean, standardeviation);
    for ( int j = 0; j < temp; j++) {

      int random = rand() % 100;

      if ( random < probA) {
        myfile << "A";
      }
      else if ( random < probC) {
        myfile << "C" ;
      }
      else if ( random < probG) {
        myfile << "G";
      }
      else  {
        myfile << "T";
      }
    }
     myfile << endl;
  }

  myfile.close();

  return 0;

} // end of main()
