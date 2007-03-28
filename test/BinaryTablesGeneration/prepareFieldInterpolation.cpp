// Magnetic Field Interpolation Test Program
// by droll (03/02/04)
// Updated N. Amapane 3/07

#include <iostream>

#include "prepareMagneticFieldGrid.h"

using namespace std;

int main(int argc, char **argv) {
  if (argc != 3) {
    cout << "SYNOPSIS:" << endl
	 << " prepareFieldInterpolation [input.table] [output.bin]" << endl;
    cout << "Example:" << endl
	 << " prepareFieldInterpolation /afs/cern.ch/cms/OO/mag_field/version_85l_030919/v-xyz-217.table grid.217.bin" << endl;
      return 1;  
  }
//   const string filename1 = "/afs/cern.ch/cms/OO/mag_field/version_85l_030919/v-xyz-217.table";
//   const string filename2 = "/afs/cern.ch/cms/OO/mag_field/grid_85l_030919/grid-217.bin";

  string filename1 = argv[1];
  string filename2 = argv[2];

  prepareMagneticFieldGrid MFG001;                                    // MFG001 for standard cases
  if (!MFG001.isReady()) MFG001.countTrueNumberOfPoints(filename1);   // check, if file contains some points twice
  if (!MFG001.isReady()) MFG001.fillFromFile(filename1);              // determine grid structure (standard cases)
  int type           =   MFG001.gridType();                           // grid type
  if (type == 0) cout << "  grid sructure detection failed: PLEASE CHECK AGAIN (check EPSILON parameter)" << endl;
  if (MFG001.isReady())  MFG001.validateAllPoints();                  // check position of every point
  if (MFG001.isReady())  MFG001.saveGridToFile(filename2);            // write grid to disk
  cout << " " << endl;
  if (!MFG001.isReady()) {                                            // MFG001 anlysis was not successful
    prepareMagneticFieldGrid MFG002;                                  // MFG002 for special cases
    if (!MFG002.isReady()) MFG002.countTrueNumberOfPoints(filename1); // check, if file contains some points twice
    if (!MFG002.isReady()) MFG002.fillFromFileSpecial(filename1);     // determine grid structure (special cases)
    int type           =   MFG002.gridType();                         // grid type
    if (type == 0) cout << "  grid sructure detection failed: PLEASE CHECK AGAIN (check EPSILON parameter)" << endl;
    if (MFG002.isReady())  MFG002.validateAllPoints();                // check position of every point
    if (MFG002.isReady())  MFG002.saveGridToFile(filename2);          // write grid to disk
    cout << " " << endl;
  }

  return(0);
}
