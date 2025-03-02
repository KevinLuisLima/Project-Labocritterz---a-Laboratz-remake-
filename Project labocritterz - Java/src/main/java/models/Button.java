package models;
import com.raylib.Raylib;

public class Button {
    Raylib.Rectangle hitbox;
    Float position;
    Raylib.Image image;

    public Button(Raylib.Rectangle hitbox, Float position, Raylib.Image image){
        this.hitbox = hitbox;
        this.position = position;
        this.image = image;
    }

    public Raylib.Rectangle getHitbox(){
        return hitbox;
    }
    public Float getPosition(){
        return position;
    }
    public Raylib.Image getImage(){
        return image;
    }

    public void setPosition(Float position){
        this.position = position;
    }
}
