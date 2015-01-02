#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <locale>
#include <sstream>
#include <string> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TCanvas.h"
#include "TGraph.h"
#include "TAxis.h"
#include "TMultiGraph.h"
#include "TGraphErrors.h"

#include "TH2.h"
using namespace std;



int Histogram(){
 
TCanvas *c1 = new TCanvas("c1","A Simple Graph Example",200,10,700,500);
 TH2D *h1 = new TH2D("h1","Pixel Test", 8,1,9,3,0,3 );
 
  double rate[8][3]={{0,0,0},{3.67,2.31,0},{0,0,0},{1.78,0,1.64},{2.21,1.98,0},{1.39,1.30,1.96},{1.84,1.46,1.94},{1.59,1.51,2.23}};
  
  for(int ii= 1; ii<9; ii++){
    for(int kk = 0; kk<3; kk++){
      h1 -> Fill(ii, kk,rate[ii-1][kk] );
    }
  }
    h1->Draw("LEGO2");
    h1->GetXaxis()->SetTitle("Row Number");
    h1->GetYaxis()->SetTitle("Column Number");
    h1->GetZaxis()->SetTitle("Event Rate (HZ)");
    return 0;

}
