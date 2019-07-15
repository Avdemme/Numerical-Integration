#include "stdio.h"
#include "stdlib.h"
#include <fstream>
#include <iostream>
#include "math.h"
#include "string.h"
#include "time.h"
#include <cmath>
#include <iomanip>

using namespace std;

int main( int argc, char** argv ) {
  
  double ddx=0.0002;
  
  std::remove( "dx_c_and_pi.txt" );
  ofstream dx_and_pi;

    
  double x = 0;
  double y = 0;
  double dx = 1;
  double pi_act = M_PI;
  double a_c = 0;
  double v_disk = 0;
  double v_sphere_i = 0;
  double v_sphere_f = 0;
  double radius = 0.5;
  double v_cube = pow(2*radius , 3 );

  for ( dx = 1; dx > 0 ; dx -=ddx ) {

    x = 0;
    y = 0;
    a_c = 0;
    v_disk = 0;
    v_sphere_i = 0;
    v_sphere_f =0;
    
    
  
    for ( x = -radius; x < radius ; x += dx ) {
      
      y = sqrt( pow(radius,2) - pow(x,2)); 
      a_c = pi_act * pow(y,2);
      v_disk = a_c * dx;
      v_sphere_f = v_sphere_i + v_disk;
      v_sphere_i = v_sphere_f;
      
    }
    
    double pi_approx = ( 3 * v_sphere_f ) / ( 4 * pow(radius,3));
    double cube_frac = v_sphere_f / v_cube;
    double dx_complement = 1 - dx;
    std::cout << std::setprecision(15) << dx << "\t" << dx_complement << "\t" << v_sphere_f << "\t"<< cube_frac << "\t" << pi_approx << endl;

    dx_and_pi.open ( "dx_c_and_pi.txt", ios::app);
    dx_and_pi << std::setprecision(15) << dx_complement << "\t" << pi_approx << endl;
    dx_and_pi.close();
    
    if ( dx < 1.001* ddx ) {
      break;
    }
  }
  return 0;
  
}
