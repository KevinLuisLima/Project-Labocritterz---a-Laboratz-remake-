package controllers;
import java.io.*;
import java.nio.file.FileSystemException;
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

    public ArrayList<String> configReader(int line){
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
            ArrayList<String> result = new ArrayList<String>();

            for(int index = 1; index < lineSplitted.length; index++){
                result.add(lineSplitted[index]);
            }
            return result;

        }catch (Exception e){
            e.printStackTrace();
        }
        return null;
    }

    public ArrayList<String> readArchivePaths(String name){
        try{
            String pathName = " ";
            switch (name){
                case "Sounds":
                    pathName = "src/main/resources/Sounds/Paths.log";
                    break;

                case "Images":
                    pathName = "src/main/resources/Images/Paths.log";
                    break;
            }

            if (!pathName.equals(" ")){
                File providedPath = new File(pathName);
                if(!providedPath.exists()){
                    if(!providedPath.mkdir()){
                        throw new RuntimeException();
                    }
                }
                ArrayList<String> output = new ArrayList<String>();
                BufferedReader reader = new BufferedReader(new FileReader(pathName));
                String read;
                while((read = reader.readLine()) != null){
                    String[] vector = read.split("\n");
                    String instance = vector[0];
                    output.add(instance);
                }
                reader.close();
                return output;
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return null;
    }
}
