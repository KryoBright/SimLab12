#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

class team
{
	private:
		int lambda=10*(rand()*1.0/RAND_MAX);
	public:
		bool isIn=true;
		
		int getScores()
		{
			int m=0;
			double S=0;
			while (S>=-lambda)
			{
				S+=log(rand()*1.0/RAND_MAX);
				m++;
			}
			return m;
		}
};

int main()
{
	srand(unsigned(time(0)));
	int teamCount;
	cout<<"Enter number of teams:"<<endl;
	cin>>teamCount;
	int teamsIn=teamCount;
	team *teams=new team[teamCount];
	int i=0;
	while (teamsIn!=1)
	{
        while(!teams[i].isIn)
		{	
			i=(i+1)%teamCount;
		}
		int home=i;
		i=(i+1)%teamCount;
		while(!teams[i].isIn)
		{	
			i=(i+1)%teamCount;
		}
		int opp=i;
		i++;
		cout<<endl<<"Team "<<home<<" vs Team "<<opp<<":";
		int score1=teams[home].getScores();
		int score2=teams[opp].getScores();
		cout<<endl<<score1<<" : "<<score2;
		if (score1>score2)
		{
			cout<<endl<<"Team "<<opp<<" out"<<endl;
			teams[opp].isIn=false;
		}
		else
		{
			cout<<endl<<"Team "<<home<<" out"<<endl;
			teams[home].isIn=false;
		}
		teamsIn--;
	}
	i=0;
	while (!teams[i].isIn)
	{
		i++;
	}
	cout<<endl<<"Team "<<i<<" wins tournament";
}
