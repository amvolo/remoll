#include "remollPrimaryGeneratorAction.hh"

#include "G4Event.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "remollIO.hh"
#include "remolltypes.hh"
#include "globals.hh"

remollPrimaryGeneratorAction::remollPrimaryGeneratorAction() {
  G4int n_particle = 1;
  particleGun = new G4ParticleGun(n_particle);

  G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
  G4String particleName;
  G4ParticleDefinition* particle;

  // Default generator data
  particle = particleTable->FindParticle(particleName="e-");
  particleGun->SetParticleDefinition(particle);
  particleGun->SetParticleMomentumDirection(G4ThreeVector(0.0,0.0,1.0));
  particleGun->SetParticleEnergy(1.0*GeV);
  particleGun->SetParticlePosition(G4ThreeVector(0.*cm,0.*cm,-100.*cm));

}

remollPrimaryGeneratorAction::~remollPrimaryGeneratorAction() {
  delete particleGun;
}

void remollPrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent) {
  G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
  G4String particleName;
  G4ParticleDefinition* particle;


  // Several different types of scattering
  // Let's start with e'N elastic

  //  Roll up random values
  
  /* FIXME 
   *   Generate event, set IO data
   */

  /*
  particleGun->SetParticleDefinition(particle);

  particleGun->SetParticleMomentumDirection( G4ThreeVector( 0.0, 0.0, 1.0) );
  particleGun->SetParticleEnergy( 1.0*GeV );
  particleGun->SetParticlePosition( G4ThreeVector( 0.0, 0.0, -10.0*m ));
  */
	  
  particleGun->GeneratePrimaryVertex(anEvent);

}

G4ParticleGun* remollPrimaryGeneratorAction::GetParticleGun() {
  return particleGun;
} 
