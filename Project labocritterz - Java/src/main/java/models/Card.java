package models;
import com.raylib.Raylib;
import java.util.ArrayList;

public class Card {
    Raylib.Image image;
    long cardID;
    ArrayList<Integer> cardSideValues;
    float height;
    float width;

    public Card(Raylib.Image image, long cardID, float height, float width){
        this.image = image;
        this.cardID = cardID;
        this.height = height;
        this.width = width;
    }

    public Raylib.Image getImage(){
        return image;
    }
    public long getCardID(){
        return cardID;
    }
    public ArrayList<Integer> getCardSideValues(){
        return cardSideValues;
    }
    public float getHeight(){
        return height;
    }
    public float getWidth(){
        return width;
    }
}
