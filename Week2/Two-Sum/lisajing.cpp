class node
{
    public:
        int number;
        int location;
        node *next;
        node():number(0),location(-1),next(NULL){}
        ~node(){}
};

bool compare(int a,int b)
{
    return a < b;
}
class Solution {
	public:
		    vector<int> twoSum(vector<int> &numbers, int target) 
			{
			    vector <int> index;
			    int size = numbers.size();
			    if(size <= 1)
			        return index;
			    node *Headnode,*p;
			    node *newnode= new node();
			    newnode -> number = numbers [0];
			    newnode -> location = 0;
			    newnode ->next = NULL;
			    Headnode = newnode;
			    p = Headnode;
			    for(int i = 1;i < size;i++)
			    {
			       node *newnode= new node();
			       newnode -> number = numbers [i];
			       newnode -> location = i;
			       newnode ->next = NULL;
			       p -> next = newnode;
			       p = p -> next;  
			    }
				p = Headnode;
			    sort(numbers.begin(),numbers.end(),compare);
			    int i = 0;
			    int j = size - 1;
			    while(i <= j)
			    {
				    if(numbers[i] + numbers[j] == target)
			        {
			            break;
			        }
			        else if(numbers[i] + numbers[j] < target)
			        {
			            i++;
			        }
			        else
			        {
			            j--;
			        }
			    }
			  int one = -1;
			  int another = -1;
			  while((Headnode != NULL )&&((one == -1)||(another == -1) )	)
			  {
			      if( (one == -1)&&(Headnode -> number == numbers[i]) )
			      {
			          one = Headnode -> location + 1;
			      }
				  else if((another == -1)&&(Headnode -> number == numbers[j]))
			      {
			          another = Headnode -> location + 1;
			      }
				  Headnode = Headnode ->next;
			  }
			  index.push_back(one < another ? one : another);
			  index.push_back(one >another ? one : another);
			 return index;
			}
			
};
