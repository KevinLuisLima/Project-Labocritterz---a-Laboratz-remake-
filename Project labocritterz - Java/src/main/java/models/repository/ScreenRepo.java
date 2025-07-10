package models.repository;
import models.beans.Screen;
import java.util.ArrayList;

public class ScreenRepo {
    private int resolutionSelected;
    private ArrayList<Screen> object = new ArrayList<Screen>();

    public ScreenRepo(int initialScreen){
        Screen one = new Screen(640,480);
        Screen oneSquare = new Screen(800, 600);
        Screen two = new Screen(1280,720);
        Screen twoSquare = new Screen(1024, 768);
        Screen three = new Screen(1920, 1080);
        Screen threeSquare = new Screen(1600, 1200);
        this.object.add(one);
        this.object.add(oneSquare);
        this.object.add(two);
        this.object.add(twoSquare);
        this.object.add(three);
        this.object.add(threeSquare);
        this.resolutionSelected = initialScreen;
    }

    public int getScreenHeight() {
        return object.get(resolutionSelected).getHeight();
    }
    public int getScreenWidth() {
        return object.get(resolutionSelected).getWidth();
    }
    public int getScreenResolution(){
        return resolutionSelected;
    }

    public boolean setScreenResolution(int screenSelected){
        try{
            this.resolutionSelected = screenSelected;
            return true;
        }catch (Exception e){
            e.printStackTrace();
        }
        return false;
    }
}
