#include <iostream>
#include <vector>
#include <tuple>

using namespace std;


class vertex{
public:
	float x;
	float y;
	float z;

	//std::vector<vertex> v;

	vertex(float _x, float _y, float _z){
		x=_x; y=_y; z=_z;
	}

};

class edge{
public:
	float x1;
	float y1;
	float z1;
	float x2;
	float y2;
	float z2;	

 	//std::vector<edge> E;
	
 	edge(float _x1, float _y1, float _z1,float _x2, float _y2, float _z2){
 		x1=_x1; y1=_y1; z1=_z1;x2=_x2; y2=_y2; z2=_z2;	
 	}

};

class twodtothreed{
public:
	std::vector<vertex> fv;
	std::vector<vertex> tv;
	std::vector<vertex> sv;
	std::vector<edge> fe;
	std::vector<edge> te;
	std::vector<edge> se;
	
	std::vector<vertex> pt;
	std::vector<edge> ln;

	void crete3D(){
		for (int i = 0; i < fv.size(); ++i)
		{
			for (int j = 0; j < tv.size(); ++j)
			{
				for (int k = 0; k < sv.size(); ++k)
				{
					if (fv[i].x == tv[j].x)
					{
						if (tv[j].z == sv[k].z)
						{
							if (sv[k].y == fv[i].y)
							{
								pt.push_back(vertex(fv[i].x, sv[k].y, tv[j].z ));
							}
						}
					}
				}
			}
		}

		for (int s = 0; s < pt.size(); ++s)
		{
			for (int t = 0; t < pt.size(); ++t)
			{
				for (int a = 0; a < fe.size(); ++a)
				{
					for (int b = 0; b < te.size(); ++b)
					{
						for (int c = 0; c < se.size(); ++c)
						{
							if ((pt[s].x == fe[a].x1) && (pt[t] == fe[a].x2))
							{
								if ((pt[s].x == te[b].x1) && (pt[t] == te[b].x2))
								{
									if ((pt[s].x == se[c].x1) && (pt[t] == se[c].x2))
									{
										ln.push_back(edge(pt[s].x, pt[s].y, pt[s].z,pt[t].x, pt[t].y, pt[t].z ));
									}
								}
							}
						}
					}
				}
			}
		}

		cout<<"3D points"<<endl;
		for (int p = 0; p < pt.size(); ++p)
		{
			cout<<"(" <<pt[p].x <<"," <<pt[p].y <<"," <<pt[p].z <<")" <<endl;
		}

		//ln.push_back(edge(pt[0].x, pt[0].y, pt[0].z,pt[1].x, pt[1].y, pt[1].z));
	 	cout<<"Edges"<<endl;
		for (int q = 0; q < ln.size(); ++q)
		{
			cout<<"(" <<ln[q].x1 <<"," <<ln[q].y1 <<"," <<ln[q].z1 <<")"<<"(" <<ln[q].x2 <<"," <<ln[q].y2 <<"," <<ln[q].z2 <<")" <<endl;
		}
	}
	
};

/*
// class threedtotwod{
// public:

// 	std::vector<vertex> threeD_points;

// 	void create_frontview (std::vector<vertices> x){
		
// 	}

// 	void create_sideview (std::vector<vertices> x){
		
// 	}

// 	void create_topview (std::vector<vertices> x){
		
// 	}

// };
*/

int main()
{
	
	twodtothreed obj;
	obj.fv.push_back(vertex(1, 1, 0));
	obj.fv.push_back(vertex(1, 2, 0));
	obj.fv.push_back(vertex(2, 1, 0));
	obj.fv.push_back(vertex(2, 2, 0));

	obj.tv.push_back(vertex(1, 0, 1));
	obj.tv.push_back(vertex(1, 0, 2));
	obj.tv.push_back(vertex(2, 0, 1));
	obj.tv.push_back(vertex(2, 0, 2));

	obj.sv.push_back(vertex(0, 1, 1));
	obj.sv.push_back(vertex(0, 2, 1));
	obj.sv.push_back(vertex(0, 1, 2));
	obj.sv.push_back(vertex(0, 2, 2));

	obj.fe.push_back(edge(1, 1, 0, 1, 2, 0));
	obj.fe.push_back(edge(1, 2, 0, 2, 1, 0));
	obj.fe.push_back(edge(2, 1, 0, 2, 2, 0));
	obj.fe.push_back(edge(2, 2, 0, 1, 1, 0));

	obj.te.push_back(edge(1, 0, 1, 1, 0, 2));
	obj.te.push_back(edge(1, 0, 2, 2, 0, 1));
	obj.te.push_back(edge(2, 0, 1, 2, 0, 2));
	obj.te.push_back(edge(2, 0, 2, 1, 0, 1));

	obj.se.push_back(edge(0, 1, 1, 0, 2, 1));
	obj.se.push_back(edge(0, 2, 1, 0, 1, 2));
	obj.se.push_back(edge(0, 1, 2, 0, 1, 2));
	obj.se.push_back(edge(0, 2, 2, 0, 2, 2));

	obj.crete3D();
	return 0;
		
}
