package models;
import com.raylib.Raylib;

public class Image {
    Raylib.Image image;

    public Image(){
        this.image = Raylib.LoadImage("src/main/resources/Screens_Images/menu.png");
    }

    public Raylib.Image getImage() {
        return image;
    }
}
