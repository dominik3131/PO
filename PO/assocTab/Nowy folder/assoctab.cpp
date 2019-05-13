#include <iostream>
#include <ctype.h>
#include <string.h>
using namespace std;
#include "assoctab.h"

//node
assocTabDL::node::node(const char *k):next (NULL)
{
	key = new char[strlen (k) + 1];
	strcpy (key, k);
};
assocTabDL::node::~node()
{
	delete[]key;
}
assocTabDL::node::node(const node & s):next (NULL)
{
	if (s.key == NULL)
		key = NULL;
	else
	{
		key = new char[strlen (s.key) + 1];
	    strcpy (key, s.key);
	}
	val=s.val;
};

//list
assocTabDL::assocTabDL()
{
  head = NULL;
}

assocTabDL::assocTabDL(const assocTabDL & l)
{
  node *src, **dst;
  head = NULL;
  src = l.head;
  dst = &head;
  try
  {
    while (src)
      {
		*dst = new node (*src);
		src = src->next;
		dst = &((*dst)->next);
      }
  }
  catch (...)//any error with new node above
  {
    clear ();
    throw;
  };
}

assocTabDL::~assocTabDL()
{
  clear ();
}

void assocTabDL::clear()
{
  while (head)
    {
      node *t = head->next;
      delete head;
      head = t;
    };
}

void assocTabDL::insert(const char *key, int value)
{
  node *nowy = new node (key);
  nowy->next = head;
  head = nowy;
  head->val = value;
}

void assocTabDL::swap (assocTabDL & l)
{
  node *t = head;
  head = l.head;
  l.head = t;
}

assocTabDL & assocTabDL::operator= (const assocTabDL & l)
{
  if (&l == this)
    return *this;
  assocTabDL t (l);
  swap (t);
  return *this;
}

assocTabDL::node * assocTabDL::find (const char *key) const
{
  node * c = head;
  while (c)
    {
      if (!strcmp (c->key, key))
	return c;
      c = c->next;
    };
  return NULL;
}

int & assocTabDL::operator[] (const char *key)
{
  node *c = find (key);
  if (!c)
    {
      insert (key, 0);
      c = head;
    };
  return c->val;
}
//<----------------------------------------------------------->
assocTabNDL::node * assocTabNDL::find ( char *key) const
{toLowerCase(key);
  assocTabDL::find(key);
}

void assocTabNDL::insert( char *key, int value)
{toLowerCase(key);
	assocTabDL::insert(key,value);
}
void assocTabNDL::toLowerCase( char* key) const
{	
	
	for (int i = 0; i < sizeof(key); i++)
		key[i] = tolower(key[i]);

}
