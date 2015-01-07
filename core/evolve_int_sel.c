// Copyright 2011-2015 Ewerton Assis
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "evolve_rng.h"
#include "evolve_int_sel.h"

evolve_int_chrom_t **
evolve_int_tournament_selection (const evolve_int_pop_t *population,
                                 size_t tournament_size,
                                 size_t total_selection)
{
  size_t i, j;
  evolve_int_chrom_t *local_best;
  evolve_int_chrom_t **selection = (evolve_int_chrom_t **) calloc (total_selection, sizeof (evolve_int_chrom_t *));
  for (i = 0; i < total_selection; i++)
    {
      evolve_int_chrom_t **tournament = (evolve_int_chrom_t **) calloc (tournament_size, sizeof (evolve_int_chrom_t *));
      for (j = 0; j < tournament_size; j++)
        {
          size_t point = gsl_rng_uniform_int (rng, population->size - 1);
          tournament[j] = population->individuals[point];
        }
      local_best = tournament[0];
      for (j = 1; j < tournament_size; j++)
        if (tournament[j]->fitness > local_best->fitness)
          local_best = tournament[j];
      free (tournament);
      selection[i] = local_best;
    }
  return selection;
}

evolve_int_chrom_t **
evolve_int_roulette_wheel_selection (const evolve_int_pop_t *population,
                                     size_t total_selection)
{
  size_t i, j;
  double amount, roulette_value;
  double total_fitness = 0;
  evolve_int_chrom_t **selection = (evolve_int_chrom_t **) calloc (total_selection, sizeof (evolve_int_chrom_t *));
  for (i = 0; i < population->size; i++)
    total_fitness += population->individuals[i]->fitness;
  for (i = 0; i < total_selection; i++)
    {
      amount = 0;
      roulette_value = gsl_ran_flat (rng, 0, total_fitness);
      for (j = 0; j < population->size; j++)
        {
          amount += population->individuals[j]->fitness;
          if (amount >= roulette_value)
            break;
        }
      selection[i] = population->individuals[j];
    }
  return selection;
}
