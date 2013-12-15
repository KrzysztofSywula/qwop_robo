module tummy()
{
  crack = 490;
  width = 761;
  side1 = 6000;
  side2 = width*2 + crack;
  side3 = 2700;
  thck = 100;      //1mm plastic thickness
  hole_dist=250; // distance between holes on sides layer
  hole_r=60;     //radius of metal-wire hole 
  servo_arm_thck = 160;
  cable_crack_x = 300;
  cable_crack_y = 792;
 
  difference() {	
    cube([side1,side2,side3]); //global cube
    translate([thck,thck,thck]) cube([side1-(thck*2), side2-(thck*2), side3-(thck*2)]); // remove all inside
    translate([thck,thck,side3-thck]) cube([side1-(thck*2), side2-(thck*2), thck]); //remove one wall
    translate([thck, side2/2 - crack/2, 0]) cube([160, crack, thck]); // left servo arm hole
    translate([side1-thck-servo_arm_thck, side2/2 - crack/2, 0]) cube([servo_arm_thck, crack, thck]); // right servo arm hole
    rotate([0, 90, 0]) translate([-(side3/2 -1.5*hole_dist), side2/2, 0]) 
    cylinder(h=thck+1, r=hole_r); //wire bottom hole
   rotate([0, 90, 0]) translate([-(side3/2 -0.5*hole_dist), side2/2, 0]) 
    cylinder(h=thck+1, r=hole_r); //wire top hole
  rotate([0, 90, 0]) translate([-(side3/2 -1.5*hole_dist), side2/2, side1-thck]) 
    cylinder(h=thck+1, r=hole_r); //wire bottom hole
  rotate([0, 90, 0]) translate([-(side3/2 -0.5*hole_dist), side2/2, side1-thck]) 
    cylinder(h=thck+1, r=hole_r); //wire top hole

    translate([side3-300-cable_crack_x, side2/2 - cable_crack_y/2, 0]) cube([cable_crack_x, cable_crack_y, thck]);
    translate([side1-(side3-300), side2/2 - cable_crack_y/2, 0]) cube([cable_crack_x, cable_crack_y, thck]);
  }
}

tummy();
