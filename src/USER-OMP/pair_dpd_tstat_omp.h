/* -*- c++ -*- ----------------------------------------------------------
   LAMMPS - Large-scale Atomic/Molecular Massively Parallel Simulator
   http://lammps.sandia.gov, Sandia National Laboratories
   Steve Plimpton, sjplimp@sandia.gov

   Copyright (2003) Sandia Corporation.  Under the terms of Contract
   DE-AC04-94AL85000 with Sandia Corporation, the U.S. Government retains
   certain rights in this software.  This software is distributed under
   the GNU General Public License.

   See the README file in the top-level LAMMPS directory.
------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------
   Contributing author: Axel Kohlmeyer (Temple U)
------------------------------------------------------------------------- */

#ifdef PAIR_CLASS

PairStyle(dpd/tstat/omp,PairDPDTstatOMP)

#else

#ifndef LMP_PAIR_DPD_TSTAT_OMP_H
#define LMP_PAIR_DPD_TSTAT_OMP_H

#include "pair_dpd_tstat.h"
#include "thr_omp.h"

namespace LAMMPS_NS {

class PairDPDTstatOMP : public PairDPDTstat, public ThrOMP {

 public:
  PairDPDTstatOMP(class LAMMPS *);
  virtual ~PairDPDTstatOMP();

  virtual void compute(int, int);
  virtual double memory_usage();

 protected:
  class RanMars **random_thr;

 private:
  template <int EVFLAG, int EFLAG, int NEWTON_PAIR>
  void eval(int ifrom, int ito, ThrData * const thr);
};

}

#endif
#endif
