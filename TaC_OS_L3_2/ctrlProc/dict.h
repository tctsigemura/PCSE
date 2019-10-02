#define MAX_DICT_SIZE 64


struct Entry{
  char[] fileName;
  int    isdir;
  int    ismp3;
};


public int getDictLen();

public char[] getFileName(int i);
public int getIsdir(int i);

public void newDict(char[] path);
public void renewDict(char[] path);
public void shuffle();