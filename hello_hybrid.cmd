#!/bin/bash
#PBS -q normal
#PBS -N hello_hybrid
#PBS -l nodes=2:ppn=16:native
#PBS -l walltime=0:10:00
#PBS -o hello_hybrid.out
#PBS -e hello_hybrid.err
#PBS -V
##PBS -M youremail@xyz.edu
##PBS -m abe
cd $PBS_O_WORKDIR
export OMP_NUM_THREADS=8
ibrun -n 4 --tpr 8 ./hello_hybrid
