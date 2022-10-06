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
 
タイプ定義 構造体 time カラ 
    整数 month と day と hour と minute っ 
    time から まで カラ マデ 
    time から 文字列 & str まで カラ 
        文字 tmp っ 
        stringstream ss っ 
        ss 左に動く str っ 
        ss 右に動く month 右に動く tmp 右に動く day 右に動く tmp 右に動く hour 右に動く tmp 右に動く minute っ 
    マデ 
    friend 論理値 operator 小なり から 定数 time & x と 定数 time & y まで カラ 
        もしも から x の month 等しくない y の month まで 戻る x の month 小なり y の month っ 
        もしも から x の day 等しくない y の day まで 戻る x の day 小なり y の day っ 
        もしも から x の hour 等しくない y の hour まで 戻る x の hour 小なり y の hour っ 
        戻る x の minute 小なり y の minute っ 
    マデ 
マデ Time っ 
 
タイプ定義 構造体 record カラ 
    文字列 license っ 
    Time time っ 
    論理値 inOut っ 
    整数 loc っ 
    record から まで カラ マデ 
    record から 文字列 & line まで カラ 
        文字列 tmp っ 
        stringstream ss っ 
        ss 左に動く line っ 
        ss 右に動く license 右に動く tmp っ 
        time は Time から tmp まで っ 
        ss 右に動く tmp っ 
        inOut は から tmp 等しい "exit" まで っ 
        ss 右に動く loc っ 
    マデ 
マデ Record っ 
 
自動タイプ recordCmp は [ ] から 定数 Record & x と 定数 Record & y まで カラ 
    もしも から x の license 等しい y の license まで 戻る x の time 小なり y の time っ 
    戻る x の license 小なり y の license っ 
マデ っ 
 
虚 solve から 定数 整数 & t まで カラ 
    整数 price [ 24 ] っ 
    文字列 line っ 
    stringstream ss っ 
    vector 小なり Record 大なり data っ 
    map 小なり 文字列 と 整数 大なり result っ 
    getline から 入力 と line まで っ 
    ss 左に動く line っ 
    為に から 整数 i は 0 っ i 小なり 24 っ i 増える まで 
        ss 右に動く price [ i ] っ 
    繰り返す から getline から 入力 と line まで まで カラ 
        もしも から line 等しい "" まで 中断する っ 
        data の emplace_back から Record から line まで まで っ 
    マデ 
    sort から data の begin から まで と data の end から まで と recordCmp まで っ 
    為に から 自動タイプ iter は data の begin から まで っ iter 等しくない data の end から まで っ 増える iter まで カラ 
        自動タイプ last は iter 増える っ 
        もしも から iter 等しい data の end から まで まで 中断する っ 
        もしも から から 掛け算 last まで の license 等しくない から 掛け算 iter まで の license || から 掛け算 last まで の inOut 大なりイコール から 掛け算 iter まで の inOut まで カラ 
            減る iter っ 
            続ける っ 
        マデ 
        自動タイプ fd は result の find から から 掛け算 iter まで の license まで っ 
        整数 cost は price [ から 掛け算 last まで の time の hour ] 掛け算 abs から から 掛け算 iter まで の loc 引く から 掛け算 last まで の loc まで 足す 100 っ 
        もしも から fd 等しい result の end から まで まで 
            result の insert から make_pair から から 掛け算 iter まで の license と cost 足す 200 まで まで っ 
        それ以外 から 掛け算 fd まで の second 足される cost っ 
    マデ 
    為に から 自動タイプ & p : result まで 
        出力 左に動く p の first 左に動く " $" 左に動く p の second 割る 100 左に動く '.' 
            左に動く setw から 2 まで 左に動く setfill から '0' まで 左に動く p の second 残る 100 左に動く '\n' っ 
    もしも から t まで 出力 左に動く '\n' っ 
マデ 
 
整数 main から まで カラ 
 
    ios_base の中の sync_with_stdio から 偽 まで っ 
    入力 の tie から 0 まで っ 
 
    整数 t っ 
    文字列 tmp っ 
    入力 右に動く t っ 
    getline から 入力 と tmp まで っ 
    getline から 入力 と tmp まで っ 
    繰り返す から t 減る まで 
        solve から t まで っ 
    戻る 0 っ 
マデ 
