package views;
import com.raylib.Raylib;
import controllers.GameController;

import static com.raylib.Colors.RAYWHITE;
import static com.raylib.Colors.WHITE;
import static com.raylib.Raylib.MOUSE_BUTTON_LEFT;

public class GameView {
    GameController gameController;
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
                    Raylib.Vector2 mousePosition = Raylib.GetMousePosition();
                    if(gameController.isDesiredButtonBeingPressed(mousePosition,"startGame")){
                        gameController.startMatch();
                    } else if (gameController.isDesiredButtonBeingPressed(mousePosition,"endGame")) {
                        gameController.shutdown();
                    }
                }
                generateTheBackground();
            }

    }
    
    public void generateTheBackground(){
        Raylib.BeginDrawing();
        Raylib.DrawTexture(, 0, 0, WHITE);
        Raylib.ClearBackground(RAYWHITE);
        Raylib.EndDrawing();
    }
}
