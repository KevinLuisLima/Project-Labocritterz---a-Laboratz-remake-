package org.example;
import controllers.FileManipulator;
import controllers.ScreenController;
import controllers.SoundController;

public class Main {

    public static void main(String[] args) {
        try {
            System.out.printf("Hello and welcome!\n");
            FileManipulator fileManip = new FileManipulator();
            fileManip.gameFileInit();
            ScreenController screenCon = new ScreenController();
            screenCon.initializeScreen();
            SoundController soundCon = new SoundController();
//        Raylib.Texture texture = Raylib.LoadTextureFromImage(image.getImage());
//        while(!Raylib.WindowShouldClose()){
//            Raylib.BeginDrawing();
//            Raylib.DrawTexture(texture,0,0,WHITE);
//            Raylib.ClearBackground(RAYWHITE);
//            Raylib.EndDrawing();
//        }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}