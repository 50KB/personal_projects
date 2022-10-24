package Source;

public class CricketPlayer {

    private String playerName, type;
    private int jerseyNumber, ranking; //creating instance variables
    private double salary;
    //constructor initialize the instance variables
    public CricketPlayer(String playerName, int jerseyNumber, double salary,String type,int ranking) {
        this.playerName = playerName;
        this.jerseyNumber = jerseyNumber;
        this.salary = salary;
        this.type=type;
        this.ranking=ranking;
    }

    public void setPlayerName(String playerName) {  //setter method
        this.playerName=playerName;//set the player name
    }

    public String getPlayerName() {//getter method
        return playerName;//return the player name
    }

    public void setjerseyNumber(int jerseyNumber) {//setter method
        this.jerseyNumber=jerseyNumber;//set the jersey number
    }

    public int getJerseyNumber() {//getter method
        return jerseyNumber;//return the player jersey number
    }

    public void setSalary(double salary) {//setter method
        this.salary=salary;//set the salary
    }

    public double getSalary() {//getter method
        return salary;//return the player salary
    }

    public void setType(String type) {//setter method
        this.type=type; //set the player type
    }

    public String getType() {//getter method
        return type;//return the player type
    }

    public void setRanking(int ranking) {//setter method
        this.ranking=ranking;//set the player ranking
    }

    public int getRanking() {//getter method
        return ranking;//return the player ranking
    }
}
