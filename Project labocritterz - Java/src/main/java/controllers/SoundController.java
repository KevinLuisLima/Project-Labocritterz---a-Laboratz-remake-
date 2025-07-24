package controllers;
import com.raylib.Raylib;
import models.beans.Sound;
import models.repository.SoundRepo;

import java.util.ArrayList;

public class SoundController {
    private SoundRepo repository;
    private FileManipulator fileManipulator;
    public SoundController(){
        this.repository = new SoundRepo();
        this.fileManipulator = new FileManipulator();
        initializeAudioDevice();
    }

    public void initializeAudioDevice(){
        Raylib.InitAudioDevice();
    }
}
