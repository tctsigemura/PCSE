#define MAX_DICT_SIZE 32


struct Entry{
  char[] fileName;
  int    isdir;
};


public int getDictLen();

public char[] getFileName(int i);
public int getIsdir(int i);

public void newDict(char[] path);
public void renewDict(char[] path);