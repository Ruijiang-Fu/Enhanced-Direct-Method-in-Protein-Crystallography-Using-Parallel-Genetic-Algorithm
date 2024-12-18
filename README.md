# Enhanced-Direct-Method-in-Protein-Crystallography-Using-Parallel-Genetic-Algorithm

This software is designed for direct phasing of protein crystals, enabling the reconstruction of protein electron density directly from protein crystal diffraction data. It is referenced in the paper titled "Enhanced Direct Method in Protein Crystallography Using Parallel Genetic Algorithm," authored by Ruijiang Fu, Wu-Pei Su, and Hongxing He.

(1) Software Requirements:
To compile and run the code, you will need the Intel C++ Compiler, MPI Library, and Math Kernel Library, all bundled within the Intel oneAPI HPC Toolkit.

(2) Download and Installation Instructions:
You can procure and install the Intel oneAPI HPC Toolkit via this link:
https://www.intel.com/content/www/us/en/developer/tools/oneapi/hpc-toolkit-download.html
By navigating to this page, you will discover options to download the toolkit compatible with your operating system. Follow the outlined instructions to finalize the installation. Upon installation, you will gain access to the Intel C++ Compiler, MPI Library, and Math Kernel Library necessary for compiling and executing your code.

(3) Compilation and Execution Instructions:
It is crucial to note that the number of processes utilized by mpirun should not surpass the total number of cores (or threads) on your CPU, as exceeding this limit may significantly hinder performance.
Assuming a CPU with at least 10 cores, we recommend using 10 processes for mpirun.
To compile and execute the code, simply follow these commands:

make

mpirun -np 10 ./a.out

(4) Preparing Input Files (Illustrated with Example 6eik):
When the PDB structure is known, and you aim to validate the phasing method, the required input files are:
6eik_fmodel.hkl,.HKL,.sca
6eik_uniq_sf.txt
6eik_iter_sigm.txt
6g6e_hist.txt
crysPara.hpp

A. Download the atomic model 6eik.pdb from www.rcsb.org, and run phenix.fmodel to generate 6eik_fmodel.hkl,.HKL,.mtz for assessing phase angle deviations in direct phasing:

phenix.fmodel 6eik.pdb k_sol=0.336 b_sol=50 high_res=1.52 scattering_table=wk1995 data_column_label="FMODEL,PHIFMODEL" output.file_name=6eik_fmodel.hkl,.HKL,.mtz > log.phenix.fmodel.txt;

B. Download 6eik-sf.cif from www.rcsb.org, extract _refln.F_meas_au and _refln.F_meas_sigma_au, and sort reflections by resolution to obtain 6eik_uniq_sf.txt.

C. Refer to the paper "Improving the convergence rate of a hybrid input-output phasing algorithm by varying the reflection data weight" by He, H.; Su, W.-P. (Acta Cryst. A 2018, 74, 36–43. http://doi.org/10.1107/S205327331701436X) to generate 6eik_iter_sigm.txt.

D. To modify the reconstructed electron density for histogram matching, select a protein (e.g., 6g6b) with similar resolution, average temperature factor, and secondary structure. Obtain the protein histogram for 6g6b to generate 6eik_hist.txt.

E. Set crystal parameters including a, b, c, alpha, beta, gamma, space group, cutoff resolution, estimated solvent content, and direct phasing parameters such as sigma for the weighted average density used in reconstructing the protein contour.

When the PDB structure is unknown, and direct phasing is the goal, the required input files are:
6eik_uniq_sf.txt
6eik_iter_sigm.txt
6g6e_hist.txt
crysPara.hpp

By adhering to these instructions, users can effectively utilize the software for protein crystal direct phasing.
