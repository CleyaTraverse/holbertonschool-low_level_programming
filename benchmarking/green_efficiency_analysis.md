                                                                                          Green efficiency analysis


Measurement Methodology


I compiled everything with gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-long-long and no optimization flag. Times come from clock() and are divided by CLOCKS_PER_SEC to get seconds. I ran each program 3 times (4 for the baseline loop) and saved the outputs in the *-metrics.md files. Everything ran on the same machine.

For instrumentation_lab.c, TOTAL starts before the first call (build_dataset) and stops after the last one (reduce_checksum). Each phase has its own clock() just before and right after its call. The printf calls come after all the timing, so printing isn't counted. I didn't touch the logic of the algorithms.


Observed Performance Differences


In comparison_algorithms, the naive version took 1.818741 s on average over 3 runs, and the single-pass version took 0.000057 s. The single-pass version was way faster.

In instrumentation_lab, the average times over the 3 runs were 0.000335 s for BUILD_DATA, 0.000285 s for PROCESS and 0.000084 s for REDUCE, with a TOTAL of 0.000709 s. BUILD_DATA was the slowest phase every time. The runs aren't identical. The naive version went from 1.814004 to 1.827266 s, and TOTAL in instrumentation_lab went from 0.000627 to 0.000857 s. The first run was the slowest by far. The baseline loop did the same: three runs took between 0.156104 and 0.158378 s, and the fourth took 0.219320 s.


Relation Between Runtime and Energy Consumption


I only measured time, not energy, so I can't tell how much energy each version used. What the measurements do show is that the naive version took the CPU for 1.818741 s where the single-pass needed 0.000057 s, on the same machine. The project treats runtime as a proxy for energy, so this is as far as I can go. I didn't test whether energy grows in the same proportion.


Limitations of the Experiment


I ran each program only 3 or 4 times, which isn't enough for a proper study. One baseline run took 0.219320 s while the other three were around 0.157 s.
Finally, I only tested on one machine (WSL on Windows), so I can't say the results would hold with another hardware.


Practical Engineering Takeaway


In the multi-phase program, BUILD_DATA was the slowest phase, and in the comparison the single-pass version was far cheaper in CPU time than the naive one. Measuring each phase separately shows which part takes the most time, so to make this program faster I would start with BUILD_DATA. I'd also repeat the runs before trusting a result, because the same program gave different times each time.
