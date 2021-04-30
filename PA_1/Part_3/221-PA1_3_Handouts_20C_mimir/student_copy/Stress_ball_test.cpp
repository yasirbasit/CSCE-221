#include <iostream>
#include <fstream>
#include <sstream>
#include "Stress_ball.h"
#include "Collection.h"

using CollectionSB = Collection<Stress_ball, Stress_ball_colors, Stress_ball_sizes>;

istream& operator>>(istream& is, CollectionSB& c) {
    string color, size;
    Stress_ball_colors co;
    Stress_ball_sizes si;
    while(is >> color >> size){
        //input for color
        if (color == "red")
            co = Stress_ball_colors::red;
        else if (color == "blue")
            co = Stress_ball_colors::blue;
        else if (color == "green")
            co = Stress_ball_colors::green;
        else if (color == "yellow")
            co = Stress_ball_colors::yellow;
        else
            cout << "Error: invalid input of color, please check your input..." << endl;
        
        //input for size
        if (size == "small")
            si = Stress_ball_sizes::small;
        else if (size == "medium")
            si = Stress_ball_sizes::medium;
        else if (size == "large")
            si = Stress_ball_sizes::large;
        else
            cout << "Error: invalid input of size, please check your input..." << endl;

        Stress_ball sb(co, si);
        c.insert_item(sb);
    }
    return is;
}

ostream& operator<<(ostream& os, const CollectionSB& c) {
    for (int i = 0; i < c.total_items(); i++) {
        os << "(";
        switch (c[i].get_color()) {
            case Stress_ball_colors::red:
                os << "red, ";
                break;
            case Stress_ball_colors::blue:
                os << "blue, ";
                break;
            case Stress_ball_colors::yellow:
                os << "yellow, ";
                break;          
            case Stress_ball_colors::green:
                os << "green, ";
                break;
        }
        switch (c[i].get_size()) {
            case Stress_ball_sizes::small:
                os << "small)" << endl;
                break;
            case Stress_ball_sizes::medium:
                os << "medium)" << endl;
                break;
            case Stress_ball_sizes::large:
                os << "large)" << endl;
                break;
        }
    }
    return os;
}

void test_stress_balls(){
        Stress_ball stress_ball_1 = Stress_ball(Stress_ball_colors::blue, Stress_ball_sizes::large);
        Stress_ball stress_ball_2 = Stress_ball(Stress_ball_colors::yellow, Stress_ball_sizes::large);
        Stress_ball stress_ball_3 = Stress_ball(Stress_ball_colors::green, Stress_ball_sizes::small);
        Stress_ball stress_ball_4 = Stress_ball(Stress_ball_colors::red, Stress_ball_sizes::medium);
        CollectionSB collection_1;
        CollectionSB collection_2(3);
        CollectionSB collection_3(5);
        CollectionSB collection_file(1);
        collection_2.insert_item(stress_ball_2);
        collection_2.insert_item(stress_ball_4);
        collection_1.insert_item(stress_ball_1);
        collection_2.insert_item(stress_ball_2);
        collection_2.insert_item(Stress_ball(Stress_ball_colors::blue, Stress_ball_sizes::small));
        collection_2.insert_item(stress_ball_3);
        collection_2.insert_item(stress_ball_3);
        CollectionSB collection_4 = collection_1;
        CollectionSB collection_5(move(collection_4));
        collection_1.insert_item(Stress_ball(Stress_ball_colors::green, Stress_ball_sizes::small));
        collection_2.insert_item(Stress_ball(Stress_ball_colors::blue, Stress_ball_sizes::medium));
        collection_2.insert_item(Stress_ball(Stress_ball_colors::red, Stress_ball_sizes::large));
        collection_2.insert_item(Stress_ball(Stress_ball_colors::red, Stress_ball_sizes::large));
        collection_2.remove_this_item(stress_ball_2);        
        collection_2.print_items();
        ifstream ifs("stress_ball1.data");
        ifs >> collection_file;
        collection_file.insert_item(stress_ball_3);
        collection_file.insert_item(stress_ball_3);
        collection_2.insert_item(stress_ball_3);
        collection_2.insert_item(stress_ball_3);
        collection_2.insert_item(stress_ball_2);
        collection_2.insert_item(stress_ball_1);
        
        collection_file.print_items();
        collection_3 = make_union(collection_file,collection_2);
        if(collection_3.total_items() == (collection_file.total_items() + collection_2.total_items())){ 
                          sort_by_size(collection_2,Sort_choice::insertion_sort);                           
                          cout<<collection_3;
        }
}