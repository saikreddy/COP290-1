#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>

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
			for (int t = s+1; t < pt.size(); ++t)
			{
				for (int a = 0; a < fe.size(); ++a)
				{
					bool l2 = false;
					if ((pt[s].x == fe[a].x1) && (pt[t].x == fe[a].x2) && (pt[s].y == fe[a].y1) && (pt[t].y == fe[a].y2))
					{
						ln.push_back(edge(pt[s].x,pt[s].y,pt[s].z, pt[t].x,pt[t].y,pt[t].z));
						break;
					}
					else
					{
						for (int b = 0; b < te.size(); ++b)
						{
							bool l3 = false;
							if ((pt[s].x == te[b].x1) && (pt[t].x == te[b].x2) && (pt[s].z == te[b].z1) && (pt[t].z == te[b].z2))
							{	
								l2 = true;
								ln.push_back(edge(pt[s].x,pt[s].y,pt[s].z, pt[t].x,pt[t].y,pt[t].z));
								break;
							}
							else
							{
								for (int c = 0; c < se.size(); ++c)
								{
									if ((pt[s].y == se[c].y1) && (pt[t].y == se[c].y2) && (pt[s].z == se[c].z1) && (pt[t].z == se[c].z2))
									{	
										l3 = true;
										ln.push_back(edge(pt[s].x,pt[s].y,pt[s].z, pt[t].x,pt[t].y,pt[t].z));
										break;
									}
								}
							}
							if (l3)
							{	
								//ln.push_back(edge(pt[s].x,pt[s].y,pt[s].z, pt[t].x,pt[t].y,pt[t].z));
								break;
							}						
						}
					}
					if (l2)
					{	
						//ln.push_back(edge(pt[s].x,pt[s].y,pt[s].z, pt[t].x,pt[t].y,pt[t].z));
						break;
					}
				}
			}
		}

		//-------------PRINT 3D VERTICES----------------
		cout<<"3D points"<<endl;
		for (int p = 0; p < pt.size(); ++p)
		{
			cout<<"(" <<pt[p].x <<"," <<pt[p].y <<"," <<pt[p].z <<")" <<endl;
		}

		//-------------- PRINT EDGE --------------------
		cout<<"edge"<<endl;
		cout<<ln.size()<<endl;
		for (int p = 0; p < ln.size(); ++p)
		{
			cout<<"(" <<ln[p].x1 <<"," <<ln[p].y1 <<"," <<ln[p].z1 <<")" <<" " <<"(" <<ln[p].x2 <<"," <<ln[p].y2<<"," <<ln[p].z2 <<")" <<endl;
		}
	

	}
	
};

//-------------------------------  3D to 2D --------------------------------------------------========================
//---------------------------------------------------------------------------------------------======================
class threedtotwod{
public:
	std::vector<vertex> vertices;
	std::vector<vertex> cf;
	std::vector<vertex> ct;
	std::vector<vertex> cs;

	std::vector<vertex> front_proj;
	std::vector<vertex> side_proj;
	std::vector<vertex> top_proj;

// // ----------------------- FRONT VIEW ---------------------
	void create_frontview (){
		for (int i = 0; i < vertices.size(); ++i)
		{
			cf.push_back(vertex(vertices[i].x, vertices[i].y, 0));
		}

		cout<<"Front View"<<endl;
		print_proj(front_proj, cf);
	}

//--------------- ----------- TOP VIEW ------------------------
	void create_topview (){
		for (int i = 0; i < vertices.size(); ++i)
		{
			ct.push_back(vertex(vertices[i].x, 0, vertices[i].y));
		}
		cout<<"Top View"<<endl;
		print_proj(top_proj, ct);
	}

//-------------------------- SIDE VIEW ----------------------
	void create_sideview (){
		for (int i = 0; i < vertices.size(); ++i)
		{
			cs.push_back(vertex(0, vertices[i].y, vertices[i].z));
		}
		cout<<"Side View"<<endl;
		print_proj(side_proj, cs);
	}

//------------------- PRINT PROJECTIOS -----------------
	void print_proj(vector<vertex> v_out, vector<vertex> v){
		v_out.push_back(vertex(v[0].x, v[0].y, v[0].z ));
		cout<<"(" <<v[0].x <<"," <<v[0].y <<"," <<v[0].z <<")" <<endl;
		for (int i = 1; i < v.size(); ++i)
		{
			bool t = true;
			for (int j = i-1; j >= 0; --j)
			{
				if ((v[j].x==v[i].x) && (v[j].y==v[i].y) && (v[j].z==v[i].z))
				{
					t = false;
				}
			}
			if (t==true)
			{
				v_out.push_back(vertex(v[i].x, v[i].y, v[i].z ));
				cout<<"(" <<v[i].x <<"," <<v[i].y <<"," <<v[i].z <<")" <<endl;
			}
		}
	}

};



int main()
{
	int i;

	cout<<"Press 1 for 2D to 3D"<<endl;
	cout<<"Press 2 for 3D to 2D"<<endl;
	cin>> i;

	if (i==1)
	{
		twodtothreed obj;

		std::ifstream infile("in2d.txt");
		std::string line;
		while (std::getline(infile, line))
		{
		    std::istringstream iss(line);
		    int a, b, c;
		    if (!(iss >> a >> b >> c)) { break; } // error

			obj.fv.push_back(vertex(a, b, c));		   
		}
		while (std::getline(infile, line))
		{
		    std::istringstream iss(line);
		    int a, b, c;
		    if (!(iss >> a >> b >> c)) { break; } // error

		    obj.tv.push_back(vertex(a, b, c));
		}

		while (std::getline(infile, line))
		{
		    std::istringstream iss(line);
		    int a, b, c;
		    if (!(iss >> a >> b >> c)) { break; } // error

		    obj.sv.push_back(vertex(a, b, c));
		}

		while (std::getline(infile, line))
		{
		    std::istringstream iss(line);
		    int a, b , c, d, e, f;
		    if (!(iss >> a >> b >> c >> d >> e >> f)) { break; } // error

		    obj.fe.push_back(edge(a, b, c, d, e, f));
		}

		while (std::getline(infile, line))
		{
		    std::istringstream iss(line);
		    int a, b , c, d, e, f;
		    if (!(iss >> a >> b >> c >> d >> e >> f)) { break; } // error

		    obj.te.push_back(edge(a, b, c, d, e, f));
		}

		while (std::getline(infile, line))
		{
		    std::istringstream iss(line);
		    int a, b , c, d, e, f;
		    if (!(iss >> a >> b >> c >> d >> e >> f)) { break; } // error

		    obj.se.push_back(edge(a, b, c, d, e, f));
		}

		obj.crete3D();
	}

	else if(i==2)
	{
		std::ifstream infile("in3d.txt");
		threedtotwod obj1;
		int x, y, z;
	 	while (infile >> x >> y >>z)
		{
			if (!(infile >> x >> y >> z)) { break; }
			obj1.vertices.push_back(vertex(x, y, z));
		}

		obj1.create_frontview();
		obj1.create_topview();
		obj1.create_sideview();	

	}

	else{cout<<"Please enter correct value"<<endl;}

		
}
