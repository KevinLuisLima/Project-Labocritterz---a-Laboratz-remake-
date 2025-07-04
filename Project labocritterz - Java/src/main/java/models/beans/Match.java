package models.beans;

import java.util.ArrayList;

public class Match {
    ArrayList<Deck> decksUsed;
    String matchResult;

    public Match(ArrayList<Deck> decksUsed){
        this.decksUsed = decksUsed;
    }

    public ArrayList<Deck> getDecksUsed(){
        return decksUsed;
    }
    public String getMatchResult(){
        return matchResult;
    }

    public void setMatchResult(String matchResult){
        this.matchResult = matchResult;
    }
}
