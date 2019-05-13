#ifndef __assocTab_H__
#define __assocTab_H__
//DL distinguishing letters
class assocTabDL
{
friend class assocTabNDL;
public:
class node
  {
  	public:
	    node *next;
	    char *key;
	    int val;
	    node (const char *);
	    node (const node & );
	    ~node ();
  	private:			//assignment not allowed
    	node & operator= (const node &);
  };
  assocTabDL ();
  assocTabDL (const assocTabDL & );
  assocTabDL & operator= (const assocTabDL & );
  ~assocTabDL ();
  int &operator[] (const char *);
private:
  node *head;
  void insert (const char *, int );
  void clear ();
  virtual node *find (const char *) const;
  void swap (assocTabDL & );
};
//NDL not distinguishing letters
class assocTabNDL : public assocTabDL
{
friend class assocTabDL;
private:
		node *find (const char *) const;
};

#endif /* __assocTab_H__ */
