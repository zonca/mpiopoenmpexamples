#include <stdio.h>
#include "mpi.h"
#include <omp.h>

int main(int argc, char *argv[]) {
  int numprocs, rank, namelen, iam = 0, total_threads = 1;
  char processor_name[MPI_MAX_PROCESSOR_NAME];

  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Get_processor_name(processor_name, &namelen);

  #pragma omp parallel default(shared) private(iam, total_threads)
  {
    total_threads = omp_get_num_threads();
    iam = omp_get_thread_num();
    printf("Hello people of the universe from thread %d out of %d from process %d out of %d on %s\n",
           iam, total_threads, rank, numprocs, processor_name);
  }
  #pragma omp parallel num_threads(3) default(shared) private(iam, np)
  {
    np = omp_get_num_threads();
    iam = omp_get_thread_num();
    printf("Hello people of the universe from thread %d out of %d f$
           iam, np, rank, numprocs, processor_name);
  }


  MPI_Finalize();
}

