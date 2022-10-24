package Source;

import javafx.application.Application;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.Modality;
import javafx.stage.Stage;

import java.util.ArrayList;

public class GUI extends Application {//GUI extend application class
    ArrayList<CricketPlayer> cricketPlayers = new ArrayList<>();//Declaring array to store the data of players
    Stage window = new Stage();//primary stage

    public static void main(String[] args) {
        launch();
    }

    @Override
    public void start(Stage stage) throws Exception {
        window.setTitle("Cricket Player Database");
        window.setScene(roasterScene());
                                //showing the primary stage
        window.show();
    }
    //1st scene which contain table and the button
    public Scene roasterScene(){
        TableColumn<CricketPlayer, String> nameColumn=new TableColumn<>("Player Name");//add a column on table
        nameColumn.setMinWidth(200);//column size
        nameColumn.setCellValueFactory(new PropertyValueFactory<>("playerName"));//adding data to table  column

        TableColumn<CricketPlayer,Integer> jerseyColumn=new TableColumn<>("Jersey");//add a column on table
        jerseyColumn.setMinWidth(100);//column size
        jerseyColumn.setCellValueFactory(new PropertyValueFactory<>("jerseyNumber"));//adding data to table  column

        TableColumn<CricketPlayer,Double> salaryColumn=new TableColumn<>("Salary");//add a column on table
        salaryColumn.setMinWidth(100);//column size
        salaryColumn.setCellValueFactory(new PropertyValueFactory<>("salary"));//adding data to table  column

        TableColumn<CricketPlayer,String> typeColumn=new TableColumn<>("Position");//add a column on table
        typeColumn.setMinWidth(100);//column size
        typeColumn.setCellValueFactory(new PropertyValueFactory<>("type"));//adding data to table  column

        TableColumn<CricketPlayer,Integer> rankColumn=new TableColumn<>("ICC Ranking");//add a column on table
        rankColumn.setMinWidth(100);//column size
        rankColumn.setCellValueFactory(new PropertyValueFactory<>("ranking"));//adding data to table  column

        TableView table= new TableView<>();//load table
        table.getColumns().addAll(nameColumn,jerseyColumn,salaryColumn,typeColumn,rankColumn);//add column on the table

        Button add = new Button("Add");//creating add button object
        add.setPrefWidth(70);//setting button size
        Button remove = new Button("Remove");//creating remove button object
        remove.setPrefWidth(70);//setting button size
        Button show = new Button("Show");//creating show button object
        show.setPrefWidth(70);//setting button size

        add.setOnAction(e-> {
            addPlayer();      //setting the action of add player button
        });

        remove.setOnAction(e-> {
            removePlayer();    //setting the action of remove player button
        });

        show.setOnAction(e-> {
            window.setScene(showScene()); ////setting the action of show button
        });

        VBox vBox = new VBox();
        vBox.getChildren().addAll(add, new Label(), remove, new Label(), show);//add buttons in VBox pane

        HBox hBox = new HBox();
        hBox.getChildren().addAll(new Label("       "), vBox, new Label("       "), table);//adding table and buttons in the HBox pane

        Scene scene = new Scene(hBox, 720,600);//adding the HBox pane on the scene

        return scene;
    }

    public ObservableList<CricketPlayer> getPlayer(){//loading the cricketPlayer array from cricketPlayer class
        ObservableList<CricketPlayer> list= FXCollections.observableArrayList();
        for(int i=0;i<cricketPlayers.size();i++) {
            list.add(cricketPlayers.get(i));
        }
        return list;
    }
    //showing the table with player data
    public Scene showScene(){
        TableColumn<CricketPlayer, String> nameColumn=new TableColumn<>("Player Name");//add a column on table
        nameColumn.setMinWidth(200);//column size
        nameColumn.setCellValueFactory(new PropertyValueFactory<>("playerName"));//adding data to table  column

        TableColumn<CricketPlayer,Integer> jerseyColumn=new TableColumn<>("Jersey");//add a column on table
        jerseyColumn.setMinWidth(100);//column size
        jerseyColumn.setCellValueFactory(new PropertyValueFactory<>("jerseyNumber"));//adding data to table  column

        TableColumn<CricketPlayer,Double> salaryColumn=new TableColumn<>("Salary");//add a column on table
        salaryColumn.setMinWidth(100);//column size
        salaryColumn.setCellValueFactory(new PropertyValueFactory<>("salary"));//adding data to table  column

        TableColumn<CricketPlayer,String> typeColumn=new TableColumn<>("Position");//add a column on table
        typeColumn.setMinWidth(100);//column size
        typeColumn.setCellValueFactory(new PropertyValueFactory<>("type"));//adding data to table  column

        TableColumn<CricketPlayer,Integer> rankColumn=new TableColumn<>("ICC Ranking");//add a column on table
        rankColumn.setMinWidth(100);//column size
        rankColumn.setCellValueFactory(new PropertyValueFactory<>("ranking"));//adding data to table  column

        TableView table= new TableView<>();//load table
        table.setItems(getPlayer());//load data of cricket player class
        table.getColumns().addAll(nameColumn,jerseyColumn,salaryColumn,typeColumn,rankColumn);//add column on the table

        Button add = new Button("Add");//creating add button object
        add.setPrefWidth(70);//setting the column size
        Button remove = new Button("Remove");//creating remove button object
        remove.setPrefWidth(70);//setting the column size
        Button show = new Button("Show");//creating show button object
        show.setPrefWidth(70);//setting the column size

        add.setOnAction(e-> {
            window.setScene(roasterScene());
            addPlayer();                    //setting the action of add player button
        });

        remove.setOnAction(e-> {
            window.setScene(roasterScene());
            removePlayer();            //setting the action of remove player button
        });

        show.setOnAction(e-> {
            window.setScene(showScene());//setting the action of show button
        });

        VBox vBox = new VBox();//creating VBox pane
        vBox.getChildren().addAll(add, new Label(), remove, new Label(), show);//place button on pane

        HBox hBox = new HBox();//creating HBox pane
        hBox.getChildren().addAll(new Label("       "), vBox, new Label("       "), table);//place VBox pane and table on the pane

        Scene scene = new Scene(hBox, 720,600);//adding the HBox pane on the scene

        return scene;
    }
    public void addPlayer(){//action event of add player button
        Stage stage = new Stage();
        stage.setTitle("Player Information");//stage title
        stage.initModality(Modality.APPLICATION_MODAL);//can't back to the previous window before closing the add player window

        Label label1 = new Label("Player Name  ");//label of text field
        TextField textField1 = new TextField();//declaring new text field

        Label label2 = new Label("Jersey  ");//label of text field
        TextField textField2 = new TextField();//declaring new text field

        Label label3 = new Label("Salary  ");//label of text field
        TextField textField3 = new TextField();//declaring new text field

        Label label4 = new Label("Position  ");//label of text field
        TextField textField4 = new TextField();//declaring new text field

        Label label5 = new Label("ICC Ranking  ");//label of text field
        TextField textField5 = new TextField();

        Button add = new Button("Add");
        add.setPrefWidth(70);          //adding buttons
        Button back = new Button("Back");
        back.setPrefWidth(70);

        add.setOnAction(e-> {//action of add button
            CricketPlayer C = new CricketPlayer(textField1.getText(), Integer.parseInt(textField2.getText()), Double.parseDouble(textField3.getText()), textField4.getText(), Integer.parseInt(textField5.getText()));
            //collecting data from text field
            cricketPlayers.add(C);//add data in array list

            Button close = new Button("Close");

            VBox vBox =  new VBox();
            vBox.getChildren().addAll(new Label(), new Label("Player Added"), new Label(), close);//add button and text on the pane
            vBox.setAlignment(Pos.CENTER);//placing VBox on the center of the scene

            close.setOnAction(e1-> {
                stage.close();//closing the window
            });

            Scene scene2 = new Scene(vBox, 400,300);//add pane on the scene and setting the scene size
            stage.setScene(scene2);//add scene on the stage
        });

        back.setOnAction(e-> {
            stage.close();;//closing the window
        });

        GridPane gridPane = new GridPane();//creating a pane
         
        gridPane.add(label1,0,0);//placing label on pane
        gridPane.add(textField1,1,0);//placing the text field and labels on a grid pane
        gridPane.add(new Label(),0,1);//placing label on pane
        gridPane.add(label2,0,2);//placing label on pane
        gridPane.add(textField2,1,2);//placing the text field and labels on a grid pane
        gridPane.add(new Label(),0,3);//placing label on pane
        gridPane.add(label3,0,4);//placing label on pane
        gridPane.add(textField3,1,4);//placing the text field and labels on a grid pane
        gridPane.add(new Label(),0,5);//placing label on pane
        gridPane.add(label4,0,6);//placing label on pane
        gridPane.add(textField4,1,6);//placing the text field and labels on a grid pane
        gridPane.add(new Label(),0,7);//placing label on pane
        gridPane.add(label5,0,8);//placing label on pane
        gridPane.add(textField5,1,8);//placing the text field and labels on a grid pane
        gridPane.add(new Label(),0,9);//placing label on pane
        gridPane.add(add,0,10);//placing the add button on pane
        gridPane.add(back,1,10);//placing back button on pane

        gridPane.setAlignment(Pos.CENTER);//setting the alignment on center of the scene

        Scene scene = new Scene(gridPane,400,300);//add pane on the scene and setting the scene size
        stage.setScene(scene);//set scene on the stage
        stage.show();//show the stage
    }
        
    public void removePlayer(){//action event of remove player button
        Stage stage = new Stage();//creating new stage
        stage.setTitle("Remove Player");//stage title

        stage.initModality(Modality.APPLICATION_MODAL);//can't back to the previous window before closing the add player window

        Label label1 = new Label("Player Name  ");//creating new table
        TextField textField1 = new TextField();//creating text field

        Button remove = new Button("Remove");
        Button back = new Button("Back");    //create button object

        GridPane gridPane = new GridPane();//creating new grid pane

        gridPane.add(label1,0,0);
        gridPane.add(textField1,1,0);
        gridPane.add(new Label(),0,1);  //add text field and labels on the pane
        gridPane.add(remove,0,2);
        gridPane.add(back,1,2);

        gridPane.setAlignment(Pos.CENTER);//set the pane on the center of the scene

        remove.setOnAction(e-> {//action event of remove  button
            String msg = "No such player exist";

            for(int i = 0; i < cricketPlayers.size(); i++){
                if(cricketPlayers.get(i).getPlayerName().equals(textField1.getText())){//searching for player we have to remove
                    cricketPlayers.remove(i);//removing the player
                    msg = "Player removed";//this text on the scene
                    break;
                }
            }

            Button close = new Button("Close");

            VBox vBox =  new VBox();//create new vertical box pane
            vBox.getChildren().addAll(new Label(), new Label(msg), new Label(), close);//add button and labels on the pane
            vBox.setAlignment(Pos.CENTER);//place the pane center of the scene

            close.setOnAction(e1-> {
                stage.close();//closing the window
            });

            Scene scene2 = new Scene(vBox, 400,300);//add pane on the scene
            stage.setScene(scene2);//add scene n the stage
        });

        back.setOnAction(e-> {
            stage.close();//close the window/stage
        });

        gridPane.setAlignment(Pos.CENTER);//place the pane center of the scene

        Scene scene = new Scene(gridPane,400,300);
        stage.setScene(scene);//add scene on the stage
        stage.show();//show the stage
    }
}

