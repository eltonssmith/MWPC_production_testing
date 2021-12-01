void plot_Denethor_HVscan (void)
{
//
// plot the relative rate and gain as a function of HV for Denethor
// Data from R178-R183
//

// #include <TMath.h>
#include <TRandom.h>

gROOT->Reset();
gStyle->SetPalette(1,0);
//TTree *Bfield = (TTree *) gROOT->FindObject("Bfield");
gStyle->SetPalette(1,0);
gStyle->SetOptStat(kTRUE);
    gStyle->SetOptStat(1111111);
gStyle->SetOptFit(kTRUE);
// gStyle->SetOptFit(1111);
gStyle->SetPadRightMargin(0.15);
gStyle->SetPadLeftMargin(0.15);
gStyle->SetPadBottomMargin(0.15);
// gStyle->SetFillColor(0);
//
   
   const Int_t npoints=100;

   // define histograms

    Double_t PI = 3.14159;
    
    // input data
    
    const Int_t npts=8;
    Double_t HV[npts]={0,1690,1715,1765,1790,1815,1840,2000};
    Double_t irun[npts]={0,182,179,178,181,180,183,300};
    Double_t gain[npts]={0,11887,17626,30370,39055,58571,80000,200000};
    Double_t nhits[npts]={0,13591,14009,14735,15278,16873,21861,100000};
    
    Double_t irun_Arwen[npts]={0,182,179,178,181,180,183,300};
    Double_t gain_Arwen[npts]={0,10276,13682,23698,32890,44298,58456,200000};
    // Double_t nhits_Arwen[npts]={0,13283,13740,14732,14913,15995,18224,100000};
    Double_t nhits_Arwen[npts]={0,13283,13740,16047,14913,15995,18224,100000};
    
    Double_t Rgain[npts];
    Double_t Rnhits[npts];
    Double_t Rgain_Arwen[npts];
    Double_t Rnhits_Arwen[npts];
    
    // plot relative gain and rates
    
    Double_t gain1765 = gain[3];
    Double_t nhits1765 = nhits[3];
    Double_t gain1765_Arwen = gain_Arwen[3];
    Double_t nhits1765_Arwen = nhits_Arwen[3];
    
    for (Int_t jj=0; jj<npts; jj++) {
        Rgain[jj] = gain[jj]/gain1765;
        Rnhits[jj] = nhits[jj]/nhits1765;
    }
    
    for (Int_t jj=0; jj<npts; jj++) {
        Rgain_Arwen[jj] = gain_Arwen[jj]/gain1765_Arwen;
        Rnhits_Arwen[jj] = nhits_Arwen[jj]/nhits1765_Arwen;
    }
    
    TGraph *gr_gain = new TGraph (npts,HV,Rgain);
    TGraph *gr_nhits = new TGraph (npts,HV,Rnhits);
    
    TGraph *gr_gain_Arwen = new TGraph (npts,HV,Rgain_Arwen);
    TGraph *gr_nhits_Arwen = new TGraph (npts,HV,Rnhits_Arwen);
    //
    
    TCanvas *c1 = new TCanvas("c1","c1",200,10,500,500);
    // c1->SetLogy();
    // c1->Divide(2,2);
    
    TString text;
   
   c1->cd(1);
    gPad->SetGridx();
    gPad->SetGridy();
    
   text.Form("Denethor");
   gr_gain->SetTitle(text);
   gr_gain->GetXaxis()->SetLabelSize(0.05);
   gr_gain->GetXaxis()->SetTitleSize(0.05);
   gr_gain->GetYaxis()->SetLabelSize(0.05);
   gr_gain->GetYaxis()->SetTitleSize(0.05);
   gr_gain->GetYaxis()->SetTitleOffset(1.5);
   gr_gain->GetXaxis()->SetTitle("HV (Volts)");
   gr_gain->GetYaxis()->SetTitle("Relative Gain, MWPC hits/10k triggers");
    gr_gain->GetXaxis()->SetRangeUser(1650,1850);
    gr_gain->GetYaxis()->SetRangeUser(0,3.5);
    gr_gain->GetXaxis()->SetNdivisions(505);
   gr_gain->SetMarkerStyle(20);
    gr_gain->SetMarkerSize(1.0);
    gr_gain->SetMarkerColor(2);
    
    gr_gain->Draw("Ap");
    gr_nhits->SetMarkerStyle(20);
     gr_nhits->SetMarkerSize(1.0);
     gr_nhits->SetMarkerColor(4);
    gr_nhits->Draw("psame");
    
    TLegend *leg = new TLegend(0.15,0.8,0.85,0.9);
    leg->AddEntry(gr_gain,"Relative Gain/Gain@1765V","p");
    leg->AddEntry(gr_nhits,"Relative MWPC hits/hits@1765V","p");
    leg->SetTextSize(0.04);
    leg->Draw();
    
    
    TCanvas *c2 = new TCanvas("c2","c2",200,10,500,500);
    // c2->SetLogy();
    
    c2->cd(1);
    gPad->SetGridx();
    gPad->SetGridy();
    
    text.Form("Arwen");
    gr_gain_Arwen->SetTitle(text);
    gr_gain_Arwen->GetXaxis()->SetLabelSize(0.05);
    gr_gain_Arwen->GetXaxis()->SetTitleSize(0.05);
    gr_gain_Arwen->GetYaxis()->SetLabelSize(0.05);
    gr_gain_Arwen->GetYaxis()->SetTitleSize(0.05);
    gr_gain_Arwen->GetYaxis()->SetTitleOffset(1.5);
    gr_gain_Arwen->GetXaxis()->SetTitle("HV (Volts)");
    gr_gain_Arwen->GetYaxis()->SetTitle("Relative Gain, MWPC hits/10k triggers");
     gr_gain_Arwen->GetXaxis()->SetRangeUser(1650,1850);
     gr_gain_Arwen->GetYaxis()->SetRangeUser(0,3.5);
     gr_gain_Arwen->GetXaxis()->SetNdivisions(505);
    gr_gain_Arwen->SetMarkerStyle(20);
     gr_gain_Arwen->SetMarkerSize(1.0);
     gr_gain_Arwen->SetMarkerColor(2);
    
    gr_gain_Arwen->Draw("Ap");
    gr_nhits_Arwen->SetMarkerStyle(20);
     gr_nhits_Arwen->SetMarkerSize(1.0);
     gr_nhits_Arwen->SetMarkerColor(4);
    gr_nhits_Arwen->Draw("psame");
    leg->Draw();
    
    /*text.Form("plot_Denethor_HVscan_m1_%.0f_m2_%.0f.pdf",gmean1,gmean2);
    c1->SaveAs(text+"(");
    c2->SaveAs(text);
    c3->SaveAs(text);
    c4->SaveAs(text);
    c6->SaveAs(text);
    c5->SaveAs(text+")");*/
    
    c1->SaveAs("plot_Denethor_HVscan.pdf");
    c2->SaveAs("plot_Arwen_HVscan.pdf");
    
    
}
