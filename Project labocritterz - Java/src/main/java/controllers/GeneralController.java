package controllers;

public class GeneralController {
    BoardController boardController;
    ButtonController buttonController;
    CardController cardController;
    DeckController deckController;
    GameController gameController;
    ImageController imageController;
    MatchController matchController;
    PlaceController placeController;
    ScreenController screenController;
    SoundController soundController;

    public GeneralController(){
        this.boardController = new BoardController();
        this.buttonController = new ButtonController();
        this.cardController = new CardController();
        this.deckController = new DeckController();
        this.gameController = new GameController();
        this.imageController = new ImageController();
        this.matchController = new MatchController();
        this.placeController = new PlaceController();
        this.screenController = new ScreenController();
        this.soundController = new SoundController();
    }

    public BoardController getBoardController() {
        return boardController;
    }
    public ButtonController getButtonController() {
        return buttonController;
    }
    public CardController getCardController() {
        return cardController;
    }
    public DeckController getDeckController() {
        return deckController;
    }
    public GameController getGameController() {
        return gameController;
    }
    public ImageController getImageController() {
        return imageController;
    }
    public MatchController getMatchController() {
        return matchController;
    }
    public PlaceController getPlaceController() {
        return placeController;
    }
    public ScreenController getScreenController() {
        return screenController;
    }
    public SoundController getSoundController() {
        return soundController;
    }

}
