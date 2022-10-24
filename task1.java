
public class task1 {
    public static int throwDice(){
        return (int) (2 * Math.random());
    }

    public static int rollDie(){
        return (int) (6 * Math.random() + 1);
    }

    public static void main(String[] args) {
        int die, coin, s, point = -1, count = 1;

        while (true){
            die = rollDie();

            coin = throwDice();

            s = die + coin;

            System.out.println("The Die is " + die);
            System.out.println("The coin is " + coin);


            if(die == 6 && coin == 1 && count == 1){
                System.out.println("Player wins");
                break;
            }

            else if(die == 1 && coin == 0 && count == 1){
                System.out.println("Player loses");
                break;
            }

            else if(die == 1 && coin == 0 && count != 1){
                System.out.println("Player loses");
                break;
            }

            else if(die == 6 && coin == 1 && count != 1){
                System.out.println("Player loses");
                break;
            }

            else if(s == point){
                System.out.println("Player wins");
                break;
            }

            else {
                System.out.println("Point is " + s + ": Game Continued");
                point = s;
                count++;
            }
        }
    }
}
