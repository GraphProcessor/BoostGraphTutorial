#include "create_bundled_edges_and_vertices_markov_chain.h"

#include "create_bundled_edges_and_vertices_markov_chain.impl"

#include "create_bundled_edges_and_vertices_markov_chain_demo.impl"

#include <cassert>
#include <iostream>
#include "convert_dot_to_svg.h"
#include "copy_file.h"


#include "get_edge_iterators.h"
#include "get_vertex_iterators.h"
#include "get_edge_descriptors.h"
#include "get_bundled_vertex_my_vertexes.h"
#include "get_bundled_edge_my_edges.h"
#include "get_vertex_descriptors.h"
#include "get_vertex_names.h"
#include "create_bundled_edges_and_vertices_markov_chain.h"
#include "create_bundled_edges_and_vertices_k3_graph.h"

#include "save_bundled_edges_and_vertices_graph_to_dot.h"

void create_bundled_edges_and_vertices_markov_chain_test() noexcept
{
  //Basic tests
  {
    const auto g = create_bundled_edges_and_vertices_markov_chain();
    assert(boost::num_vertices(g) == 2);
    assert(boost::num_edges(g) == 4);
    assert(boost::num_vertices(g) == 2);
    assert(boost::num_edges(g) == 4);
    const auto vip = get_vertex_iterators(g);
    assert(vip.first != vip.second);
    const auto vds = get_vertex_descriptors(g);
    assert(vds.size() == 2);
    const auto eip = get_edge_iterators(g);
    assert(eip.first != eip.second);
    const auto eds = get_edge_descriptors(g);
    assert(eds.size() == 4);
    const std::vector<my_bundled_vertex> vertex_my_bundled_vertexes{
      get_bundled_vertex_my_vertexes(g)
    };
    const std::vector<my_bundled_vertex> expected_my_bundled_vertexes{
      my_bundled_vertex("Sunny","Yellow thing",1.0,2.0),
      my_bundled_vertex("Rainy","Grey things",3.0,4.0)
    };
    assert(expected_my_bundled_vertexes == vertex_my_bundled_vertexes);

    const std::vector<my_bundled_edge> edge_my_edges{
      get_bundled_edge_my_edges(g)
    };
    const std::vector<my_bundled_edge> expected_my_edges{
      my_bundled_edge("Sometimes","20%",1.0,2.0),
      my_bundled_edge("Often","80%",3.0,4.0),
      my_bundled_edge("Rarely","10%",5.0,6.0),
      my_bundled_edge("Mostly","90%",7.0,8.0)
    };
    assert(edge_my_edges == edge_my_edges);

  }
  //Create the .dot and .svg of the 'create_bundled_edges_and_vertices_markov_chain' chapter
  {
    const auto g = create_bundled_edges_and_vertices_markov_chain();
    const std::string base_filename{"create_bundled_edges_and_vertices_markov_chain"};
    const std::string dot_filename{base_filename + ".dot"};
    const std::string svg_filename{base_filename + ".svg"};
    save_bundled_edges_and_vertices_graph_to_dot(g, dot_filename);
    convert_dot_to_svg(dot_filename, svg_filename);
    copy_file(
      dot_filename,
      "../BoostGraphTutorial/" + dot_filename,
      copy_file_mode::allow_overwrite
    );
    copy_file(
      svg_filename,
      "../BoostGraphTutorial/" + svg_filename,
      copy_file_mode::allow_overwrite
    );
  }

  create_bundled_edges_and_vertices_markov_chain_demo();
  std::cout << __func__ << ": OK" << '\n';
}
