package controllers;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class FileManipulator {

    public boolean gameFileInit(){
        try {

            String folderPath = "src/main/java/resources/gameLog";
            String fileName = "initFile.log";
            String content = "1280 720";
            File createFolder = new File(folderPath);
            File createFile = new File(folderPath,fileName);
            File createFileOnly = new File(folderPath + "/" + fileName);
            if (!createFolder.exists()) {
                if (createFolder.mkdir()) {
                    return simpleFileWriter(createFile);
                }
            } else if (!createFileOnly.exists()) {
                return simpleFileWriter(createFile);
            }
        }
        catch (Exception e) {
            throw new RuntimeException(e);
        }
        return false;
    }
    private boolean simpleFileWriter(File fileToCreate) {
        try{
            FileWriter writer = new FileWriter(fileToCreate);
            writer.flush();
            writer.close();
            return true;
        }catch (IOException IOE){
            IOE.printStackTrace();
        }
        return false;
    }
}
