package models.beans;
import com.raylib.Raylib;

public class Button {
    Raylib.Rectangle hitBox;
    Raylib.Image image;

    public Button(Raylib.Rectangle hitBox, Raylib.Image image){
        this.hitBox = hitBox;
        this.image = image;
    }

    public Raylib.Rectangle getHitBox(){
        return hitBox;
    }
    public Raylib.Image getImage(){
        return image;
    }


}
