package models;
import java.util.ArrayList;

public class Deck{

    ArrayList<Card> cardsContained;
    long deckID;
    String deckName;

    public Deck(long deckID, String deckName){
        this.deckID = deckID;
        this.deckName = deckName;
    }

    public ArrayList<Card> getCardsContained(){
        return cardsContained;
    }
    public long getDeckID(){
        return deckID;
    }
    public String getDeckName(){
        return deckName;
    }

    public void setCardsContained(ArrayList<Card> cardsContained) {
        this.cardsContained = cardsContained;
    }
    public void setDeckName(String deckName){
        this.deckName = deckName;
    }
}
