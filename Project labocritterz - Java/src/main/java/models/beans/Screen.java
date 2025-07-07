package models.beans;

public class Screen {
    private final int height;
    private final int width;
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
