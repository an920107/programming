#define 入力 cin
#define 出力 cout
#define 右に動く >>
#define 左に動く <<
#define から {
#define まで }
#define もしも if
#define 他の else
#define 繰り返す while
#define 真 true
#define 偽 false
#define 戻る return
#define 使う using
#define 終わる ;
#define と ,
#define は =
#define 足す +
#define 引く -
#define 掛け算 *
#define 割る /
#define 残る %
#define 足される +=
#define 引かれる -=
#define かけられる *=
#define 割られる /=
#define 残られる %=
#define 増える ++
#define 減る --
#define 大なり >
#define 小なり <
#define 大なりイコール >=
#define 小なりイコール <=
#define イコール ==
#define 等しくない !=
#define ドット .
#define 虚 void
#define 整数 int
#define 浮動小数点数 float
#define 論理値 bool
#define 文字列 string

#include <bits/stdc++.h> 
使う namespace std 終わる 
 
vector 小なり 整数 大なり graph [ 26 ] 終わる 
論理値 visited [ 26 ] 終わる 
 
虚 dfs ( const 整数 & start ) から 
    visited [ start ] は 真 終わる 
    for ( 整数 point : graph [ start ] ) 
        もしも ( ! visited [ point ] ) 
            dfs ( point ) 終わる 
まで 
 
虚 solve ( const 整数 & t ) から 
    文字列 str 終わる 
    整数 result は 0 終わる 
    getline ( 入力 と str ) 終わる 
    整数 maxChar は str [ 0 ] 引く 'A' 終わる 
    繰り返す ( getline ( 入力 と str ) ) から 
        もしも ( str イコール "" ) break 終わる 
        const 整数 u は str [ 0 ] 引く 'A' と v は str [ 1 ] 引く 'A' 終わる 
        graph [ u ] ドット emplace_back ( v ) 終わる 
        graph [ v ] ドット emplace_back ( u ) 終わる 
    まで 
    for ( 整数 i は 0 終わる i 小なりイコール maxChar 終わる i 増える ) から 
        もしも ( ! visited [ i ] ) から 
            result 増える 終わる 
            dfs ( i ) 終わる 
        まで 
    まで 
    出力 左に動く result 左に動く ( t 大なり 0 ? "\n\n" : "\n" ) 終わる 
まで 
 
整数 main ( ) から 
    ios_base :: sync_with_stdio ( 偽 ) 終わる 
    入力 ドット tie ( 0 ) 終わる 
 
    文字列 str 終わる 
    整数 t 終わる 
    入力 右に動く t 終わる 
    getline ( 入力 と str ) 終わる 
    getline ( 入力 と str ) 終わる 
    繰り返す ( t 減る ) から 
        solve ( t ) 終わる 
    まで 
    戻る 0 終わる 
まで 
