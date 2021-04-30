#include <iostream>
#include <fstream>
#include <sstream>
#include "Stress_ball.h"
#include "Collection.h"

using CollectionSB = Collection<Stress_ball, Stress_ball_colors, Stress_ball_sizes>;

istream& operator>>(istream& is, CollectionSB& c);
ostream& operator<<(std::ostream& o, const Stress_ball& sb);
void test_stress_balls();