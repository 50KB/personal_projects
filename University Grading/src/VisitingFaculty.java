
public class VisitingFaculty extends Faculty {
	private final double  BASIC_SALARY = 4000.0;
    private Course[] courses=new Course[10];
    private int numberOfCourses;
    
    public VisitingFaculty() {
    	
    }
    public VisitingFaculty(String name,int age,String address) {
    	 super(name,age,address);
    }
    
    
	@Override
	public void addCourses(Course newCourse) {
		if(numberOfCourses<3) {
	         courses[numberOfCourses++] = newCourse;
	       }
	     else
		    System.out.println("cannot take anymore course");
		
	}
	
	
	@Override
	public void printCourses() {
		for(int i=0;i<numberOfCourses;i++) {
			System.out.println("Name of Course: "+courses[i].getNameOfCourse());
    		System.out.println("Course Code: "+courses[i].getCourseCode());
    		System.out.println();
    	}
		
	}
	
	
	@Override
	public Course[] getCourse() {
		return courses;
	}
	
	
	@Override
	public int getNumberOFCourses() {
		return numberOfCourses;
	}
	
	
	@Override
	public double getSalary() {
		return BASIC_SALARY+(((BASIC_SALARY*20)/100)*getNumberOFCourses());
	}
	
	
	public String toString() {
    	return super.toString()+"\nNumber Of Courses: "+getNumberOFCourses()+"\nSalary: "+getSalary()+"\n";
    }
	
}
