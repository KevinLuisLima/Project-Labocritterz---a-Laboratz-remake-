package controllers;
import java.io.*;
import java.util.ArrayList;

public class FileManipulator {

    public boolean gameFileInit(){
        try {
            String folderPath = "src/main/resources/gameLog";
            String fileName = "configs.log";
            String content = "resolution 2";
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

    public String configReader(int line){
        try{
            String filePath = "src/main/resources/gameLog/configs.log";
            File checkFilePath = new File(filePath);

            if (!checkFilePath.exists()){
                gameFileInit();
            }
            ArrayList<String> output = new ArrayList<String>();
            BufferedReader reader = new BufferedReader(new FileReader(filePath));
            String read;

            while((read = reader.readLine()) != null){
                String[] vector = read.split("\n");
                String instance = vector[0];
                output.add(instance);
            }
            reader.close();
            String[] lineSplitted = output.get(line).split(" ");
            
        }catch (IOException IOE){
            IOE.printStackTrace();
        }
        return null;
    }
}
