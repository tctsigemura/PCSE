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
 * fatFs/dirEnt.h : ハードディスクドライバの外部インタフェース
 *
 * 2013.05.24           : コメントの修正(コメントに誤りがあった)
 * 2011.05.27           : 新規作成
 *
 * $Id$
 *
 */

#ifndef DIRENT_H

struct DIR {                             // ディレクトリを表すデータ構造
  char[] name;                           //   ファイル名("abcdef  .txt"形式)
  int    attr;                           //   属性(0x10ならディレクトリ)
  int    clst;                           //   先頭ラスタ番号
  int    lenH, lenL;                     //   ファイルサイズ(32bit)
};

#define DIRENT_H
#endif
