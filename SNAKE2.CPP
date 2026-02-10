#include"n3.h"
#include <stdio.h>
int width =640;
int height =480;
int snakeLength=5;
int score = 0;
int snakeX[100], snakeY[100];
int foodX, foodY;
char direction;
void setup(){
    for(int i=0; i< snakeLength; i++){
       snakeX[i] = 100 -i * 10;
       snakeY[i] = 100;
       }
       direction = 'D';
       foodX =(rand() %(width / 10))*10;
       foodY = (rand() %(height / 10))*10;
   }

  void draw(){
   cleardevice();
char scoreText[20];
sprintf(scoreText, "Score: %d", score);
outtextxy(10, 10, scoreText);

for(int i = 0; i< snakeLength; i++){
     setcolor(WHITE);
   ellipse(snakeX[i] + 5, snakeY[i] + 5, 0 , 360, 5, 10);
   floodfill(snakeX[i] + 5, snakeY[i] + 5,WHITE);
   }
   ellipse(foodX + 5, foodY + 5 , 0 , 360 ,5 ,5);
   setfillstyle(SOLID_FILL,WHITE);
   floodfill(foodX + 5, foodY + 5, WHITE);
   delay(200);
 }

void input(){
if(kbhit()){
char key =getch();
if(key == 27){
exit(0);
}
switch (key){
case'1': direction ='U'; break;
case'2': direction ='D'; break;
case'3': direction ='L'; break;
case'4': direction ='R'; break;
    }
  }
}
void logic(){
int prevX = snakeX[0];
int prevY = snakeY[0];
int prev2X,prev2Y;

switch (direction){
case 'U': snakeY[0] -= 10; break;
case 'D': snakeY[0] += 10; break;
case 'L': snakeX[0] -= 10; break;
case 'R': snakeX[0] += 10; break;
}
for (int i=1; i< snakeLength; i++){
prev2X = snakeX[i];
prev2Y = snakeY[i];
snakeX[i] = prevX;
snakeY[i] = prevY;
prevX = prev2X;
prevY = prev2Y;
}
if(snakeX[0] == foodX && snakeY[0] == foodY){
snakeLength++;
score++;
foodX = (rand() % (width / 10))*10;
foodY = (rand() % (height / 10))*10;
}
if(snakeX[0] < 0 || snakeX[0] >= width || snakeY[0] < 0|| snakeY[0] >= height){
outtextxy(width /2 - 50, height / 2,"game over!");
delay(2000);
exit(0);
}
}
int main(){
int gd = DETECT,gm;
initgraph(&gd,&gm,"..\\bgi");
setup();
while(1){
draw();
input();
logic();
}
closegraph();
return 0;
}































