package models.beans;
import java.util.ArrayList;

public class Board {
    private final ArrayList<Place> placement;

    public Board(ArrayList<Place> placement){
        this.placement = placement;
    }

    public Place getPlacementIndex(int index) {
        return placement.get(index);
    }
}
