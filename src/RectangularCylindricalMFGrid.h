#ifndef RectangularCylindricalMFGrid_H
#define RectangularCylindricalMFGrid_H

#include "FWCore/Utilities/interface/Visibility.h"
#include "MFGrid3D.h"

class binary_ifstream;

class dso_internal RectangularCylindricalMFGrid : public MFGrid3D {
public:

  RectangularCylindricalMFGrid( binary_ifstream& istr, 
				const GloballyPositioned<float>& vol );

  virtual LocalVector uncheckedValueInTesla( const LocalPoint& p) const;

  virtual void dump() const;

  virtual void toGridFrame( const LocalPoint& p, double& a, double& b, double& c) const;

  virtual LocalPoint fromGridFrame( double a, double b, double c) const;

};

#endif
