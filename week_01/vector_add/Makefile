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

COMMON_DEPENDENCIES=Makefile utils.h

all: vec_add_seq vec_add_omp vec_add_ocl

vec_add_seq: $(COMMON_DEPENDENCIES) vec_add_seq.c
	@$(CC) $(CC_FLAGS) vec_add_seq.c -o vec_add_seq

vec_add_omp: $(COMMON_DEPENDENCIES) vec_add_omp.c
	@$(CC) $(CC_FLAGS) vec_add_omp.c -o vec_add_omp -fopenmp

vec_add_ocl: $(COMMON_DEPENDENCIES) vec_add_ocl.c
	@$(CC) $(CC_FLAGS) vec_add_ocl.c -o vec_add_ocl $(OPENCL_FLAGS)

.PHONEY: clean
clean:
	@rm vec_add_seq vec_add_omp vec_add_ocl

run: all
	@echo "Sequential:"
	@./vec_add_seq
	@echo
	@echo "OpenMP:"
	@./vec_add_omp
	@echo
	@echo "OpenCL:"
	@./vec_add_ocl


