#!/bin/bash
#SBATCH --job-name=ds221_run
#SBATCH --nodes=1
#SBATCH --partition=debug
#SBATCH --nodelist=node7
#SBATCH --ntasks=1
#SBATCH --time=00:05:00
#SBATCH --chdir=/scratch/kartikeyag/ds221-1
#SBATCH --output=out_%j.txt
#SBATCH --error=err_%j.txt

# Ensure we are in the right directory
cd /scratch/kartikeyag/ds221-1

echo "========================================"
echo "Job started on: $(hostname)"
echo "Current directory: $(pwd)"
echo "Date: $(date)"
echo "========================================"

# Run the program with all required arguments (Q1, Q2, and Q3)
./ds221_exe \
    sample_test/Question_1/input.txt out_q1.txt \
    sample_test/Question_2/input.txt out_q2.txt \
    sample_test/Question_3/input.txt out_q3.txt

echo ""
echo "=== Question 1 Output ==="
cat out_q1.txt
echo ""

echo "=== Question 2 Output ==="
cat out_q2.txt
echo ""

echo "=== Question 3 Output ==="
cat out_q3.txt
echo ""

echo "========================================"
echo "Job finished at: $(date)"
echo "========================================"