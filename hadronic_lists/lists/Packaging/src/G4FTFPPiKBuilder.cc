//
// ********************************************************************
// * DISCLAIMER                                                       *
// *                                                                  *
// * The following disclaimer summarizes all the specific disclaimers *
// * of contributors to this software. The specific disclaimers,which *
// * govern, are listed with their locations in:                      *
// *   http://cern.ch/geant4/license                                  *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.                                                             *
// *                                                                  *
// * This  code  implementation is the  intellectual property  of the *
// * GEANT4 collaboration.                                            *
// * By copying,  distributing  or modifying the Program (or any work *
// * based  on  the Program)  you indicate  your  acceptance of  this *
// * statement, and all its terms.                                    *
// ********************************************************************
//
 #include "G4FTFPPiKBuilder.hh"
 #include "G4ParticleDefinition.hh"
 #include "G4ParticleTable.hh"
 #include "G4ProcessManager.hh"

 G4FTFPPiKBuilder::
 G4FTFPPiKBuilder() 
 {
   theMin = 15*GeV;
   theModel = new G4TheoFSGenerator;
   theCascade = new G4GeneratorPrecompoundInterface;
   thePreEquilib = new G4PreCompoundModel(&theHandler);
   theCascade->SetDeExcitation(thePreEquilib);  
   theModel->SetTransport(theCascade);
   theModel->SetHighEnergyGenerator(&theStringModel);
   theStringDecay = new G4ExcitedStringDecay(&theFragmentation);
   theStringModel.SetFragmentationModel(theStringDecay);
 }

 G4FTFPPiKBuilder::
 ~G4FTFPPiKBuilder() 
 {
   delete theStringDecay;
 }

 void G4FTFPPiKBuilder::
 Build(G4HadronElasticProcess & ) {}

 void G4FTFPPiKBuilder::
 Build(G4PionPlusInelasticProcess & aP)
 {
   theModel->SetMinEnergy(theMin);
   theModel->SetMaxEnergy(100*TeV);
   aP.AddDataSet(&thePiData);
   aP.RegisterMe(theModel);
 }

 void G4FTFPPiKBuilder::
 Build(G4PionMinusInelasticProcess & aP)
 {
   theModel->SetMinEnergy(theMin);
   theModel->SetMaxEnergy(100*TeV);
   aP.AddDataSet(&thePiData);
   aP.RegisterMe(theModel);
 }

 void G4FTFPPiKBuilder::
 Build(G4KaonPlusInelasticProcess & aP)
 {
   theModel->SetMinEnergy(theMin);
   theModel->SetMaxEnergy(100*TeV);
   aP.RegisterMe(theModel);
 }

 void G4FTFPPiKBuilder::
 Build(G4KaonMinusInelasticProcess & aP)
 {
   theModel->SetMinEnergy(theMin);
   theModel->SetMaxEnergy(100*TeV);
   aP.RegisterMe(theModel);
 }

 void G4FTFPPiKBuilder::
 Build(G4KaonZeroLInelasticProcess & aP)
 {
   theModel->SetMinEnergy(theMin);
   theModel->SetMaxEnergy(100*TeV);
   aP.RegisterMe(theModel);
 }

 void G4FTFPPiKBuilder::
 Build(G4KaonZeroSInelasticProcess & aP)
 {
   theModel->SetMinEnergy(theMin);
   theModel->SetMaxEnergy(100*TeV);
   aP.RegisterMe(theModel);
 }

 // 2002 by J.P. Wellisch