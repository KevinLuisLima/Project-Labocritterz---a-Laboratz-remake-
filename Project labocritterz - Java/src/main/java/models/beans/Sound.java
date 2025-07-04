package models.beans;
import com.raylib.Raylib;

public class Sound {
    int waitTime;
    float volume;
    Raylib.Sound soundArchive;

    public Sound(Raylib.Sound soundArchive){
        this.soundArchive = soundArchive;
    }

    public int getWaitTime(){
        return waitTime;
    }
    public float getVolume(){
        return volume;
    }
    public Raylib.Sound getSoundArchive(){
        return soundArchive;
    }

    public void setWaitTime(int waitTime){
        this.waitTime = waitTime;
    }
    public void setVolume(float volume){
        this.volume = volume;
    }
}
