package controllers;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class FileManipulator {

    public boolean gameFileInit(){
        try {
            String folderPath = "src/main/resources/gameLog";
            String fileName = "configs.log";
            String content = "resolution 1280 720";
            File createFolder = new File(folderPath);
            File createFile = new File(folderPath,fileName);
            File createFileOnly = new File(folderPath + "/" + fileName);

            if (!createFolder.exists()) {
                if (createFolder.mkdir()) {
                    return simpleFileWriter(createFile, content);
                }
            } else if (!createFileOnly.exists()) {
                return simpleFileWriter(createFile, content);
            }
        }
        catch (Exception e) {
            throw new RuntimeException(e);
        }
        return false;
    }
    private boolean simpleFileWriter(File fileToCreate,String content) {
        try{
            FileWriter writer = new FileWriter(fileToCreate);
            writer.write(content + "\n");
            writer.flush();
            writer.close();
            return true;
        }catch (IOException IOE){
            IOE.printStackTrace();
        }
        return false;
    }

//    public ArrayList<String> fileReader(){
//    }
}
