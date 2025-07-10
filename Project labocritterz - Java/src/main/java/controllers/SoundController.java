package controllers;
import com.raylib.Raylib;
import models.beans.Sound;

import java.util.ArrayList;

public class SoundController {
    ArrayList<Sound> sound;
    public SoundController(){
    }

    public Sound getSound(int index){
        return sound.get(index);
    }

    public void initializeAudioDevice(){
        Raylib.InitAudioDevice();
    }
}
