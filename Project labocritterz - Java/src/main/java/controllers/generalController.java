package controllers;
import com.raylib.Raylib;

public class generalController {
    ScreenController screenController;
    public generalController(){
        this.screenController = new ScreenController();
    }

    public ScreenController getScreenController() {
        return screenController;
    }
}
