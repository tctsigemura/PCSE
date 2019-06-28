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
 *  kernel/proc.h : プロセス管理関係の宣言
 *
 * 2011.05.20           : 新規作成
 *
 * $Id$
 *
 */

#define P_STKSIZ  100                // プロセスの標準スタックサイズ
#define P_LOW_PRI 30000              // プロセスの最低優先度

#define P_RUN     1                  // プロセスは実行可能または実行中
#define P_WAIT    2                  // プロセスは実行不可能

#define P_MAGIC  0xabcd              // スタックオーバーフロー検知に使用

// プロセスコントロールブロック(PCB or TCB)
struct PCB {
  int   sp;                          // プロセスのコンテキスト
                                     // (他のレジスタはスタックに置く)
  int   pid;                         // プロセス番号
  int   stat;                        // プロセスの状態
  int   nice;                        // プロセスの本来優先度
  int   enice;                       // プロセスの実質優先度

  // プロセスは重連結環状リストで管理
  PCB   prev;                        // PCB リスト(前へのポインタ)
  PCB   next;                        // PCB リスト(次へのポインタ)

  int   magic;                       // スタックオーバーフローを検知
};


// セマフォ
struct SEM {
  int   cnt;                         // カウンタ
  PCB   queue;                       // プロセスキュー
};

#define  SEM_MAX 30                  // セマフォは最大20個
#define  PRC_MAX 10                  // プロセスは最大10個

