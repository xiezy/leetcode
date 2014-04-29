#include<iostream>
using namespace std;

 struct RandomListNode {
      int label;
      RandomListNode *next, *random;
      RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 };
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL)
            return NULL;
        else if (head->next == NULL)
        {
            RandomListNode *ret = new RandomListNode(head->label);
            if (head->random != NULL)
                ret->random = ret;
            return ret;
        }
        RandomListNode *ret = new RandomListNode(0);
        RandomListNode *tail = ret;
        RandomListNode *p = head;
        while (p!= NULL)
        {
            RandomListNode *tmp = p->next;
            RandomListNode *node = new RandomListNode(p->label);
            node->random = p;
            tail->next = node;
            tail = node;
            p->next = node;
            p = tmp;
        }
        p = head;
        tail = ret->next;
        while (tail!= NULL)
        {
            if (tail->random->random != NULL)
                tail->random = tail->random->random->next;
            else tail->random = NULL;
					  tail = tail->next;
//            p->next = tail->next->random;
				}
				return ret->next;
}

int main()
{
	RandomListNode *p = new RandomListNode(1), *tail = p;
  for (int i = 0; i < 5; ++i)
	{
		RandomListNode *node = new RandomListNode(i+2);
		tail->next = node;
		tail = node;
	}
	RandomListNode *copy = copyRandomList(p);
	while (copy!= NULL)
	{
		cout << copy->label << "->";
		copy = copy->next;
	}
	cout << endl;
}
