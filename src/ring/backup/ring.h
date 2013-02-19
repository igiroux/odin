#include <string.h>
#include <hdf5.h>
#include <vector>

using namespace std;

class RingScatter
{
  vector<float> quats,Q,THETA,XYZA;
  vector<string> QVALS;
  
  float  wavelen,qres;
  int    n_rotations,Nphi,numAtoms;

  float * rings;
  
  string qstring;

  hid_t  h5_file_id, h5_ring_group_id;
  
  hid_t  space_rings,space_single;
  
  void Scatter();

  void generate_random_quaternion(
                 float r1, float  r2, float r3,
                float &q1, float &q2, float &q3, float &q4);

  void rotate(float x, float y, float z,
              float b0, float b1, float b2, float b3,
              float &ox, float &oy, float &oz);

  void sleep(int mseconds);

  void split_string(const string &s, char delim, vector<string> &elems);

public:
  RingScatter (string in_file,int Nphi_,int n_rotations_,float qres_, float wavelen_, string qstring_);
 ~RingScatter ();

};
