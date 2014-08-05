#!/bin/bash
#PBS -q normal
#PBS -N hello_openmp
#PBS -l nodes=1:ppn=16:native
#PBS -l walltime=0:10:00
#PBS -o hello_openmp.out
#PBS -e hello_openmp.err
#PBS -V
##PBS -M youremail@xyz.edu
##PBS -m abe
#PBS -A gue998
cd $PBS_O_WORKDIR
export OMP_NUM_THREADS=16
./hello_openmp
