float base = 50;
float armL1 = 50;
float armL2 = 50;
float stick = 0;
float angle0 = 0;
float angle1 = 0;
float angle2 = 0;
float targetangle0 = 0;
float targetangle1 = 0;
float matox = 0;
float matoz = 0;
float i = 0;
float k = 0;


void setup(){
  size(1200, 800, P3D);
  noStroke();  
}

void draw(){
    camera(mouseX, 100, mouseY, 0, 100, 0, 0, 0, -1);
  
  background(255);
  
  
  
  if(keyPressed){
    
    if(key == 'a'){
      matox = random(-50, 50);
      matoz = random(-50, 50);
      
      targetangle1 = asin(matoz/armL1);
      targetangle0 = asin(-matox/(base+armL1*cos(targetangle1)));
    }
    
    
      if(key == 's'){
        i=i+1;
              if( i < 100){
      angle1 = (degrees(targetangle1))*i/100;
      angle0 = (degrees(targetangle0))*i/100;
              }
    }
    
    if(key == 'p'){
      k=k+1;
              if( k < 100){
      stick = (200 - armL2-cos(radians(angle0))*(base+armL1*cos(radians(angle1))))*k/100;
              }
    }
    
      if(key == 'r'){
      angle0 = 0;
      angle1 = 0;
      matox = 0;
      matoz = 0;
      stick = 0;
      i =0;
      k = 0;
    }

      
  }
      
  
  //mato
  pushMatrix();
  translate(matox, 200, matoz);
  fill(255, 0, 0);
  box(10, 10, 10);
  popMatrix();
  
  pushMatrix();
  //base
  rotateZ(radians(angle0));
  translate(0,base/2,0);
  fill(175);
  box(10,base, 10);
  
  //1st link
  translate(0, base/2, 0);
  rotateX(radians(angle1));
  translate(0, armL1/2, 0);
  fill(150);
  box(10, armL1, 10);
  popMatrix();
  
  //2nd link
  translate(-sin(radians(angle0))*base-sin(radians(angle0))*cos(radians(angle1))*armL1, cos(radians(angle0))*base+cos(radians(angle0))*cos(radians(angle1))*armL1, sin(radians(angle1))*armL1);
  rotateZ(radians(angle2));  
  translate(0, armL2/2, 0);
  fill(125);
  box(10, armL2, 10);
  
  //stick
  translate(0, armL2/2+stick/2, 0);
  fill(0);
  box(5,stick, 5);

}
