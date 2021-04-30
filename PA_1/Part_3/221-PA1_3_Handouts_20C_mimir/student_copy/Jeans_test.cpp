#include <iostream>
#include <fstream>
#include <sstream>
#include "Jeans.h"
#include "Collection.h"

using CollectionJN = Collection<Jeans, Jeans_colors, Jeans_sizes>;

istream& operator>>(istream& is, CollectionJN& c) {
    string color, size;
    Jeans_colors co;
    Jeans_sizes si;
    while(is >> color >> size){
        //input for color
        if (color == "white")
            co = Jeans_colors::white;
        else if (color == "blue")
            co = Jeans_colors::blue;
        else if (color == "grey")
            co = Jeans_colors::grey;
        else if (color == "black")
            co = Jeans_colors::black;
        else
            cout << "Error: invalid input of color, please check your input..." << endl;
        
        //input for size
        if (size == "small")
            si = Jeans_sizes::small;
        else if (size == "medium")
            si = Jeans_sizes::medium;
        else if (size == "large")
            si = Jeans_sizes::large;
        else if (size == "xlarge")
            si = Jeans_sizes::xlarge;
        else
            cout << "Error: invalid input of size, please check your input..." << endl;

        Jeans sb(co, si);
        c.insert_item(sb);
    }
    return is;
}

ostream& operator<<(ostream& os, const CollectionJN& c) {
    for (int i = 0; i < c.total_items(); i++) {
        os << "(";
        switch (c[i].get_color()) {
            case Jeans_colors::white:
                os << "white, ";
                break;
            case Jeans_colors::blue:
                os << "blue, ";
                break;
            case Jeans_colors::black:
                os << "black, ";
                break;          
            case Jeans_colors::grey:
                os << "grey, ";
                break;
        }
        switch (c[i].get_size()) {
            case Jeans_sizes::small:
                os << "small)" << endl;
                break;
            case Jeans_sizes::medium:
                os << "medium)" << endl;
                break;
            case Jeans_sizes::large:
                os << "large)" << endl;
                break;
            case Jeans_sizes::xlarge:
                os << "xlarge)" << endl;
                break;
        }
    }
    return os;
}

void test_jeans(){
        Jeans jeans_1 = Jeans(Jeans_colors::grey, Jeans_sizes::small);
        Jeans jeans_2 = Jeans(Jeans_colors::grey, Jeans_sizes::large);
        Jeans jeans_3 = Jeans(Jeans_colors::blue, Jeans_sizes::large);
        Jeans jeans_4 = Jeans(Jeans_colors::black, Jeans_sizes::medium);
        CollectionJN collection_0;
        CollectionJN collection_1;
        CollectionJN collection_2(3);
        CollectionJN collection_3(5);
        CollectionJN collection_file(1);
        collection_0.insert_item(jeans_1);
        collection_0.make_empty();
        collection_1.insert_item(jeans_1);
        collection_2.insert_item(jeans_2);
        
        collection_2.print_items();
        collection_2.insert_item(Jeans(Jeans_colors::blue, Jeans_sizes::small));
        collection_2.insert_item(jeans_3);
        collection_2.insert_item(jeans_3);
        CollectionJN collection_copy(collection_1);
        collection_1.insert_item(Jeans(Jeans_colors::black, Jeans_sizes::small));
        CollectionJN collection_7 = move(collection_1);
        collection_2.insert_item(Jeans(Jeans_colors::blue, Jeans_sizes::medium));
        collection_2.insert_item(Jeans(Jeans_colors::grey, Jeans_sizes::large));
        collection_2.insert_item(Jeans(Jeans_colors::grey, Jeans_sizes::large));
        collection_2.remove_this_item(jeans_2);
        
        collection_2.print_items();
        collection_copy.make_empty();
        if(collection_2.is_empty()){
            collection_2.insert_item(Jeans(Jeans_colors::black, Jeans_sizes::small));
        }
        ifstream ifs("jeans1.data");
        ifs >> collection_file;
        collection_file.insert_item(jeans_3);
        collection_file.insert_item(jeans_3);
        collection_2.insert_item(jeans_3);
        collection_2.insert_item(jeans_3);
        collection_2.insert_item(jeans_2);
        collection_2.insert_item(jeans_1);
        
        collection_file.print_items();
      
                    swap(collection_file,collection_2);
                    collection_3 = make_union(collection_file,collection_2);                
                     if((collection_3.total_items() - collection_2.total_items()) == collection_file.total_items()){
                          sort_by_size(collection_2,Sort_choice::selection_sort);
                          cout<<collection_3;
                     }
}
