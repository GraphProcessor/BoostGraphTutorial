HEADERS += \
  bfs_name_printer.h \
  create_empty_graph.h \
  is_self_loop.h \
  get_n_vertices_test.h \
  print_trans_delay.h \
  print_trans_delays.h \
  print_vertex_name.h \
  print_vertex_names.h \
  get_n_edges.h \
  get_n_vertices.h \
    $$PWD/create_router_network.h \
    $$PWD/build_router_network.h \
    $$PWD/create_router_network_graph.h \
    create_k2_graph.h \
    get_n_edges_test.h \
    create_named_vertices_k2_graph.h \
    create_named_vertices_k2_graph_test.h \
    get_vertex_names.h \
    get_vertex_names_test.h \
    set_vertex_names.h \
    set_vertex_names_test.h



SOURCES += \
  bfs_name_printer.cpp \
  create_empty_graph.cpp \
  get_n_vertices_test.cpp \
    $$PWD/create_router_network.cpp \
    $$PWD/build_router_network.cpp \
    $$PWD/create_router_network_graph.cpp \
    create_empty_graph_test.cpp \
    create_router_network_graph_test.cpp \
    create_k2_graph.cpp \
    create_k2_graph_test.cpp \
    get_n_edges_test.cpp \
    create_named_vertices_k2_graph.cpp \
    create_named_vertices_k2_graph_test.cpp \
    get_vertex_names_test.cpp \
    print_vertex_names_test.cpp \
    print_vertex_name_test.cpp \
    print_trans_delay_test.cpp \
    print_trans_delays_test.cpp \
    is_self_loop_test.cpp \
    set_vertex_names_test.cpp
