package models.beans;
import com.raylib.Raylib;

public class Image {
    Raylib.Image image = new Raylib.Image();

    public Raylib.Image getImage() {
        return image;
    }
    public boolean loadImage(String path){
        try {
            this.image = Raylib.LoadImage(path);
            return true;
        } catch (Exception e) {
            e.printStackTrace();
        }
        return false;
    }
}