#include "create_named_edges_and_vertices_k3_graph.h"

#include "create_empty_named_edges_and_vertices_graph.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::undirectedS,
  boost::property<boost::vertex_name_t,std::string>,
  boost::property<boost::edge_name_t,std::string>
>
create_named_edges_and_vertices_k3_graph() noexcept
{
  auto g = create_empty_named_edges_and_vertices_graph();
  const auto vd_a = boost::add_vertex(g);
  const auto vd_b = boost::add_vertex(g);
  const auto vd_c = boost::add_vertex(g);
  const auto aer_ab = boost::add_edge(vd_a, vd_b, g);
  assert(aer_ab.second);
  const auto aer_bc = boost::add_edge(vd_b, vd_c, g);
  assert(aer_bc.second);
  const auto aer_ca = boost::add_edge(vd_c, vd_a, g);
  assert(aer_ca.second);

  //Add vertex names
  auto vertex_name_map = boost::get(boost::vertex_name,g);
  vertex_name_map[vd_a] = "top";
  vertex_name_map[vd_b] = "right";
  vertex_name_map[vd_c] = "left";

  //Add edge names
  auto edge_name_map = boost::get(boost::edge_name,g);
  edge_name_map[aer_ab.first] = "AB";
  edge_name_map[aer_bc.first] = "BC";
  edge_name_map[aer_ca.first] = "CA";

  return g;

}
