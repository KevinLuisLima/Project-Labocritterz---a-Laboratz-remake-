package controllers;
import models.beans.Screen;
import com.raylib.Raylib;
import models.repository.ScreenRepo;

public class ScreenController {
    private ScreenRepo repository;
    private FileManipulator fileManipulator;

    public ScreenController(){
        this.repository = new ScreenRepo(fileManipulator.);
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
