# Benchmarking Report

## Measurement Methodology

All programs were compiled with `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-long-long`, with no optimization flag, so every measurement was made at gcc's default level (-O0). Timing relies on `clock()` from `<time.h>`, converted to seconds with `CLOCKS_PER_SEC`. Each program was run [N] times, and all outputs were recorded in the `*-metrics.md` files.

In `instrumentation_lab.c`, `TOTAL` starts before the first call (`build_dataset`) and ends after the last call (`reduce_checksum`). Each phase is measured with the same pattern: one `clock()` immediately before its call and one immediately after. The `printf` calls come after all measurements, so printing is never timed. Algorithm logic was not modified.

## Observed Performance Differences

In `comparison_algorithms`, implementation A averaged [X] seconds over [N] runs ([t1], [t2], [t3]) and implementation B averaged [Y] seconds ([t1], [t2], [t3]). Implementation [A/B] is therefore about [ratio] times slower than [B/A].

In `instrumentation_lab`, the phases measured [BUILD] s (BUILD_DATA), [PROCESS] s (PROCESS) and [REDUCE] s (REDUCE), for a TOTAL of [TOTAL] s. The slowest phase was [phase], representing about [%] of TOTAL. [If some phases printed 0.000000, say so here.]

Between runs, times varied from [min] to [max] seconds, so small differences are not reliable.

## Relation Between Runtime and Energy Consumption

No energy was measured in this experiment: I only recorded execution times. I therefore cannot state how much energy any implementation used. The only supported statement is conditional: a program that runs longer on the same machine keeps the CPU busy longer, so implementation [slower one], at [Y] s versus [X] s, occupied the CPU about [ratio] times longer. Whether that translates into proportional energy use was not tested here.

## Limitations of the Experiment

First, `clock()` measures CPU time used by the process, not wall-clock time, and its resolution is limited. [With a dataset of 50,000 elements, phase times were very small (e.g. [value] s), so rounding to six decimals hides detail.]

Second, only [N] runs were made, which is too few for a statistical conclusion; run-to-run variation was [min]–[max] s.

Third, everything was measured at -O0 on one machine (WSL on Windows), so results may not hold with optimization enabled or on other hardware.

## Practical Engineering Takeaway

The measurements show that [slower implementation] cost about [ratio] times more CPU time than [faster one] for the same task, and that [phase] dominated the multi-phase program at [%] of TOTAL. In practice, this means measuring each phase separately before optimizing: the effort should go to the phase that the data show is slowest. Conclusions should also be backed by repeated runs, since the same program produced different times from one run to the next.
