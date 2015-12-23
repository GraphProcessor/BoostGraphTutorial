#ifndef CREATE_BUNDLED_EDGES_AND_VERTICES_MARKOV_CHAIN_H
#define CREATE_BUNDLED_EDGES_AND_VERTICES_MARKOV_CHAIN_H

#include <boost/graph/adjacency_list.hpp>
#include "my_bundled_edge.h"
#include "my_bundled_vertex.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::directedS,
  my_bundled_vertex,
  my_bundled_edge
>
create_bundled_edges_and_vertices_markov_chain() noexcept;

void create_bundled_edges_and_vertices_markov_chain_test() noexcept;

#endif // CREATE_BUNDLED_EDGES_AND_VERTICES_MARKOV_CHAIN_H
