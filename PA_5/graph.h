#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <sstream>
#include <fstream>
#include <istream>
#include <string>


using namespace std;

//edits to this are likely not needed
template <class T>
struct Vertex {
  T label; // unique int for a vertex
  vector<T> adj_list;
  int indegree = 0; // Part 2: number of nodes pointing in
  int top_num; // Part 2: topological sorting number
  Vertex(T l) : label(l) {top_num = 0; label = l;} //Part 1
};

// optional, but probably helpful
template <class T>
ostream& operator<<(ostream &o, Vertex<T> v){
	// cout << v.label << "...";
	o << v.label << " : ";
	for (int i = 0; i < v.adj_list.size(); ++i)
		o << v.adj_list[i] << " ";
	o << endl;
	return o;
};


// syntax for custom compare functor
// template<class T>
// class VertexCompare
// {
// public:
//   bool operator()(Vertex<T> v1, Vertex<T> v2){
//     //todo - implement
//     return false;
//   }
// };

template <class T>
class Graph {
private:
  //c++ stl hash table
  unordered_map<T, Vertex<T>> node_set;
  std::vector<T> input_order;
  std::vector<Vertex<T>> out_node;
  //Use other data fields if needed
public:
  Graph() {
  	unordered_map<T, Vertex<T>> node_set;
  	this -> node_set = node_set;
  };  // default constructor
  ~Graph() {};
  // build a graph
  void buildGraph(istream &input){
  	string data;
  	while(getline(input, data)) { // !input.eof()
    	T label, adj;
  		stringstream stringin(data); 
  		stringin >> label;
      Vertex<T> node(label);
  		while(stringin >> adj)
  			node.adj_list.push_back(adj);
  		input_order.push_back(label); // testing
  		node_set.insert(std::make_pair(label, node));
  	}
  }

  // display the graph into o
  void displayGraph(ostream& o){
  	for (int i = 0; i < input_order.size(); ++i) {
  		o << node_set.at(input_order[i]);
  	}
  }

  //return the vertex at label, else throw any exception
  Vertex<T> at(T label){
  	if (node_set.find(label) == node_set.end()) throw runtime_error("Cannot find.");
  	return node_set.at(label);

  	// std::unordered_map<std::string,double>::const_iterator got = node_set.find (label);
	  // if (got == node_set.end()) throw runtime_error("Cannot find.");
	  // return *got;
  }

  //return the graph size (number verticies)
  int size(){
  	int count = 0;
  	for(auto& node: node_set)
  		count += 1;
  	return count;
  }

  // topological sort
  // return true if successful, false on failure (cycle)
  bool topological_sort() { 
  	queue<Vertex<T>> q;
    int counter = 0;
    for (auto& node : node_set) {
      if (node.second.indegree == 0)
        q.push(node.second);
    }

    while (!q.empty()) {
      Vertex<T> v = q.front();
      q.pop();
      v.top_num = ++counter;
      out_node.push_back(v);
      for(T la : v.adj_list)
        if (--node_set.at(la).indegree == 0) q.push(node_set.at(la));
    }
    if (counter != size()) return false;
    return true;
  };

  // find indegree
  void compute_indegree() {
    for(auto& node : node_set) {
      for (int i = 0; i < node.second.adj_list.size(); ++i)
        node_set.at(node.second.adj_list[i]).indegree++;
    }
  };


  // print topological sort into o
  //  if addNewline is true insert newline into stream
  void print_top_sort(ostream& o, bool addNewline=true) { 
    for (int i = 0; i < out_node.size(); ++i)
      o << out_node[i].label << " ";
    if(addNewline) o << '\n';
  }; // Part 2
};

#endif
