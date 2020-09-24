

public class Circle {  // Save as "Circle.java"
   // private instance variable, not accessible from outside this class
   private int radius;
   private int x,y;

   private static final float PI = 3.14;  // remember staic variable is of class
                                       // its memory is allocated for class level only and not for each object
                                       // final keword means constant value


   /* Three argument constructor which sets all field values. */
   public Circle(int x,int y,int r) {
      this.x=x;  // this keyword will help to manage ambiguity
      this.y=y;
      radius = r; // no need to manage ambiguity
   }




   /* No argument constructor which sets all field values to 0. This will call the 3 argument constructor */
   public Circle() {  // (default) constructor
      Circle(0,0,0);
   }

   /* Make a two argument constructor which sets x and y and radius= 0. This will also call the 3 argument constructor */
   public Circle(int x,int y) {
       Circle(x,y,0);
   }

   // Give code for a methods getX(), setX(),getY(), setY() [private methods],  getRadius() and setRadius() [public methods] .. which should return/set the corresponding field values.
   public int getX() {
     return x;
   }

   public int getY() {
     return y;
   }

   public int getRadius() {
     return radius;
   }

   public void setX(int x) {
     this.x=x;
   }

   public void setY(int y) {
     this.y=y;
   }

   public void setRadius(int r) {
     radius=r;
   }


   //Give code for setCenter(a,b) and printCenter() to set and print the coordinates of the center of the circle. Both these methods return nothing.
   public void setCenter(int a,int b) {
      x=a;
      y=b;
   }

   public void printCenter(int a,int b) {
      System.out.print("Center: ");
      System.out.print(x);
      System.out.print(" ");
      System.out.println(y);
   }

   //Give code for the translate (a,b) method to move circle to (x+a, y+b)
   public void translate(int a,int b) {
      x=x+a;
      y=y+b;
   }

   //Give code for the area() method which will return the area. Use the PI value as defined at the class level.
   public double area() {
      return radius*radius*pi;
   }
}
