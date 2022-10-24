#include <iostream>
#include <vector>

using namespace std;

class node{
public :
    void status_visited(bool b);
    void update_connexions(vector<node> v);
    void set_numero(int n);
    void clean_co();
    int get_numero()
    {
        return numero;
    }
    bool get_visited()
    {
        return visited;
    }
    vector<node> get_connexions()
    {
        return connexions;
    }
    void add_connexions(node a)
    {
        connexions.push_back(a);
    }
private :
    int numero;
    bool visited;
    vector<node> connexions;
};

void node::set_numero(int n){
    //cout << "ok" << endl;
    numero=n;
    //cout << "ok" << endl;
}

void node::status_visited(bool b) {
    visited=b;
}

void node::update_connexions(vector<node> v){
    connexions.clear();
   for(size_t i=0;i<v.size();i++)
   {
       connexions.push_back(v[i]);
   }
}

bool proba(double p)
{
    if(p>1)
    {
        exit(0);
    }

    bool b(false);

    double r(0);
    r=rand()%1000;
    if(r<1000*p)
    {
        b=1;
    }
    return b;
}

void disp_graph(vector<node> graph)
{
    for(size_t i=0;i<graph.size();i++)
    {
        for(size_t j=0;j<graph[i].get_connexions().size();j++)
        {
            cout << graph[i].get_connexions()[j].get_numero() << " ";
        }
        cout << endl;
    }
}

void disp_co(vector<node> co)
{
    for(size_t i=0;i<co.size();i++)
    {
        cout << co[i].get_numero() <<" ";
    }
    cout << endl;
}

vector<node> create_graph(int n, double p)
{
    vector<node> graph(n);

    for(int i=0;i<n;i++)
    {
        graph[i].set_numero(i+1);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(proba(p)and(i!=j))
            {
                graph[i].add_connexions((graph[j]));
                graph[j].add_connexions((graph[i]));
            }
        }
    }

    disp_graph(graph);
    cout << endl;
    return graph;
}

void explore_depth(vector<node> graph,node n,vector<int>& done)
{
    if(done.size()==graph.size())
    {
        return;
    }

    int a(0);
    a=n.get_numero();

    done.push_back(a);

    for(size_t i=0;i<graph[a-1].get_connexions().size();i++)
    {
        bool b(1);
        for(size_t j=0;j<done.size();j++)
        {
            if(graph[a-1].get_connexions()[i].get_numero()==done[j])
            {
                b=0;
            }
        }

        if((!graph[a-1].get_connexions()[i].get_visited())and b)
        {
            explore_depth(graph,graph[a-1].get_connexions()[i],done);
        }
    }
}

bool connex_depth(vector<node> graph)
{
    vector<int> done(0);
    explore_depth(graph,graph[0],done);
    bool b(1);

    cout << endl << "Path followed : " << endl;
    for(size_t i=0;i<done.size();i++)
    {
        cout << done[i] << endl;
    }

    if(done.size()==graph.size())
    {
        b=1;
        cout << "connex" << endl;
        return b;
    }
    else
    {
        b=0;
        cout << "not connex" << endl;
        return b;
    }
}

void explore_amplitude(vector<node>& graph,vector<node>& done,int& i)
{
    if(done.size()==graph.size())
    {
        return;
    }

    int a(0);
    a=done[i].get_numero();
    i++;
    for(size_t i=0;i<graph[a-1].get_connexions().size();i++)
    {
        bool b(1);
        for(size_t j=0;j<done.size();j++)
        {
            if(graph[a-1].get_connexions()[i].get_numero()==done[j].get_numero())
            {
                b=0;
            }
        }

        if(b)
        {
            done.push_back(graph[a-1].get_connexions()[i]);
        }
    }
    if(i<done.size())
    {
        explore_amplitude(graph,done,i);
    }

}

bool connex_amplitude(vector<node> graph)
{
    bool b(0);
    int i(0);
    vector<node> done(0);
    done.push_back(graph[0]);
    explore_amplitude(graph,done,i);

    cout << endl << "Path followed : " << endl;
    for(size_t i=0;i<done.size();i++)
    {
        cout << done[i].get_numero() << endl;
    }

    if(done.size()==graph.size())
    {
        b=1;
        cout << "connex" << endl;
        return b;
    }
    else
    {
        b=0;
        cout << "not connex" << endl;
        return b;
    }
}

int main()
{
    double p(0);
    int n(0);
    cout << "Enter the size of the graph : " << endl;
    cin >> n;
    cout <<"Enter the probability (between 0 and 1) : " << endl;
    cin>>p;
    // Utilizar una de las dos lienas siguientes
    connex_amplitude(create_graph(n,p));
    connex_depth((create_graph(n,p)));
}

/* We observe that with n=10, the probability of having a connex graph is high for p>0.5 and is low for p<0.2
 *
 * Con un grafo dirigido seria mucho menos probable que encontremos un camino que pasa por todos los nodos*/