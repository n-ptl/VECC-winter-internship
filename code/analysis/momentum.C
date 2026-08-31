#include <TFile.h>
#include <TTree.h> 
#include<TBranch.h>
#include <TObject.h>
#include <TCanvas.h>

void momentum() {

// define histograms  

TH1D* Hpx1 = new TH1D("Hpx1","UrQMD Momentum", 400, -3, 3);
TH1D* Hpx2 = new TH1D("Hpx2","SMASH Momentum", 400, -3 , 3);
TH1D* HpT1 = new TH1D("Hpt1","SMASH pT", 400, -0.5, 3);
TH1D* HpT2 = new TH1D("Hpt2","UrQMD pT", 400, -0.5, 3); 
TH1D* Heta1 = new TH1D("Heta1","UrQMD eta", 400, -5, 8); 
TH1D* Heta2 = new TH1D("Heta2","SMASH eta", 400, -5, 8); 
TH1D* Heta101 = new TH1D("Heta101","UrQMD pT", 200, 0.0, 3); 
TH1D* Heta201 = new TH1D("Heta201","SMASH pT", 200, 0.0, 3); 
TH1D* Heta112 = new TH1D("Heta112","UrQMD pT", 200, 0.0, 3); 
TH1D* Heta212 = new TH1D("Heta212","SMASH pT", 200, 0.0, 3); 
TH1D* Heta123 = new TH1D("Heta123","UrQMD pT", 200, 0.0, 3); 
TH1D* Heta223 = new TH1D("Heta223","SMASH pT", 200, 0.0, 3); 
TH1D* Heta134 = new TH1D("Heta134","UrQMD pT", 200, 0.0, 3); 
TH1D* Heta234 = new TH1D("Heta234","SMASH pT", 200, 0.0, 3); 
TH1D* Heta145 = new TH1D("Heta145","UrQMD pT", 200, 0.0, 3); 
TH1D* Heta245 = new TH1D("Heta245","SMASH pT", 200, 0.0, 3); 
TH1D* Heta156 = new TH1D("Heta156","UrQMD pT", 200, 0.0, 3); 
TH1D* Heta256 = new TH1D("Heta256","SMASH pT", 200, 0.0, 3); 
TH1D* Heta167 = new TH1D("Heta167","UrQMD pT", 200, 0.0, 3); 
TH1D* Heta267 = new TH1D("Heta267","SMASH pT", 200, 0.0, 3); 
TH1D* Heta178 = new TH1D("Heta178","UrQMD pT", 200, 0.0, 3); 
TH1D* Heta278 = new TH1D("Heta278","SMASH pT", 200, 0.0, 3); 
TH1D* Hphi1 = new TH1D("Hphi1","UrQMD phi", 400, -4, 4); 
TH1D* Hphi2 = new TH1D("Hphi2","SMASH phi", 400, -4, 4);
TH1D* Hmcount1 = new TH1D("mcount1","UrQMD muon", 400, -2, 2);
TH1D* Hmcount2 = new TH1D("mcount2","SMASH muon", 400, -2, 2);
TH1D* Hpioncount1 = new TH1D("pioncount1","UrQMD pion", 400, 0, 200);
TH1D* Hpioncount2 = new TH1D("pioncount2","SMASH pion", 400, 0, 200);

// create root file to save the histograms
TFile *fOut = new TFile("Analysis.root", "RECREATE");

// open urqmd file 
  TFile *input_file1 = TFile::Open("urqmd.auau.10gev.centr.root");
  if (input_file1->IsOpen()) {
    printf("Successfully opened file %s\n", input_file1->GetName());
  } else {
    printf("Error at opening file %s\n", input_file1->GetName());
  }
  
// open smash file
   TFile *input_file2 = TFile::Open("Particles.root");
  if (input_file2->IsOpen()) {
    printf("Successfully opened file %s\n", input_file2->GetName());
  } else {
    printf("Error at opening file %s\n", input_file2->GetName());
  }
  
// read the tree from urqmd file  
 TTree *tree1 = (TTree*) input_file1->Get("events");
  
 TBranch *branch_event = tree1->GetBranch("event");
 
  Int_t y = 100000;
  Int_t    npart1;
  Int_t pdg1[y];;
  Double_t px1[y], py1[y], pz1[y];
  Int_t ecount1=0;
  Int_t pcount1=0;
  Int_t mcount1=0;
  Int_t pioncount1=0, rcount1=0, antimuonc1=0, wcount1=0, kaonc1=0, protonc1=0, electronc1=0, neutronc1=0;
  Double_t b_cm;
  Double_t g_cm, m;
  

tree1->SetBranchAddress("fParticles.fPx", px1);
tree1->SetBranchAddress("fParticles.fPy", py1);
tree1->SetBranchAddress("fParticles.fPz", pz1);
tree1->SetBranchAddress("fParticles.fPdg", pdg1);

  TLeaf *leafPx = tree1->GetLeaf("fParticles.fPx");

  Long64_t n1 = tree1->GetEntries();
  for (Long64_t i = 0; i < n1; ++i) {
    tree1->GetEntry(i);

  Int_t pioncount1=0;
cout<<n1<<endl;
    Int_t npart1 = leafPx->GetLen();
    for (Int_t j = 0; j < npart1; ++j) {
    
    int pdg = pdg1[j];
    
      //Hpx1->Fill(px1[j]);                
                        
      if (pdg1[j] == 221 ) {
      ecount1++;
      m=0.54786;
      }
      if (pdg1[j] == 13 ){ 
      mcount1++;
      m=0.105658;
      }
      if (pdg1[j] == 333 ){
      m=1.019;			
      pcount1++;
      }
      if (pdg1[j] == 211 ) pioncount1++;
      Hpioncount1->Fill(pioncount1); 
      if (pdg1[j] == 223) wcount1++;            
      if (pdg1[j] == 113) rcount1++;                   
      if (pdg1[j] == -13) antimuonc1++;
      if (pdg1[j] == 321) kaonc1++;
      if (pdg1[j] == 2212) protonc1++;
      if (pdg1[j] == 11) electronc1++;
      if (pdg1[j] == 2112) neutronc1++;
      
      Double_t p1  = sqrt(px1[j]*px1[j] + py1[j]*py1[j] + pz1[j]*pz1[j]);
      Double_t E1 = sqrt(p1 * p1 + m * m); 
      
      b_cm = 0.95;
      g_cm = 1.0/sqrt(1 - (b_cm*b_cm));
      
      Double_t px1_lab = px1[j];  
      Hpx1->Fill(px1_lab);     
      Double_t py1_lab = py1[j];
      Double_t pz1_lab = g_cm * (pz1[j] + b_cm * E1);
     
      Double_t pT1 = sqrt(px1_lab * px1_lab + py1_lab * py1_lab);
      HpT1->Fill(pT1);
     
      Double_t E_lab = sqrt(px1_lab * px1_lab + py1_lab * py1_lab + pz1_lab * pz1_lab + m * m); 
 
      Double_t eta1 = 0.5 * log((E_lab + pz1_lab)/(E_lab - pz1_lab));
      Heta1->Fill(eta1); 
      if(eta1 > 0.0 && eta1 <= 1.0) Heta101->Fill(pT1);
      if(eta1 > 1.0 && eta1 <= 2.0) Heta112->Fill(pT1);
      if(eta1 > 2.0 && eta1 <= 3.0) Heta123->Fill(pT1);
      if(eta1 > 3.0 && eta1 <= 4.0) Heta134->Fill(pT1);
      if(eta1 > 4.0 && eta1 <= 5.0) Heta145->Fill(pT1);
      if(eta1 > 5.0 && eta1 <= 6.0) Heta156->Fill(pT1);
      if(eta1 > 6.0 && eta1 <= 7.0) Heta167->Fill(pT1);
      if(eta1 > 7.0 && eta1 <= 8.0) Heta178->Fill(pT1);
      
      Double_t phi1 = atan2(py1_lab,px1_lab);
      Hphi1->Fill(phi1);
      
      if(pioncount1 != 0) {
      Hpioncount1->Fill(pioncount1);
      }
      Hmcount1->Fill(mcount1);
    }
  }
  // read the tree from smash file
   TTree *tree = (TTree*) input_file2->Get("particles");
  
 Int_t x=100000; 
 Int_t    npart;
 Int_t pdgcode2[x];
 Double_t px2[x], py2[x], pz2[x];
 Int_t ecount2=0;
 Int_t pcount2=0;
 Int_t mcount2=0;
 Int_t pioncount2=0, rcount2=0, antimuonc2=0, wcount2=0, kaonc2=0, protonc2=0, electronc2=0, neutronc2=0;
 
// get a tree from file
  tree->SetBranchAddress("npart", &npart);
  tree->SetBranchAddress("px", px2);
  tree->SetBranchAddress("py", py2);
  tree->SetBranchAddress("pz", pz2);
  tree->SetBranchAddress("pdgcode", pdgcode2);

 // run the loop   
Long64_t nentries = tree->GetEntries();
 for (Long64_t i = 0; i < nentries; ++i) {
    tree->GetEntry(i); 
    
      Int_t pioncount2=0;
    
    for (Int_t j = 0; j < npart; ++j) {
    
    int pdgcode = pdgcode2[j];
    
      Hpx2->Fill(px2[j]);
      
      Double_t p2  = sqrt(px2[j]*px2[j] + py2[j]*py2[j] + pz2[j]*pz2[j]);
      
      Double_t pT2 = std::sqrt(px2[j]*px2[j] + py2[j]*py2[j]);
      HpT2->Fill(pT2);
      
      
      Double_t eta2 = 0.5 * log((p2+pz2[j])/(p2-pz2[j]));
      Heta2->Fill(eta2);
      
      if(eta2 > 0.0 && eta2 <= 1.0) Heta201->Fill(pT2);
      if(eta2 > 1.0 && eta2 <= 2.0) Heta212->Fill(pT2);
      if(eta2 > 2.0 && eta2 <= 3.0) Heta223->Fill(pT2);
      if(eta2 > 3.0 && eta2 <= 4.0) Heta234->Fill(pT2);
      if(eta2 > 4.0 && eta2 <= 5.0) Heta245->Fill(pT2);
      if(eta2 > 5.0 && eta2 <= 6.0) Heta256->Fill(pT2);
      if(eta2 > 6.0 && eta2 <= 7.0) Heta267->Fill(pT2);
      if(eta2 > 7.0 && eta2 <= 8.0) Heta278->Fill(pT2);
      
      Double_t phi2 = atan2(py2[j],px2[j]);
      Hphi2->Fill(phi2);
      
      if (pdgcode2[j] == 221 ) ecount2++; 
      if (pdgcode2[j] == 13 ) mcount2++;
      Hmcount2->Fill(mcount2);
      if (pdgcode2[j]== 333 ) pcount2++;
      if (pdgcode2[j]== 111 ) pioncount2++;
      Hpioncount2->Fill(pioncount2);
      if(pioncount2 != 0) {
      Hpioncount2->Fill(pioncount2);
      if (pdgcode2[j] == 223) wcount2++;            
      if (pdgcode2[j] == 113) rcount2++;                        
      if (pdgcode2[j] == -13) antimuonc2++;
      if (pdgcode2[j] == 321) kaonc2++;
      if (pdgcode2[j] == 2212) protonc2++;
      if (pdgcode2[j] == 11) electronc2++;
      if (pdgcode2[j] == 2112) neutronc2++;
      }
    }    
 }

// defined histograms for ratio plots
TH1D *Hpx_ratio = (TH1D*) Hpx2->Clone("Hpx_ratio");
Hpx_ratio->Divide(Hpx1);
TH1D *HpT_ratio = (TH1D*) HpT2->Clone("HpT_ratio");
HpT_ratio->Divide(HpT1);
TH1D *Heta_ratio = (TH1D*) Heta1->Clone("Heta_ratio");
Heta_ratio->Divide(Heta2);
TH1D *Heta01_ratio = (TH1D*) Heta201->Clone("Heta01_ratio");
Heta01_ratio->Divide(Heta101);
TH1D *Heta12_ratio = (TH1D*) Heta212->Clone("Heta12_ratio");
Heta12_ratio->Divide(Heta112);
TH1D *Heta23_ratio = (TH1D*) Heta223->Clone("Heta23_ratio");
Heta23_ratio->Divide(Heta123);
TH1D *Heta34_ratio = (TH1D*) Heta234->Clone("Heta34_ratio");
Heta34_ratio->Divide(Heta134);
TH1D *Heta45_ratio = (TH1D*) Heta245->Clone("Heta45_ratio");
Heta45_ratio->Divide(Heta145);
TH1D *Heta56_ratio = (TH1D*) Heta256->Clone("Heta56_ratio");
Heta56_ratio->Divide(Heta156);
TH1D *Heta67_ratio = (TH1D*) Heta267->Clone("Heta67_ratio");
Heta67_ratio->Divide(Heta167);
TH1D *Heta78_ratio = (TH1D*) Heta278->Clone("Heta78_ratio");
Heta78_ratio->Divide(Heta178);
TH1D *Hphi_ratio = (TH1D*) Hphi2->Clone("Hphi_ratio");
Hphi_ratio->Divide(Hphi1); 

// print the counts
std::cout << "eta counts\t(UrQMD)=" << ecount1 << "\t(SMASH)=" << ecount2 << std::endl;
std::cout << "muon counts\t(UrQMD)=" << mcount1 << "\t(SMASH)=" << mcount2 << std::endl;
std::cout << "phi counts\t(UrQMD)=" << pcount1 << "\t(SMASH)=" << pcount2 << std::endl;
std::cout << "pion counts\t(UrQMD)=" << pioncount1<< "\t(SMASH)=" << pioncount2  << std::endl;
std::cout << "omega counts\t(UrQMD)=" << wcount1 << "\t(SMASH)=" << wcount2 << std::endl;
std::cout << "rho counts\t(UrQMD)=" << rcount1 << "\t(SMASH)=" << rcount2 << std::endl;
std::cout << "antimuon counts\t(UrQMD)=" << antimuonc1 << "\t(SMASH)=" << antimuonc2 << std::endl;
std::cout << "kaon counts\t(UrQMD)=" << kaonc1 << "\t(SMASH)=" << kaonc2 << std::endl;
std::cout << "proton counts\t(UrQMD)=" << protonc1 << "\t(SMASH)=" << protonc2 << std::endl;
std::cout << "electron counts\t(UrQMD)=" << electronc1 << "\t(SMASH)=" << electronc2 << std::endl;
std::cout << "neutron counts\t(UrQMD)=" << neutronc1 << "\t(SMASH)=" << neutronc2 << std::endl;

 // momentum
 TCanvas *c_px = new TCanvas();

 Hpx1->SetLineColor(12);
 Hpx1->SetLineWidth(2);
 Hpx2->SetLineColor(46);
 Hpx1->SetLineWidth(1);

 Hpx2->GetXaxis()->SetTitle("Momentum(GeV/c)");
 Hpx2->GetYaxis()->SetTitle("Counts");

 Hpx2->Draw();
 Hpx1->Draw("same");
 
 c_px->BuildLegend();
 
 // px ratio
 TCanvas *cpx_ratio = new TCanvas();

 Hpx_ratio->Draw();

 Hpx_ratio->GetXaxis()->SetTitle("px");
 Hpx_ratio->GetYaxis()->SetTitle("Ratio");
 
 // pT(Transverse momentum)
 TCanvas *c_pT = new TCanvas();

 HpT1->SetLineColor(12);
 HpT1->SetLineWidth(2);
 HpT2->SetLineColor(46);
 HpT2->SetLineWidth(1);

 HpT2->GetXaxis()->SetTitle("Momentum(GeV/c)");
 HpT2->GetYaxis()->SetTitle("Counts");

 HpT1->Scale(1.0 / n1);
 HpT1->Scale(1.0, "width");

 HpT2->Scale(1.0 / nentries);
 HpT2->Scale(1.0, "width");


 HpT2->Draw();
 HpT1->Draw("same");
 
 c_pT->BuildLegend();
 
 // pT ratio
 TCanvas *cpT_ratio = new TCanvas();

 HpT_ratio->Draw();
 
 //HpT_ratio->Scale(1.0 / HpT_ratio->Integral()); 
 
 HpT_ratio->GetXaxis()->SetTitle("pT");
 HpT_ratio->GetYaxis()->SetTitle("Ratio");

// eta
 TCanvas *c_eta = new TCanvas();

 Heta1->SetLineColor(12);
 Heta1->SetLineWidth(2);
 Heta2->SetLineColor(46);
 Heta2->SetLineWidth(1);
 
 Heta2->GetXaxis()->SetTitle("eta(#eta)");
 Heta2->GetYaxis()->SetTitle("Counts");
 
 Heta1->Scale(1.0 / n1);
 Heta1->Scale(1.0, "width");

 Heta2->Scale(1.0 / nentries);
 Heta2->Scale(1.0, "width");
 
 Heta2->Draw();
 Heta1->Draw("same");
 
 c_eta->BuildLegend();

 // eta01
 TCanvas *c_eta01 = new TCanvas();

 Heta101->SetLineColor(12);
 Heta101->SetLineWidth(2);
 Heta201->SetLineColor(46);
 Heta201->SetLineWidth(1);
 
 Heta201->GetXaxis()->SetTitle("pT");
 Heta201->GetYaxis()->SetTitle("Counts");
 
 Heta101->Scale(1.0 / n1);
 Heta101->Scale(1.0, "width");

 Heta201->Scale(1.0 / nentries);
 Heta201->Scale(1.0, "width");
 
 Heta101->Draw();
 Heta201->Draw("same");
 
 c_eta01->BuildLegend();

 // eta12
 TCanvas *c_eta12 = new TCanvas();

 Heta112->SetLineColor(12);
 Heta112->SetLineWidth(2);
 Heta212->SetLineColor(46);
 Heta212->SetLineWidth(1);
 
 Heta212->GetXaxis()->SetTitle("pT");
 Heta212->GetYaxis()->SetTitle("Counts");
 
 Heta112->Scale(1.0 / n1);
 Heta112->Scale(1.0, "width");

 Heta212->Scale(1.0 / nentries);
 Heta212->Scale(1.0, "width");
 
 Heta212->Draw();
 Heta112->Draw("same");
 
 c_eta12->BuildLegend();

 // eta23
 TCanvas *c_eta23 = new TCanvas();

 Heta123->SetLineColor(12);
 Heta123->SetLineWidth(2);
 Heta223->SetLineColor(46);
 Heta223->SetLineWidth(1);
 
 Heta223->GetXaxis()->SetTitle("pT");
 Heta223->GetYaxis()->SetTitle("Counts");
 
 Heta123->Scale(1.0 / n1);
 Heta123->Scale(1.0, "width");

 Heta223->Scale(1.0 / nentries);
 Heta223->Scale(1.0, "width");
 
 Heta223->Draw();
 Heta123->Draw("same");
 
 c_eta23->BuildLegend();

 // eta34
 TCanvas *c_eta34 = new TCanvas();

 Heta134->SetLineColor(12);
 Heta134->SetLineWidth(2);
 Heta234->SetLineColor(46);
 Heta234->SetLineWidth(1);
 
 Heta234->GetXaxis()->SetTitle("pT");
 Heta234->GetYaxis()->SetTitle("Counts");
 
 Heta134->Scale(1.0 / n1);
 Heta134->Scale(1.0, "width");

 Heta234->Scale(1.0 / nentries);
 Heta234->Scale(1.0, "width");
 
 Heta234->Draw();
 Heta134->Draw("same");
 
 c_eta34->BuildLegend();
  
 // eta45

 TCanvas *c_eta45 = new TCanvas();

 Heta145->SetLineColor(12);
 Heta145->SetLineWidth(2);
 Heta245->SetLineColor(46);
 Heta245->SetLineWidth(1);
 
 Heta245->GetXaxis()->SetTitle("pT");
 Heta245->GetYaxis()->SetTitle("Counts");
 
 Heta145->Scale(1.0 / n1);
 Heta145->Scale(1.0, "width");

 Heta245->Scale(1.0 / nentries);
 Heta245->Scale(1.0, "width");
 
 Heta245->Draw();
 Heta145->Draw("same");
 
 c_eta45->BuildLegend();

 // eta56
 TCanvas *c_eta56 = new TCanvas();

 Heta156->SetLineColor(12);
 Heta156->SetLineWidth(2);
 Heta256->SetLineColor(46);
 Heta256->SetLineWidth(1);
 
 Heta256->GetXaxis()->SetTitle("pT");
 Heta256->GetYaxis()->SetTitle("Counts");
 
 Heta156->Scale(1.0 / n1);
 Heta156->Scale(1.0, "width");

 Heta256->Scale(1.0 / nentries);
 Heta256->Scale(1.0, "width");
 
 Heta256->Draw();
 Heta156->Draw("same");
 
 c_eta56->BuildLegend();

 // eta67
 TCanvas *c_eta67 = new TCanvas();

 Heta167->SetLineColor(12);
 Heta167->SetLineWidth(2);
 Heta267->SetLineColor(46);
 Heta267->SetLineWidth(1);
 
 Heta267->GetXaxis()->SetTitle("pT");
 Heta267->GetYaxis()->SetTitle("Counts");
 
 Heta167->Scale(1.0 / n1);
 Heta167->Scale(1.0, "width");

 Heta267->Scale(1.0 / nentries);
 Heta267->Scale(1.0, "width");
 
 Heta267->Draw();
 Heta167->Draw("same");
 
 c_eta67->BuildLegend();

 // eta78
 TCanvas *c_eta78 = new TCanvas();

 Heta178->SetLineColor(12);
 Heta178->SetLineWidth(2);
 Heta278->SetLineColor(46);
 Heta278->SetLineWidth(1);
 
 Heta278->GetXaxis()->SetTitle("pT");
 Heta278->GetYaxis()->SetTitle("Counts");
 
 Heta178->Scale(1.0 / n1);
 Heta178->Scale(1.0, "width");

 Heta278->Scale(1.0 / nentries);
 Heta278->Scale(1.0, "width");
 
 Heta278->Draw();
 Heta178->Draw("same");
 
 c_eta78->BuildLegend();

 // eta ratio
 TCanvas *ceta_ratio = new TCanvas();
  
 Heta_ratio->Draw(); 
 
 Heta_ratio->GetXaxis()->SetTitle("eta(#eta)");
 Heta_ratio->GetYaxis()->SetTitle("Ratio");
 
 // eta01 ratio
 TCanvas *ceta01_ratio = new TCanvas();
  
 Heta01_ratio->Draw(); 
 
 Heta01_ratio->GetXaxis()->SetTitle("eta(#eta)");
 Heta01_ratio->GetYaxis()->SetTitle("Ratio");
 
 // eta12 ratio
 TCanvas *ceta12_ratio = new TCanvas();

 Heta12_ratio->Draw(); 
 
 Heta12_ratio->GetXaxis()->SetTitle("eta(#eta)");
 Heta12_ratio->GetYaxis()->SetTitle("Ratio");
 
 // eta23 ratio
 TCanvas *ceta23_ratio = new TCanvas();

 Heta23_ratio->Draw(); 
 
 Heta23_ratio->GetXaxis()->SetTitle("eta(#eta)");
 Heta23_ratio->GetYaxis()->SetTitle("Ratio");
 
 // eta34 ratio
 TCanvas *ceta34_ratio = new TCanvas();

 Heta34_ratio->Draw(); 
 
 Heta34_ratio->GetXaxis()->SetTitle("eta(#eta)");
 Heta34_ratio->GetYaxis()->SetTitle("Ratio");
 
 // eta45 ratio
 TCanvas *ceta45_ratio = new TCanvas();

 Heta45_ratio->Draw(); 
 
 Heta45_ratio->GetXaxis()->SetTitle("eta(#eta)");
 Heta45_ratio->GetYaxis()->SetTitle("Ratio"); 

 // eta56 ratio
 TCanvas *ceta56_ratio = new TCanvas();

 Heta56_ratio->Draw(); 
 
 Heta56_ratio->GetXaxis()->SetTitle("eta(#eta)");
 Heta56_ratio->GetYaxis()->SetTitle("Ratio");
 
 // eta67 ratio
 TCanvas *ceta67_ratio = new TCanvas();

 Heta67_ratio->Draw(); 
 
 Heta67_ratio->GetXaxis()->SetTitle("eta(#eta)");
 Heta67_ratio->GetYaxis()->SetTitle("Ratio"); 
 
 ceta67_ratio->BuildLegend();
 
 // eta78 ratio
 TCanvas *ceta78_ratio = new TCanvas();

 Heta78_ratio->Draw(); 
 
 Heta78_ratio->GetXaxis()->SetTitle("eta(#eta)");
 Heta78_ratio->GetYaxis()->SetTitle("Ratio");
 
 ceta78_ratio->BuildLegend();
   
//TCanvas *c_eta2 = new TCanvas();
//Heta2->Draw();

// phi
 TCanvas *c_phi = new TCanvas();

 Hphi1->SetLineColor(12);
 Hphi1->SetLineWidth(2);
 Hphi2->SetLineColor(46);
 Hphi2->SetLineWidth(1);
 
 Hphi1->GetXaxis()->SetTitle("phi(#phi)");
 Hphi1->GetYaxis()->SetTitle("Counts");
 
 Hphi1->Scale(1.0 / n1);
 Hphi1->Scale(1.0, "width");

 Hphi2->Scale(1.0 / nentries);
 Hphi2->Scale(1.0, "width");
 
 Hphi1->Draw();
 Hphi2->Draw("same");

 c_phi->BuildLegend();
 
 //phi ratio
 TCanvas *cphi_ratio = new TCanvas();
 Hphi_ratio->Draw();
 
 //Hphi_ratio->Scale(1.0 / Hphi_ratio->Integral());

 Hphi_ratio->GetXaxis()->SetTitle("phi(#phi)");
 Hphi_ratio->GetYaxis()->SetTitle("Ratio");
//TCanvas *c_muon = new TCanvas();
//Hphi2->Draw();

// muon count
TCanvas *c_mcount = new TCanvas();

 Hmcount1->SetLineColor(12);
 Hmcount1->SetLineWidth(2);
 Hmcount2->SetLineColor(46);
 Hmcount2->SetLineWidth(1);
 
 Hmcount2->GetXaxis()->SetTitle("muon(#mu)");
 Hmcount2->GetYaxis()->SetTitle("Counts");
 
 Hmcount1->Scale(1.0 / n1);
 Hmcount1->Scale(1.0, "width");

 Hmcount2->Scale(1.0 / nentries);
 Hmcount2->Scale(1.0, "width");

 Hmcount2->Draw();
 Hmcount1->Draw("same");

 c_mcount->BuildLegend();
 
 // pion count
 TCanvas *c_pioncount = new TCanvas();

 Hpioncount1->SetLineColor(12);
 Hpioncount1->SetLineWidth(2);
 Hpioncount2->SetLineColor(46);
 Hpioncount2->SetLineWidth(1);
 
 Hpioncount2->GetXaxis()->SetTitle("");
 Hpioncount2->GetYaxis()->SetTitle("Counts");
 
 //Hpioncount1->Scale(1.0 );
 //Hpioncount1->Scale(1.0, "width");

 //Hpioncount2->Scale(1.0 / nentries);
 //Hpioncount2->Scale(1.0, "width"); 
 
 Hpioncount2->Draw();
 Hpioncount1->Draw("same");

 c_pioncount->BuildLegend();
 
 fOut->cd();
 
    Hpx1->Write();
    Hpx2->Write();
    HpT1->Write();
    HpT2->Write();
    Hphi1->Write();
    Hphi2->Write();
    Heta1->Write();
    Heta2->Write();
    Hpx_ratio->Write();
    HpT_ratio->Write();
    Hphi_ratio->Write();
    Heta_ratio->Write();
    Heta01_ratio->Write();
    Heta12_ratio->Write();
    Heta23_ratio->Write();
    Heta34_ratio->Write();
    Heta45_ratio->Write();
    Heta56_ratio->Write();
    Heta67_ratio->Write();
    Heta78_ratio->Write();
    
    if(c_px) c_px->Write();
    if(cpx_ratio) cpx_ratio->Write();
    if(c_pT) c_pT->Write();
    if(cpT_ratio) cpT_ratio->Write();
    if(c_eta) c_eta->Write();
    if(c_eta01) c_eta01->Write();
    if(c_eta12) c_eta12->Write();
    if(c_eta23) c_eta23->Write();
    if(c_eta34) c_eta34->Write();
    if(c_eta45) c_eta45->Write();
    if(c_eta56) c_eta56->Write();
    if(c_eta67) c_eta67->Write();
    if(c_eta78) c_eta78->Write();
    if(ceta_ratio) ceta_ratio->Write();
    if(c_phi) c_phi->Write();
    if(cphi_ratio) cphi_ratio->Write();
    if(c_mcount) c_mcount->Write();
    if(c_pioncount) c_pioncount->Write();
    
 fOut->Write();
 //fOut->Close();
}


