#include<iostream>

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

    ListNode *partition(ListNode *head, int x) {
        ListNode *back = new ListNode(0);
        ListNode *front = new ListNode(0);
        ListNode *ret = front, *backhead = back;
        ListNode *p = head;
        while (p!= NULL)
        {
            if (p->val >= x)
            {
                back->next = p;
            p = p->next;
                back = back->next;
            }
            else
            {
                front->next = p;
            p = p->next;
                front = front->next;
            }
        }
        back->next = NULL;
        front->next = backhead->next;
        return ret->next;
    }

int main()
{
  ListNode *p = new ListNode(2);
  p->next = new ListNode(1);
  p = partition(p,2);
  while (p!= NULL)
  {
    std::cout << p->val << "->";
    p = p->next;
   }
  std::cout << std::endl;
}
