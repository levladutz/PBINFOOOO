///IFTOEDE VLAD
#include <bits/stdc++.h>
using namespace std;
ifstream fin ( "lrx.in" );
ofstream fout ( "lrx.out" );
int n, ans, nri;
int a[1000000], b[1000000], dif[1000000];
struct diferenta
{
    int v, i;
    bool operator<( const diferenta &a )
    {
        if( a.v != v )
            return a.v > v;

        return a.i > i;
    }
} v[1000000];
struct interval
{
    int l, r;

};
bool operator<( const interval &a, const interval &b )
{
    if( a.l != b.l )
        return a.l > b.l;

    return a.r > b.r;
}
set<interval>m;
int ok( interval x )
{
    return x.l <= x.r;
}
int main()
{
    fin >> n;

    for ( int i = 1; i <= n; i++ )
        fin >> a[i];

    for ( int i = 1; i <= n; i++ )
        fin >> b[i];

    for ( int i = 1; i <= n; i++ )
        {
            dif[i] = b[i] - a[i];
            v[i].i = i;
            v[i].v = dif[i];
        }

    sort( v + 1, v + n + 1 );
    interval x;
    x.l = 1;
    x.r = n;
    m.insert( x );

    for ( int i = 1; i <= n; i++ )
        {
            int nri = m.size();
            ///aduni la raspuns cate intervale ai pana acum inmultite cu inaltimea de la cel anterior la cel actial
            ans += nri * ( v[i].v - v[i - 1].v );

            ///scot elementele j egale cu i din intervale
            do
                {
                    for( auto it : m )
                        {
                            if( it.l <= v[i].i && it.r >= v[i].i )
                                {
                                    interval s, d;
                                    //intervalul din stanga
                                    s.l = it.l;
                                    s.r = v[i].i - 1;
                                    //intervalul din dreapta
                                    d.l = v[i].i + 1;
                                    d.r = it.r;
                                    //sterg intervalul mare
                                    m.erase( m.find( it ) );

                                    //daca s valida
                                    if( ok( s ) )
                                        m.insert( s );

                                    //daca d valida
                                    if( ok( d ) )
                                        m.insert( d );
                                }
                        }

                    ///ma opresc cand urmatorul element nu mai e egal cu cel anterior
                    if( v[i].v != v[i + 1].v )
                        break;

                    i++;
                }
            while( true );
        }

    fout << ans;

    return 0;
}
