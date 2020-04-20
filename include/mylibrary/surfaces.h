//
// Created by Ankitha Damisetty on 4/18/2020.
//
#include <vector>
#ifndef FINALPROJECT_SURFACES_H
#define FINALPROJECT_SURFACES_H

using namespace std;

namespace myapp {
class Surfaces{
  public:
    Surfaces();
    vector<vector<size_t>> GetSurface();
    void AddToSurfaces(vector<size_t>);
  private:
    vector<vector<size_t>> all_surfaces;
};
}
#endif //FINALPROJECT_SURFACES_H
