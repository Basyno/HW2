#ifndef Gaussian_Blur_H_
#define Gaussian_Blur_H_
#include <systemc>
using namespace sc_core;

#include <tlm>
#include <tlm_utils/simple_target_socket.h>

#include "filter_def.h"

class Gaussianblur : public sc_module {
public:
  tlm_utils::simple_target_socket<Gaussianblur> t_skt;

  sc_fifo<unsigned char> i_r;
  sc_fifo<unsigned char> i_g;
  sc_fifo<unsigned char> i_b;
  sc_fifo<int> o_result;
  

  SC_HAS_PROCESS(Gaussianblur);
  Gaussianblur(sc_module_name n);
  ~Gaussianblur();

private:
  void do_gblur();
  int val[MASK_N];

  unsigned int base_offset;
  void blocking_transport(tlm::tlm_generic_payload &payload,
                          sc_core::sc_time &delay);
};
#endif
