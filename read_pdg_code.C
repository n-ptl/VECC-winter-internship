#include <TFile.h>
#include <TTree.h> 
#include <TBranch.h>
#include <iostream> 
#include <TClonesArray.h>
#include <TObject.h>
 
class CbmMCTrack; 
void read_pdg_code() {

// define histograms

TH1D* Hp = new TH1D("Hp","Momentum", 100, 0, 20);
TH1D* Hpx = new TH1D("Hpx","Momentum", 100, -20, 20);
TH1D* Hpy = new TH1D("Hpy","Momentum", 100, -20, 20);
TH1D* Hpz = new TH1D("Hpz","Momentum", 100, -20, 20);
TH1D* He = new TH1D("He","Energy Loss", 100, 0, 10);
TH1D* Hx = new TH1D("Hx","x-axis", 100, -200, 200);
TH1D* Hy = new TH1D("Hy","y-axis", 100, -200, 200);
TH1D* Hz = new TH1D("Hz","z-axis", 500, 0, 500);
TH1D* Hstat = new TH1D("Hstat","Station Counts", 500, -1, 4);
TH1D* Hstat1 = new TH1D("Hstat1","Station 1 Counts", 500, -1, 1);
TH1D* Hstat2 = new TH1D("Hstat2","Station 2 Counts", 500, 0, 2);
TH1D* Hstat3 = new TH1D("Hstat3","Station 3 Counts", 500, 1, 3);
TH1D* Hstat4 = new TH1D("Hstat4","Station 4 Counts", 500, 2, 4);
TH1D* Hlay = new TH1D("Hlay","Station Layer Counts", 500, -1, 4);
TH1D* Hlay1 = new TH1D("Hlay1","Station1 Layer Counts", 500, -1, 4);
TH1D* Hlay2 = new TH1D("Hlay2","Station2 Layer Counts", 500, -1, 4);
TH1D* Hlay3 = new TH1D("Hlay3","Station3 Layer Counts", 500, -1, 4);
TH1D* Hlay4 = new TH1D("Hlay4","Station4 Layer Counts", 500, -1, 4);
TH1D* Hmod = new TH1D("Hmod","Module Counts", 500, -1, 20);
TH1D* Hmod1 = new TH1D("Hmod1","Module Counts (Station1 Layer1)", 500, -1, 17);
TH1D* Hmod2 = new TH1D("Hmod2","Module Counts (Station2 Layer2)", 500, -1, 21);
TH1D* Hmod3 = new TH1D("Hmod3","Module Counts (Station3 Layer3)", 500, -1, 21);
TH1D* Hmod4 = new TH1D("Hmod4","Module Counts (Station4 Layer1)", 500, -1, 21);
TH1D* Hrad = new TH1D("Hrad","Radius of Layer", 500, 0, 200);
TH1D* Hrad1 = new TH1D("Hrad1","Radius of Layer (Station 1)", 500, 0, 200);
TH1D* Hrad2 = new TH1D("Hrad2","Radius of Layer (Station 2)", 500, 0, 200);
TH1D* Hrad3 = new TH1D("Hrad3","Radius of Layer (Station 3)", 500, 0, 200);
TH1D* Hrad4 = new TH1D("Hrad4","Radius of Layer (Station 4)", 500, 0, 200);
TH2D* Hxy = new TH2D("Hxy","XY", 500, -200, 200, 500, -200, 200);
TH2D* HxyS1 = new TH2D("HxyS1","XY", 500, -200, 200, 500, -200, 200);
TH2D* HxyS1M1 = new TH2D("HxyS1M1","XY", 500, -200, 200, 500, -200, 200);
TH2D* HxyS2 = new TH2D("HxyS2","XY", 500, -200, 200, 500, -200, 200);
TH2D* HxyS3 = new TH2D("HxyS3","XY", 500, -200, 200, 500, -200, 200);
TH2D* HxyS4 = new TH2D("HxyS4","XY", 500, -200, 200, 500, -200, 200);
TH1D* Hetap = new TH1D("Hetap","Pseudorapidity",200,-10,10);
TH1D* Hetas = new TH1D("Hetas","Pseudorapidity",200,-10,10);
TH1D* Hphi = new TH1D("Hphi","Phi",200,-10,10);
TH1D* HphiS1 = new TH1D("HphiS1","Phi",200,-10,10);
TH2D* HphiS1L1 = new TH2D("HphiS1L1", "Phi",100,0,16, 50,-4,4);
TH2D* HmodRad = new TH2D("HmodRad","",21,0,21,100,0,200);
TH1D* HphiS1M1 = new TH1D("HphiS1M1","Phi",200,-10,10);
TCanvas *c1 = new TCanvas();  
 
// open root file to read
  TFile *input_file = TFile::Open("testmfn.tra.root");
  if (input_file->IsOpen()) {
    printf("Successfully opened file %s\n", input_file->GetName());
  } else {
    printf("Error at opening file %s\n", input_file->GetName());
  }
// create an output root file  
 TFile *fout = new TFile("histogram.root","recreate");
 
// get a tree from file
    TTree* tree = (TTree*) input_file->Get("cbmsim");
  
  //get the MuchPoint branch from tree 
  TClonesArray *MuchPoint = new TClonesArray("CbmMuchPoint");
  tree->SetBranchAddress("MuchPoint", &MuchPoint); 
  
  //get the MCTrack branch from tree
  TClonesArray* fMCTrack = new TClonesArray("CbmMCTrack");
  tree->SetBranchAddress("MCTrack", &fMCTrack);
// int fPdgCode_value;

// set the counter to 0 
  int wcount=0;
  int ecount=0;
  int rcount=0;
  int pcount=0;
  int pioncount=0;
  int muonc=0;
  int antimuonc=0;
  int kaonc=0;
  int protonc=0;
  int electronc=0;
  int neutronc=0;
  int pric=0;
  int secc=0;
  int pricS1L1=0;
  int pricS1L2=0;
  int pricS1L3=0;
  int pricS2L1=0;
  int pricS2L2=0;
  int pricS2L3=0;
  int pricS3L1=0;
  int pricS3L2=0;
  int pricS3L3=0;
  int pricS4L1=0;
  int pricS4L2=0;
  int pricS4L3=0; 
  int sS1L1=0;
  int sS1L2=0;
  int sS1L3=0;
  int sS2L1=0;
  int sS2L2=0;
  int sS2L3=0;
  int sS3L1=0;
  int sS3L2=0;
  int sS3L3=0;
  int sS4L1=0;
  int sS4L2=0;
  int sS4L3=0;                   
    
Long64_t nentries = tree->GetEntries();

cout<<nentries<<endl;
   
// run the loop  
for (Long64_t i = 0; i < tree->GetEntries(); ++i) {
    tree->GetEntry(i); // read data for this entry
    
      for (int j = 0; j < fMCTrack->GetEntriesFast(); j++) {
      
      CbmMCTrack* track = (CbmMCTrack*)(fMCTrack->At(j));
           
      Int_t motherId = track->GetMotherId();
        
       if (track) { // always check for a valid pointer
        
            Int_t pdg_code = track->GetPdgCode(); // assuming this method exists
            
             if (pdg_code == 223) wcount++;
             if (pdg_code == 221) ecount++;
             if (pdg_code == 113) rcount++;
             if (pdg_code == 333) pcount++;
             if (pdg_code == 111) pioncount++;
             if (pdg_code == 13 ) muonc++;
             if (pdg_code == -13) antimuonc++;
             if (pdg_code == 321) kaonc++;
             if (pdg_code == 2212) protonc++;
             if (pdg_code == 11) electronc++;
             if (pdg_code== 2112) neutronc++;
             if (motherId == -1) pric++;
             if (motherId != -1) secc++;
             }
        }
    
    Int_t nPoints = MuchPoint->GetEntries();
    
    for (Int_t iPoint1 = 0; iPoint1 < nPoints; iPoint1++){
    
        CbmMuchPoint* point1 = (CbmMuchPoint*) MuchPoint->At(iPoint1);
        
        Int_t stId = CbmMuchAddress::GetStationIndex(point1->GetDetectorID());
        Hstat->Fill(stId);
        if (stId == 0){ Hstat1->Fill(stId);}
        else if (stId == 1){ Hstat2->Fill(stId);}
        else if (stId == 2){ Hstat3->Fill(stId);}
        else if (stId == 3){ Hstat4->Fill(stId);}
        
        Double_t x = 0.5 * (point1->GetXIn() + point1->GetXOut());
        Hx->Fill(x);
        Double_t y = 0.5 * (point1->GetYIn() + point1->GetYOut());
        Hy->Fill(y);
        Double_t z = 0.5 * (point1->GetZIn() + point1->GetZOut());
        Hz->Fill(z);
        Hxy->Fill(x,y);
        Double_t Eloss = point1->GetEnergyLoss();
        He->Fill(Eloss);
        Double_t phi = TMath::ATan2(y,x);
        Hphi->Fill(phi);
        
        Double_t rad = sqrt(x * x + y * y);
        Hrad->Fill(rad);
        if (stId == 0){ Hrad1->Fill(rad); HxyS1->Fill(x,y); HphiS1->Fill(phi);}
        if (stId == 1){ Hrad2->Fill(rad); HxyS2->Fill(x,y);}
        if (stId == 2){ Hrad3->Fill(rad); HxyS3->Fill(x,y);}
        if (stId == 3){ Hrad4->Fill(rad); HxyS4->Fill(x,y);}
        
        Int_t layId = CbmMuchAddress::GetLayerIndex(point1->GetDetectorID());
        Hlay->Fill(layId);
        if (stId == 0){ Hlay1->Fill(layId);}
        else if (stId == 1 ) Hlay2->Fill(layId);
        else if (stId == 2 ) Hlay3->Fill(layId);
        else if (stId == 3 ) Hlay4->Fill(layId);
        
        Int_t modId = CbmMuchAddress::GetModuleIndex(point1->GetDetectorID());
        Int_t layersideId = CbmMuchAddress::GetLayerSideIndex(point1->GetDetectorID());
        Hmod->Fill(modId);
        if (stId ==0 && layersideId == 1) modId = modId + 8;
        if (stId ==1 && layersideId == 1) modId = modId + 10;
        if (stId ==2 && layersideId == 1) modId = modId + 9;
        if (stId ==3 && layersideId == 1) modId = modId + 9;
        if (stId == 0 && layId == 0){ Hmod1->Fill(modId);}
        if (stId == 0 && layId == 0 && modId == 0){HphiS1M1->Fill(phi); HxyS1M1->Fill(x,y);}
        if (stId == 1 && layId == 1){ Hmod2->Fill(modId); HmodRad->Fill(modId, rad);}
        if (stId == 2 && layId == 2){ Hmod3->Fill(modId);}
        if (stId == 3 && layId == 0){ Hmod4->Fill(modId);}
        
        if(stId == 0 && layId == 0){HphiS1L1->Fill(modId, phi);}
        
        Int_t trackId = point1->GetTrackID();
        CbmMCTrack* mcTrack = (CbmMCTrack*)fMCTrack->At(trackId);
	      Int_t motherId = mcTrack->GetMotherId();
        
        if (stId == 0 && layId == 0 && motherId == -1) pricS1L1++;
        if (stId == 0 && layId == 1 && motherId == -1) pricS1L2++;
        if (stId == 0 && layId == 2 && motherId == -1) pricS1L3++;
                
        if (stId == 0 && layId == 0 && motherId != -1) sS1L1++;
        if (stId == 0 && layId == 1 && motherId != -1) sS1L2++;
        if (stId == 0 && layId == 2 && motherId != -1) sS1L3++;
                
        if (stId == 1 && layId == 0 && motherId == -1) pricS2L1++;
        if (stId == 1 && layId == 1 && motherId == -1) pricS2L2++;
        if (stId == 1 && layId == 2 && motherId == -1) pricS2L3++;
                
        if (stId == 1 && layId == 0 && motherId != -1) sS2L1++;
        if (stId == 1 && layId == 1 && motherId != -1) sS2L2++;
        if (stId == 1 && layId == 2 && motherId != -1) sS2L3++;
                
        if (stId == 2 && layId == 0 && motherId == -1) pricS3L1++;
        if (stId == 2 && layId == 1 && motherId == -1) pricS3L2++;
        if (stId == 2 && layId == 2 && motherId == -1) pricS3L3++;
        
        if (stId == 2 && layId == 0 && motherId != -1) sS3L1++;
        if (stId == 2 && layId == 1 && motherId != -1) sS3L2++;
        if (stId == 2 && layId == 2 && motherId != -1) sS3L3++;
                
        if (stId == 3 && layId == 0 && motherId == -1) pricS4L1++;
        if (stId == 3 && layId == 1 && motherId == -1) pricS4L2++;
        if (stId == 3 && layId == 2 && motherId == -1) pricS4L3++;
        
        if (stId == 3 && layId == 0 && motherId != -1) sS4L1++;
        if (stId == 3 && layId == 1 && motherId != -1) sS4L2++;
        if (stId == 3 && layId == 2 && motherId != -1) sS4L3++;
                 
        Double_t px = point1->GetPx();
        Hpx->Fill(px);
        Double_t py = point1->GetPy();
        Hpy->Fill(py);
        Double_t pz = point1->GetPz();
        Hpz->Fill(pz);
        Double_t p = sqrt(px * px + py * py + pz * pz);
        Hp->Fill(p);
        
        // eta plot
        TVector3 pe(px,py,pz);
        if(motherId != -1){ Hetas->Fill(pe.Eta());}
        if(motherId == -1){ Hetap->Fill(pe.Eta());}
                      
    }
}
    /*   
       for (int i=1; i<= Hrad1->GetNbinsX(); ++i) 
       {
       double r = Hrad1->GetBinCenter(i);
       
       Hrad1->SetBinContent(i, Hrad1->GetBinContent(i) / (r*r));
       
       }
      */ 
       
        Hrad1->SetLineColor(kBlue);
        Hrad1->SetLineWidth(2);
        Hrad2->SetLineColor(kRed);
        Hrad2->SetLineWidth(2);
        Hrad3->SetLineColor(kMagenta);
        Hrad3->SetLineWidth(2);
        Hrad4->SetLineColor(kBlack);
        Hrad4->SetLineWidth(2);
      
        Hrad->GetXaxis()->SetTitle("Radius(cm)");
        Hrad->GetYaxis()->SetTitle("Counts");
        
        Hrad1->GetXaxis()->SetTitle("Radius(cm)");
        Hrad1->GetYaxis()->SetTitle("Counts");
        
        Hrad2->GetXaxis()->SetTitle("Radius(cm)");
        Hrad2->GetYaxis()->SetTitle("Counts");
        
        Hrad3->GetXaxis()->SetTitle("Radius(cm)");
        Hrad3->GetYaxis()->SetTitle("Counts");
        
        Hrad4->GetXaxis()->SetTitle("Radius(cm)");
        Hrad4->GetYaxis()->SetTitle("Counts");
            
        Hetap->GetXaxis()->SetTitle("eta");
        Hetap->GetYaxis()->SetTitle("Counts");
        
        Hetas->GetXaxis()->SetTitle("eta");
        Hetas->GetYaxis()->SetTitle("Counts");
        
        c1->cd();
        Hrad1->Draw();
        Hrad2->Draw("same");
        Hrad3->Draw("same");
        Hrad4->Draw("same");
        
        c1->BuildLegend();

    // print the output
    cout << "-----------------------------------" << endl;
    std::cout << "omega counts= " << wcount << std::endl; 
    std::cout << "eta counts= " << ecount << std::endl;
    std::cout << "rho counts= " << rcount << std::endl;
    std::cout << "phi counts= " << pcount << std::endl;
    std::cout << "pion counts= " << pioncount << std::endl;
    std::cout << "muon counts= " << muonc << std::endl;
    std::cout << "antimuon counts= " << antimuonc << std::endl;
    std::cout << "kaon counts= " << kaonc << std::endl;
    std::cout << "proton counts= " << protonc << std::endl;
    std::cout << "electron counts= " << electronc << std::endl;
    std::cout << "neutron counts= " << neutronc << std::endl;
    std::cout << "primary counts= " << pric << std::endl;
    std::cout << "secondary counts= " << secc << std::endl;
    cout << "-----------------------------------" << endl;   
    std::cout << "primary counts station1 Layer1\t" << pricS1L1 << "\tlayer 2\t "<< pricS1L2 << "\tlayer 3\t"<<pricS1L3<< std::endl;
    std::cout << "primary counts station2 Layer1\t" << pricS2L1 << "\tlayer 2\t "<< pricS2L2 << "\tlayer 3\t"<<pricS2L3<< std::endl;
    std::cout << "primary counts station3 Layer1\t" << pricS3L1 << "\tlayer 2\t "<< pricS3L2 << "\tlayer 3\t"<<pricS3L3<< std::endl;
    std::cout << "primary counts station4 Layer1\t" << pricS4L1 << "\tlayer 2\t "<< pricS4L2 << "\tlayer 3\t"<<pricS4L3<< std::endl;
    cout << "-----------------------------------" << endl; 
    std::cout << "secondary counts station1 Layer1 " << sS1L1 << "\tlayer 2\t "<< sS1L2 << "\tlayer 3\t"<<sS1L3<< std::endl;
    std::cout << "secondary counts station2 Layer1 " << sS2L1 << "\tlayer 2\t "<< sS2L2 << "\tlayer 3\t"<<sS2L3<< std::endl;
    std::cout << "secondary counts station3 Layer1 " << sS3L1 << "\tlayer 2\t "<< sS3L2 << "\tlayer 3\t"<<sS3L3<< std::endl;
    std::cout << "secondary counts station4 Layer1 " << sS4L1 << "\tlayer 2\t "<< sS4L2 << "\tlayer 3\t"<<sS4L3<< std::endl;
      
    Hstat->Write();
    Hstat1->Write();
    Hstat2->Write();
    Hstat3->Write();
    Hstat4->Write();
    Hlay->Write();
    Hlay1->Write();
    Hlay2->Write();
    Hlay3->Write();
    Hlay4->Write();
    Hmod->Write();
    Hmod1->Write();
    Hmod2->Write();
    Hmod3->Write();
    Hmod4->Write();
    Hp->Write();
    Hpx->Write();
    Hpy->Write();
    Hpz->Write();
    Hx->Write();
    Hy->Write();
    Hz->Write();
    Hxy->Write();
    HxyS1->Write();
    HxyS1M1->Write();
    HxyS2->Write();
    HxyS3->Write();
    HxyS4->Write();
    He->Write();
    Hrad->Write();
    Hrad1->Write();
    Hrad2->Write();
    Hrad3->Write();
    Hrad4->Write();
    HmodRad->Write();
    Hetap->Write();
    Hetas->Write();
    Hphi->Write();
    HphiS1->Write();
    HphiS1L1->Write();
    HphiS1M1->Write();

  // close the input file
  input_file->Close();

}
