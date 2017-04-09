#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
typedef unsigned char byte;

class world {
public:
    world( int x, int y ) : _wid( x ), _hei( y ) {
        int s = _wid * _hei * sizeof( byte );
        _cells = new byte[s];
        memset( _cells, 0, s );
    }
    ~world() {
        delete [] _cells;
    }
    int wid() const {
        return _wid;
    }
    int hei() const {
        return _hei;
    }
    byte at( int x, int y ) const {
        return _cells[x + y * _wid];
    }
    void set( int x, int y, byte c ) {
        _cells[x + y * _wid] = c;
    }
    void swap( world* w ) {
        memcpy( _cells, w->_cells, _wid * _hei * sizeof( byte ) );
    }
    int _wid, _hei;
    byte* _cells;
};
class rule {
public:
    rule( world* w ) : wrd( w ) {
        wid = wrd->wid();
        hei = wrd->hei();
        wrdT = new world( wid, hei );
    }
    ~rule() {
        if( wrdT ) delete wrdT;
    }
    bool hasLivingCells() {
        for( int y = 0; y < hei; y++ )
            for( int x = 0; x < wid; x++ )
                if( wrd->at( x, y ) ) return true;
        std::cout << "*** All cells are dead!!! ***\n\n";
        return false;
    }
    void swapWrds() {
        wrd->swap( wrdT );
    }
    void setRuleB( std::vector<int>& birth ) {
        _birth = birth;
    }
    void setRuleS( std::vector<int>& stay ) {
        _stay = stay;
    }
    void applyRules() {
        int n;
        for( int y = 0; y < hei; y++ ) {
            for( int x = 0; x < wid; x++ ) {
                n = neighbours( x, y );
                if( wrd->at( x, y ) ) {
                    wrdT->set( x, y, inStay( n ) ? 1 : 0 );
                } else {
                    wrdT->set( x, y, inBirth( n ) ? 1 : 0 );
                }
            }
        }
    }
private:
    int neighbours( int xx, int yy ) {
        int n = 0, nx, ny;
        for( int y = -1; y < 2; y++ ) {
            for( int x = -1; x < 2; x++ ) {
                if( !x && !y ) continue;
                nx = ( wid + xx + x ) % wid;
                ny = ( hei + yy + y ) % hei;
                n += wrd->at( nx, ny ) > 0 ? 1 : 0;
            }
        }
        return n;
    }
    bool inStay( int n ) {
        return( _stay.end() != find( _stay.begin(), _stay.end(), n ) );
    }
    bool inBirth( int n ) {
        return( _birth.end() != find( _birth.begin(), _birth.end(), n ) );
    }
    int wid, hei;
    world *wrd, *wrdT;
    std::vector<int> _stay, _birth;
};
class cellular {
public:
    cellular( int w, int h ) : rl( 0 ) {
        wrd = new world( w, h );
    }
    ~cellular() {
        if( rl ) delete rl;
        delete wrd;
    }
    void start( int r ) {
        rl = new rule( wrd );
        gen = 1;
        std::vector<int> t;
        switch( r ) {
            case 1: // conway
                t.push_back( 2 ); t.push_back( 3 ); rl->setRuleS( t );
                t.clear(); t.push_back( 3 ); rl->setRuleB( t );
                break;
            case 2: // amoeba
                t.push_back( 1 ); t.push_back( 3 ); t.push_back( 5 ); t.push_back( 8 ); rl->setRuleS( t );
                t.clear(); t.push_back( 3 ); t.push_back( 5 ); t.push_back( 7 ); rl->setRuleB( t );
                break;
            case 3: // life34
                t.push_back( 3 ); t.push_back( 4 ); rl->setRuleS( t );
                rl->setRuleB( t );
                break;
            case 4: // maze
                t.push_back( 1 ); t.push_back( 2 ); t.push_back( 3 ); t.push_back( 4 ); t.push_back( 5 ); rl->setRuleS( t );
                t.clear(); t.push_back( 3 ); rl->setRuleB( t );
                break;
        }

        /******************************************/
        generation();
    }

    void display() {
        system( "cls" );
        int wid = wrd->wid(),
            hei = wrd->hei();
        std::cout << "+" << std::string( wid, '-' ) << "+\n";
        for( int y = 0; y < hei; y++ ) {
            std::cout << "|";
            for( int x = 0; x < wid; x++ ) {
                if( wrd->at( x, y ) ) std::cout << "#";
                else std::cout << " ";
            }
            std::cout << "|\n";
        }
     std::cout << "+" << std::string( wid, '-' ) << "+\n";
    }

    byte getDataAt(int x, int y,byte* data,int _wid ){
      return data[x + y * _wid];
    }

       float comparePercentage(byte* data){
        float total=wrd->_hei*wrd->_wid;
        float similiarityCounter=0;

         for( int y = 0; y < wrd->hei(); y++ ) {
            for( int x = 0; x < wrd->wid(); x++ ) {
                if( wrd->at( x, y ) == getDataAt(x,y,data,wrd->_wid))
                    similiarityCounter++;
            }
        }
        return similiarityCounter/total;
    }

    private:
    void generation() {
        do {
            rl->applyRules();
            rl->swapWrds();
            gen++;
        }
        while ( rl->hasLivingCells() );
    }
    rule* rl;
    world* wrd;
    int gen;
};

