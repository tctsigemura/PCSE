; 
;  TaC-OS Source Code
;     Tokuyama kousen Advanced educational Computer.
; 
;  Copyright (C) 2011 by
;                       Dept. of Computer Science and Electronic Engineering,
;                       Tokuyama College of Technology, JAPAN
; 
;    上記著作権者は，Free Software Foundation によって公開されている GNU 一般公
;  衆利用許諾契約書バージョン２に記述されている条件を満たす場合に限り，本ソース
;  コード(本ソースコードを改変したものを含む．以下同様)を使用・複製・改変・再配
;  布することを無償で許諾する．
; 
;    本ソースコードは＊全くの無保証＊で提供されるものである。上記著作権者および
;  関連機関・個人は本ソースコードに関して，その適用可能性も含めて，いかなる保証
;  も行わない．また，本ソースコードの利用により直接的または間接的に生じたいかな
;  る損害に関しても，その責任を負わない．
; 
; 

; 
;  kernel/kernAsm.s : TaC-OS のアセンブリ言語部分
; 
;  2011.05.20           : 新規作成
; 
;  $Id$
; 

_setPri                         ; プロセッサの割り込みレベルを変更
	ld	g0,1,sp		; 引数の値を G0 に取り出す
	push	g0              ; 新しい状態をスタックに積み
	ld	g0,flag		; 古いフラグの値を返す準備をする
	reti                    ; reti は flag と PC を同時に pop する

_dispatch
	push	flag		; 割り込み許可状態を保存する
	push	fp		; フレームポインタ
	push	g6		; 以下で保存するのは
	push	g7		;  C-- のレジスタ変数だけ。
	push	g8		; _dispatch が C-- から呼び出される
	push	g9		;  前提で考えている。
	push	g10		; C-- のバージョンその他に依存しているので
	push	g11		;  要注意部分！！！
	ld	g1,_curProc	; dispatch を呼出したプロセスの PCB
	st	sp,0,g1		; SP 保存領域にストア

_startProc
	call	_selProc	; C-- で記述された次のプロセス選択ルーチン
	ld	g1,_curProc	; 次に実行するプロセス
	ld	sp,0,g1		; PCB から SP を取り出す
	pop	g11		;
	pop	g10		; レジスタ変数を復元する
	pop	g9		; この部分も C-- のバージョン、その他に
	pop	g8		;   依存しているので
	pop	g7		;     要注意部分！！！
	pop	g6		;
	pop	fp		; フレームポインタ復元
	reti			; フラグと PC を復元
	
