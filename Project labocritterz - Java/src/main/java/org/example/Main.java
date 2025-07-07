package org.example;
import controllers.FileManipulator;
import controllers.ScreenController;
public class Main {

    public static void main(String[] args) {
        System.out.printf("Hello and welcome!\n");
        FileManipulator fileManip = new FileManipulator();
        ScreenController screenCon = new ScreenController();
        fileManip.gameFileInit();
//        controller.getScreenController().initializeScreen();
//        controller.getSoundController().initializeAudioDevice();
//        Image image = new Image();
//        Raylib.Texture texture = Raylib.LoadTextureFromImage(image.getImage());
//        while(!Raylib.WindowShouldClose()){
//            Raylib.BeginDrawing();
//            Raylib.DrawTexture(texture,0,0,WHITE);
//            Raylib.ClearBackground(RAYWHITE);
//            Raylib.EndDrawing();
//        }
    }
}