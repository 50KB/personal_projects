set PATH_TO_FX=".\Environment\lib"
javac --module-path %PATH_TO_FX% --add-modules javafx.controls,javafx.fxml Source\GUI.java 
java --module-path %PATH_TO_FX% --add-modules javafx.controls Source.GUI