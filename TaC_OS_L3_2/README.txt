TaC-OS 組込み版の使用例(TaC_OS_L3_2)の README ファイル

TaC_OS.L2 をベースにバックグラウンドで曲再生ができる、CLI MP3プレーヤを作った例
(TaC_OS.L2 にplayerProcを追加してある。)

  mp3.txt       : デコーダLSIの制御について
  tac_os.txt    : TaC_OS_L3_2のドキュメント

  GNUmakefile   : gmake 用の Makefile
  Makefile      : make 用の Makefile
  Makefile.rul  : サブディレクトリの Makefile からインクルードされる

  util          : C--のサポートルーチン
  vgaWin        : ディスプレイにウインドを定義し管理するモジュール
  kernel        : TaC-OS本体
  fatFs         : TaC-OS用のFAT16ファイルシステム・サーバプロセス

  kbdProc       : ユーザプロセスのサンプル(キーボードドライバを含む)
  lifeProc      : ユーザプロセスのサンプル(ライフゲーム)
  playerProc    : ユーザプロセスのサンプル(バックグランドで曲を再生)
