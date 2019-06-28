/*
 * TaC-OS Source Code
 *    Tokuyama kousen Advanced educational Computer.
 *
 * Copyright (C) 2011 by
 *                      Dept. of Computer Science and Electronic Engineering,
 *                      Tokuyama College of Technology, JAPAN
 *
 *   上記著作権者は，Free Software Foundation によって公開されている GNU 一般公
 * 衆利用許諾契約書バージョン２に記述されている条件を満たす場合に限り，本ソース
 * コード(本ソースコードを改変したものを含む．以下同様)を使用・複製・改変・再配
 * 布することを無償で許諾する．
 *
 *   本ソースコードは＊全くの無保証＊で提供されるものである。上記著作権者および
 * 関連機関・個人は本ソースコードに関して，その適用可能性も含めて，いかなる保証
 * も行わない．また，本ソースコードの利用により直接的または間接的に生じたいかな
 * る損害に関しても，その責任を負わない．
 *
 *
 */

/*
 * fatFs/hdd.h : ハードディスクドライバの外部インタフェース
 *
 * 2011.05.23           : IPL-- をもとに新規作成
 *
 * $Id$
 *
 */

// hddInit : ハードディスクドライバの初期化
//   解説 
//        hddInit は、
//          (1) 割込みベクタの初期化
//          (2) 割込みルーチンとの同期用のセマフォの作成
//        を行う。
//
public void hddInit();

//
// hddRead : 指定セクタを読み出す
//   引数
//        labH : 論理セクタ番号(上位 16 ビット)
//        labL : 論理セクタ番号(下位 16 ビット)
//        buf  : データバッファ
//   解説 
//        hddRead は、labH、 labL で指定された１セクタを buf に読み出す。
//
public void hddRead(int labH, int labL, char[] buf);
