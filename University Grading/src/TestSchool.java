import java.util.ArrayList;
import java.util.Scanner;

public class TestSchool {
	

	public static void main(String[] args) {
		ArrayList<Student> s=new ArrayList<>();
		ArrayList<Course> c=new ArrayList<>();
		ArrayList<Faculty> f=new ArrayList<>();
	   
	   Course CSE115=new Course("Programming Language 1", "115");
	   Course CSE215=new  Course("Programming Language 2", "215");
	   Course CSE225=new Course("Data Structures and Algorithms", "225");
	   Course CSE231=new Course("DLD", "231");
	   Course CSE311=new Course("Database Management", "311");
	   Course CSE323=new Course("Operating Systems", "323");
	   Course CSE331=new Course("Microprocessors", "331");
	   Course CSE338=new Course("Computer Networking", "338");
	   Course CSE373=new Course("Design and Analysis of Algorithms", "373");
	   Course CSE419=new Course("Data Mining", "419");
	   c.add(CSE419);
	   c.add(CSE373);
	   c.add(CSE338);
	   c.add(CSE331);
	   c.add(CSE323);
	   c.add(CSE311);
	   c.add(CSE231);
	   c.add(CSE225);
	   c.add(CSE215);
	   c.add(CSE115);
	   PermanentFaculty p1=new PermanentFaculty("Sajid Mahmud",40,"Mirpur");
	   System.out.println(p1);
	   VisitingFaculty v1=new VisitingFaculty("Ahsanur Rahman", 48,"Bashundhara");
	   System.out.println(v1);
	   f.add(p1);
	   f.add(v1);
	   //adding Course
	   p1.addCourses(CSE115);
	   p1.addCourses(CSE215);
	   p1.addCourses(CSE225);
	   p1.addCourses(CSE231);
	   p1.addCourses(CSE311);
	   p1.addCourses(CSE323);
	   p1.addCourses(CSE331);
	   p1.addCourses(CSE338);
	   System.out.println();
	   System.out.println(p1);
	   p1.printCourses();
	   
	   
	   v1.addCourses(CSE338);
	   v1.addCourses(CSE373);
	   v1.addCourses(CSE419);
	   System.out.println();
	   System.out.println(v1);
	   v1.printCourses();
	   
	   
	   Student s1=new Student("David Miller", 23, "Mirpur", 3.10, "16112839234");
	   s1.addCourse(CSE115);
	   s1.addCourse(CSE215);
	   s1.addCourse(CSE225);
	   s1.addCourse(CSE231);
	   s1.addCourse(CSE311);
	   System.out.println();
	   System.out.println(s1);
	   s1.printCourses();
	   
	   
	   s1.addCourse(CSE323);
	   s1.addCourse(CSE331);
	   System.out.println();
	   System.out.println(s1);
	   s1.printCourses();
	   
	   
	   Student s2=new Student("Rihan", 24, "Dhanmondi,Dhaka-1207", 2.4, "1712184642");
	   s2.addCourse(CSE115);
	   s2.addCourse(CSE215);
	   s2.addCourse(CSE225);
	   s2.addCourse(CSE231);
	   s2.addCourse(CSE311);
	   System.out.println();
	   System.out.println(s2);
	   s2.printCourses();
	   
	   
	   Student s3=new Student("Shanto",22,"Rampura",3.4,"1812386042");
	   Student s4=new Student("Razib",24,"Banani",3.7,"1916376042");
	   s3.addCourse(CSE115);
	   s3.addCourse(CSE338);
	   s4.addCourse(CSE115);
	   s4.addCourse(CSE338);
	   s.add(s1);
	   s.add(s2);
	   s.add(s3);
	   s.add(s4);
	   
	   
	   
	   System.out.println("Students’ list for CSE215");
	 
	   for(int i = 0; i < s.size(); i++){
		   Course[] course= s.get(i).getCourse();
	       for(int j=0;j<s.get(i).getNumOfCourse();j++) {
	    	     if(course[j].getCourseCode().equals("215")) {
	    	    	System.out.println( s.get(i).getName());
	    	     }
	         }
	                   
	      }
	   System.out.println();
	   System.out.println("Students’ list for CSE338");
	  
	   for(int i = 0; i < s.size(); i++){
		   Course[] course= s.get(i).getCourse();
	       for(int j=0;j<s.get(i).getNumOfCourse();j++) {
	    	     if(course[j].getCourseCode().equals(CSE338.getCourseCode())) {
	    	    	System.out.println( s.get(i).getName());
	    	    }
	         }
	       }
	   
	   
	   System.out.println();
	   
	   
	   s4.Assigned();
	   System.out.println("Assigning the grade of "+s4.getName());
	   s4.setCgpaperSubject();
	   s4.Assigned();
	   System.out.println("Result of "+s4.getName());
	   for(int i = 0; i < s4.getNumOfCourse(); i++){
		   System.out.println(s4.getCgpaperSubject(i));
	   }
	   
	   s4.totalCgpa();
	   System.out.printf("Total CGPA of %s : %.2f",s4.getName(),s4.getCgpa());
	  
   }

}
