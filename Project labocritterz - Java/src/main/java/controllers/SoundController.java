package controllers;
import com.raylib.Raylib;
import models.Sound;

import java.util.ArrayList;

public class SoundController {
    ArrayList<Sound> sound;
    public SoundController(){
        //initialize the sounds
    }

    public Sound getSound(int index){
        return sound.get(index);
    }

    public void initializeAudioDevice(){
        Raylib.InitAudioDevice();
    }
}
