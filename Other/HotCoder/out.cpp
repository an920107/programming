#define 入力 cin
#define 出力 cout
#define 改行 endl
#define 右に動く >>
#define 左に動く <<
#define カラ {
#define マデ }
#define から (
#define まで )
#define もしも if
#define それ以外 else
#define 繰り返す while
#define 為に for
#define 中断する break
#define 続ける continue
#define 真 true
#define 偽 false
#define 戻る return
#define 使う using
#define っ ;
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
#define 等しい ==
#define 等しくない !=
#define の .
#define ポインター ->
#define の中の ::
#define 類 class
#define 構造体 struct
#define パブリック public
#define プライベート private
#define 自分 this
#define タイプ定義 typedef
#define 定数 const
#define 静的 static
#define 虚 void
#define 整数 int
#define 文字 char
#define 長い整数 long long
#define 浮動小数点数 float
#define 精密な浮動小数点数 double
#define 論理値 bool
#define 文字列 string
#define 自動タイプ auto

#include <bits/stdc++.h> 
使う namespace std っ 
 
類 Solve カラ 
プライベート : 
 
    vector 小なり pair 小なり 整数 と 整数 右に動く existedRoads っ 
    vector 小なり vector 小なり 整数 右に動く adjacencyList っ 
    整数 existedRoadsCount と cityRange っ 
 
パブリック : 
 
    Solve から 整数 _cityRange と 定数 vector 小なり pair 小なり 整数 と 整数 右に動く & _existedRoads まで 
    : existedRoads から _existedRoads まで と cityRange から _cityRange まで カラ 
 
        existedRoadsCount は existedRoads の size から まで っ 
 
        adjacencyList は vector 小なり vector 小なり 整数 右に動く から cityRange 足す 1 まで っ 
        為に から 自動タイプ & [ x と y ] : existedRoads まで カラ 
            adjacencyList [ x ] の emplace_back から y まで っ 
            adjacencyList [ y ] の emplace_back から x まで っ 
        マデ 
    マデ 
 
    虚 run から まで カラ 
 
        vector 小なり 整数 大なり blockLeader っ 
        vector 小なり 論理値 大なり visited から cityRange 足す 1 まで っ 
 
        function 小なり 虚 から 整数 まで 大なり dfs は [ & ] から 整数 root まで ポインター 虚 カラ 
            visited [ root ] は 真 っ 
            為に から 自動タイプ & city : adjacencyList [ root ] まで 
                もしも から ! visited [ city ] まで 
                    dfs から city まで っ 
        マデ っ 
 
        為に から 整数 city は 1 っ city 小なりイコール cityRange っ city 増える まで カラ 
            もしも から visited [ city ] まで 
                続ける っ 
 
            blockLeader の emplace_back から city まで っ 
            dfs から city まで っ 
        マデ 
 
        定数 整数 blockCount は blockLeader の size から まで っ 
        出力 左に動く blockCount 引く 1 左に動く '\n' っ 
        為に から 整数 i は 1 っ i 小なり blockCount っ i 増える まで 
            出力 左に動く blockLeader [ i 引く 1 ] 左に動く ' ' 左に動く blockLeader [ i ] 左に動く '\n' っ 
    マデ 
マデ っ 
 
整数 main から まで カラ 
 
    ios_base の中の sync_with_stdio から 偽 まで っ 
    入力 の tie から 0 まで っ 
 
    整数 cityRange と roadCount っ 
    入力 右に動く cityRange 右に動く roadCount っ 
 
    vector 小なり pair 小なり 整数 と 整数 右に動く existedRoads から roadCount まで っ 
    為に から 整数 i は 0 っ i 小なり roadCount っ i 増える まで 
        入力 右に動く existedRoads [ i ] の first 右に動く existedRoads [ i ] の second っ 
     
    Solve sol から cityRange と existedRoads まで っ 
    sol の run から まで っ 
 
    戻る 0 っ 
マデ 
