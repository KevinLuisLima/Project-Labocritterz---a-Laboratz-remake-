package models.beans;
import com.raylib.Raylib;

public class Sound {
    int waitTime;
//    float volume;
    Raylib.Sound soundArchive;
    String name;

    public Sound(Raylib.Sound soundArchive, String name){
        this.soundArchive = soundArchive;
        this.name = name;
    }

    public int getWaitTime(){
        return waitTime;
    }
    public Raylib.Sound getSoundArchive(){
        return soundArchive;
    }
    public String getName(){
        return name;
    }

    public void setWaitTime(int waitTime){
        this.waitTime = waitTime;
    }
}
