
OCL_HOME=/scratch/c703/c7031057/opencl

CC=gcc
CC_FLAGS=-O3 -std=c11 -I$(OCL_HOME)/include -L$(OCL_HOME)/lib -Werror -pedantic

COMMON_DEPENDENCIES=Makefile utils.h

all: mat_mul_seq mat_mul_omp mat_mul_ocl

mat_mul_seq: $(COMMON_DEPENDENCIES) mat_mul_seq.c
	@$(CC) $(CC_FLAGS) mat_mul_seq.c -o mat_mul_seq

mat_mul_omp: $(COMMON_DEPENDENCIES) mat_mul_omp.c
	@$(CC) $(CC_FLAGS) mat_mul_omp.c -o mat_mul_omp -fopenmp

mat_mul_ocl: $(COMMON_DEPENDENCIES) mat_mul_ocl.c cl_utils.h
	@$(CC) $(CC_FLAGS) mat_mul_ocl.c -o mat_mul_ocl -lOpenCL

.PHONEY: clean
clean:
	@rm mat_mul_seq mat_mul_omp mat_mul_ocl
	
run: all
	@echo "Sequential:"
	@./mat_mul_seq
	@echo
	@echo "OpenMP:"
	@./mat_mul_omp
	@echo
	@echo "OpenCL:"
	@./mat_mul_ocl


