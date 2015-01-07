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

#ifndef __evolve_rng_h__
#define __evolve_rng_h__

#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

gsl_rng *rng;

void
evolve_set_rng (unsigned long int seed);

void
evolve_tear_rng ();

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __evolve_rng_h__
