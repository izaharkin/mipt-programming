#include <iostream>
#include <memory>
#include <vector>

using std::make_unique;
using std::unique_ptr;
using std::make_pair;
using std::istream;
using std::vector;
using std::move;
using std::pair;
using std::cout;
using std::cin;

class Graph {
 public:
  Graph()
      : node_count_(0), edge_count_(0), edges_(0) {}
  Graph(Graph &&graph_to_move) {
    node_count_ = graph_to_move.node_count_;
    edge_count_ = graph_to_move.edge_count_;
    edges_ = move(graph_to_move.edges_);
  }
  // fabric method
  static unique_ptr<Graph> fromStream(istream &input_stream) {
    auto g = make_unique<Graph>();
    input_stream >> g.node_count_ >> g.edge_count_;
    return g;
  }
  size_t getNodeCount() const {
    return node_count_;
  }
  pair<vector<int>::const_iterator, vector<int>::const_iterator> getNodeList(int vertex_ind) const {
    return make_pair(edges_[vertex_ind].begin(), edges_[vertex_ind].end());
  }
 private:
  int node_count_;
  int edge_count_;
  vector<vector<int>> edges_;
};

class ITraverse {
 public:
  virtual void Run() = 0;
};

class DFS: public ITraverse {
 public:
  DFS(unique_ptr<Graph> pgraph, unique_ptr<IStat> pstat)
      : pgraph_(move(pgraph)), pstat_(move(pstat)) {}
  virtual void Run() override {
    vector<int> visited;
    pstat_->init(pgraph_->getNodeCount());
  }
 private:
  unique_ptr<Graph> pgraph_;
  unique_ptr<IStat> pstat_;

  void dfs(int v);
};

class BFS: public ITraverse {
 public:
  BFS(unique_ptr<Graph> pgraph, unique_ptr<IStat> pstat)
      : pgraph_(move(pgraph)), pstat_(move(pstat)) {}
  virtual void Run() override {
    vector<int> visited;
    pstat_->init(pgraph_->getNodeCount());
  }
 private:
  unique_ptr<Graph> pgraph_;
  unique_ptr<IStat> pstat_;

  void bfs(int v);
};

class IStat {
 public:
  virtual void init(int NodesSize);
  virtual void enterNode();
  virtual void exitNode();
  virtual void skipEdge();
};

class ComponentsStat : public IStat {
 public:
  void init(int nodesSize) override;
  virtual void enterNode() override {
    if (nodeStack.size() == 0) {
      components += 1;
      stack_size_ += 1;
    }
  }
 private:
  int stack_size_;
};

int getComponentCount() {
  int components;
  for (int i = 0; i < NodeCount; ++i) {
    if (visited[i] == true) {
      continue;
    } else {
      dfs(i);
    }
  }
  return components;
}

int main() {
  auto g = Graph::fromStream(cin);

  return 0;
}