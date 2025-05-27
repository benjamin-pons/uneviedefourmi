#ifndef ALGO_HPP
#define ALGO_HPP

#include <iostream>
#include <vector>
#include <windows.h>
#include <string>
#include "ants.hpp"
#include "node.hpp"

void printStepBar (int step);
void algorithm(std::vector<std::shared_ptr<Node>> anthill, std::vector<Ants> ants);

#endif