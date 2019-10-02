/*
 * vgaWin/vgaWin.h
 *  VGA ディスプレイにウインドを作って管理する
 */

struct WIN {
  int     org;             // ウインドの左上端 VRAM 内アドレス
  int     ys;              // ウインドの縦長さ
  int     xs;              // ウインドの横長さ
  int     cy;              // カーソルの y 座標
  int     cx;              // カーソルの x 座標
  boolean sc;              // 次回、画面をスクロールする
  boolean cr;              // 次回、キャリッジリターンする

  // printf が使用するワーク領域
  int     putnum_w;        // 桁数
  int     putnum_b;        // 基数
  char    putnum_p;        // '0' か ' '
  boolean putnum_m;        // データは負だった
};

public WIN newWin(int y0, int x0, int ys, int xs);    // 新しいウインドを作る
public void wSetProp(WIN w, int y0, int x0, int ys, int xs); // 位置と大きさ変更
public void wPutc(WIN w, char c);                     // ウインドに文字を表示
public void wPuts(WIN w, char[] str);                 // ウインドに文字列を表示
public void wMove(WIN w, int y, int x);               // カーソル移動
public void wClear(WIN w);                            // ウインド消去
public int  wPrintf(WIN w, char[] fmt, ...);          // ウインド用の printf
