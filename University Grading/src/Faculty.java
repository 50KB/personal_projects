
public abstract class Faculty extends Person {
	
	public Faculty() {
		
	}
    public Faculty(String name,int age,String address) {
    	super(name,age,address);
	}
    
    public abstract void addCourses(Course newCourse);
    public abstract void printCourses();
    public abstract int getNumberOFCourses();
    public abstract double getSalary();
    public abstract Course[] getCourse();
    
    public String toString() {
    	return "FACULTY: "+ super.toString();
    }
	
		
	
    
}
