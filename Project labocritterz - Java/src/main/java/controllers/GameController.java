package controllers;
import com.raylib.Raylib;
import models.beans.Button;
import models.beans.Game;

public class GameController {
    Game game;
    GeneralController generalController;
    Button startButton;

    public GameController(){
        Raylib.Rectangle hitBox = new Raylib.Rectangle().x(490).y(420).width(300).height(80);
        Button startButton = new Button(hitBox, Raylib.LoadImage());
    }

    public Game getGame() {
        return game;
    }

    public boolean startup(){
        try{
            generalController.getScreenController().initializeScreen();
            generalController.getSoundController().initializeAudioDevice();
            return true;
        } catch (Exception e) {
            return false;
        }
    }

    public boolean menu(){

    }

    public boolean runMusicStream(){
        try{
            //Raylib.UpdateMusicStream();
            return true;
        } catch(Exception e){
            return false;
        }
    }

    public void startMatch(){
        generalController.matchController.startup();
    }

    public String isDesiredButtonBeingPressed(Raylib.Vector2 mousePosition, String buttonInput){
        if(buttonInput.equals("startGame")){
            return Raylib.CheckCollisionPointRec(mousePosition,hitbox);
        } else if (buttonInput.equals("endGame")) {
            
        }
        boolean resultCollisionTest = Raylib.CheckCollisionPointRec(mousePosition, desiredButton);
    }
    
    public void shutdown(){
        
    }
}
