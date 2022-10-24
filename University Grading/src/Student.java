import java.util.ArrayList;
import java.util.Scanner;

public class Student extends Person implements AssignGrade {
    private double cgpa;
    private String id;
    private Course[] courses=new Course[10];
    private  int numberOfCourses;
    double cg;
    int b=0;
    ArrayList<Double> cglist = new ArrayList<>();
    Scanner input = new Scanner(System.in);
    
    public Student() {
    	
    }
    public Student(String name,int age,String address,double cgpa,String id) {
    	super(name,age,address);
    	this.cgpa=cgpa;
    	this.id=id;
    
    }
    
    
    public double getCgpa() {
    	return cgpa;
    }
    public void setCgpa(double cgpa) {
    	this.cgpa=cgpa;
    }
    
    
    
    public String getId() {
    	return id;
    }
    public void setId(String id) {
    	this.id=id;
    }
    
    
    
    
    public Course[] getCourse() {
    	return courses;
    }
    
    
    public int getNumOfCourse() {
    	return numberOfCourses; 
    }
    
    
    
    
    
    public void addCourse(Course newCourse) {
    	   if(getCgpa()>2.50) 
    	    {
    	         if(numberOfCourses<6) 
    	    	       courses[numberOfCourses++] = newCourse;
    			  else
    				   System.out.println("You are not allowed to take more than 6 courses");
    		  }
    	   if(getCgpa()<2.50) {
    		   if(numberOfCourses<4) 
	    	       courses[numberOfCourses++] = newCourse;
			 else
				   System.out.println("You are not allowed to take more than 4 courses");
		   }
    	}
    	
    
    
    
    
    public void printCourses() {
    	for(int i=0;i<numberOfCourses;i++) {
    		System.out.println("Name of Course: "+courses[i].getNameOfCourse());
    		System.out.println("Course Code: "+courses[i].getCourseCode());
    		System.out.println();
    	}
    }
    
  
    	
    
    
	@Override
	public void setCgpaperSubject() {
		System.out.println("Enter  CGPA(on a scale 4.0)");
		System.out.println("Mark\tGrade\tPoint \n93+\tA\t4.0 \n90-92\tA-\t3.7 \n87-89\tB+\t3.3 \n83-86\tB\t3.0 \n80-82\tB-\t2.7 \n77-89\tC+\t2.3 \n73-76\tC\t2.0 \n70-72\tC-\t1.7 \n67-69\tD+\t1.3 \n60-66\tD\t1.0 \n60-\tF\t0.0");
		double[] mark= {4.0,3.7,3.3,3.0,2.7,2.3,2.0,1.7,1.3,1.0,0.0};
		
		for(int i=0;i<numberOfCourses;)
		{
			boolean b=false;
			System.out.println("Course Code: "+courses[i].getCourseCode());
			System.out.print("CGPA:");
			double a=input.nextDouble();
			for(int j=0;j<mark.length;j++) 
			{
			   if(mark[j]==a)
			    {
				b=true;
			    }
		    }
			if(b==true)
			{
			i++;
			cglist.add(a);
			if(i==numberOfCourses)
				System.out.println("No more Courses");
			}
			else
				System.out.println("Enter a valid CGPA(on a scale 4.0)");
	   }	
	}
	
	
	
	
	@Override
	public void Assigned() {
		if(cglist.isEmpty())
			System.out.println(getName()+"'s "+"Geade not assigned");
		else
			System.out.println(getName()+"'s "+"Geade assigned");
	}
	
	
	
	
	
	@Override
	public double getCgpaperSubject(int index) {
		cglist.get(index);
		System.out.print("Course Code "+courses[index].getCourseCode()+": ");
		return cglist.get(index); 
	}
	
	
	
	
	
	@Override
	public void totalCgpa() {
		if(cglist.isEmpty()!=true)
		{
		for(int i=0;i<numberOfCourses;i++) {
			System.out.print("Enter credit for Course Code: "+courses[i].getCourseCode()+":");
			int a=input.nextInt();
			cg=cg+(cglist.get(i)*a);
			b = b+a;
		   }
		setCgpa(cg/b);
		}
		else
			System.out.println("Geade is not assigned yet");
	}
	
	
	public String toString() {
    	return "STUDENT : "+ super.toString()+"\nCGPA: "+cgpa+"\nID :"+id+"\n";
    }
}
