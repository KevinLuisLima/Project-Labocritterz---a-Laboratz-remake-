package controllers;
import models.Screen;
import com.raylib.Raylib;

public class ScreenController {
    Screen screen;
    public ScreenController(){
        this.screen = new Screen(720,1280);
    }

    public Screen getScreen() {
        return screen;
    }

    public void setScreen(Screen screen) {
        this.screen = screen;
    }

    public void initializeScreen(){
        Raylib.InitWindow(screen.getWidth(),screen.getHeight(),"Labocritterz - Um remake de Laboratz!");
        Raylib.SetTargetFPS(60);
    }
}
