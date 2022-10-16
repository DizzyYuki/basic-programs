#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> vec;
        int r=0;
        while(l1!=NULL || l2!=NULL){
            int sum=r;
            if(l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }
            if(sum>=10){
                r=1;
                sum=sum%10;
            }
            else{
                r=0;
            }
            vec.push_back(sum);
            
        }
        if(r==1){
            vec.push_back(r);
        }
        ListNode* head=new ListNode(0);
        ListNode* k=head;
        for(int i=0;i<vec.size();i++){
            ListNode* p=new ListNode(vec[i]);
            k->next=p;
            k=p;
        }
        return head->next;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}