package views;
import com.raylib.Raylib;
import controllers.GameController;

import static com.raylib.Colors.RAYWHITE;
import static com.raylib.Colors.WHITE;
import static com.raylib.Raylib.MOUSE_BUTTON_LEFT;

public class GameView {
    GameController gameController;
    Raylib.Vector2 mousePosition;
    boolean gameLoop;
    boolean collision;

    public GameView(){
        this.gameLoop = true;
    }

    public void menuCycle(){
            gameLoop = gameController.startup();
            while(!gameLoop){
                gameController.runMusicStream();

                if(Raylib.IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                    if(isDesiredButtonBeingPressed()){
                        gameController.startMatch();
                    }
                }
                generateTheBackground();
            }

    }

    public boolean isDesiredButtonBeingPressed(desiredButton){
        mousePosition = Raylib.GetMousePosition();
        return Raylib.CheckCollisionPointRec(mousePosition, desiredButton);
    }
    
    public void generateTheBackground(){
        Raylib.BeginDrawing();
        Raylib.DrawTexture(, 0, 0, WHITE);
        Raylib.ClearBackground(RAYWHITE);
        Raylib.EndDrawing();
    }
}
