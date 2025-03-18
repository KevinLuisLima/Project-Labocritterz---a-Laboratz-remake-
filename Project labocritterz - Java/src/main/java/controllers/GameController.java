package controllers;
import com.raylib.Raylib;
import models.Game;

public class GameController {
    Game game;
    GeneralController generalController;
    public GameController(){}

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
}
