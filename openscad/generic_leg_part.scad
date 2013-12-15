
module servo_stand(crack=410, width=761) {
  length = 388;   //length of 1 servo clip
  bar_height = 690; //height of the support bar
  height = 792;  //height of whole servo stand
  radius = 73;    //radius of hole
  tiny_bit_mount = 160;
  tiny_bit_size_w = 80;
  tiny_bit_size_h = 160;

  cube([length, width, height]); //left leg
  translate([0, width, tiny_bit_mount]) cube([length, tiny_bit_size_w, tiny_bit_size_h]);
  translate([0, width + crack, 0]) cube([length, width, height]); //right leg
  translate([0, width + crack - tiny_bit_size_w, tiny_bit_mount]) cube([length, tiny_bit_size_w, tiny_bit_size_h]);

  difference() { //bar
    translate([0, 0, height]) cube([length, 2*width + crack, bar_height]);
    translate([length/2, (2*width + crack)/2, height]) cylinder(h=bar_height, r=radius);
  }
}

module hip()
{
  crack = 490;
  width = 761;
  side1 = 2700;     //29mm side of whole thing servo size: 26.58mm
  side2 = width*2 + crack;
  side3 = 2700;
  thck = 100;      //1mm plastic thickness
  hole_dist=250; // distance between holes on bottom layer
  hole_r=60;     //radius of metal-wire hole
  screw_driver_r=160;
  
 
  difference() {	
    cube([side1,side2,side3]); //global cube
    translate([0,thck,thck]) cube([side1, side2-(thck*2), side3-(thck*2)]); // remove all inside
    translate([0,0,thck]) cube([side1, thck, side1-(thck*2)]); //remove one wall
    translate([side1/2 + 0.5*hole_dist, side2/2, 0]) cylinder(h=100, r=hole_r); //center hole
    translate([side1/2 - 1.5*hole_dist, side2/2, 0]) cylinder(h=100, r=hole_r); //left hole
    translate([side1/2 - 0.5*hole_dist, side2/2, 0]) cylinder(h=100, r=hole_r); //left hole
    translate([side1/2 + 1.5*hole_dist, side2/2, 0]) cylinder(h=100, r=hole_r); //right hole
    translate([0 + 60, side2/2, side3-thck]) cylinder(h=thck, r=screw_driver_r); //screw_driver hole
    translate([side1 - 60, side2/2, side3-thck]) cylinder(h=thck, r=screw_driver_r); //screw_driver hole
  }
  translate([ side1-388, 0, 100]) servo_stand(crack, width);
  translate([ 0, 0, 100]) servo_stand(crack, width);
}

//hip();
//servo_stand();
rotate([90, 180, 90]) hip(); //rotating to position it well on 3D printer
