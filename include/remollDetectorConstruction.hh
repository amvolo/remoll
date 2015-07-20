#ifndef __MOLLERDETECTORCONSTRUCTION_HH
#define __MOLLERDETECTORCONSTRUCTION_HH

#include "G4GDMLParser.hh"
#include "G4VUserDetectorConstruction.hh"
#include "remollGlobalField.hh"
#include <vector>

class G4Tubs;
class G4LogicalVolume;
class G4VPhysicalVolume;
class G4VSensitiveDetector;

class remollIO;

class remollDetectorConstruction : public G4VUserDetectorConstruction
{
  public:

    remollDetectorConstruction();
    virtual ~remollDetectorConstruction();

  public:

    G4VPhysicalVolume* Construct();

    G4int UpdateCopyNo(G4VPhysicalVolume*,G4int);

    void CreateGlobalMagneticField();

    void SetDetectorGeomFile(const G4String&);

    remollGlobalField* GetGlobalField(){ return fGlobalField; }

    G4GDMLParser *fGDMLParser;

    void SetIO( remollIO *io ){ fIO = io; }

  private:
    //----------------------
    // global magnet section
    //----------------------
    //

    G4FieldManager*         fGlobalFieldManager;
    remollGlobalField*      fGlobalField;
    G4String                fDetFileName;

    remollIO *fIO;
};

#endif//__MOLLERDETECTORCONSTRUCTION_HH
