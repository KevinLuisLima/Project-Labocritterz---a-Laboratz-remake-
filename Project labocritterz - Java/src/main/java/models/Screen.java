package models;

public class Screen {
    int height;
    int width;

    public Screen(int height, int width){
        this.height = height;
        this.width = width;
    }

    public Float getHeight(){
        return height;
    }
    public Float getWidth(){
        return width;
    }
}
