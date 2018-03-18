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
			for (int t = s+1; t < pt.size(); ++t)
			{
				for (int a = 0; a < fe.size(); ++a)
				{
					for (int b = 0; b < te.size(); ++b)
					{
						for (int c = 0; c < se.size(); ++c)
						{
							if (((pt[s].x == fe[a].x1) && (pt[t].x == fe[a].x2) && (pt[s].y == fe[a].y1) && (pt[t].y == fe[a].y2)) ||
							    ((pt[s].x == te[b].x1) && (pt[t].x == te[b].x2) && (pt[s].z == te[b].z1) && (pt[t].z == te[b].z2)) ||
							    ((pt[s].y == se[c].y1) && (pt[t].y == se[c].y2) && (pt[s].z == se[c].z1) && (pt[t].z == se[c].z2)) )
							{	
								ln.push_back(edge(pt[s].x,pt[s].y,pt[s].z, pt[t].x,pt[t].y,pt[t].z));
							}
						}
					}
				}
			}
		}

		//-------------------------------PRINT 3D VERTICES--------------------------------------
		cout<<"3D points"<<endl;
		for (int p = 0; p < pt.size(); ++p)
		{
			cout<<"(" <<pt[p].x <<"," <<pt[p].y <<"," <<pt[p].z <<")" <<endl;
		}

	
	 	//------------------------------- PRINT EDGE -------------------------------------------------------------------------

		// cout<<"Edges"<<endl;
 	// 	cout<<"(" <<ln[0].x1 <<"," <<ln[0].y1 <<"," <<ln[0].z1 <<")" <<" "<<"(" <<ln[0].x2 <<"," <<ln[0].y2 <<"," <<ln[0].z2 <<")" <<endl;
		// for (int i = 1; i < ln.size(); ++i)
		// {
		// 	bool t = true;
		// 	for (int j = i-1; j >= 0; --j)
		// 	{
		// 		if ((ln[j].x1==ln[i].x1) && (ln[j].y1==ln[i].y1) && (ln[j].z1==ln[i].z1) && (ln[j].x2==ln[i].x2) && (ln[j].y2==ln[i].y2) && (ln[j].z2==ln[i].z2))
		// 		{
		// 			t = false;
		// 		}
		// 	}
		// 	if (t==true)
		// 	{
		// 		cout<<"(" <<ln[i].x1 <<"," <<ln[i].y1 <<"," <<ln[i].z1 <<")" <<" " <<"(" <<ln[i].x2 <<"," <<ln[i].y2<<"," <<ln[i].z2 <<")" <<endl;
		// 	}
		// }
	}
	
};


class threedtotwod{
public:
	std::vector<vertex> vertices;
	std::vector<vertex> cf;
	std::vector<vertex> ct;
	std::vector<vertex> cs;

	std::vector<vertex> front_proj;
	std::vector<vertex> side_proj;
	std::vector<vertex> top_proj;



// ------------------------------------------FRONT VIEW ----------------------------------------------------------------------
	void create_frontview (){
		for (int i = 0; i < vertices.size(); ++i)
		{
			cf.push_back(vertex(vertices[i].x, vertices[i].y, 0));
		}

		cout<<"Front View"<<endl;
		print_proj(front_proj, cf);
	}

//------------------------------------------  TOP VIEW --------------------------------------------------------------
	void create_topview (){
		for (int i = 0; i < vertices.size(); ++i)
		{
			ct.push_back(vertex(vertices[i].x, 0, vertices[i].y));
		}
		cout<<"Top View"<<endl;
		print_proj(top_proj, ct);
	}

//-----------------------------------------  SIDE VIEW ---------------------------------------------------------------
	void create_sideview (){
		for (int i = 0; i < vertices.size(); ++i)
		{
			cs.push_back(vertex(0, vertices[i].y, vertices[i].z));
		}
		cout<<"Side View"<<endl;
		print_proj(side_proj, cs);
	}

//--------------------------------------- PRINT PROJECTIOS ------------------------------------------------------
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
	
	twodtothreed obj;
	threedtotwod obj1;
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
	obj.se.push_back(edge(0, 1, 2, 0, 2, 2));
	obj.se.push_back(edge(0, 2, 2, 0, 1, 1));

	obj.crete3D();

	obj1.vertices.push_back(vertex(1, 1, 1));
	obj1.vertices.push_back(vertex(1, 1, 2));
	obj1.vertices.push_back(vertex(1, 2, 1));
	obj1.vertices.push_back(vertex(2, 1, 1));
	obj1.vertices.push_back(vertex(1, 2, 2));
	obj1.vertices.push_back(vertex(2, 2, 1));
	obj1.vertices.push_back(vertex(2, 1, 2));
	obj1.vertices.push_back(vertex(2, 2, 2));

	obj1.create_frontview();
	obj1.create_topview();
	obj1.create_sideview();	


	return 0;
		
}
