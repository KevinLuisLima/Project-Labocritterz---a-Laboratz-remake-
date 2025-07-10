package controllers;
import com.raylib.Raylib;
import models.repository.ScreenRepo;

public class ScreenController {
    private ScreenRepo repository;
    private FileManipulator fileManipulator;

    public ScreenController(){
        try {
            this.fileManipulator = new FileManipulator();
            int selectedResolution = Integer.parseInt((fileManipulator.configReader(0).get(0)));
            this.repository = new ScreenRepo(selectedResolution);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public boolean initializeScreen(){
        try {
            Raylib.InitWindow(repository.getScreenHeight(), repository.getScreenWidth(), "Labocritterz - Um remake de Laboratz!");
            Raylib.SetTargetFPS(60);
            return true;
        } catch (Exception e) {
            e.printStackTrace();
        }
        return false;
    }
}
