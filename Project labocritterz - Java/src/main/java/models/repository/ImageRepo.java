package models.repository;
import models.beans.Image;
import java.util.ArrayList;

public class ImageRepo {
    private ArrayList<Image> object = new ArrayList<Image>();

    public ImageRepo(ArrayList<String> paths) {
        for (String path : paths) {
            Image instance = new Image();
            instance.loadImage(path);
            object.add(instance);
        }
    }

    public ArrayList<Image> getObject() {
        return object;
    }
}
