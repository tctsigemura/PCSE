/*
 * playerProc/mp3.h
 */

public void mp3Reset();                    // デコーダ LSI をリセット
public void mp3Flush();                    // デコーダ LSI のバッファをクリア
public void mp3Send(char[] buf, int len);  // デコーダ LSI にデータを送る
