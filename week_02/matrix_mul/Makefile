CC_FLAGS = -std=c11 -O3 -Werror -pedantic -I../../shared -D _POSIX_C_SOURCE=199309L
OPENCL_FLAGS = -lOpenCL

ifneq ($(OS), Windows_NT)
  ifeq ($(shell uname -s), Darwin)
    ifeq ($(shell brew ls gcc &>/dev/null; echo $$?), 0)
      GCC_PREFIX = $(shell brew --prefix gcc)
      CC = $(GCC_PREFIX)/bin/gcc-7
      OPENCL_FLAGS = -framework OpenCL
    else
      $(error "GCC is not installed, run `brew install gcc`")
    endif
	else
    OCL_HOME = /scratch/c703/c7031057/opencl
    CC_FLAGS += -I$(OCL_HOME)/include -L$(OCL_HOME)/lib
  endif
endif

all: mat_mul_seq mat_mul_omp mat_mul_ocl

mat_mul_seq: mat_mul_seq.c
	@$(CC) $(CC_FLAGS) mat_mul_seq.c -o mat_mul_seq

mat_mul_omp: mat_mul_omp.c
	@$(CC) $(CC_FLAGS) mat_mul_omp.c -o mat_mul_omp -fopenmp

mat_mul_ocl: mat_mul_ocl.c cl_utils.h
	@$(CC) $(CC_FLAGS) mat_mul_ocl.c -o mat_mul_ocl $(OPENCL_FLAGS)

.PHONEY: clean
clean:
	$(RM) mat_mul_seq mat_mul_omp mat_mul_ocl

run: all
	@echo "Sequential:"
	@./mat_mul_seq
	@echo
	@echo "OpenMP:"
	@./mat_mul_omp
	@echo
	@echo "OpenCL:"
	@./mat_mul_ocl


