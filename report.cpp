/**
 * Generate report for an integration test.
 *
 * Copyright (c) 2019, Sekhar Ravinutala.
 */

#include <algorithm>
#include <vector>
#include <cstdio>
#include "data/data.h"
#include "match/match.h"

#define GENDER(g) (g ? "Male" : "Female")

int main() {
  std::vector<Profile> up = profiles(10);

  // Sample print for illustration, replace with your code
  for (auto p : up) {
    printf("%-8d %s\n", p.id, GENDER(p.gender));
  }
}
