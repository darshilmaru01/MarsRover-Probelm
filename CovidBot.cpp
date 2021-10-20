#include<iostream>
#include<string>
using namespace std;

class CovidBot{

int x;
int y;
char orientation ;

public :
   CovidBot();
   CovidBot( int , int , char );
   void rotateLeft();
   void rotateRight();
   void movePosition();
   void displayPosition();
};    

CovidBot :: CovidBot()
{
   x=0;
   y=0;
   orientation = 'N';
}

CovidBot :: CovidBot ( int positionX , int positionY , char Orientation )
{
   x = positionX;
   y = positionY;
   orientation = Orientation ;
}

void CovidBot :: displayPosition()
{
   cout<<"Final Coordinates: "<<x<<" "<<y<<" "<<orientation;
}


void CovidBot :: rotateLeft()
{
   switch (orientation) { 
   case 'N': orientation = 'W'; break;
   case 'W': orientation = 'S'; break;
   case 'S': orientation = 'E'; break;
   case 'E': orientation = 'N'; break;}
}


void CovidBot :: rotateRight()
{
   switch (orientation) { 
   case 'N': orientation = 'E'; break;
   case 'W': orientation = 'N'; break;
   case 'S': orientation = 'W'; break;
   case 'E': orientation = 'S'; break;}
}


void CovidBot :: movePosition()
{
 if(orientation=='N')
   y++;   //Move North
 else if(orientation=='W')
   x--;   //Move East
 else if(orientation=='S')
   y--;   //Move South
 else if(orientation=='E')
   x++;   //Move West
}


int main()
{

   int x,x2,y,y2; 
   char orient;

   cout<<"Upper right: ";
   cin>>x2>>y2;

   cout<<"Enter Position of Bot: ";
   cin>>x>>y>>orient;

   if(x>x2 || y>y2 ){
      cout<<"Out of range!!!"<<endl;
      return 0;
   }
   
   CovidBot firstCovidBot(x,y,orient);

   string botMovement;
   cout<<"Enter Movement: ";
   cin>>botMovement;

   for(int i=0 ; i < botMovement.size() ; i++)
   {
      if(botMovement[i]=='L')
         firstCovidBot.rotateLeft();

      else if(botMovement[i]=='R')
         firstCovidBot.rotateRight();

      else
         firstCovidBot.movePosition();
   }
   
   firstCovidBot.displayPosition();

  return 0;
}