// Practice_2_6.cc

#include "RooRealVar.h"
#include "RooGaussModel.h"
#include "RooDecay.h"
#include "RooPlot.h"
#include "RooConstVar.h"

using namespace RooFit;

int main(){
  
  RooRealVar t("t","t",0.,10.);
  RooRealVar lambda("lambda","Decay parameter",1.6);
  RooGaussModel res("res","Resolution model",t,RooConst(0.),RooConst(0.2));
  RooDecay model("model","model",t,lambda,res,RooDecay::SingleSided);

  RooPlot* frame = t.frame();
  model.plotOn(frame);

  frame->Draw();
  return 0;
}
