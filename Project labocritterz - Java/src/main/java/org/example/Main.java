package org.example;
import com.raylib.Raylib;
import controllers.GeneralController;
import models.beans.Image;

import static com.raylib.Colors.*;

public class Main {
    static GeneralController controller;

    public static void main(String[] args) {
        controller = new GeneralController();
        System.out.printf("Hello and welcome!\n");

        controller.getScreenController().initializeScreen();
        controller.getSoundController().initializeAudioDevice();
        Image image = new Image();
        Raylib.Texture texture = Raylib.LoadTextureFromImage(image.getImage());
        while(!Raylib.WindowShouldClose()){
            Raylib.BeginDrawing();
            Raylib.DrawTexture(texture,0,0,WHITE);
            Raylib.ClearBackground(RAYWHITE);
            Raylib.EndDrawing();
        }
    }
}