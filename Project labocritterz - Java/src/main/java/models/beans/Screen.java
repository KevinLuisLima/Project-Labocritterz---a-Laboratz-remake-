package models.beans;

public class Screen {
    int height;
    int width;
    public Screen(int height, int width){
        this.height = height;
        this.width = width;
    }

    public int getHeight(){
        return height;
    }
    public int getWidth(){
        return width;
    }
}
