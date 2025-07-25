package org.example;
import com.raylib.Raylib;
import controllers.FileManipulator;
import controllers.ImageController;
import controllers.ScreenController;
import controllers.SoundController;

import static com.raylib.Colors.RAYWHITE;

public class Main {

    public static void main(String[] args) {
        try {
            System.out.println("Hello and welcome!\n");
            FileManipulator fileManip = new FileManipulator();
            ScreenController screenCon = new ScreenController();
            SoundController soundCon = new SoundController();
            ImageController imageCon = new ImageController();
            fileManip.gameFileInit();
            screenCon.initializeScreen();

            while(!Raylib.WindowShouldClose()){
              Raylib.BeginDrawing();
              imageCon.drawnImagesFor("Menu");
              Raylib.ClearBackground(RAYWHITE);
              Raylib.EndDrawing();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}