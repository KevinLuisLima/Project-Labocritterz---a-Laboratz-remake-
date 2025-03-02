package org.example;
import com.raylib.Raylib.*;
import controllers.generalController;

public class Main {
    static generalController controller;

    public static void main(String[] args) {
        this.controller = new generalController();
        System.out.printf("Hello and welcome!\n");
        controller.getScreenController().initiateScreen();
    }
}