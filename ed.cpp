#include <iostream>
#include <vector>

using namespace std;


class vertex{
	float x;
	float y;
	float z;

	std::vector<vertex> v;

};

class edge{
	std::vector<vertex> v1;
	std::vector<vertex> v2;

	std::vector<edge> lines;

};


class projection{

	std::vector<vertex> frontview;

	std::vector<vertex> sideview;

	std::vector<vertex> topview;
};

class twodtothreed{
	projection front_view;
	projection side_view;
	projection top_view;

	void crete3D(projection x, projection y, projection z){
		
	}
};

class threedtotwod{

	std::vector<vertex> threeD_points;

	void create_frontview (std::vector<vertex> x){
		
	}

	void create_sideview (std::vector<vertex> x){
		
	}

	void create_topview (std::vector<vertex> x){
		
	}

};


int main()
{
	return 0;
}
