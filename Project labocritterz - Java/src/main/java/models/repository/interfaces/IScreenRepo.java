package models.repository.interfaces;
public interface IScreenRepo {
    int getScreenHeight();
    int getScreenWidth();
    int getScreenResolution();
    boolean setScreenResolution(int screenSelected);
}
