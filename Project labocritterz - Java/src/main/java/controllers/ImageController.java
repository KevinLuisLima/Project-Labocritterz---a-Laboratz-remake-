package controllers;
import com.raylib.Raylib;
import models.repository.ImageRepo;
import static com.raylib.Colors.WHITE;

public class ImageController {
    private ImageRepo repository;
    private FileManipulator fileManipulator = new FileManipulator();

    public ImageController() {
        try {
            this.repository = new ImageRepo(fileManipulator.readArchivePaths("Images"));
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void drawnImagesFor(String currentScreen) {
        try {
            switch (currentScreen){
                case "Menu":
                    Raylib.Texture texture = Raylib.LoadTextureFromImage(repository.getImages().get(0).getImage());
                    Raylib.DrawTexture(texture,0,0,WHITE);
                    break;
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
