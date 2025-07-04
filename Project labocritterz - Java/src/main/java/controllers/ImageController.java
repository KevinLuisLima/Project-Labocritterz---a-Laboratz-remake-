package controllers;
import com.raylib.Raylib;

import java.util.ArrayList;

public class ImageController {
    ArrayList<Raylib.Image> image;

    public ImageController(){
        //Image image = new Image();
        //this.image.add(image.getImage());
    }

    public Raylib.Image getImage(int index) {
        return image.get(index);
    }
}
