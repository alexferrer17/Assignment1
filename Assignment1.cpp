#include <iostream>
#include <fstream>
#include <math.h>
#include <cmath>
using namespace std;

double randNum()
{
  double temp = (double)rand() / (RAND_MAX) - 1;
  return temp;
}

double GaussianDistribution () {
  double temp1 = sqrt(2 * exp( 1.0 / randNum()));
  double temp2 = cos ( 2 * 3.14 * randNum() );
  return temp1 * temp2;
}

double Generator(double mean, double standardeviation) {
  return standardeviation * GaussianDistribution() + mean;
}


  //reitirate through a string to find bigrams
int main(int argc, char const *argv[]) {
  ofstream myfile;
  string dnaLine;
  string dna, result;
  int A, C, T, G, AA, AC, AT, CA, CC, CT, CG, TA, TC, TT, TG, GA, GC, GT, GG; // keep track of each bigram to calculate the probability
  float probA, probC, probT, probG, probAA, probAC, probAT, probCA, probCC, probCT, probCG, probTA, probTC, probTT, probTG, probGA, probGC, probGT, probGG;
  float sum = 0, mean = 0, varience = 0, standardeviation = 0, variance = 0 ; // adds all the lengts of the different lines.
  int nlines = 0;


  cout << "Insert the name of a file" << '\n';
  cin >> nameFileout;

  while (getline(nameFileout, dnaLine)){ // getline is a standar library that gets an a line as an imput and adds it to a string. NOTE:nameFileout is for the file.
    dna.length() += sum;  // adds to the sum the whole length of a line
    dna.length() += mean;
    nlines += 1;
    int total = 0;
    int totBigram = 0;

    //for loop that reitirates throughout the string to check if its the beggining of a bigram
    for (int a = 0; a < dnaLine.length() ; a++ ) {
        //this adds a count to later on calculate each probability of bigrams.
      if( a == "A") {
        A += dna[a];
        total++;
      }

      else if (a == "C") {
        C += dna[a];
        total++;
      }

      else if (a == "T") {
        T += dna[a];
        total++;
      }

      else if (a == "G") {
        G += dna[a];
        total++;
      }
  /* This if statements are to find the different bigrams
  */
       if ( dna[a] && dna[a+1] == "AA") {
        AA += 1;
        totBigram++;     }

      else if (  dna[a] && dna[a+1] == "AC") {
        AC += 1;
        totBigram++;
      }


      else if (  dna[a] && dna[a+1] == "AT" ) {
        AT += 1;
        totBigram++;
      }

      else if ( dna[a] && dna[a+1] == "AG" ) {
        AG += 1;
        totBigram++;
      }

      else if ( dna[a] && dna[a+1] == "CA" ) {
        CA += 1;
        totBigram++;
      }
      else if ( dna[a] && dna[a+1] == "CC") {
        CC += 1;
        totBigram++;
      }

      else if ( dna[a] && dna[a+1] == "CT") {
        CT += 1;
        totBigram++;
      }

      else  if (  dna[a] && dna[a+1] == "CG") {
        CG += 1;
        totBigram++;
      }

      else if ( dna[a] && dna[a+1] == "TA") {
        TA += 1;
        totBigram++;
      }

      else if ( dna[a] && dna[a+1] == "TC") {
        TC += 1;
        totBigram++;
      }

      else if ( dna[a] && dna[a+1] == "TT") {
        TT += 1;
        totBigram++;
      }

      else if ( dna[a] + dna[a+1] == "TG") {
        totBigram++;
        TG += 1;
      }

      else if ( dna[a] + dna[a+1] == "GA") {
        GA += 1;
        totBigram++;
      }

      else if ( dna[a] + dna[a+1] == "GC") {
        GC += 1;
        totBigram++;
      }

      else if ( dna[a] + dna[a+1] == "GT") {
        GT += 1;
        totBigram++;
      }

      else if ( dna[a] + dna[a+1] == "GG") {
        GG += 1;
        totBigram++;
      }

    } // end of for loop

    } // end of while loop



  //probability of each letter to appear as well as each bigram

  probA = A / total * 1.0;
  probC = C / total * 1.0;
  probT = T / total * 1.0;
  probG = G / total * 1.0;

  probAA = AA / totBigram * 1.0;
  probAC = AC / totBigram * 1.0;
  probAG = AG / totBigram * 1.0;
  probAT = AT / totBigram * 1.0;

  probCA = CA / totBigram * 1.0;
  probCC = CC / totBigram * 1.0;
  probCT = CT / totBigram * 1.0;

  probCG = CG / totBigram * 1.0;
  probTA = TA / totBigram * 1.0;
  probTC = TC / totBigram * 1.0;
  probTT = TT / totBigram * 1.0;

  probTG = TG / totBigram * 1.0;
  probGA = GA / totBigram * 1.0;
  probGC = GC / totBigram * 1.0;
  probGT = GT / totBigram * 1.0;
  probGG = GG / totBigram * 1.0;
  // Clear file and start from the beggining to find the

  while (getline(nameFileout, dnaLine))
  {
    variance = (dnaLine.length() - mean) * (dnaLine.lenth() - mean);
  }

  mean = mean / nlines;
  variance = variance / nlines;
  standardeviation = sqrt(variance);

  myfile.open ("Alejandro.out");
  myfile << "Alejandro Ferrer-Peasley" << '\n';
  myfile << "2289045" << '\n';
  myfile << "The mean is = " << mean << '\n';
  myfile << "the sum is = " << sum << '\n';
  myfile << "the varience is = " << variance << '\n';
  myfile << "the standar deviation is = " << standardeviation << '\n';

  myfile << "The relative probability for A =" << probA << '\n';
  myfile << "The relative probability for C =" << probC << '\n';
  myfile << "The relative probability for G =" << probG << '\n';
  myfile << "The relative probability for T =" << probT << '\n';

  myfile << "The relative probability for AA =" << probAA << '\n';
  myfile << "The relative probability for AC =" << probAC << '\n';
  myfile << "The relative probability for AT =" << probAT << '\n';
  myfile << "The relative probability for AG =" << probAG << '\n';

  myfile << "The relative probability for CA =" << probCA << '\n';
  myfile << "The relative probability for CC =" << probCC << '\n';
  myfile << "The relative probability for CT =" << probCT << '\n';
  myfile << "The relative probability for CG =" << probCG << '\n';

  myfile << "The relative probability for TA =" << probTA << '\n';
  myfile << "The relative probability for TC =" << probTC << '\n';
  myfile << "The relative probability for TT =" << probTT << '\n';
  myfile << "The relative probability for TG =" << probTG << '\n';

  myfile << "The relative probability for GA =" << probGA << '\n';
  myfile << "The relative probability for GC =" << probGC << '\n';
  myfile << "The relative probability for GT =" << probGT << '\n';
  myfile << "The relative probability for GG =" << probGG << '\n';





//for loop that prints the DNA strings.
  for ( int i = 0; i < 1000; i++ ) {
    int temp = (int) value(mean, standardeviation);
    for ( int j = 0; j < temp; j++) {

      double random = double randNum() / RAND_MAX;
      std::cout << "A" <<;
      if ( random < probA) {
      }
      else if ( random < probC) {
        myfile << "C" <<;
      }
      else if ( random < probG) {
        myfile << "G" <<;
      }
      else if ( random < probT) {
        myfile << "T" <<;
      }
    }
  }

  return 0;
} // end of main()
